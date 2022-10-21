//`define BYPASS
`define ADJUST_VSYNC
/****************************************************************************
	X1 double scan video converter 15KHz -> near VGA

	Version 080430

	Copyright(C) 2004,2005 Tatsuyuki Satoh

	This software is provided "AS IS", with NO WARRANTY.
	NON-COMMERCIAL USE ONLY

	Histry:
		2008. 4.30 adjust H-scan timming in Width 80
		2005. 1.14 added ADJUST_VSYNC switch
		2005. 1.11 1su release

	Note:

	Distributing all and a part is prohibited. 
	Because this version is developer-alpha version.

X1 HSYNC  = 8 * 1.78975MHZ = 4.469us
VGA HSYNC = 3.84us = 28.636Mhz x110clk

****************************************************************************/
module dbl_scan(
  I_CLK,
//
  I_ICLK_EN,
  I_R,
  I_G,
  I_B,
  I_HSYNC,
  I_VSYNC,
//
  I_OCLK_EN,
  O_R,
  O_G,
  O_B,
  O_HSYNC,
  O_VSYNC
);
// input signals
input I_CLK;
input I_ICLK_EN;
input I_R;
input I_G;
input I_B;
input I_HSYNC;
input I_VSYNC;
//
input I_OCLK_EN;
output O_R;
output O_G;
output O_B;
output O_HSYNC;
output O_VSYNC;

`ifdef BYPASS
assign O_R = I_R;
assign O_G = I_G;
assign O_B = I_B;
assign O_HSYNC = I_HSYNC;
assign O_VSYNC = I_VSYNC;
`else

//---------------------------------------------------------------------------
// buffer RAM
//---------------------------------------------------------------------------
reg [3:0] line_ram[2047:0];

//---------------------------------------------------------------------------
// input timming
//---------------------------------------------------------------------------

reg [9:0] hnum;

reg [9:0] hpos_i;	 // input capture postion
reg page;
reg hs_old;

wire [3:0]	lram_di = {I_R,I_G,I_B,I_HSYNC};

always @(posedge I_CLK)
begin
  if(I_ICLK_EN)
  begin
	// capture data
	line_ram[{page,hpos_i}] <= lram_di;
	hpos_i <= hpos_i + 1;

	// change line page
	hs_old <= I_HSYNC;
	if(~hs_old	& I_HSYNC)
	begin
	 hnum	<= hpos_i;
	 hpos_i <= 0;
	 page	<= ~page;
   end
 end

end

//---------------------------------------------------------------------------
//output timming
//---------------------------------------------------------------------------
reg [9:0] hpos_o;
reg [3:0] lram_do;

reg hs_sync;

//wire dscan_return = (~hs_old & I_HSYNC) | (hpos_o == hnum);
wire dscan_return = (~hs_sync & hs_old) | (hpos_o == hnum);
reg hsync_r;

`ifdef ADJUST_VSYNC
reg [2:0] vsync_r;
`else
reg vsync_r;
`endif

//reg vsync_r;
always @(posedge I_CLK)
begin

  if(I_OCLK_EN)
  begin

	hs_sync <= hs_old;

	lram_do <= line_ram[{~page,hpos_o}];
	hpos_o <= hpos_o + 1;

	// SYNC to VSYNC
	if(dscan_return)
	begin
	  hpos_o <= 0;

`ifdef ADJUST_VSYNC
	  if(~I_VSYNC)
		vsync_r <= 3'b110;
	  else
		vsync_r <= {1'b0,vsync_r[2:1]};
`else
	  vsync_r <= I_VSYNC;
`endif
	end

	// 3.84us / 34.92ns = 109.9
	hsync_r <= hpos_o<109;

  end

end

//---------------------------------------------------------------------------
// output
//---------------------------------------------------------------------------

assign O_R = lram_do[3];
assign O_G = lram_do[2];
assign O_B = lram_do[1];
//assign O_HSYNC = lram_do[0];
assign O_HSYNC = hsync_r;
//assign O_VSYNC = I_VSYNC;
`ifdef ADJUST_VSYNC
assign O_VSYNC = vsync_r[0];
`else
assign O_VSYNC = vsync_r;
`endif
`endif

endmodule
