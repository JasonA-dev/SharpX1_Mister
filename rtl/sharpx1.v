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

/*
//rom #(.AW(13), .FN("../bios/reference/fw_bios_spi/boot.hex")) IPL
rom #(.AW(13), .FN("../bios/ipl_x1.hex")) IPL
//rom #(.AW(13), .FN("../bios/ipl_x1.hex")) IPL
(
	.clock      (clk_sys       ),
	.ce         (1'b1          ),
	.data_out   (romDo_SharpX1 ),
	.a          (romA          )
);
*/

/*
always @(posedge clk_sys) begin
  if (ioctl_download) begin
    $display("ioctl_download %h ioctl_index %h ioctl_addr %h ioctl_wr %h ioctl_dout %h", ioctl_download, ioctl_index, ioctl_addr[12:0], ioctl_wr, ioctl_dout);
  end
end
*/

dpram #(8, 13) IPL  // (4KB)
(
	.clock     (clk_sys          ),
	.address_a (ioctl_addr       ),
	.wren_a    (ioctl_wr         ),
	.data_a    (ioctl_dout       ),
	.q_a       (                 ),

	.wren_b    (                 ), 
	.address_b (romA             ), 
	.data_b    (                 ),
	.q_b       (romDo_SharpX1    ) 
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
reg  [ 7:0] ramDi;
reg  [ 7:0] ramDo;
reg  [15:0] ramA;
reg         ramWe;
dpram #(8, 16) RAM  // (64KB)
(
	.clock      (clk_sys  ),
	.address_a  (ramA     ),
	.wren_a     (ramWe    ),
	.data_a     (ramDi    ),
	.q_a        (ramDo    ),

	.wren_b     (         ),
	.address_b  (         ),
	.data_b     (         ),
	.q_b        (         )
);

// VRAM 4KB
reg  [ 7:0] vramDi;
reg  [ 7:0] vramDo;
reg  [15:0] vramA;
reg         vramWe;
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

// PSG RAM 6KB
reg  [ 7:0] psgramDi;
reg  [ 7:0] psgramDo;
reg  [15:0] psgramA;
reg         psgramWe;
dpram #(8, 13) PSGRAM  // (8KB)
(
	.clock      (clk_sys  ),
	.address_a  (psgramA  ),
	.wren_a     (psgramWe ),
	.data_a     (psgramDi ),
	.q_a        (psgramDo ),

	.wren_b     (         ),
	.address_b  (         ),
	.data_b     (         ),
	.q_b        (         )
);

// GRAM 48KB
reg  [ 7:0] gramDi;
reg  [ 7:0] gramDo;
reg  [15:0] gramA;
reg         gramWe;
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
  Z80A CPU
****************************************************************************/

always @(negedge clk_sys) ce <= ce+1'd1;

`ifdef VERILATOR
reg [ 3:0] ce;
assign ce_pix = pe8M8;
wire pe8M8 =  ce[0];
wire ne8M8 = ~ce[0];

wire pe4M4 = ~ce[0] &  ce[1];
wire ne4M4 = ~ce[0] & ~ce[1];

wire pe2M2 = ~ce[0] & ~ce[1] &  ce[2];
wire ne2M2 = ~ce[0] & ~ce[1] & ~ce[2];

wire pe1M1 = ~ce[0] & ~ce[1] & ~ce[2] &  ce[3];
wire ne1M1 = ~ce[0] & ~ce[1] & ~ce[2] & ~ce[3];
`else
reg [ 4:0] ce;
assign ce_pix = pe8M8;
wire pe8M8 = ~ce[0] &  ce[1];
wire ne8M8 = ~ce[0] & ~ce[1];

wire pe4M4 = ~ce[0] & ~ce[1] &  ce[2];
wire ne4M4 = ~ce[0] & ~ce[1] & ~ce[2];

wire pe2M2 = ~ce[0] & ~ce[1] & ~ce[2] &  ce[3];
wire ne2M2 = ~ce[0] & ~ce[1] & ~ce[2] & ~ce[3];

wire pe1M1 = ~ce[0] & ~ce[1] & ~ce[2] & ~ce[3] &  ce[4];
wire ne1M1 = ~ce[0] & ~ce[1] & ~ce[2] & ~ce[3] & ~ce[4];
`endif

reg   [ 7:0] di;
reg   [ 7:0] data_out;
reg   [15:0] a;
wire         mreq;
wire         iorq;
wire         wr;
wire         rd;
reg   [15:0] dir;
reg          dirset;
wire         halt_n;

cpu Cpu
(
	.reset_n  (reset    ), // I
	.clock    (clk_sys  ), // I 
	.cep      (pe4M4    ), // I 
	.cen      (ne4M4    ), // I 
	.int_n    (1        ), // I

	.di       (di       ), // I 7:0
	.dir 	    (dir	    ), // I
	.dirset   (dirset	  ), // I

	.halt_n   (halt_n   ), // O
	.mreq     (mreq     ), // O
	.iorq     (iorq     ), // O
	.wr       (wr       ), // O
	.rd       (rd       ), // O
	.m1       (m1       ), // O

	.data_out (data_out ), // O 7:0
	.a        (a        )  // O 15:0
);

/****************************************************************************
  Sub CPU 80C49
****************************************************************************/

reg  [ 7:0] subDo;
reg  [ 7:0] subDi;
reg sub_rd;
reg sub_wr;

x1_sub subCPU
(
  .I_reset(~reset),
  .I_clk(clk_sys),  // 32MHz
  // MAIN-SUB communication port
  .I_cs(sub_cs),
  .I_rd(sub_rd),
  .I_wr(sub_wr),
  .I_M1_n(~m1),
  .I_D(subDi),
  .O_D(subDo),
  .O_DOE(),
  // Timer IC Timming Port
  .O_clk1(),
  // FDC emulation
  .O_FDC_DRQ_n(),
  // O_FDC_INT_n,
  .I_FDCS(),
  .I_RFSH_n(),
  .I_RFSH_STB_n(),
  // Z80DMA / FDD memory access
  .I_DMA_CS(dma_cs),
  .O_DMA_BANK(dma_bank),
  .O_DMA_A(dma_a),
  .I_DMA_D(dma_di),
  .O_DMA_D(dma_do),
  .O_DMA_MREQ_n(dma_mreq_n),
  .O_DMA_IORQ_n(dma_iorq_n),
  .O_DMA_RD_n(dma_rd_n),
  .O_DMA_WR_n(dma_wr_n),
  .O_DMA_BUSRQ_n(),
  .I_DMA_BUSAK_n(),
  .I_DMA_RDY(),
  .I_DMA_WAIT_n(halt_n),
  .I_DMA_IEI(dma_iei),
  .O_DMA_INT_n(dma_int_n),
  .O_DMA_IEO(dma_ieo),
  //
  .O_PCM(),
  .O_FD_LAMP(),
  // SUBCPU Firmware Access Port
  .I_fa(),
  .I_fcs(),
  // PS2 keyboard
  .I_PS2C(),
  .I_PS2D(),
  .O_PS2CT(),
  .O_PS2DT(),
  // communication handshake signal 
  .O_TX_BSY(),
  .O_RX_BSY(),
  .O_KEY_BRK_n(),
  // subcpu int controll
  .I_SPM1(),
  .I_RETI(),
  .I_IEI(),
  .O_INT_n(),
  // JOYSTICK EMULATION PORT
  .O_JOY_A(),
  .O_JOY_B()
);

/****************************************************************************
  Address Decoder
****************************************************************************/

// chip selects
wire ipl_cs;
wire ram_cs;
wire sub_cs;
wire miocs;
wire psgram_cs;
wire gram_cs;

x1_adec x1_adec(
  .I_RESET(~reset),
  .I_CLK(clk_sys),
  .I_A(a),
  .I_MREQ_n(~mreq),
  .I_IORQ_n(~iorq),
  .I_RD_n(),
  .I_WR_n(),
  // mode select
  .I_IPL_SEL(),
  .I_DAM(),
  .I_DEFCHR(),
  // memory CS
  .O_IPL_CS(ipl_cs),
  .O_RAM_CS(ram_cs),
  //
  .O_MIOCS(miocs),
  // I/O CS
  .O_EMM_CS(),
  .O_EXTROM_CS(),
  .O_KANROM_CS(),
  .O_FD5_CS(),
  .O_PAL_CS(),
  .O_CG_CS(),
  .O_CRTC_CS(),
  .O_SUB_CS(sub_cs),
  .O_PIA_CS(),
  .O_PSG_CS(psgram_cs),
  .O_IPL_SET_CS(),
  .O_IPL_RES_CS(),
  //
  .O_ATTR_CS(),
  .O_TEXT_CS(),
  .O_GRB_CS(gram_cs),
  .O_GRR_CS(gram_cs),
  .O_GRG_CS(gram_cs),
  // option board
`ifdef FMBOARD
  .O_FM_CS(),
  .O_FMO_CTC_CS(),
`endif
  .O_HDD_CS(),
  .O_FD8_CS(),
// X1turbo
`ifdef X1TURBO
  .O_KANJI_CS(), // 3800-3fff
  .O_BMEM_CS(),  // 0b00
  .O_DMA_CS(),   // 1f8x
  .O_SIO_CS(),   // 1f90-1f93
  .O_CTC_CS(),   // 1fa0-1fa3
  .O_P1FDX_CS(),
  .O_BLACK_CS(), // 1fe0
  .O_DIPSW_CS(), // 1ff0
`endif
  .O_DAM_CLR()  
);

//wire [15:0] ZA;
//wire [7:0] ZDO;
//wire ZMREQ_n, ZIORQ_n, ZRD_n, ZWR_n;
wire [3:0] ice_bank;
/****************************************************************************
  system bus MUX

  master
  Z80DMA  (with RFSH hack access for FDD data)
  Z80 CPU (with Z80 DEBUGGER)
****************************************************************************/
wire [3:0]  dma_bank;
wire [15:0] dma_a;
wire [7:0] dma_do,dma_di;
wire dma_mreq_n,dma_iorq_n,dma_rd_n,dma_wr_n;
wire dma_sel;

wire [7:0] sdi;

// SYNC / ASYNC BUS SIGNAL SELECTOR
`define SYNC_Z80_BUS

`ifdef  SYNC_Z80_BUS
// SYNC / LATCHED Z80 BUS
reg [7:0] sdo;
reg  [3:0]  sbank;
reg [15:0] sa;
reg sm1_n,smreq_n,sireq_n,srd_n,swr_n;

always @(posedge clk_sys or negedge reset)
begin
  if(reset)
  begin
  sbank <= 0;
  sa    <= 16'h0000;
  sdo   <= 8'h00;
  smreq_n <= 1'b1;
  sireq_n <= 1'b1;
  srd_n <= 1'b1;
  swr_n <= 1'b1;
  end else begin
  sbank <= dma_sel ? dma_bank : ice_bank;
  sa    <= dma_sel ? dma_a    : a; // ZA
  sdo   <= dma_sel ? dma_do   : data_out;  // ZDO
  smreq_n <= dma_sel ? dma_mreq_n : ~mreq;  // ZMREQ_n
  sireq_n <= dma_sel ? dma_iorq_n : ~iorq; // ZIORQ_n
  srd_n <= dma_sel ? dma_rd_n : ~rd;  // ZRD_n
  swr_n <= dma_sel ? dma_wr_n : ~wr; // ZWR_n
  end
end
`else
// ASYNC / NON LATCHED Z80 BUS
wire [3:0]  sbank;
wire [15:0] sa;
wire sm1_n,smreq_n,siorq_n,srd_n,swr_n;

assign sbank   = dma_sel ? dma_bank   : ice_bank;
assign sa    = dma_sel ? dma_a    : a;  // ZA
assign smreq_n = dma_sel ? dma_mreq_n : ~mreq; // ZMREQ_n
assign sireq_n = dma_sel ? dma_iorq_n : ~iorq; // ZIORQ_n
assign srd_n   = dma_sel ? dma_rd_n   : ~rd; // ZRD_n
assign swr_n   = dma_sel ? dma_wr_n   : ~wr; // ZWR_n

assign sdo     = dma_sel ? dma_do   : data_out;  // ZDO

`endif

assign ZDI    = sdi;
assign dma_di = sdi;

/****************************************************************************
  Data & Address Buses
****************************************************************************/

always @(posedge clk_sys) begin
  
  /*
  if(ioctl_download == 1'b0) begin
    $display("A=%h, D=%h wr=%h halt_n=%h mreq=%h iorq=%h rd=%h m1=%h ram_cs=%h sub_cs=%h psgram_cs=%h gram_cs=%h", a, data_out, wr, halt_n, mreq, iorq, rd, m1, ram_cs, sub_cs, psgram_cs, gram_cs);
  end
  */

  if(ram_cs) begin
    if(wr) begin
      ramDi <= data_out;    
      ramWe <= 1;
      //$display("RAM write %h %h", a, data_out);
    end
    else if (rd) begin
      ramWe <= 0;
      $display("RAM read %h %h", a, ramDo);      
    end
    ramA <= a;
  end
  else if (gram_cs) begin
    if(wr) begin
      gramDi <= data_out;    
      gramWe <= 1;
      //$display("GRAM write %h %h", a, data_out);
    end
    else if (rd) begin
      gramWe <= 0;
      //$display("GRAM read %h %h", a, gramDo);            
    end
    gramA <= a;
  end
  else if (psgram_cs) begin
    if(wr) begin
      psgramDi <= data_out;    
      psgramWe <= 1;
      //$display("PSGRAM write %h %h", a, data_out);
    end
    else if (rd) begin
      psgramWe <= 0;
      //$display("PSGRAM read %h %h", a, psgramDo);         
    end
    psgramA <= a;
  end
  else if (sub_cs) begin
    if(wr) begin
      subDi <= data_out;    
      sub_wr <= 1;
      sub_rd <= 0;
      //$display("SUB CPU write %h %h", a, data_out);
    end
    else if (rd) begin
      sub_wr <= 0;
      sub_rd <= 1;
      //$display("SUB CPU read %h %h", a, subDo);         
    end
  end
end

assign romA = a;

//assign ramWe = !(!mreq && !wr);
//assign ramDi = data_out;
//assign ramA  = a;

//assign gramWe = !(!mreq && !wr);
//assign gramDi = data_out; 
//assign gramA  = a;

//assign psgramWe = !(!mreq && !wr);
//assign psgramDi = data_out; 
//assign psgramA  = a;

assign di = ram_cs ? ramDo : 
            ipl_cs ? romDo_SharpX1 :
            sub_cs ? subDo :
            gram_cs ? gramDo :
            psgram_cs ? psgramDo :            
            8'hff;

endmodule