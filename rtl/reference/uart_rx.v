/****************************************************************************
  UART RX 
****************************************************************************/
// 8bit , no parity , 1stop
module uart_rx(
// system & clocks
  reset,
  clk,
  clk_en,
// PIN
  rxd,
// HOST interface
  rx_data,
  rx_ready,
  rx_clr
);

input reset;
input clk;
input clk_en;  // 16xbps
input rxd;
output [7:0] rx_data;
output rx_ready;
input rx_clr;

/****************************************************************************
  receive
****************************************************************************/
reg [3:0] rx_sync;
reg [8:0] rx_shift;
reg [7:0] rx_data;
reg rx_ready;
wire rx_idle = (rx_shift==9'h1ff);

reg [1:0] rx_clr_r;

always @(posedge clk or posedge reset)
begin
  if(reset)
  begin
	rx_shift <= 9'h1ff;
	rx_sync  <= 0;
	rx_clr_r <= 2'b00;
	rx_ready <= 1'b0;
  end else begin
	// sense rx_clr raise edge
	rx_clr_r <= {rx_clr_r[0],rx_clr};
	if(rx_clr_r==2'b01)
	  rx_ready <= 1'b0;

	if(clk_en)
	begin
	  rx_sync <= rx_sync + 1;
	  // preset SYNC counter when IDLE
	  if(rx_idle & rxd)
		  rx_sync  <= 8;

	  // shift in receive
	  if(rx_sync==4'hf)
	  begin
		// shift in serial data
		rx_shift <= {rxd,rx_shift[8:1]};
		// end of word
		if(~rx_shift[0])
		begin
		  // latch rx data
		  rx_data  <= rx_shift[8:1];
		  rx_ready <= 1'b1;
		  // clear shift register
		  rx_shift <= 9'h1ff;
		end
	  end
	end
  end
end

endmodule
