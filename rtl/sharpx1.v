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

// ROM IPL 4KB
//wire  [7:0]  romDo_Sharpx1;
//wire [13:0]  romA;
rom #(.AW(13), .FN("../bios/fw_bios_spi/boot.rom")) bios_fw_spi
(
	.clock      (clk_sys       ),
	.ce         (1'b1          ),
	.data_out   ( ),
	.a          (    )
);

// ROM 2KB CHARACTER GENERATOR


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
dpram #(8, 16) RAM
(
	.clock(clk_sys),
	.address_a(),
	.wren_a(),
	.data_a(),
	.q_a(),

	.wren_b(),
	.address_b(),
	.data_b(),
	.q_b()
);

// VRAM 4KB
dpram #(8, 12) VRAM
(
	.clock(clk_sys),
	.address_a(),
	.wren_a(),
	.data_a(),
	.q_a(),

	.wren_b(),
	.address_b(),
	.data_b(),
	.q_b()
);

// PCG RAM 6KB
dpram #(8, 13) PCGRAM
(
	.clock(clk_sys),
	.address_a(),
	.wren_a(),
	.data_a(),
	.q_a(),

	.wren_b(),
	.address_b(),
	.data_b(),
	.q_b()
);

// GRAM 48KB
dpram #(8, 16) GRAM
(
	.clock(clk_sys),
	.address_a(),
	.wren_a(),
	.data_a(),
	.q_a(),

	.wren_b(),
	.address_b(),
	.data_b(),
	.q_b()
);



endmodule