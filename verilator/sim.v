`timescale 1ns/1ns
// top end ff for verilator

module top(

   input clk_48 /*verilator public_flat*/,
   input clk_12 /*verilator public_flat*/,
   input reset,
	 input soft_reset,   
   input [11:0]  inputs/*verilator public_flat*/,

   output [7:0] VGA_R/*verilator public_flat*/,
   output [7:0] VGA_G/*verilator public_flat*/,
   output [7:0] VGA_B/*verilator public_flat*/,
   
   output VGA_HS,
   output VGA_VS,
   output VGA_HB,
   output VGA_VB,

   output [15:0] AUDIO_L,
   output [15:0] AUDIO_R,
   
   input        ioctl_download,
   input        ioctl_upload,
   input        ioctl_wr,
   input [24:0] ioctl_addr,
   input [7:0]  ioctl_dout,
   input [7:0]  ioctl_din,   
   input [7:0]  ioctl_index,
   output  reg  ioctl_wait=1'b0
   
);

   // Core inputs/outputs
   wire       pause;
   wire [7:0] audio;
   wire [8:0] rgb;
   wire [3:0] led/*verilator public_flat*/;
   reg [7:0]  trakball/*verilator public_flat*/;
   reg [7:0]  joystick/*verilator public_flat*/;
   reg [9:0]  playerinput/*verilator public_flat*/;  

   // Hardcode default switches
   reg [7:0]  sw1 = { 1'b0, 1'b0,2'b0,2'b0,2'b0 };
   reg [7:0]  sw2 = 8'h02;

   // Convert 3bpp output to 8bpp
   assign VGA_R = {rgb[2:0],rgb[2:0],rgb[2:1]};
   assign VGA_G = {rgb[5:3],rgb[5:3],rgb[5:4]};
   assign VGA_B = {rgb[8:6],rgb[8:6],rgb[8:7]};
    
   // MAP INPUTS FROM SIM
   // -------------------
   assign playerinput[9] = ~inputs[10]; // coin r
   assign playerinput[8] = ~inputs[9]; // coin m
   assign playerinput[7] = ~inputs[8]; // coin l
   assign playerinput[6] = 1'b1;       // self-test
   assign playerinput[5] = 1'b0;       // cocktail
   assign playerinput[4] = 1'b1;       // slam
   assign playerinput[3] = ~inputs[7]; // start 2
   assign playerinput[2] = ~inputs[6]; // start 1
   assign playerinput[1] = ~inputs[5]; // fire 2
   assign playerinput[0] = ~inputs[4]; // fire 1  
   assign joystick[7:4] = { ~inputs[0],~inputs[1],~inputs[2],~inputs[3] }; // right, left, down, up 1
   assign joystick[3:0] = { ~inputs[0],~inputs[1],~inputs[2],~inputs[3] }; // right, left, down, up 2
   assign pause = inputs[11];       // pause

   // MAP OUTPUTS
   assign AUDIO_L = {audio,audio};
   assign AUDIO_R = AUDIO_L;

   reg ce_pix;
   always @(posedge clk_12) begin  // clk_48
      reg old_clk;
      
      old_clk <= clk_12;  // clk_12
      ce_pix <= old_clk & ~clk_12;  // clk_12
   end

//wire reset = ~ioctl_download;

/*
sharpx1 sharpx1
(
   .clk_sys(clk_48),
	.reset(reset),

	.pal(),
	.scandouble(),

	.ioctl_download(ioctl_download),
	.ioctl_index(ioctl_index),
	.ioctl_wr(ioctl_wr),
	.ioctl_addr(ioctl_addr),
	.ioctl_dout(ioctl_dout),

	.ce_pix(),

	.HBlank(VGA_HB),
	.HSync(VGA_HS),
	.VBlank(VGA_VB),
	.VSync(VGA_VS),

	.video(rgb)
);
*/

assign clk_reset = reset;

/****************************************************************************
  video converter
****************************************************************************/

wire hsync,vsync;

// VIDEO SYNC
assign VGA_HS = hsync ? 1'b0 : 1'bz;
assign VGA_VS = vsync ? 1'b0 : 1'bz;

/****************************************************************************
  SRAM Controller
****************************************************************************/
/*
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
*/

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

//wire sys_reset = ext_reset | clk_reset;
xc3_sram xc3_sram(
  .I_RESET(reset),
  .I_CLK(clk_12),  // clk_48
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

assign ram_addr   = sram_a;
assign ram_we   = ~sram_wc;
assign ram_oe   = ~sram_oe;
assign ram_a_data = sram_wc ? {sram_dw,sram_dw} : 16'bzzzzzzzzzzzzzzzz;
assign ram_b_data = sram_wc ? {sram_dw,sram_dw} : 16'bzzzzzzzzzzzzzzzz;
assign ram_a_ce = reset;  // sys_reset
assign ram_b_ce = reset;  // sys_reset
assign ram_a_lb = ~sram_bw[0];
assign ram_a_ub = ~sram_bw[1];
assign ram_b_lb = ~sram_bw[2];
assign ram_b_ub = ~sram_bw[3];

/****************************************************************************
  RAM 64KB
****************************************************************************/

reg  [ 7:0] ramDi;
reg  [ 7:0] ramDo;
reg  [15:0] ramA;
reg         ramWe;

dpram #(8, 16) RAM  // (64KB)
(
	.clock      (clk_12), // clk_48
	.address_a  (ram_addr  ),
	.wren_a     (sram_a ),
	.data_a     (ram_a_data ),
	.q_a        (ram_a_data ),

	.wren_b     (      ),
	.address_b  (ram_addr      ),
	.data_b     (ram_b_data      ),
	.q_b        (ram_b_data)
);

/****************************************************************************
  sharpx1_legacy
****************************************************************************/

sharpx1_legacy sharpx1_legacy(
// DEBUG

// System RESET , System CLOCKs
  .I_RESET(reset), // sys_reset
  .I_CLK32M(clk_12),   // clk32M
  .I_CLK28M636(clk_12),  // clk28M636  // clk_12
//  I_CLK4M,

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
// SD / MMC Card
   .O_MMC_CLK(),
   .O_MMC_CS(),
   .O_MMC_DOUT(),
   .I_MMC_DIN(1'b0),
// PS2
   .I_PS2_CLK(PS2_CLK),
   .I_PS2_DAT(PS2_DATA),
   .O_PS2_CLK_T(ps2_clk_t),
   .O_PS2_DAT_T(ps2_dat_t),
// sound
   .PCM_L(pcm_l),
   .PCM_R(),
// NTSC S1 Video out
`ifdef NTSC_S2
  .O_VY(VY),
  .O_VC(VC),
`endif
// Front / Back Panel Switches
  .O_LED_FDD_RED(fd5_lamp),
  .O_LED_FDD_GREEN(),

  .I_NMI_n(~ext_nmi),
  .O_LED_POWER(),
  .O_LED_TIMER(),
`ifdef X1TURBO
  .I_IPL_n(~ext_reset),
  .I_DEFCHR_SW(defchr_disable),
  .O_LED_HIRESO(),
  .I_DSW(),
 `ifdef X1TURBOZ
  .I_DSW(6'b000000),
  .O_LED_ANALOG(),
 `else
  .I_DSW(4'b0000),
 `endif
`endif
// DIP SW.
// JOYSTICK
  .I_JOYA(joy_a_n),
  .I_JOYB(joy_b_n),
  .O_JOYA(),
  .O_JOYB(),
  .T_JOYA(),
  .T_JOYB(),
// VGA / SCART RGB output
  .O_VGA_R(VGA_R),
  .O_VGA_G(VGA_G),
  .O_VGA_B(VGA_B),
  .O_VGA_HS(hsync),
  .O_VGA_VS(vsync),
// debug port : SUB CPU firmware download
  .I_FIRMWARE_EN(1'b1),  // 1'b0
// debug port : SUB CPU number monitor
  .O_DBG_NUM4(seg7_num),
  .O_DBG_DOT4(seg7_dot),
  .O_DBG_LED8(),
// debug port : USART
  .I_USART_CLK(uart_clk),
  .I_USART_CLKEN16(uart_clk_e),
  .I_USART_RX(uart_rx),
  .O_USART_TX(uart_tx)
);

endmodule
