/////////////////////////////////////////////////////////////////////////////
// nbit x nbit GenericDualPort RAM
/////////////////////////////////////////////////////////////////////////////

module dpram(
// CPU I/F
  ACLK,AA,AI,AO,ACS,AWE,
  BCLK,BA,BI,BO,BCS,BWE
);
parameter ADDR_DEPTH = 11; // 11=2K
parameter DATA_WIDTH =  8; //

input  ACLK,BCLK;
input  [ADDR_DEPTH-1:0] AA,BA;
input  [DATA_WIDTH-1:0] AI,BI;
output [DATA_WIDTH-1:0] AO,BO;
input  ACS,BCS,AWE,BWE;

/////////////////////////////////////////////////////////////////////////////
reg [DATA_WIDTH-1:0] ram [(2**ADDR_DEPTH)-1:0];
reg [DATA_WIDTH-1:0] AO,BO;

always @(posedge ACLK)
begin
  if (ACS) begin
    if (AWE) ram[AA] <= AI;
    AO <= ram[AA];
  end
end

always @(posedge BCLK) BO <= ram[BA];

endmodule
