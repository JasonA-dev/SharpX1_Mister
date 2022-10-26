/****************************************************************************
  7SEGMENT x4digit Dynamic Driver
****************************************************************************/
module hex4_7seg(
  clk4i,    // x4 interval
  clk4e,    // clock enable
  reset,
//
  num,      // binary input
  dot,      // 7segment dot
//
  segment,  // segment output 
  common    // common output
);

input clk4i;
input clk4e;
input reset;

input [15:0] num;
input [3:0] dot;

output [7:0] segment;
output [3:0] common;

// HEX digit segment decoder
function [7:0] seg_dec;
input [3:0] hex;
input dot;
begin
  case ( hex )
     0: seg_dec[6:0] = 7'b1000000;
     1: seg_dec[6:0] = 7'b1111001;
     2: seg_dec[6:0] = 7'b0100100;
     3: seg_dec[6:0] = 7'b0110000;
     4: seg_dec[6:0] = 7'b0011001;
     5: seg_dec[6:0] = 7'b0010010;
     6: seg_dec[6:0] = 7'b0000010;
     7: seg_dec[6:0] = 7'b1111000;
     8: seg_dec[6:0] = 7'b0000000;
     9: seg_dec[6:0] = 7'b0010000;
    10: seg_dec[6:0] = 7'b0001000;
    11: seg_dec[6:0] = 7'b0000011;
    12: seg_dec[6:0] = 7'b1000110;
    13: seg_dec[6:0] = 7'b0100001;
    14: seg_dec[6:0] = 7'b0000110;
    15: seg_dec[6:0] = 7'b0001110;
  endcase
  seg_dec[7] = ~dot;
end
endfunction

// common decoder
function [3:0] com_dec;
input [1:0] sel;
begin
case ( sel )
     0: com_dec = 4'b1110;
     1: com_dec = 4'b1101;
     2: com_dec = 4'b1011;
     3: com_dec = 4'b0111;
  endcase
end
endfunction

// number selector
function [4:0] digit_sel;
input [15:0] hex4;
input [3:0] dot;
input [1:0] sel;
begin
case ( sel )
     0: digit_sel = {dot[0],hex4[3:0]};
     1: digit_sel = {dot[1],hex4[7:4]};
     2: digit_sel = {dot[2],hex4[11:8]};
     3: digit_sel = {dot[3],hex4[15:12]};
  endcase
end
endfunction

// dynamic counter
reg [1:0] digit;
always @(posedge clk4i)
begin
  if(reset)
    digit <= 0;
  else if(clk4e)
    digit <= digit + 1;
end

// digit select
wire [4:0] seg7_hex = digit_sel(num,dot,digit);

// output
assign segment = seg_dec(seg7_hex[3:0],seg7_hex[4]);
assign common  = reset ? 4'b1111 : com_dec(digit);

endmodule
