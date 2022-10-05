//
// 16Bit x 4K synched ROM
//
module sub_rom(
  CLK,
  A,
  DO
);

input  CLK;
input  [10:0] A;
output [15:0] DO;

reg [15:0] DO;

