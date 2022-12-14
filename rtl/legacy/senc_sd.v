/////////////////////////////////////////////////////////////////////////////
//
// 10bit Sound Encoder SigmaDelta DAC
//
// Version : 1.00
//
// Copyright(c) 2004 Tatsuyuki Satoh , All rights reserved
//
// License:
//   This source is under the GPL license.
//
// Histry:
//   2004. 7.21 1st Release
//
/////////////////////////////////////////////////////////////////////////////

module senc_sd(CLK,IN,OUT);

input CLK;
input [9:0] IN;
output OUT;

dac dac(.DACout(OUT), .DACin(IN), .Clk(CLK), .Reset(1'b0));

endmodule

//
// XAPP154 based SigmaDeltaPCM Module
//
// Important !
//
// This program is freeware for non-commercial use. 
// An author does no guarantee about this program.
// You can use this under your own risk. 
//
// See the xapp154.pdf on Xilinx application note.
//
//

`timescale 100 ps / 10 ps
`define MSBI 9 // Most significant Bit of DAC input
//This is a Delta-Sigma Digital to Analog Converter

module dac(DACout, DACin, Clk, Reset);
output DACout; // This is the average output that feeds low pass filter
reg DACout; // for optimum performance, ensure that this ff is in IOB
input [`MSBI:0] DACin; // DAC input (excess 2**MSBI)
input Clk;
input Reset;
reg [`MSBI+2:0] DeltaAdder; // Output of Delta adder
reg [`MSBI+2:0] SigmaAdder; // Output of Sigma adder
reg [`MSBI+2:0] SigmaLatch; // Latches output of Sigma adder
reg [`MSBI+2:0] DeltaB; // B input of Delta adder

always @(SigmaLatch) DeltaB = {SigmaLatch[`MSBI+2], SigmaLatch[`MSBI+2]} << (`MSBI+1);

always @(DACin or DeltaB) DeltaAdder = DACin + DeltaB;

always @(DeltaAdder or SigmaLatch) SigmaAdder = DeltaAdder + SigmaLatch;

always @(posedge Clk or posedge Reset)
begin
	if(Reset)
	begin
		SigmaLatch <= #1 1'b1 << (`MSBI+1);
		DACout <= #1 1'b0;
	end
	else
	begin
//		SigmaLatch <== #1 SigmaAdder;
		SigmaLatch <= #1 SigmaAdder;
		DACout <= #1  SigmaLatch[`MSBI+2];
	end
end
endmodule

