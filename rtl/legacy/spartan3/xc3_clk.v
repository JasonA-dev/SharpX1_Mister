/****************************************************************************
	Xilinx Spartan3 DCM based clock generator

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

module xc3_clk(
  I_RESET,
  I_CLK50M,
//
  O_CLK50M, 	 O_LOCK50M,
  O_CLK28M636,	 O_LOCK28M636,
  O_CLK32M, 	 O_LOCK32M,
  O_CLK24M, 	 O_LOCK24M
);
input I_RESET;
input I_CLK50M;

output O_CLK50M;
output O_CLK28M636;
output O_CLK32M;
output O_CLK24M;

output O_LOCK50M;
output O_LOCK28M636;
output O_LOCK32M;
output O_LOCK24M;

/////////////////////////////////////////////////////////////////////////////
// DCM
/////////////////////////////////////////////////////////////////////////////

wire clk50M;
wire clk90M,lock90M;

// 50MHz->90MHz->28.6364MHz for VIDEO
xc3s_dcm_50m_90m xc3s_dcm_50m_90m(
  .CLKIN_IN(I_CLK50M),
  .RST_IN(I_RESET),
  .CLKFX_OUT(clk90M),
  .CLK0_OUT(clk50M), 
  .LOCKED_OUT(lock90M)
);

wire clk28M636;
wire lock28M636;
xc3s_dcm_90m_28m636 xc3s_dcm_90m_28m636(
  .CLKIN_IN(clk90M),
  .RST_IN(~lock90M),
  .CLKFX_OUT(clk28M636),
  .LOCKED_OUT(lock28M636)
);

// 32MHz for SYSTEM
wire clk32M;
wire lock32M;
dcm50_32 dcm50_32(
  .CLKIN_IN(clk50M),
  .RST_IN(~lock90M),
  .CLKFX_OUT(clk32M),
  .LOCKED_OUT(lock32M)
);

// 24MHz for UART
wire clk24M;
wire lock24M;
dcm50_24 dcm50_24(
  .CLKIN_IN(clk50M),
  .RST_IN(~lock90M),
  .CLKFX_OUT(clk24M),
  .LOCKED_OUT(lock24M)
);

/////////////////////////////////////////////////////////////////////////////
// output 
/////////////////////////////////////////////////////////////////////////////
assign O_CLK50M    = clk50M;
assign O_CLK28M636 = clk28M636;
assign O_CLK32M    = clk32M;
assign O_CLK24M    = clk24M;

assign O_LOCK50M	= lock90M;
assign O_LOCK28M636 = lock28M636;
assign O_LOCK32M	= lock32M;
assign O_LOCK24M	= lock24M;

endmodule
