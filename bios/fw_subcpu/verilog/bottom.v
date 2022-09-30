/////
always @(posedge CLK)
begin
  DO <= rom(A);
end

endmodule

