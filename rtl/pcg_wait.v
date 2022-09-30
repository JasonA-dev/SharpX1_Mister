/****************************************************************************
	X1 PCG AUTO WAIT TARP

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
module pcg_wait(
  I_RESET,
// CPU I/F
  I_CCLK,
  I_CG_CS,
  I_A,
// VIDEO CLOCK
  I_VDISP,
  I_QD,
  I_RA0,
// wait controll
  O_CG_WAIT_n
);

input I_RESET;
// CPU I/F
input I_CCLK;
input [15:0] I_A;
input I_CG_CS;
output O_CG_WAIT_n;

// VIDEO CLOCK
input I_VDISP;
input I_QD;
input I_RA0;

/////////////////////////////////////////////////////////////////////////////
// delayed RA0
/////////////////////////////////////////////////////////////////////////////
reg ra0_dly;
always @(posedge I_QD) ra0_dly <= I_RA0;

/////////////////////////////////////////////////////////////////////////////
// trap address
/////////////////////////////////////////////////////////////////////////////
reg second_access;
reg [1:0] trap_a;
reg last_ra0;
reg ra0_dly_s , ra0_acc;

wire trap_access = second_access & (trap_a == I_A[9:8]);

always @(posedge I_CCLK or posedge I_VDISP)
begin
  if(I_VDISP)
  begin
    second_access <= 1'b0;
    last_ra0      <= 1'b1;
    ra0_acc       <= 1'b1;
  end else begin
    if(I_CG_CS)
    begin
      // when first access , set trap address
      if(~second_access)
      begin
        trap_a <= I_A[9:8];
        ra0_acc  <= ra0_dly;
      end
      if(trap_access)
      begin
        ra0_acc  <= ra0_dly;
      end
      second_access <= 1'b1;

    end else begin
      // set last access line
      last_ra0 <= ra0_acc;
    end
  end
end

/****************************************************************************
  WAIT generator
****************************************************************************/
assign O_CG_WAIT_n = ~(I_CG_CS & trap_access & (last_ra0==ra0_dly) );

endmodule
