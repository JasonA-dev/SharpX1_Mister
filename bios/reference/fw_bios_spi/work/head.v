//
// 2KB ROM
//
module bootrom(
  CLK,
  A,
  DO
);

input  CLK;
input  [10:0] A;
output [7:0] DO;

