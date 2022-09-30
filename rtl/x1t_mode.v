/****************************************************************************
	X1 turbo mode switch controll

	Version 050413

	Copyright(C) 2005 Tatsuyuki Satoh

	This software is provided "AS IS", with NO WARRANTY.
	NON-COMMERCIAL USE ONLY

	Histry:
		2005. 4.13 Create

	Note:

	Distributing all and a part is prohibited. 
	Because this version is developer-alpha version.

****************************************************************************/

module x1t_mode(
  I_RESET,
  CLK,
  I_D,
  O_D,
  O_DOE,
  I_WR,
  I_RD,
//
  I_P1FD0_CS,
  I_P1FE0_CS,
// Port 1FD0
  O_HIRESO,
  O_LINE400,
  O_TEXT12,
  O_GRAM_RP,
  O_GRAM_WP,
  O_PCG_TURBO,
  O_CG16,
  O_UDLINE,
// Port 1FE0
  O_BLACK_COL,
  O_TXT_BLACK,
  O_GR0_BLACK,
  O_GR1_BLACK,
  O_BLK_BLACK
);

input I_RESET;
input CLK;
input [7:0] I_D;
output [7:0] O_D;
output O_DOE;
input I_WR;
input I_RD;

input I_P1FD0_CS;
input I_P1FE0_CS;
//input I_P1FF0_CS;

output  O_HIRESO;
output  O_LINE400;
output  O_TEXT12;
output  O_GRAM_RP;
output  O_GRAM_WP;
output  O_PCG_TURBO;
output  O_CG16;
output  O_UDLINE;
// Port 1FE0
output [2:0] O_BLACK_COL;
output  O_TXT_BLACK;
output  O_GR0_BLACK;
output  O_GR1_BLACK;
output  O_BLK_BLACK;


/////////////////////////////////////////////////////////////////////////////
// Port1FD0
/////////////////////////////////////////////////////////////////////////////
reg [7:0] latch_1fd0;
reg [6:0] latch_1fe0;

always @(posedge CLK)
begin
  if(I_RESET)
  begin
    latch_1fd0 <= 8'h00;
    latch_1fe0 <= 7'h00;
  end else begin
    if(I_P1FD0_CS & I_WR)
      latch_1fd0 <= I_D;
    if(I_P1FE0_CS & I_WR)
      latch_1fe0 <= I_D[6:0];
  end
end

assign O_HIRESO    = latch_1fd0[0];
assign O_LINE400   = latch_1fd0[1];
assign O_TEXT12    = latch_1fd0[2];
assign O_GRAM_RP   = latch_1fd0[3];
assign O_GRAM_WP   = latch_1fd0[4];
assign O_PCG_TURBO = latch_1fd0[5];
assign O_CG16      = latch_1fd0[6];
assign O_UDLINE    = latch_1fd0[7];

assign O_BLACK_COL = latch_1fe0[2:0];
assign O_TXT_BLACK = latch_1fe0[3];
assign O_GR0_BLACK = latch_1fe0[4];
assign O_GR1_BLACK = latch_1fe0[5];
assign O_BLK_BLACK = latch_1fe0[6];

endmodule
