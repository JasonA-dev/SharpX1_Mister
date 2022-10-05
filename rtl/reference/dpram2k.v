//
// 2KBytes DualPort RAM for text vram
//
module dpram2k(
// CPU I/F
  CCLK,CA,CDI,CDO,CCS,CWE,CRD,
// VIDEO 
  VCLK,VA,VDO
);

input  CCLK;
input  [10:0] CA;
input  [7:0] CDI;
output [7:0] CDO;
input  CCS,CWE,CRD;

input VCLK;
input [10:0] VA;
output [7:0] VDO;

////////////////////////////////////////////
reg [7:0] ram [2047:0];
reg [10:0] ca_reg,va_reg;

always @(posedge CCLK)
if (CCS) begin
 if (CWE) ram[CA] <= CDI;
 ca_reg <= CA;
end

always @(posedge VCLK)
  va_reg <= VA;

assign CDO = ram[ca_reg];
assign VDO = ram[va_reg];

endmodule
