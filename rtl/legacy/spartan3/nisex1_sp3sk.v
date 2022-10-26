/****************************************************************************
  X1 for Spartan3 Starter Kit 

  Version 0504xx

  Copyright(C) 2004,2005 Tatsuyuki Satoh

  This software is provided "AS IS", with NO WARRANTY.
  NON-COMMERCIAL USE ONLY

  Histry:
    2005. 4.12 
    2005. 4.12 .d88 support
    2005. 1.20 added NTSC S2 encoder
    2005. 1.14 Cleanup
           LED all off when eco-mode
    2005. 1.12 1st release

  Note:

  Distributing all and a part is prohibited. 
  Because this version is developer-alpha version.

Button assign

Button[3] : Reset Switch
Button[2] : NMI Switch
Button[1] : JOY-DOWN (select)
Button[0] : JOY-TRIG ()

LED assign

 led[0] = dummy
 led[1] = IPL select
 led[2] = dummy
 led[3] = width40;
 led[4] = 1Hz clock (sub cpu timer monitor)
 led[5] = BREAK signal (subcpu)
 led[6] = uart_rx;
 led[7] = uart_tx;

switches
 switch[0] DEFCHR/CRTC KILL (X1turbo)
 switch[1] IPL KILL
 switch[2] SUB-CPU Firmware Download Mode (build option)
 switch[3] no use
 switch[4] no use
 switch[5] eco mode (LED off)
 switch[6] 8MHz CPU clock
 switch[7] NoICE monitor mode & break enable
 
****************************************************************************/
module nisex1_sp3sk(
  uart_tx,uart_rx,switch,button,led,
  led7seg , led7com,
  ram_addr , ram_we,ram_oe,
  ram_a_data,ram_a_ce,ram_a_lb,ram_a_ub,
  ram_b_data,ram_b_ce,ram_b_lb,ram_b_ub,
  din,cclk,reset_prom,
  clk,
// PS2
   PS2_CLK,PS2_DATA,
// sound
  DAC,
// S1 out
  VY,VC,
// VGA
  VGA_R,VGA_G,VGA_B,VGA_HS,VGA_VS
);

/****************************************************************************
  I/O PIN description
****************************************************************************/
             
// PS2 keyboard / mouse
inout PS2_CLK;
inout PS2_DATA;

// 1bit SigmaDelta SOUND DAC
output DAC;

// VGA monitor
output VGA_R,VGA_G,VGA_B;
output VGA_HS,VGA_VS;

// RS232C serial port
output uart_tx;
input uart_rx;

// switch & button
input [7:0] switch;
input [3:0] button;

// static LED
output [7:0] led;

// 7segment LED
output [7:0] led7seg;
output [3:0] led7com;

// SRAM
output [17:0] ram_addr;
output ram_we;
output ram_oe;
inout [15:0] ram_a_data;
output ram_a_ce;
output ram_a_lb;
output ram_a_ub;
inout [15:0] ram_b_data;
output ram_b_ce;
output ram_b_lb;
output ram_b_ub;

// CFG ROM
inout din;
output cclk;
output reset_prom;

// 50MHz clock
input clk;

// NTSC S2
output [3:0] VY;
output [3:0] VC;

/****************************************************************************
  button / switch function
****************************************************************************/
wire ext_reset     = button[3];
wire ext_nmi     = button[2];
wire ext_joya_dn   = button[1];
wire ext_joya_t1   = button[0];
`ifdef OVER_CLOCK
wire ext_8mhz    = switch[6];
`else
wire ext_8mhz    = 1'b0;
`endif

wire ext_ipl_kill  = switch[1];
wire ext_trap_en   = switch[7];
wire defchr_disable = switch[0];
wire ext_eco_mode  = switch[5];

/****************************************************************************
  clock generator
****************************************************************************/
wire clk_reset;

wire clk50M;
wire clk28M636;
wire clk24M;
wire clk32M;

wire lock50M;
wire lock28M636;
wire lock32M;

xc3_clk x1_base_clock(
// clock input
  .I_RESET(ext_reset),
  .I_CLK50M(clk),
// clock output
  .O_CLK50M(clk50M),
  .O_CLK28M636(clk28M636),
  .O_CLK32M(clk32M),
  .O_CLK24M(clk24M),
// lock output
  .O_LOCK50M(lock50M),
  .O_LOCK28M636(lock28M636),
  .O_LOCK32M(lock32M),
  .O_LOCK24M()
);

assign clk_reset = ext_reset | ~lock50M | ~lock28M636 | ~lock32M;

/****************************************************************************
  115.2KHz x 16 UART clock
****************************************************************************/
reg [3:0] uart_pris;

wire uart_clk   = clk24M;
wire uart_clk_e = (uart_pris==12);

always @(posedge uart_clk)
begin
  uart_pris <= uart_clk_e ? 0 : uart_pris + 1;
end

/****************************************************************************
  7SEGMENT LED module
****************************************************************************/

wire [15:0] seg7_num; // binary number
wire [3:0]  seg7_dot; // dot inputs

`ifdef LED_7SEG

reg [15:0] clk400_cnt;
wire clk400e = (clk400_cnt==0);
always @(posedge clk24M or posedge clk_reset)
begin
  if(clk_reset)
  begin
  clk400_cnt <= 0;
  end else begin
  clk400_cnt <= clk400e ? (60000-1) : clk400_cnt-1;
  end
end

hex4_7seg segment7(
  .clk4i(clk24M),
  .clk4e(clk400e),
  .reset(ext_eco_mode),
  .num(seg7_num),
  .dot(seg7_dot),
  .segment(led7seg),
  .common(led7com)
);
`else

assign led7seg = 8'h00;
assign led7com = 4'B1111;
`endif

/****************************************************************************
  PS/2 KBD
****************************************************************************/
wire ps2_clk_t,ps2_dat_t;

assign PS2_CLK  = ps2_clk_t ? 1'bz : 1'b0;
assign PS2_DATA = ps2_dat_t ? 1'bz : 1'b0;

/****************************************************************************
  JOY STICK (switch emu)
****************************************************************************/
wire [7:0] joy_a_n , joy_b_n;

// active low
assign joy_a_n = {2'b11,~ext_joya_t1,3'b111,~ext_joya_dn,1'b1};
assign joy_b_n = 8'hff;

/****************************************************************************
  AUDIO DAC
****************************************************************************/
wire [15:0] pcm_l;

`define USE_DELTA_DAC
`ifdef  USE_DELTA_DAC

senc_sd senc_sd(.CLK(clk32M),.IN(pcm_l[15:6]),.OUT(DAC));

`else
assign DAC = 1'b0;
`endif

/****************************************************************************
  video converter
****************************************************************************/

wire hsync,vsync;

// VIDEO SYNC
assign VGA_HS = hsync ? 1'b0 : 1'bz;
assign VGA_VS = vsync ? 1'b0 : 1'bz;

/****************************************************************************
  external SRAM
****************************************************************************/

// CPU BUS
wire [3:0]  sbank;
wire [15:0] sa;
wire [7:0] sram_dr , cbus_wdata;
wire srd_n,swr_n;
wire ipl_cs;
wire mram_cs;
wire gr_b_cs;
wire gr_r_cs;
wire gr_g_cs;

// GRAM BUS
wire [13:0] vaddr;
wire [7:0]  grb_dr,grr_dr,grg_dr;

// SRAM BUS
wire [17:0] sram_a;
wire [7:0]  sram_dw;
wire sram_wc;
wire sram_we;
wire sram_oe;
wire [3:0] sram_bw;

wire sys_reset = ext_reset | clk_reset;

xc3_sram xc3_sram(
  .I_RESET(sys_reset),
  .I_CLK(clk32M),
// SRAM
  .O_SRAM_A(sram_a),
  .O_SRAM_D(sram_dw),
  .I_SRAM_D({ram_b_data,ram_a_data}),
  .O_SRAM_WC(sram_wc),
  .O_SRAM_WE(sram_we),
  .O_SRAM_OE(sram_oe),
  .O_SRAM_BW(sram_bw),
// CPU BUS
  .I_CB(sbank),
  .I_CA(sa),
  .I_CD(cbus_wdata),
  .O_CD(sram_dr),
  .I_CRD(~srd_n),
  .I_CWR(~swr_n),
  .I_IPL_CS(ipl_cs),
  .I_RAM_CS(mram_cs),
  .I_GB_CS(gr_b_cs),
  .I_GR_CS(gr_r_cs),
  .I_GG_CS(gr_g_cs),
`ifdef X1TURBO
// GRAM BANK
  .I_GRP(gram_rp),
  .I_GWP(gram_wp),
`endif
// VIDEO BUS
  .I_GA(vaddr),
  .O_GB_D(grb_dr),
  .O_GR_D(grr_dr),
  .O_GG_D(grg_dr)
);

// SRAM
assign ram_addr   = sram_a;
assign ram_we   = ~sram_wc;
assign ram_oe   = ~sram_oe;
assign ram_a_data = sram_wc ? {sram_dw,sram_dw} : 16'bzzzzzzzzzzzzzzzz;
assign ram_b_data = sram_wc ? {sram_dw,sram_dw} : 16'bzzzzzzzzzzzzzzzz;
assign ram_a_ce = sys_reset;
assign ram_b_ce = sys_reset;
assign ram_a_lb = ~sram_bw[0];
assign ram_a_ub = ~sram_bw[1];
assign ram_b_lb = ~sram_bw[2];
assign ram_b_ub = ~sram_bw[3];

/****************************************************************************
  unused I/O
****************************************************************************/

wire [3:0] fd5_lamp;

assign led[0] = fd5_lamp[0] & ~ext_eco_mode;
assign led[1] = fd5_lamp[1] & ~ext_eco_mode;
assign led[2] = 1'b0; // ipl_sel & ipl_enable & ~ext_eco_mode;
assign led[3] = 1'b0; // width40 & ~ext_eco_mode;
assign led[4] = 1'b0; // clk1 & ~ext_eco_mode;
assign led[5] = 1'b0; // key_brk_n & ~ext_eco_mode;
assign led[6] = ~uart_rx & ~ext_eco_mode;
assign led[7] = ~uart_tx & ~ext_eco_mode;

/****************************************************************************
  X1
****************************************************************************/
nisex1_top nisex1_top(
// System RESET , System CLOCKs
  .I_RESET(sys_reset),
  .I_CLK32M(clk32M),
  .I_CLK28M636(clk28M636),
// External CPU Bus (Main RAM)
  .O_CBUS_BANK(sbank),
  .O_CBUS_ADDRESS(sa),
  .O_CBUS_DATA(cbus_wdata),
  .I_CBUS_DATA(sram_dr),
  .O_CBUS_RD_n(srd_n),
  .O_CBUS_WR_n(swr_n),
  .I_CBUS_WAIT_n(1'b1),
  .O_CBUS_CS_IPL(ipl_cs),
  .O_CBUS_CS_MRAM(mram_cs),
  .O_CBUS_CS_GRAMB(gr_b_cs),
  .O_CBUS_CS_GRAMR(gr_r_cs),
  .O_CBUS_CS_GRAMG(gr_g_cs),
  .O_CBUS_BANK_GRAM_R(gram_rp),
  .O_CBUS_BANK_GRAM_W(gram_wp),
// External VIDEO Bus
  .O_GRAM_A(vaddr),
  .I_GRAM_D_R(grr_dr),
  .I_GRAM_D_G(grg_dr),
  .I_GRAM_D_B(grb_dr),
// Xilinx Config ROM
  .O_XCF_CCLK(cclk),
  .O_XCF_RESET(reset_prom),
  .I_XCF_DIN(din),
// PS2
  .I_PS2_CLK(PS2_CLK),
  .I_PS2_DAT(PS2_DATA),
  .O_PS2_CLK_T(ps2_clk_t),
  .O_PS2_DAT_T(ps2_dat_t),
// SD / MMC Card
  .O_MMC_CLK(),
  .O_MMC_CS(),
  .O_MMC_DOUT(),
  .I_MMC_DIN(1'b0),
// sound
  .PCM_L(pcm_l),
  .PCM_R(),
// NTSC S1 Video out
`ifdef NTSC_S2
  .O_VY(VY),.O_VC(VC),
`endif
// Front / Back Panel Switches
// Front Panel
  .O_LED_FDD_RED(fd5_lamp),
  .O_LED_FDD_GREEN(),
//
  .I_NMI_n(~ext_nmi),
  .O_LED_POWER(),
  .O_LED_TIMER(),
`ifdef X1TURBO
  .I_IPL_n(~ext_reset),
  .I_DEFCHR_SW(defchr_disable),
  .O_LED_HIRESO(),
 `ifdef X1TURBOZ
  .I_DSW(6'b000000),
  .O_LED_ANALOG(),
 `else
  .I_DSW(4'b0000),
 `endif
`endif
// JOYSTICK
  .I_JOYA(joy_a_n),.I_JOYB(joy_b_n),
  .O_JOYA(),.O_JOYB(),
  .T_JOYA(),.T_JOYB(),
// VGA / SCART RGB output
  .O_VGA_R(VGA_R),.O_VGA_G(VGA_G),.O_VGA_B(VGA_B),
  .O_VGA_HS(hsync),.O_VGA_VS(vsync),
//
//  .I_FIRMWARE_EN(switch[5]),
  .I_FIRMWARE_EN(1'b0),
// debug port : SUB CPU number monitor
  .O_DBG_NUM4(seg7_num),.O_DBG_DOT4(seg7_dot),
  .O_DBG_LED8(),
// debug port : USART
  .I_USART_CLK(uart_clk),
  .I_USART_CLKEN16(uart_clk_e),
  .I_USART_RX(uart_rx),
  .O_USART_TX(uart_tx)
);

`ifdef NTSC_S2
`else
assign VY = 4'b0000;
assign VC = 4'b0000;
`endif

endmodule
