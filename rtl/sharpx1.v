module sharpx1
(
	input         clk_sys,
	input         clk_28636,	
	input         reset,
	
	input         pal,
	input         scandouble,

	input wire         ioctl_download,
	input wire   [7:0] ioctl_index,
	input wire         ioctl_wr,
	input       [24:0] ioctl_addr,
	input        [7:0] ioctl_dout,

	output reg    ce_pix,

	output reg    HBlank,
	output reg    HSync,
	output reg    VBlank,
	output reg    VSync,

	output  [7:0] video

/*
// DEBUG

// System RESET , System CLOCKs
  input 	I_RESET,
  input 	I_CLK32M,
  input 	I_CLK28M636,
//  I_CLK4M,

// External CPU Bus (Main RAM)
  output 	O_CBUS_BANK,
  output 	O_CBUS_ADDRESS,
  output 	O_CBUS_DATA,
  input 	I_CBUS_DATA,
  output 	O_CBUS_RD_n,
  output 	O_CBUS_WR_n,
  input 	I_CBUS_WAIT_n,
  output	O_CBUS_CS_IPL,
  output 	O_CBUS_CS_MRAM,
  output 	O_CBUS_CS_GRAMB,
  output 	O_CBUS_CS_GRAMR,
  output 	O_CBUS_CS_GRAMG,
  output 	O_CBUS_BANK_GRAM_R,
  output 	O_CBUS_BANK_GRAM_W,

// External VIDEO Bus
  output 	O_GRAM_A,
  input 	I_GRAM_D_R,
  input 	I_GRAM_D_G,
  input 	I_GRAM_D_B,

// Xilinx Config ROM
  output 	O_XCF_CCLK,
  output 	O_XCF_RESET,
  input 	I_XCF_DIN,

// SD / MMC Card
   output 	O_MMC_CLK,
   output 	O_MMC_CS,
   output 	O_MMC_DOUT,
   input 	I_MMC_DIN,

// PS2
   input 	I_PS2_CLK,
   input 	I_PS2_DAT,
   output 	O_PS2_CLK_T,
   output 	O_PS2_DAT_T,

// sound
   PCM_L,
   PCM_R,

// NTSC S1 Video out
`ifdef NTSC_S2
  output 	O_VY,
  output 	O_VC,
`endif

// Front / Back Panel Switches
  output 	O_LED_FDD_RED,
  output 	O_LED_FDD_GREEN,

  input 	I_NMI_n,
  output 	O_LED_POWER,
  output 	O_LED_TIMER,
`ifdef X1TURBO
  input 	I_IPL_n,
  input 	I_DEFCHR_SW,
  output 	O_LED_HIRESO,
  input 	I_DSW,
 `ifdef X1TURBOZ
  output 	O_LED_ANALOG,
 `endif
`endif

// DIP SW.

// JOYSTICK
  input 	I_JOYA,
  input 	I_JOYB,
  output 	O_JOYA,
  output 	O_JOYB,
  T_JOYA,
  T_JOYB,

// VGA / SCART RGB output
  output	O_VGA_R,
  output 	O_VGA_G,
  output 	O_VGA_B,
  output 	O_VGA_HS,
  output 	O_VGA_VS,

// debug port : SUB CPU firmware download
  input 	I_FIRMWARE_EN,

// debug port : SUB CPU number monitor
  output 	O_DBG_NUM4,
  output 	O_DBG_DOT4,
  output 	O_DBG_LED8,

// debug port : USART
  input 	I_USART_CLK,
  input 	I_USART_CLKEN16,
  input 	I_USART_RX,
  output 	O_USART_TX	
*/
);

/****************************************************************************
  IPL ROM
****************************************************************************/

// ROM IPL 4KB
wire  [7:0]  romDo_SharpX1;
wire [13:0]  romA;
rom #(.AW(13), .FN("../bios/ipl_x1.hex")) IPL
(
	.clock      (clk_sys       ),
	.ce         (1'b1          ),
	.data_out   (romDo_SharpX1 ),
	.a          (romA          )
);

// ROM 2KB CHARACTER GENERATOR

/****************************************************************************
  RAM
****************************************************************************/

/*
    X1 (CZ-800C) - November, 1982
     * CPU: z80A @ 4MHz, 80C49 x 2 (one for key scan, the other for TV & Cas Ctrl)
     * ROM: IPL (4KB) + chargen (2KB)
     * RAM: Main memory (64KB) + VRAM (4KB) + RAM for PCG (6KB) + GRAM (48KB, Option)
     * Text Mode: 80x25 or 40x25
     * Graphic Mode: 640x200 or 320x200, 8 colors
     * Sound: PSG 8 octave
     * I/O Ports: Centronic ports, 2 Joystick ports, Cassette port (2700 baud)
*/

// RAM 64KB
wire [ 7:0] ramDi;
wire [ 7:0] ramDo;
wire [15:0] ramA;
wire        ramWe;
dpram #(8, 16) RAM  // (64KB)
(
	.clock      (clk_sys  ),
	.address_a  (ramA     ),
	.wren_a     (ramWe   ),
	.data_a     (ramDi    ),
	.q_a        (ramDo    ),

	.wren_b     (         ),
	.address_b  (         ),
	.data_b     (         ),
	.q_b        (         )
);

// VRAM 4KB
wire [ 7:0] vramDi;
wire [ 7:0] vramDo;
wire [15:0] vramA;
wire        vramWe;
dpram #(8, 12) VRAM  // (4KB)
(
	.clock      (clk_sys  ),
	.address_a  (vramA    ),
	.wren_a     (vramWe   ),
	.data_a     (vramDi   ),
	.q_a        (vramDo   ),

	.wren_b     (         ),
	.address_b  (         ),
	.data_b     (         ),
	.q_b        (         )
);

// PCG RAM 6KB
wire [ 7:0] pcgramDi;
wire [ 7:0] pcgramDo;
wire [15:0] pcgvramA;
wire        pcgramWe;
dpram #(8, 13) PCGRAM  // (8KB)
(
	.clock      (clk_sys  ),
	.address_a  (pcgvramA ),
	.wren_a     (pcgramWe ),
	.data_a     (pcgramDi ),
	.q_a        (pcgramDo ),

	.wren_b     (         ),
	.address_b  (         ),
	.data_b     (         ),
	.q_b        (         )
);

// GRAM 48KB
wire [ 7:0] gramDi;
wire [ 7:0] gramDo;
wire [15:0] gramA;
wire        gramWe;
dpram #(8, 16) GRAM  // (64KB)
(
	.clock      (clk_sys  ),
	.address_a  (gramA    ),
	.wren_a     (gramWe   ),
	.data_a     (gramDi   ),
	.q_a        (gramDo   ),

	.wren_b     (         ),
	.address_b  (         ),
	.data_b     (         ),
	.q_b        (         )
);

/****************************************************************************
  Basic Clock Divider
****************************************************************************/

reg [3:0] pris32m;
reg cpu_clk;     // Z80 clock 4MHz

always @(negedge clk_sys or negedge reset)
begin
  /*
  if(reset)
  begin
    pris32m <= 4'b0000;
    cpu_clk <= 0;
  end 
  else 
  begin*/
    pris32m <= pris32m + 1;
    if(pris32m[0] & (pris32m[1]))  // 2'b11;
      cpu_clk <= ~cpu_clk;
  //end
end

/****************************************************************************
  Z80A CPU
****************************************************************************/

reg[5:0] ce = 0;
always @(negedge clk_sys) ce <= ce + 1'd1;

reg[3:0] ce4 = 0;
always @(negedge clk_sys) if(ce400p) ce4 <= 4'd0; else ce4 <= ce4 + 4'd1;

`ifdef VERILATOR
wire ce400p =           ce4[1];
wire ce400n = ce4[0] & ~ce4[1];
`else
wire ce400p = ce4[0] &  ce4[1]          &  ce4[3];
wire ce400n = ce4[0] & ~ce4[1] & ce4[2] & ~ce4[3];
`endif

wire  [ 7:0] di;
wire  [ 7:0] data_out;
wire  [15:0] a;
wire         mreq;
wire         iorq;
wire         wr;
reg   [15:0] dir;
reg          dirset;

cpu Cpu
(
	.reset_n  (~reset   ), // I
	.clock    (cpu_clk  ), // I change to cpu  16/4
	.cep      (ce400p   ), // I 
	.cen      (ce400n   ), // I 
	.int_n    (1        ), // I
	.halt_n   (         ), // O
	.mreq     (mreq     ), // O
	.iorq     (iorq     ), // O
	.wr       (wr       ), // O
	.di       (di       ), // I 7:0
	.data_out (data_out ), // O 7:0
	.a        (a        ), // O 15:0
	.dir 	    (dir	    ), // I
	.dirset   (dirset	  )  // I
);

/****************************************************************************
  Data & Address Buses
****************************************************************************/

assign romA = a;

assign ramWe = !(!mreq && !wr);
assign ramDi = data_out;
assign ramA  = a;

assign di = mreq ? ramDo : romDo_SharpX1;

endmodule