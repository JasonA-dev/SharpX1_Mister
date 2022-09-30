//`define DEBUG

/****************************************************************************
	X1 NTSC S2 encoder

	Version 050120

	Copyright(C) 2005 Tatsuyuki Satoh

	This software is provided "AS IS", with NO WARRANTY.
	NON-COMMERCIAL USE ONLY

	Histry:
		2005. 1.20 1st release

	Note:

	Distributing all and a part is prohibited. 
	Because this version is developer-alpha version.

****************************************************************************/
module ntsc_enc(
  I_CLK,
  I_ICLK_EN,
//
  I_SC,
  I_R,
  I_G,
  I_B,
  I_DISP,
  I_HSYNC,
  I_VSYNC,
//
`ifdef DEBUG
  I_DU,
  I_DV,
`endif
  O_Y,O_C
);
// input signals
input I_CLK;
input I_ICLK_EN;
input [1:0] I_SC;
input I_R;
input I_G;
input I_B;
input I_DISP;
input I_HSYNC;
input I_VSYNC;

`ifdef DEBUG
input [3:0] I_DU,I_DV;
`endif

//
output [3:0] O_Y,O_C;

//---------------------------------------------------------------------------
// input
//---------------------------------------------------------------------------
wire [2:0] cin = {I_G,I_R,I_B};
reg [2:0] y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12,y13,y14,y15;

wire [2:0] ycol,ccol;

always @(posedge I_CLK)
begin
  y1  <= cin; //45
  y2  <= y1;  //90
  y3  <= y2;  //180
  y4  <= y3;
  y5  <= y4;
  y6  <= y5;
  y7  <= y6;
  y8  <= y7;
  y9  <= y8;
  y10 <= y9;
  y11 <= y10;
  y12 <= y11;
  y13 <= y12;
  y14 <= y13;
  y15 <= y14;
end

assign ycol = y3;

`ifdef DEBUG
wire [2:0] ucol = 
  I_DU==0 ? y3 :
  I_DU==1 ? y4 :
  I_DU==2 ? y5 :
  I_DU==3 ? y6 :
  I_DU==4 ? y7 :
  I_DU==5 ? y8 :
  I_DU==6 ? y9 :
  I_DU==7 ? y10:
  I_DU==8 ? y11:
  I_DU==9 ? y12:
  I_DU==10? y13:
  I_DU==11? y14:y15;
wire [2:0] vcol = 
  I_DV==0 ? y3 :
  I_DV==1 ? y4 :
  I_DV==2 ? y5 :
  I_DV==3 ? y6 :
  I_DV==4 ? y7 :
  I_DV==5 ? y8 :
  I_DV==6 ? y9 :
  I_DV==7 ? y10:
  I_DV==8 ? y11:
  I_DV==9 ? y12:
  I_DV==10? y13:
  I_DV==11? y14:y15;
assign ccol = ~I_SC[0] ? vcol : ucol;
`else
assign ccol = y5;
`endif

//---------------------------------------------------------------------------
// burst position
//---------------------------------------------------------------------------

reg [4:0] bpos;

always @(posedge I_CLK)
begin
  if(I_ICLK_EN)
  begin
    if(I_HSYNC)
    begin
      bpos <= -4;
    end else if(I_SC[0])
    begin
      if(bpos[4:3] != 2'b10) // bpos!=16
        bpos <= bpos + 1;
    end
  end
end
// 4 to 18
wire cburst = (bpos<14);

//---------------------------------------------------------------------------
// C
//---------------------------------------------------------------------------
function [3:0] c_table;
input [3:0] sel;
begin
  case(sel)
  4'b0000: c_table = 4'h8; // 0-   0' : 7-180'
  4'b0001: c_table = 4'h8; // 0-  90' : 7-270'
  4'b0010: c_table = 4'h8; // 0- 180' : 7-  0'
  4'b0011: c_table = 4'h8; // 0- 270' : 7- 90'
  4'b0100: c_table = 4'h2; // 1-   0' : 6-180'
  4'b0101: c_table = 4'h7; // 1-  90' : 6-270'
  4'b0110: c_table = 4'he; // 1- 180' : 6-  0'
  4'b0111: c_table = 4'h9; // 1- 270' : 6- 90'
  4'b1000: c_table = 4'ha; // 2-   0' : 5-180'
  4'b1001: c_table = 4'he; // 2-  90' : 5-270'
  4'b1010: c_table = 4'h6; // 2- 180' : 5-  0'
  4'b1011: c_table = 4'h2; // 2- 270' : 5- 90'
  4'b1100: c_table = 4'h4; // 3-   0' : 4-180'
  4'b1101: c_table = 4'hd; // 3-  90' : 4-270'
  4'b1110: c_table = 4'hc; // 3- 180' : 4-  0'
  4'b1111: c_table = 4'h3; // 3- 270' : 4- 90'
  endcase
end
endfunction

// burst lebel == C GAIN for AGC
wire [3:0] b_level =
//{~I_SC[0],1'b0, I_SC[1],1'b0}; // (4,0,6,2) -> (A,8,6,8) : HIGH
//{~I_SC[0],~I_SC[0],~I_SC[1],1'b0}; // (e,2,c,0)->(c,8,4,8) : MID
  {1'b0,~I_SC[0],~I_SC[1],1'b0}; // (6,2,4,0)->(E,8,2,8) : LOW

wire [3:0] c_a = cburst  ? b_level :
                 ccol[2] ? {~ccol[1:0],~I_SC[1],I_SC[0]}: // col 4-7
                           { ccol[1:0], I_SC[1],I_SC[0]}; // col 0-3
reg [3:0] c_r;

always @(posedge I_CLK)
begin
  c_r <= c_table(c_a);
end

assign O_C = c_r;

//---------------------------------------------------------------------------
// Y
//---------------------------------------------------------------------------
function [3:0] y_table;
input [2:0] sel;
begin
  case(sel)
  3'h0: y_table = 4'h5;// 255 * 338 / 1000; // 56
  3'h1: y_table = 4'h7;// 255 * 411 / 1000; // 68
  3'h2: y_table = 4'h8;// 255 * 535 / 1000; // 88
  3'h3: y_table = 4'h9;// 255 * 608 / 1000; // 9B
  3'h4: y_table = 4'hb;// 255 * 725 / 1000; // B8
  3'h5: y_table = 4'hc;// 255 * 797 / 1000; // CB
  3'h6: y_table = 4'he;// 255 * 923 / 1000; // EB
  3'h7: y_table = 4'hf;// 255 * 995 / 1000; // FD
  endcase
end
endfunction

// blank level == Y gain for AGC
//wire [3:0] y_blank = 4'h4; //255 * 284 / 1000; // 48
wire [3:0] y_blank = 4'h5;
wire [3:0] y_sync  = 4'h0;

wire csync     = I_HSYNC ^ I_VSYNC;
wire [3:0] y_a = ycol;
reg [3:0] y_r;

always @(posedge I_CLK)
begin
  y_r <= csync ? y_sync : I_DISP ? y_table(y_a) : y_blank;
end

assign O_Y = y_r;

endmodule
