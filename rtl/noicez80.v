/****************************************************************************
	build in BIOS / NoICE no-resorce monitor

	Version 050414

	Copyright(C) 2004,2005 Tatsuyuki Satoh

	This software is provided "AS IS", with NO WARRANTY.
	NON-COMMERCIAL USE ONLY

	Histry:
		2005. 4.14 fix RXD clear glidge
		2005. 1.11 1st

	Note:

	Distributing all and a part is prohibited. 
	Because this version is developer-alpha version.

	use two byte stack memory for BREAK

memory map in debug_enable

0000-0fff   monitor program
1000-1fff   monitor M1 area and user MEM area
2000-2fff   Can't use.
3000-3fff   monitor M1 area and user MEM area and Switch user mode
4000-7fff   monitor work RAM area
8000-ffff.W UART TX data
8000-ffff.R UART RX data
c000-ffff.W BANK select
c000-ffff.R status port , UART TX & RX , trap mode , etc

trap-1 (break point) : after RST 00H op-code
trap-2(nmi)          : OP 0066H(NMI) after NMI and trap enable

****************************************************************************/

module noicez80 (
// remote debug port
  I_REM_CLK,
  I_REM_CLKE,
  I_REM_RXD,
  O_REM_TXD,
// remote controll
  O_REM_MODE,
  I_TRAP_ENABLE,
  O_BANK,
// Inputs
  I_RESET_n,
  I_CLK,
  I_INT_n,
  I_NMI_n,
  I_M1_n,
  I_MREQ_n,
  I_IORQ_n,
  I_RD_n,
  I_WR_n,
  I_HALT_n,
  I_A,
  I_DR,
  I_DW,
// hooked Outputs
  O_MREQ_n,
  O_NMI_n,
  O_INT_n,
  O_DR
);

input I_REM_CLK;
input I_REM_CLKE;
input I_REM_RXD;
output O_REM_TXD;
output O_REM_MODE;
input I_TRAP_ENABLE;
output [3:0] O_BANK;

input I_RESET_n;
input I_CLK;
input  I_M1_n;
input I_INT_n;
input I_NMI_n;
input [7:0] I_DR;
input I_MREQ_n;
input  I_IORQ_n;
input  I_RD_n;
input  I_WR_n;
input  I_HALT_n;
input [15:0] I_A;
input [7:0]  I_DW;

output  O_MREQ_n;
output  O_NMI_n;
output  O_INT_n;
output [7:0] O_DR;

/////////////////////////////////////////////////////////////////////////////
// registers
/////////////////////////////////////////////////////////////////////////////
reg debug_enable;
reg reset_start;
reg user_msel;
reg user_sel;
reg op_c7;
reg op_cb;
reg last_cb;
reg user_trap;

reg [3:0] bank_r;

/////////////////////////////////////////////////////////////////////////////
// memory access switch
/////////////////////////////////////////////////////////////////////////////
wire debug_window = debug_enable & I_IORQ_n & (~user_msel | ~I_M1_n);

/////////////////////////////////////////////////////////////////////////////
// IRQ MASK
/////////////////////////////////////////////////////////////////////////////
assign O_INT_n = I_INT_n | debug_enable;
assign O_NMI_n = (I_NMI_n & ~user_trap) | debug_enable;

/////////////////////////////////////////////////////////////////////////////
// UESR TRAP (NMI break)
/////////////////////////////////////////////////////////////////////////////
wire trap_req = I_TRAP_ENABLE & ~I_NMI_n;

always @(posedge I_CLK or negedge I_RESET_n)
begin
  if(~I_RESET_n)
  begin
    user_trap <= 1'b0;
  end else begin
    if(user_sel)
      user_trap <= 1'b0;
    else if(trap_req)
      user_trap <= 1'b1;
  end
end

/////////////////////////////////////////////////////////////////////////////
// TRAP handling
/////////////////////////////////////////////////////////////////////////////
wire op_cx = ~I_M1_n & ~debug_enable & (I_DR[7:4]==4'b1100) & (I_DR[1:0]==2'b11);

always @(posedge I_CLK or negedge I_RESET_n)
begin
  if(~I_RESET_n)
  begin
    debug_enable <= 1'b1;
    reset_start  <= 1'b1;
    user_msel    <= 1'b0;
    user_sel     <= 1'b0;

    op_c7   <= 1'b0;
    op_cb   <= 1'b0;
    last_cb <= 1'b0;
  end else begin
    if(~I_MREQ_n & ~I_RD_n)
    begin
      // opcode catch
      op_c7  <= op_cx & (I_DR[3:2]==2'b01) & ~last_cb;
      op_cb  <= op_cx & (I_DR[3:2]==2'b10);
      if(~I_M1_n)
      begin
        user_msel <= I_A[12] | ~debug_enable; // debug 1xxxH or user mode
        user_sel  <= I_A[13] & debug_enable;  // debug 3xxxh

        // user NMI trap
        if(trap_req & (I_A==16'h0066))
        begin
          debug_enable <= 1'b1;
          reset_start  <= 1'b0;
        end
      end
    end else begin
      // not memory read
      last_cb <= op_cb;        // prefetch CB

      if(op_c7)     // after RST 00H
      begin
        // witch to debug mode
        debug_enable <= I_TRAP_ENABLE;
        reset_start  <= 1'b0;
      end
      else if(user_sel)       // debug M1 cycle in 3000-3fff
        // witch to user mode
        debug_enable <= 1'b0;
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// Address Decode
/////////////////////////////////////////////////////////////////////////////
wire rom_cs  = debug_window & ~I_A[15] & ~I_A[14]; // 4000-7fff
wire ram_cs  = debug_window & ~I_A[15] &  I_A[14]; // 4000-7fff
wire uart_cs = debug_window &  I_A[15] & ~I_A[14]; // 8000-bfff
wire sts_cs  = debug_window &  I_A[15] &  I_A[14]; // C000-ffff

/////////////////////////////////////////////////////////////////////////////
// BOOT ROM
/////////////////////////////////////////////////////////////////////////////
wire [7:0] rom_dr;

bootrom bootrom(
  .CLK(I_CLK),
  .A(I_A[10:0]),
  .DO(rom_dr)
);

/////////////////////////////////////////////////////////////////////////////
// WORK RAM
/////////////////////////////////////////////////////////////////////////////
reg [7:0] ram [511:0]; // 1KBytes Work RAM
reg [7:0] ram_dr;

always @(posedge I_CLK)
begin
  if (ram_cs) begin
    if (~I_WR_n) ram[I_A[8:0]] <= I_DW;
    else       ram_dr <= ram[I_A[8:0]];
  end
end

/****************************************************************************
  UART RX
****************************************************************************/
wire [7:0] rxd_data;
wire rx_ready;

reg rxd_clr;
always @(posedge I_CLK)
  rxd_clr <= uart_cs & ~I_RD_n; // 8000.R

uart_rx uart_rx(
  .reset(~I_RESET_n),
  .clk(I_REM_CLK), .clk_en(I_REM_CLKE),
  .rx_data(rxd_data), .rx_clr(rxd_clr), .rx_ready(rx_ready),
  .rxd(I_REM_RXD)
);

/****************************************************************************
  UART TX clock generator
****************************************************************************/
reg [3:0] uart_tcnt;
always @(posedge I_REM_CLK)
begin
  if(I_REM_CLKE) uart_tcnt <= uart_tcnt + 1;
end
wire tx_clk_e = I_REM_CLKE & (uart_tcnt==0);

/****************************************************************************
  UART TX
****************************************************************************/
wire tx_ready;
wire txd_we  = uart_cs & ~I_WR_n; // 8000.W

uart_tx uart_tx(
  .reset(~I_RESET_n), .clk(I_REM_CLK), .clk_en(tx_clk_e),
  .wclk(I_CLK),.tx_data(I_DW), .we(txd_we), .ready(tx_ready),
  .txd(O_REM_TXD)
);

/////////////////////////////////////////////////////////////////////////////
// UART status port
/////////////////////////////////////////////////////////////////////////////
wire [7:0] uart_sts;
assign uart_sts = {reset_start,4'b0000,tx_ready,I_TRAP_ENABLE,rx_ready}; // C000.R

/****************************************************************************
  bank select
****************************************************************************/
wire bank_we = sts_cs & ~I_WR_n; // C000.W
always @(posedge I_CLK or negedge I_RESET_n)
begin
  if(~I_RESET_n)
  begin
    bank_r <= 4'b0000;
  end else begin
    if(bank_we)
      bank_r <= I_DW[3:0]; // C000.W
  end
end


/////////////////////////////////////////////////////////////////////////////
// debugger mode
/////////////////////////////////////////////////////////////////////////////
assign O_REM_MODE = debug_enable;
assign O_BANK   = bank_r;
assign O_MREQ_n = I_MREQ_n | debug_window;

/////////////////////////////////////////////////////////////////////////////
// read data multiplexer
/////////////////////////////////////////////////////////////////////////////
assign O_DR     =  sts_cs  ? uart_sts :
                   uart_cs ? rxd_data :
                   ram_cs  ? ram_dr   :
                   rom_cs  ? rom_dr   :
                   I_DR;

endmodule // noice80

