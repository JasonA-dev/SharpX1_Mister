/****************************************************************************
  UART TX 
****************************************************************************/
// 8bit , no parity , 1stop
module uart_tx(
  reset,
  clk,
  clk_en,
//
  txd,
//
  wclk,
  tx_data,
  we,
  ready
);

input reset;
input clk;
input clk_en;  // 1xbps

output txd;

input wclk;
input [7:0] tx_data;
input we;
output ready;

///////////////////////////
reg [8:0] tx_shift;
reg [3:0] tx_cnt;

reg [7:0] tx_stock;
reg tx_valid;

wire tx_start = tx_cnt[3];

always @(posedge clk or posedge reset)
begin
  if(reset)
  begin
    tx_shift <= 9'h1ff;
    tx_cnt   <= 0;
  end else begin
    if(clk_en)
    begin
      // output data
      tx_shift <= {1'b1,tx_shift[8:1]};

      if(tx_cnt!=0)
      begin
        // in transmit , count down
        tx_cnt <= tx_cnt -1;
      end else begin
        // start new data
        if(tx_valid)
        begin
          tx_shift <= {tx_stock,1'b0};
          tx_cnt   <= 10;
        end
      end
    end
  end
end

assign txd = tx_shift[0];

////////////////////////////////////////////
//
///////////////////////////////////////////

always @(posedge wclk or posedge reset)
begin
  if(reset)
  begin
    tx_stock   <= 8'h00;
  end else begin
    if(we) tx_stock <= tx_data;
  end
end

// valid status
reg tx_start_w;
wire tx_clr =  (~tx_start_w & tx_start) | reset;

reg we_r;
always @(posedge wclk or posedge tx_clr)
begin
  if(tx_clr)
  begin
    tx_valid   <= 1'b0;
    tx_start_w <= 1'b1;
    we_r       <= 1'b0;
  end else begin
    we_r <= we;
    tx_start_w <= tx_start;
    if(we_r & ~we) tx_valid <= 1'b1;
  end
end


assign ready = ~tx_valid;

endmodule
