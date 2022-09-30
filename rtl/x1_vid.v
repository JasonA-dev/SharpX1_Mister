`define X1TURBO
`define BORDER_BLACK /* neecesary for VGA(analog RGB) */

`define FAST_SQUE  /* 8dot left sque,save some circuit */

/****************************************************************************
	X1 VIDEO CIRCUIT

	Version 050414

	Copyright(C) 2004,2005 Tatsuyuki Satoh

	This software is provided "AS IS", with NO WARRANTY.
	NON-COMMERCIAL USE ONLY

	Histry:
		2008. 4.28 bugfix,can't PCG(X1mode) in WIDTH40 with X1turbo select
		2005. 4.14 X1turbo mode PCG access address generator
		           non left sque mode (coded only)
		2005. 1.11 1st release

	Note:

	Distributing all and a part is prohibited. 
	Because this version is developer-alpha version.

    VIDEO / GRAPHIC RAM read is not supported

****************************************************************************/
module x1_vid(
  I_RESET,
// CPU I/F
  I_CCLK,
  I_A,
  I_D,
  O_D,
  O_DE,
  I_WR,
  I_RD,
  O_VWAIT,
// CHIP SELECT
  I_CRTC_CS,
  I_CG_CS,
  I_PAL_CS,
  I_TXT_CS, I_ATT_CS, I_KAN_CS,
  I_GRB_CS, I_GRR_CS, I_GRG_CS,
// VIDEO CLOCK
  I_VCLK,
  I_CLK1,
  O_VQ,
// VIDEO MODE
  I_W40,
`ifdef X1TURBO
  I_HIRESO,
  I_LINE400,
  I_TEXT12,
  I_PCG_TURBO,
  I_CG16,
  I_UDLINE,
  I_BLACK_COL,
  I_TXT_BLACK,
  I_GR0_BLACK,
  I_GR1_BLACK,
  I_BLK_BLACK,
  O_YM,
`endif
// VRAM / GRAM
  O_VA,
// VRAM
  O_TXT_WE, O_ATT_WE, O_KAN_WE,
  I_TXT_D,  I_ATT_D,  I_KAN_D,
// GRAM
  O_GRB_WE, O_GRR_WE, O_GRG_WE,
  I_GRB_D , I_GRR_D,  I_GRG_D,
// CG ROM/RAM
  O_CGA,
  I_CG_D  , I_PCGB_D , I_PCGR_D , I_PCGG_D,
// VIDEO OUTPUT
  O_R     , O_G     , O_B,
  O_HSYNC , O_VSYNC , O_VDISP
);

input I_RESET;
// CPU I/F
input I_CCLK;
input [15:0] I_A;
input [7:0]  I_D;
output [7:0] O_D;
output O_DE;
input I_WR;
input I_RD;
output O_VWAIT;
// CS
input I_CRTC_CS;
input I_CG_CS;
input I_PAL_CS;
input I_TXT_CS;
input I_ATT_CS;
input I_KAN_CS;
input I_GRB_CS , I_GRR_CS , I_GRG_CS;
// VIDEO CLOCK
input I_VCLK;
input I_CLK1;
output [4:0] O_VQ;
input I_W40;

`ifdef X1TURBO
input I_HIRESO;
input I_LINE400;
input I_TEXT12;
input I_PCG_TURBO;
input I_CG16;
input I_UDLINE;
input [2:0] I_BLACK_COL;
input I_TXT_BLACK;
input I_GR0_BLACK;
input I_GR1_BLACK;
input I_BLK_BLACK;

output O_YM;
`endif

// VRAM / GRAM
// low  10bit for VRAM
// full 13bit for GRAM
output [13:0] O_VA;

// VRAM
output      O_TXT_WE , O_ATT_WE , O_KAN_WE;
input [7:0] I_TXT_D  , I_ATT_D  , I_KAN_D ;

// GRAM
output      O_GRB_WE , O_GRR_WE , O_GRG_WE;
input [7:0] I_GRB_D  , I_GRR_D  , I_GRG_D ;

// CG ROM/RAM
output [10:0] O_CGA;
input [7:0] I_CG_D  , I_PCGB_D , I_PCGR_D , I_PCGG_D;

// VIDEO OUTPUT
output O_R , O_G , O_B;
output O_HSYNC;
output O_VSYNC;
output O_VDISP;
/////////////////////////////////////////////////////////////////////////////
// video timming generator
/////////////////////////////////////////////////////////////////////////////
reg ppres;
reg [3:0] pris;
reg vid_reset;

always @(posedge I_VCLK)
begin
  ppres <= ~ppres & I_W40;
  if(~ppres)
    pris <= pris + 1;
end

always @(posedge I_VCLK or posedge I_RESET)
begin
  if(I_RESET)
  begin
    vid_reset <= 1'b1;
  end else begin
    if(pris==4'b1111)
      vid_reset <= 1'b0;
  end
end

wire QP = ppres;
wire QA = ~pris[0]; // 14.31818   : 21.47727
wire QB = ~pris[1]; //  7.15909   : 10.738635
wire QC = ~pris[2]; //  3.579545  :  5.3693175
wire QD = ~pris[3]; //  1.7897725 :  2.68465875
assign O_VQ = {QD,QC,QB,QA,QP};


/****************************************************************************
  CRTC
****************************************************************************/
wire [4:0]  crtc_ra;
wire [13:0] crtc_ma;
wire crtc_hsync;
wire crtc_vsync;
wire crtc_disptmg;

crtc6845s crtc6845s(
  .I_E(~I_CCLK),
  .I_DI(I_D),
  .I_RS(I_A[0]),
  .I_RWn(~I_WR),
  .I_CSn(~I_CRTC_CS),
  .I_CLK(~QD),
  .I_RSTn(~vid_reset),
  .O_RA(crtc_ra),
  .O_MA(crtc_ma),
  .O_H_SYNC(crtc_hsync),
  .O_V_SYNC(crtc_vsync),
  .O_DISPTMG(crtc_disptmg)
);

/****************************************************************************
  VDISP signal
****************************************************************************/
//
// 3xLS14 & RC delay(220ohm,1200pF)
// about 300ns = 35ns(28.6Mhz) * 8.5
//
reg vdisp;
reg vdisp_dly;

always @(posedge I_VCLK)
begin
  if(crtc_ra[0])
    vdisp_dly <= 1;
  else begin
    // latch VDISP
    if(~QP & QA & ~QD & ~QC & ~QB)
    begin
      if(vdisp_dly)
        vdisp <= crtc_disptmg;
      vdisp_dly <= 1'b0;
    end
  end
end

/****************************************************************************
  VRAM/GRAM access address
****************************************************************************/

`ifdef X1TURBO
// CRTC / turbo PCG address mux
wire [10:0] vram_a = (I_PCG_TURBO && ~crtc_disptmg) ? 11'b11111111111 : crtc_ma;
`else
wire [10:0] vram_a = crtc_ma;
`endif

// CPU / VRAM address mux
//assign O_VA = QD ? I_A[13:0] : {crtc_ra[2:0],vram_a};
assign O_VA  = {crtc_ra[2:0],vram_a};

/****************************************************************************
  VRAM & CG LATCH
****************************************************************************/
reg [7:0] txt_d;
reg [7:0] cgb_d , cgr_d , cgg_d;
reg [7:0] grb_d , grr_d , grg_d;
`ifdef FAST_SQUE
wire [7:0] att_d = I_ATT_D; // attr bypass
`else
reg [7:0] att_d;
reg [7:0] grb_r , grr_r , grg_r;
`endif

// attribute bit assign
reg att_h2x;
//reg att_v2x;
reg att_pcg;
reg att_blink;
reg att_rev;
reg att_g;
reg att_r;
reg att_b;

reg hsync_d , vsync_d , disp_d;

// V2X
reg [2:0] cg_line;
reg old_ra0;

always @(posedge I_VCLK)
begin
  if(~QP & QA) // 1pixel clock
  begin

    // CG pixel shift
    if(~att_h2x || ~QB)
    begin
      // pixel hift register
      cgb_d[7:1] <= cgb_d[6:0];
      cgr_d[7:1] <= cgr_d[6:0];
      cgg_d[7:1] <= cgg_d[6:0];
    end

    // GRAM pixel shift
    grb_d[7:1] <= grb_d[6:0];
    grr_d[7:1] <= grr_d[6:0];
    grg_d[7:1] <= grg_d[6:0];

    if(~QD)
    begin
`ifdef FAST_SQUE
      if( QC & ~QB) // delay 2 ealy latch
      begin
        txt_d <= I_TXT_D;

        // CG V pos
        old_ra0 <= crtc_ra[0];
        if( (att_d[6] | ~crtc_disptmg) & vdisp )
        begin
          // V2X
          if(old_ra0 & ~crtc_ra[0])
            cg_line <= cg_line + 1;    // x2 increment CRTC 2V
        end else begin
          cg_line <= crtc_ra[2:0];     // x1 CRTC through
        end
      end
`endif
      if(~QC & ~QB) // delay 4
      begin
`ifndef FAST_SQUE
        // 1 char delayed latch
        txt_d <= I_TXT_D;
        att_d <= I_ATT_D;

        // CG V pos
        old_ra0 <= crtc_ra[0];
        if( (att_d[6] | ~crtc_disptmg) & vdisp )
        begin
          // V2X
          if(old_ra0 & ~crtc_ra[0])
            cg_line <= cg_line + 1;        // x2 increment CRTC 2V
        end else begin
          cg_line <= crtc_ra[2:0];     // x1 CRTC through
        end
`endif
        // CG load
        if(~att_h2x || ~crtc_ma[0])
        begin
          cgb_d  <= I_PCGB_D; // blue
          cgr_d  <= I_PCGR_D; // reg
          cgg_d  <= att_d[5] ? I_PCGG_D : I_CG_D; // green or ROM
        end
        // ATT load
        att_h2x   <=  att_d[7];
`ifdef FAST_SQUE
//        att_v2x   <=  att_d[6];
`else
//        att_v2x   <= (att_d[6] | ~crtc_disptmg) & vdisp;
`endif
        att_pcg   <=  att_d[5];
        att_blink <=  att_d[4];
        att_rev   <=  att_d[3];
        att_g     <=  att_d[2];
        att_r     <=  att_d[1];
        att_b     <=  att_d[0];

        // GRAM load
`ifdef FAST_SQUE
        grb_d <= I_GRB_D;
        grr_d <= I_GRR_D;
        grg_d <= I_GRG_D;
        // syncs
        hsync_d  <= crtc_hsync;
        vsync_d  <= crtc_vsync;
`else
        grb_r <= I_GRB_D;
        grr_r <= I_GRR_D;
        grg_r <= I_GRG_D;
        grb_d <= grb_r;
        grr_d <= grr_r;
        grg_d <= grg_r;
        // syncs
        hsync_d  <= crtc_hsync;
        vsync_d  <= crtc_vsync;
`endif
        disp_d   <= crtc_disptmg;
      end
    end
  end
end

/****************************************************************************
  CG/PCG address
****************************************************************************/

/*
  kanji

wire kan_sel = kan_d[7]; // CG / KANJI
wire kan_rt  = kan_d[7]; // LEFT / RIGHT
wire kan_ul  = kan_d[7]; // under line
wire kan_d2  = kan_d[7]; // DAI1 / DAI2,GAIJI
wire [3:0] kan_ah = kan_d[3:0]; // upper address
*/

`ifdef X1TURBO
wire x1t_cg_sel = I_PCG_TURBO & (crtc_hsync | hsync_d);
assign O_CGA = { txt_d, x1t_cg_sel ? I_A[3:1] : cg_line };
`else
assign O_CGA = { txt_d, cg_line };
`endif

/****************************************************************************
  CG attribute effect
****************************************************************************/
wire col_rev = att_rev^(att_blink & I_CLK1);

wire cg_b = (att_pcg ? cgb_d[7] : cgg_d[7]) & att_b;
wire cg_r = (att_pcg ? cgr_d[7] : cgg_d[7]) & att_r;
wire cg_g = cgg_d[7] & att_g;

wire [2:0] cg_col = {cg_g,cg_r,cg_b} ^ {col_rev,col_rev,col_rev};
wire cg_trans = cg_col==3'b000;

/****************************************************************************
  GRAM palette / priority
****************************************************************************/
reg [7:0] PAL_B , PAL_R , PAL_G , PRIO_R;

always @(posedge I_CCLK or posedge I_RESET)
begin
  if(I_RESET)
  begin
    PAL_B  <= 8'h00;
    PAL_R  <= 8'h00;
    PAL_G  <= 8'h00;
    PRIO_R <= 8'h00;
  end else begin
    if(I_PAL_CS & I_WR)
    begin
      case(I_A[9:8])
      2'b00: PAL_B  <= I_D;
      2'b01: PAL_R  <= I_D;
      2'b10: PAL_G  <= I_D;
      2'b11: PRIO_R <= I_D;
      endcase
    end
  end
end

// palette table
wire [2:0] gr_col = disp_d ? {grg_d[7],grr_d[7],grb_d[7]} : 3'b000;

`ifdef BORDER_BLACK
wire [2:0] gr_pal = disp_d ? {PAL_G[gr_col],PAL_R[gr_col],PAL_B[gr_col]} : 3'b000;
`else
wire [2:0] gr_pal = {PAL_G[gr_col],PAL_R[gr_col],PAL_B[gr_col]};
`endif
wire gr_sel = PRIO_R[gr_col] | cg_trans | ~disp_d;

// BLACK controll
`ifdef X1TURBO
wire gr_black = (gr_col[2:1]==2'b00) & ((I_GR0_BLACK & ~gr_col[0]) | (I_GR1_BLACK & gr_col[0]));
wire cg_black = I_TXT_BLACK & (cg_col==I_BLACK_COL);
wire mx_black = ~disp_d ? I_BLK_BLACK : gr_sel ? gr_black : cg_black;
`endif

/****************************************************************************
  video output mixer
****************************************************************************/
// VGA output mixer
//                   RIGHT SIDE: text 
//                   COLOR VER : area

`ifdef X1TURBO
reg ym_r;
`endif

reg [2:0] out_col;
always @(posedge I_VCLK)
begin
`ifdef X1TURBO
  ym_r    <= mx_black;
  out_col <= mx_black ? 3'b000 : gr_sel ? gr_pal : cg_col;
`else
  out_col <= gr_sel ? gr_pal : cg_col;
`endif
end

assign O_B = out_col[0];
assign O_R = out_col[1];
assign O_G = out_col[2];
`ifdef X1TURBO
assign O_YM = ym_r;
`endif

`ifdef FAST_SQUE
assign O_HSYNC = crtc_hsync;
assign O_VSYNC = crtc_vsync;
`else
assign O_HSYNC = hsync_d;
assign O_VSYNC = vsync_d;
`endif
assign O_VDISP = vdisp;

/****************************************************************************
  CPU read data
****************************************************************************/
assign O_D  = 8'h00;
assign O_DE = 1'b0;
assign O_VWAIT = 1'b0; //!!!!!

assign O_TXT_WE = 1'b0;
assign O_ATT_WE = 1'b0;
assign O_KAN_WE = 1'b0;
assign O_GRB_WE = 1'b0;
assign O_GRR_WE = 1'b0;
assign O_GRG_WE = 1'b0;

endmodule
