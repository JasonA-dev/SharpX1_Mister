/////
reg [7:0] DO;
always @(posedge CLK) DO <= boot_rom(A);

endmodule

