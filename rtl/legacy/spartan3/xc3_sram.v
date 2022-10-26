`define X1TURBO
/****************************************************************************
	Xilinx Spartan3 multiplexed external SRAM for X1

	Version 050111

	Copyright(C) 2004,2005 Tatsuyuki Satoh

	This software is provided "AS IS", with NO WARRANTY.
	NON-COMMERCIAL USE ONLY

	Histry:
		2005. 1.11 Ver.0.1

	Note:

	Distributing all and a part is prohibited. 
	Because this version is developer-alpha version.

****************************************************************************/
module xc3_sram(
  I_RESET,
  I_CLK,
//
  O_SRAM_A,
  O_SRAM_D,
  I_SRAM_D,
  O_SRAM_WC,
  O_SRAM_WE,
  O_SRAM_OE,
  O_SRAM_BW,
//
  I_CB,
  I_CA,
  I_CD,
  O_CD,
  I_CRD,
  I_CWR,
  I_IPL_CS,
  I_RAM_CS,
  I_GB_CS,
  I_GR_CS,
  I_GG_CS,
//
`ifdef X1TURBO
  I_GRP,
  I_GWP,
`endif
  I_GA,
  O_GB_D,
  O_GR_D,
  O_GG_D
);
input I_RESET;
input I_CLK;

//
output [17:0] O_SRAM_A;
output [7:0]  O_SRAM_D;
input  [31:0] I_SRAM_D;
output O_SRAM_WC;
output O_SRAM_WE;
output O_SRAM_OE;
output [3:0] O_SRAM_BW;

input [3:0] I_CB;  // CPU BANK REG
input [15:0] I_CA; // CPU address
input [7:0] I_CD;  // CPU write data
output[7:0] O_CD;  // CPU read data (RAM,IPL,GRAM,FDC)
input I_CRD;
input I_CWR;
input I_IPL_CS;
input I_RAM_CS;
input I_GB_CS,I_GR_CS,I_GG_CS;

`ifdef X1TURBO
input I_GWP;
input I_GRP;
`endif

input  [13:0] I_GA;
output [7:0] O_GB_D,O_GR_D,O_GG_D;

/****************************************************************************
  SRAM
****************************************************************************/

/*
       Pysical Memory (256k x 8bit x 4bank)

        RAMA-L     RAMA-H     RAMB-L     RAMB-H
00000 +----------+----------+----------+----------+ 000000
      | BANK0-L  | BANK0-H  | BANK1-L  | BANK1-H  |
      |     MAIN RAM        | FD0-0    | FD0-1    |
08000 +----------+----------+----------+----------+ 020000
      | BANK2-L  | BANK2-H  | BANK3-L  | BANK3-H  |
      | FD0-2    | FD0-3    | FD0-4    | FD0-5    |
10000 +----------+----------+----------+----------+ 040000
      | BANK4-L  | BANK4-H  | BANK5-L  | BANK5-H  |
      | FD0-6    | FD0-7    | FD0-8    | FD0-9    |
18000 +----------+----------+----------+----------+ 060000
      | BANK6-L  | BANK6-H  | BANK7-L  | BANK7-H  |
      | FD0-10   | FD0-11   | FD0-12   | FD1-0    |
20000 +----------+----------+----------+----------+ 080000
      | BANK8-L  | BANK8-H  | BANK9-L  | BANK9-H  |
      | FD1-1    | FD1-2    | FD1-3    | FD1-4    |
28000 +----------+----------+----------+----------+ 0a0000
      | BANK10-L | BANK10-H | BANK11-L | BANK11-H |
      | FD1-5    | FD1-6    | FD1-7    | FD1-8    |
30000 +----------+----------+----------+----------+ 0c0000
      | BANK12-L | BANK12-H | BANK13-L | BANK13-H |
      | FD1-9    | FD1-10   | FD1-11   | FD1-12   |
38000 +----------+----------+----------+----------+ 0e0000
      | BANK14-L | BANK14-H | BANK15-L | BANK15-H |
      | IPL ROM  | GRAM B   | GRAM R   | GRAM G   |
3C000 |          +----------+----------+----------+ 0f0000
      |          | GRAM B'  | GRAM R'  | GRAM G'  |
40000 +----------+----------+----------+----------+ 100000

       Logical Memory (CPU)

0:0000 +--------------+
       |              |
       | MAIN RAM     |
       |              |
1:0000 +--------------+
       |              |
       | FD0 buffer   |
       |              |
7:8000 +--------------+
       |              |
       | FD1 buffer   |
       |              |
e:0000 +--------------+
       |              |
       | IPL          |
       |              |
e:8000 +--------------+
       | GRAM B0      |
e:C000 +--------------+
       | GRAM B1      |
f:0000 +--------------+
       | GRAM R0      |
f:4000 +--------------+
       | GRAM R1      |
f:8000 +--------------+
       | GRAM G0      |
f:C000 +--------------+
       | GRAM G1      |
f:ffff +--------------+

*/
reg [1:0] sram_phase;

reg [7:0] gr_b_dr;
reg [7:0] gr_r_dr;
reg [7:0] gr_g_dr;

reg [17:0] sram_a;
reg [7:0] sram_wd;
reg sram_wc_n;
reg sram_oe_n;
reg [3:0] sram_bw;

reg [7:0] sram_cpu_d;

// GRAM page
`ifdef X1TURBO
wire gwp = I_GWP; // CPU access bank
wire grp = I_GRP; // display bank
`else
wire gwp = 1'b1;
wire grp = 1'b1;
`endif

// CPU
wire [17:0] ca = { I_CB[3:1] | {3{I_IPL_CS} },I_CA[14:0]};
wire [17:0] ga = {3'b111,gwp,I_CA[13:0]};
//wire [17:0] ca_ga = I_RAM_CS ? ca : ga;
wire [17:0] ca_ga = (I_IPL_CS|I_GB_CS|I_GR_CS|I_GG_CS) ? ga : ca;

wire cbw0 = ~I_CB[0] & ~I_CA[15];
wire cbw1 = ~I_CB[0] &  I_CA[15];
wire cbw2 =  I_CB[0] & ~I_CA[15];
wire cbw3 =  I_CB[0] &  I_CA[15];

reg wr_setup;

always @(posedge I_CLK)
begin
  if(I_RESET)
  begin
    sram_phase <= 0;
    gr_b_dr <= 0;
    gr_r_dr <= 0;
    gr_g_dr <= 0;
    sram_a <= 0;
    sram_wd <= 0;
    sram_wc_n <= 1'b0;
    sram_oe_n <= 1'b0;
    sram_bw <= 0;
    sram_cpu_d <= 0;

    wr_setup <= 1'b0;
  end else begin

    wr_setup <= I_CWR;

    sram_phase <= sram_phase + 1;
    case(sram_phase)
    2'b00:begin
      // set video access
      sram_a     <= {3'b111,grp,I_GA};
      sram_wc_n  <= 1'b1;
      sram_oe_n  <= 1'b0;
      sram_bw    <= 4'b1110;
      end
    2'b01:begin
      // latch video gram
      gr_g_dr <= I_SRAM_D[31:24];
      gr_r_dr <= I_SRAM_D[23:16];
      gr_b_dr <= I_SRAM_D[15:8];

      // set cpu address and read or write
      sram_a     <= ca_ga;
      sram_wd    <= I_CD;   // hold write data
      sram_oe_n  <= wr_setup && I_CWR;  // hold write cycle
      sram_bw[0] <= (I_RAM_CS & cbw0) | I_IPL_CS;
      sram_bw[1] <= (I_RAM_CS & cbw1) | I_GB_CS;
      sram_bw[2] <= (I_RAM_CS & cbw2) | I_GR_CS;
      sram_bw[3] <= (I_RAM_CS & cbw3) | I_GG_CS;
      end
    2'b10:begin
      // write data enable
      sram_wc_n  <= ~sram_oe_n;
      end
    2'b11:begin
      // turn to Hi-z
      sram_wc_n  <= 1'b1;
      end
    endcase
    // latch cpu data 00,10,11 only read cycle
    if(sram_phase != 2'b01 && ~sram_oe_n)
    begin
      // latch cpu data
      sram_cpu_d <=
           sram_bw[3] ? I_SRAM_D[31:24] : // GRAM B
           sram_bw[2] ? I_SRAM_D[23:16] : // GRAM R
           sram_bw[1] ? I_SRAM_D[15:8]  : // GRAM G
                        I_SRAM_D[ 7:0]  ; // main MEM
    end
  end
end

//
assign O_SRAM_A  = sram_a;
assign O_SRAM_WC = ~sram_wc_n;
assign O_SRAM_OE = ~sram_oe_n;
assign O_CD      = sram_cpu_d;
assign O_SRAM_D  = sram_wd;
assign O_SRAM_BW = sram_bw;
assign O_GB_D    = gr_b_dr;
assign O_GR_D    = gr_r_dr;
assign O_GG_D    = gr_g_dr;

endmodule
