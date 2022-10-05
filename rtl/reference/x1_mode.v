/****************************************************************************
	X1 mode / switch controll

	Version 080430

	Copyright(C) 2004,2005,2008 Tatsuyuki Satoh

	This software is provided "AS IS", with NO WARRANTY.
	NON-COMMERCIAL USE ONLY

	Histry:
		2008. 4.30 fix, DAM update timming
		2005. 1.11 Ver.0.1

	Note:

	Distributing all and a part is prohibited. 
	Because this version is developer-alpha version.

****************************************************************************/

module x1_mode(
  I_RESET,
  C_CLK,
  I_A,
  I_D,
  I_RD,
  I_WR,
// IPL select,
  I_IPL_SET_CS,
  I_IPL_RES_CS,
  O_IPL_SEL,
// DOUJI access mode (GRAPHIC)
  C_DAM_SET_n, // fall clk
  I_DAM_CLR,   // async 
  O_DAM
);

input I_RESET;
input C_CLK;
input [15:0] I_A;
input [7:0] I_D;
input I_RD;
input I_WR;

input I_IPL_SET_CS;
input I_IPL_RES_CS;
output O_IPL_SEL;

input C_DAM_SET_n;
input I_DAM_CLR;
output O_DAM;

/////////////////////////////////////////////////////////////////////////////
// IPL select
/////////////////////////////////////////////////////////////////////////////
reg O_IPL_SEL = 1'b1;

always @(posedge C_CLK or posedge I_RESET)
begin
  if(I_RESET)
  begin
    O_IPL_SEL <= 1'b1;
  end else begin
    if(I_WR)
    begin
      if(I_IPL_SET_CS)
        O_IPL_SEL <= 1'b1;
      else if(I_IPL_RES_CS)
        O_IPL_SEL <= 1'b0;
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// DAM select
/////////////////////////////////////////////////////////////////////////////
reg dam_r;
reg O_DAM;

reg dam_clear;

always @(negedge C_DAM_SET_n or posedge dam_clear)
begin
  if(dam_clear)
    dam_r <= 1'b0;
  else
    dam_r <= 1'b1;
end

always @(posedge C_CLK or posedge I_RESET)
begin
  if(I_RESET)
  begin
    O_DAM     <= 1'b0;
    dam_clear <= 1'b1;
  end else begin
    // sync clear request
    dam_clear <= I_DAM_CLR;

    // update DAM mode
    if(~I_WR && ~I_RD)
      O_DAM <= dam_r;
  end
end

endmodule
