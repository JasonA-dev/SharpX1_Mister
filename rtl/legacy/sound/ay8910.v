/////////////////////////////////////////////////////////////////////////////
//
// AY-3-8910 Programable Sound Generator
//
// Version : 0.90
//
// Copyright(c) 2004,2007 Tatsuyuki Satoh , All rights reserved
//
// License:
//   This source is under the GPL license.
//
// Histry:
//   2007. 6.14 ver.0.90
//              Added clock enable
//              RegisterWrite clock wr to CLK
//   2004.12.15 ver.0.82
//              R1,R3,R5 read bug fix
//              bugfix swaped enable A and C
//              add reigster reset seaquence
//              noise generator sound
//              bugfix envelope illlegal restart
//   2004.12.10 bugfix envelope pattern & interval
//   2004. 9. 8 minimize
//   2004. 7.22 1st Create
//
/////////////////////////////////////////////////////////////////////////////

//`define AY_SLICE_OUT

module ay8910(rst_n,clk,clken,asel,cs_n,wr_n,rd_n,di,do,A,B,C,pa_i,pb_i,pa_o,pa_t,pb_o,pb_t);

input rst_n;
input clk;
input clken;
input asel;
input cs_n;
input wr_n;
input rd_n;
input [7:0] di;
output [7:0] do;
output [7:0] A,B,C; // 8bit sound output
input [7:0] pa_i,pb_i;
output [7:0] pa_o,pb_o;
output pa_t,pb_t;

/////////////////////////////////////////////////////////////////////////////
// ASYNC Access
/////////////////////////////////////////////////////////////////////////////

reg [3:0] addr;

// write data sync
reg [7:0] wdata;
reg wreq;
reg wack;

wire wreq_clr = ~rst_n || wack;

always @(posedge wr_n or posedge wreq_clr)
begin
  if(wreq_clr)
  begin
//    wdata <= 8'h00;
    wreq <= 1'b0;
  end else if(~cs_n)
  begin
    if(asel)
    begin
      // address write
      addr <= di[3:0];
    end else begin
      // register write
      wdata <= di;
      wreq  <= 1'b1;
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// Write Register
/////////////////////////////////////////////////////////////////////////////

// registers
reg [11:0] period_a,period_b,period_c;
reg [4:0] period_n;
reg [7:0] reg_en;
reg [4:0] vol_a,vol_b,vol_c;
reg [15:0] period_e;
reg [3:0] shape_e;
reg [7:0] pa_r,pb_r;

wire ena = reg_en[0];
wire enb = reg_en[1];
wire enc = reg_en[2];
wire na  = reg_en[3];
wire nb  = reg_en[4];
wire nc  = reg_en[5];
wire pa_od = reg_en[6];
wire pb_od = reg_en[7];

// envelope restart trigger
wire env_req = wack && (addr==5'h0d);

always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    wack <= 1'b0;

    period_a <= 12'h000;
    period_b <= 12'h000;
    period_c <= 12'h000;
    period_n <= 5'h00;
    reg_en   <= 8'b11111111;
    vol_a    <= 5'h00;
    vol_b    <= 5'h00;
    vol_c    <= 5'h00;
    period_e <= 16'h0000;
    shape_e  <= 4'h0;
    pa_r     <= 8'hff;
    pb_r     <= 8'hff;
  end else begin
    wack <= wreq;
    if(wack)
    begin
      // register write
      case(addr)
       0:period_a[ 7:0] <= wdata;
       1:period_a[11:8] <= wdata[3:0];
       2:period_b[ 7:0] <= wdata;
       3:period_b[11:8] <= wdata[3:0];
       4:period_c[ 7:0] <= wdata;
       5:period_c[11:8] <= wdata[3:0];
       6:period_n[ 4:0] <= wdata[4:0];
       7:reg_en         <= wdata;
       8:vol_a          <= wdata[4:0];
       9:vol_b          <= wdata[4:0];
      10:vol_c          <= wdata[4:0];
      11:period_e[7:0]  <= wdata;
      12:period_e[15:8] <= wdata;
      13:shape_e        <= wdata[3:0];
      14:pa_r        <= wdata;
      15:pb_r        <= wdata;
      endcase
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// Read Register
/////////////////////////////////////////////////////////////////////////////
assign do = (cs_n|rd_n) ? 8'h00:       // no read
            asel       ? {4'h0,addr}: // addr reg
            addr==4'h0 ? period_a[7:0] :
            addr==4'h1 ? {4'h0,period_a[11:8]} :
            addr==4'h2 ? period_b[7:0] :
            addr==4'h3 ? {4'h0,period_b[11:8]} :
            addr==4'h4 ? period_c[7:0] :
            addr==4'h5 ? {4'h0,period_c[11:8]} :
            addr==4'h6 ? {3'h0,period_n} :
            addr==4'h7 ? reg_en :
            addr==4'h8 ? {3'h0,vol_a} :
            addr==4'h9 ? {3'h0,vol_b} :
            addr==4'ha ? {3'h0,vol_c} :
            addr==4'hb ? period_e[7:0] :
            addr==4'hc ? period_e[15:8] :
            addr==4'hd ? {4'h0,shape_e} :
            addr==4'he ? pa_i : pb_i;

/////////////////////////////////////////////////////////////////////////////
// clock & phase
/////////////////////////////////////////////////////////////////////////////
reg [2:0] pris;
wire phase0 = (pris==0);

always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    pris <= 0;
  end else if(clken) begin
    pris <= pris + 1;
  end
end

/////////////////////////////////////////////////////////////////////////////
// PSG
/////////////////////////////////////////////////////////////////////////////

//
// toneA 12bit | 12bit
// toneB 12bit | 12bit
// toneC 12bit | 12bit
// env   15bit | 15bit
//
reg [11:0] cnt_a,cnt_b,cnt_c;
reg out_a,out_b,out_c;

wire ca_load = (cnt_a==0);
wire cb_load = (cnt_b==0);
wire cc_load = (cnt_c==0);

always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    cnt_a <= #1 0;
    cnt_b <= #1 0;
    cnt_c <= #1 0;
    out_a <= #1 0;
  end else if(clken) begin
    if(phase0)
    begin
      // tone generator
      cnt_a <= #1 ca_load ? period_a : (cnt_a-1);
      out_a <= #1 out_a ^ ca_load;

      cnt_b <= #1 cb_load ? period_b : (cnt_b-1);
      out_b <= #1 out_b ^ cb_load;

      cnt_c <= #1 cc_load ? period_c : (cnt_c-1);
      out_c <= #1 out_c ^ cc_load;
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// envelope generator
/////////////////////////////////////////////////////////////////////////////
reg [15:0] env_cnt;
reg [3:0] env_phase;
reg env_en;
reg env_inv;
reg env_trg;

// bit3 = turn reset , 0=on , 1=off
// bit2 = start , 0=up , 1=down(inv)
// bit1 = turn invert, 0=tggle , 1=fix
// bit0 = turn repeat, 0=off, 1=on

wire next_no_reset  = shape_e[3];
wire start_no_inv   = shape_e[2];
wire next_toggle    = shape_e[1];
wire next_no_repeat = shape_e[0];

// envelope volume output
wire [3:0] vol_e = env_inv ? ~env_phase : env_phase;

wire ec_load = (env_cnt==0);

always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    env_en    <= 1'b0;
    env_trg   <= 1'b0;
  end else if(clken) begin
    // start trigger
    env_trg <= env_req;
    if(env_trg)
    begin
      env_cnt   <= period_e;
      env_phase <= 0;
      env_inv   <= ~start_no_inv;
      env_en    <= 1'b1;
    end else begin
      if(phase0)
      begin
        // phase up
        env_cnt   <= ec_load ? period_e : (env_cnt-1);
        if(ec_load & env_en)
          env_phase <= env_phase + 1;

        if(ec_load & (env_phase==15))
        begin
          // turn over
          env_inv <= (env_inv ^ next_toggle ^next_no_repeat) & next_no_reset;
          env_en  <= ~next_no_repeat & next_no_reset;
        end
      end
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// noise generator
/////////////////////////////////////////////////////////////////////////////
reg [16:0] shift_n;
reg [4:0] cnt_n;
wire cn_load = (cnt_n==0);
always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    shift_n <= 17'b0000000000000001;
    cnt_n   <= 0;
  end else if(clken && phase0)
  begin
    cnt_n <= cn_load ? period_n : (cnt_n-1);
    if(cn_load)
      shift_n <= {shift_n[0]^shift_n[3],shift_n[16:1]};
  end
end

wire out_n = shift_n[0];

/////////////////////////////////////////////////////////////////////////////
// volume value to 3db linear conversion
/////////////////////////////////////////////////////////////////////////////
function [7:0] vol_tbl;
input [3:0] vol;
begin
  if(vol[0]) vol_tbl = 255>>~vol[3:1]; //  0db,-6db,-12db,-18db,...-42db
  else       vol_tbl = 180>>~vol[3:1]; // -3db,-9db,-15db,-21db,...-45db
end
endfunction

/////////////////////////////////////////////////////////////////////////////
// output
/////////////////////////////////////////////////////////////////////////////

wire out_ma = (out_a | ena) & (out_n | na);
wire out_mb = (out_b | enb) & (out_n | nb);
wire out_mc = (out_c | enc) & (out_n | nc);

`ifdef AY_SLICE_OUT
wire [5:0] sw_vol_abc = pris[1] ? {out_mc,vol_c} : pris[0] ? {out_mb,vol_b} : {out_ma,vol_a};
wire [4:0] vol_mux    = sw_vol_abc[5] ? 4'b0000 : sw_vol_abc[4] ? vol_e : sw_vol_abc[3:0];
wire [7:0] vol_linear = vol_tbl(vol_mux);

reg [7:0] A,B,C;
always @(posedge clk)
begin
  if(clken)
  begin
    if(phase0)  A <= vol_linear;
    if(pris[0]) B <= vol_linear;
    if(pris[1]) C <= vol_linear;
  end
end
`else
assign A = vol_tbl(~out_ma ? 4'h0 : vol_a[4] ? vol_e : vol_a[3:0] );
assign B = vol_tbl(~out_mb ? 4'h0 : vol_b[4] ? vol_e : vol_b[3:0] );
assign C = vol_tbl(~out_mc ? 4'h0 : vol_c[4] ? vol_e : vol_c[3:0] );
`endif
assign pa_o = pa_r;
assign pb_o = pb_r;
assign pa_t = ~pa_od;
assign pb_t = ~pb_od;

endmodule
