/////////////////////////////////////////////////////////////////////////////
//
// AY-3-8910 Programable Sound Generator
//
// Version : 0.95
//
// Copyright(c) 2004-2008 Tatsuyuki Satoh , All rights reserved
//
// License:
//   This source is under the GPL license.
//
// Histry:
//   2009. 1.20 both support indirect and direct access
//   2008.10.16 ver.0.96 fix envelope period 0 == 1
//   2008.10. 8 ver.0.95 fix envelope pattern ,fix tone period 0 == 1
//   2008. 9.xx ver.0.94 Mimimize (envelope buggy)
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

`define SUPPORT_IOPORT
`define SUPPORT_READ_REG

module ay8910(
  rst_n,clk,clken,asel,cs_n,wr_n,rd_n,
  direct_sel,
  A,B,C,
`ifdef SUPPORT_IOPORT
  pa_i,pb_i,pa_o,pa_t,pb_o,pb_t,
`endif
  di,do);

parameter DIRECT_ACCESS = 0;

input rst_n;
input clk;
input clken;
input asel;
input cs_n;
//
input [3:0] direct_sel;
//
input wr_n;
input rd_n;
input [7:0] di;
output [7:0] do;
output [9:0] A,B,C; // 10bit sound output
`ifdef SUPPORT_IOPORT
input [7:0] pa_i,pb_i;
output [7:0] pa_o,pb_o;
output pa_t,pb_t;
`endif

/////////////////////////////////////////////////////////////////////////////
// ASYNC Access
/////////////////////////////////////////////////////////////////////////////

reg  [3:0] waddr;
wire [3:0] raddr = DIRECT_ACCESS ? direct_sel : waddr;

// write data sync
reg [7:0] wdata;
reg wflip;

always @(posedge wr_n or negedge rst_n)
begin
  if(~rst_n)
  begin
    wdata <= 8'h00;
    wflip <= 1'b0;
  end else if(~cs_n)
  begin
      // address write
      if(DIRECT_ACCESS)
      begin
        waddr <= direct_sel;
        wdata <= di;
        wflip <= ~wflip;
      end else begin
        if(asel)
        begin
          waddr <= di[3:0];
        end else begin
          wdata <= di;
          wflip <= ~wflip;
        end
      end
  end
end

/////////////////////////////////////////////////////////////////////////////
// Write Register
/////////////////////////////////////////////////////////////////////////////

reg [2:0] cycle;
wire phase_t0 = (cycle==0);
wire phase_t1 = (cycle==1);
wire phase_t2 = (cycle==2);
wire phase_n  = (cycle==3);
wire phase_e  = (cycle==4);

// period registers
reg [7:0]  regsL[3:0];
reg [3:0]  regsH[3:0];
wire [1:0] regs_wa = waddr[2:1];
wire [1:0] regs_ra = cycle[1:0];

wire regl_we = (~waddr[3] && ~waddr[0]);
wire regh_we = (~waddr[3] &&  waddr[0]);

//reg [11:0] period_a,period_b,period_c;
//reg [4:0] period_n;
reg [7:0] reg_en;
reg [4:0] vol_a,vol_b,vol_c;
reg [15:0] period_e;
reg [3:0] shape_e;

`ifdef SUPPORT_IOPORT
reg [7:0] pa_r,pb_r;
`endif

wire ta_en = reg_en[0];
wire tb_en = reg_en[1];
wire tc_en = reg_en[2];
wire na_en = reg_en[3];
wire nb_en = reg_en[4];
wire nc_en = reg_en[5];
`ifdef SUPPORT_IOPORT
wire pa_od = reg_en[6];
wire pb_od = reg_en[7];
`endif

// Write Access Sense
reg [1:0] wflip_s;
wire wack = wflip_s[1]!=wflip_s[0];

// envelope restart trigger
wire env_req = wack && (waddr==4'hd);

always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    wflip_s <= 2'b00;

//    period_a <= 12'h000;
//    period_b <= 12'h000;
//    period_c <= 12'h000;
//    period_n <= 5'h00;
    reg_en   <= 8'b00111111;
    vol_a    <= 5'h00;
    vol_b    <= 5'h00;
    vol_c    <= 5'h00;
    period_e <= 16'h0000;
    shape_e  <= 4'h0;
`ifdef SUPPORT_IOPORT
    pa_r     <= 8'hff;
    pb_r     <= 8'hff;
`endif
  end else begin
    // sense write access
    wflip_s <= {wflip_s[0],wflip};
    if(wack)
    begin
      if(regl_we) regsL[regs_wa] <= wdata;
      if(regh_we) regsH[regs_wa] <= wdata[3:0];

      // register write
      case(waddr)
//       0:period_a[ 7:0] <= wdata;
//       1:period_a[11:8] <= wdata[3:0];
//       2:period_b[ 7:0] <= wdata;
//       3:period_b[11:8] <= wdata[3:0];
//       4:period_c[ 7:0] <= wdata;
//       5:period_c[11:8] <= wdata[3:0];
//       6:period_n[ 4:0] <= wdata[4:0];
       7:reg_en         <= wdata;
       8:vol_a          <= wdata[4:0];
       9:vol_b          <= wdata[4:0];
      10:vol_c          <= wdata[4:0];
      11:period_e[7:0]  <= wdata;
      12:period_e[15:8] <= wdata;
      13:shape_e        <= wdata[3:0];
`ifdef SUPPORT_IOPORT
      14:pa_r        <= wdata;
      15:pb_r        <= wdata;
`endif
      endcase
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// Read Register
/////////////////////////////////////////////////////////////////////////////
`ifdef SUPPORT_READ_REG

assign do = (cs_n|rd_n) ? 8'h00:       // no read
            raddr==4'h7 ? reg_en         :
            raddr==4'h8 ? {3'h0,vol_a}   :
            raddr==4'h9 ? {3'h0,vol_b}   :
            raddr==4'ha ? {3'h0,vol_c}   :
            raddr==4'hb ? period_e[7:0]  :
            raddr==4'hc ? period_e[15:8] :
            raddr==4'hd ? {4'h0,shape_e} :
`ifdef SUPPORT_IOPORT
            raddr==4'he ? (pa_od ? pa_o : pa_i) :
            raddr==4'hf ? (pb_od ? pb_o : pb_i) :
`endif
            // 12bit pair reg.
            regh_we     ? {4'h0,regsH[regs_wa]} :
            regsL[regs_wa];
`else
assign do = 8'h00;
`endif

/////////////////////////////////////////////////////////////////////////////
// clock & phase
/////////////////////////////////////////////////////////////////////////////

always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    cycle <= 0;
  end else if(clken) begin
    cycle <= cycle + 1;
  end
end

/////////////////////////////////////////////////////////////////////////////
// PSG
/////////////////////////////////////////////////////////////////////////////

// 12bit period register
wire [11:0] periodt  = {regsH[regs_ra],regsL[regs_ra]};
wire [11:0] periodn  = {7'b0000000,periodt[4:0]}; // mask for noize freq
wire [11:0] period12 = phase_n ? periodn : periodt;

// increment condition
wire [11:0] is_inc   = 1'b1;

//
// toneA 12bit | 12bit
// toneB 12bit | 12bit
// toneC 12bit | 12bit
// noisze 5bit
// env   15bit | 15bit
//

// period 0 -> 1
// period 1 -> 1
// period 2 -> 2
// period 3 -> 3
reg [11:0] cnt_ram[3:0];
wire [11:0] cnt = cnt_ram[regs_ra];
wire cnt_load = (cnt[11:1]==11'h7ff); // cnt >= 12'hffe

reg out_a,out_b,out_c;

// noize ring
reg  [16:0] noize_ring;
wire [16:0] noize_ring_next = {noize_ring[0]^noize_ring[3],noize_ring[16:1]};
wire out_n = noize_ring[0];

always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    out_a <= #1 0;
    out_b <= #1 0;
    out_c <= #1 0;
    noize_ring <= 17'b0000000000000001;
  end else if(clken) begin
    // count down with reload
    if(phase_t0 | phase_t1 | phase_t2 | phase_n)
    begin
      cnt_ram[regs_ra] <= #1 cnt_load ? ~period12 : (cnt_ram[regs_ra]+1);
  //    if(cnt_load)
//      out[cnta] <= ~out[cnta];
    end

    // flip output
    if(phase_t0 && cnt_load) out_a     <= #1 ~out_a;
    if(phase_t1 && cnt_load) out_b     <= #1 ~out_b;
    if(phase_t2 && cnt_load) out_c     <= #1 ~out_c;
    if(phase_n  && cnt_load)noize_ring <= #1 noize_ring_next;
  end
end

/////////////////////////////////////////////////////////////////////////////
// envelope generator
/////////////////////////////////////////////////////////////////////////////
/*
bit3 = turn reset , 0=on , 1=off
bit2 = start , 0=up , 1=down(inv)
bit1 = turn invert, 0=tggle , 1=fix
bit0 = turn repeat, 0=off, 1=on

No.          pattern
  8          DDDD
  0,1,2,3,9  DLLL
  10         DUDU
  11         DHHH
  12         UUUU
  13         UHHH
  14         UDUD
  4,5,6,7,15 ULLL

  D = 15 ->  0
  U =  0 -> 15
  H = hold  15
  L = hold   0
*/
reg [15:0] env_cnt;
reg [3:0] env_phase;
reg env_en;
reg env_inv;
reg env_trg;

// bit3 = turn reset , 0=on , 1=off
// bit2 = start , 0=up , 1=down(inv)
// bit1 = turn invert, 0=tggle , 1=fix
// bit0 = turn repeat, 0=off, 1=on

wire env_continue = shape_e[3]; // CONTINUE (~zero after turn)
wire env_attack   = shape_e[2]; // ATTACK   (0=fall 1st,1=raise 1st)
wire env_altanate = shape_e[1]; // ALTANATE (flip U/D)
wire env_hold     = shape_e[0]; // HOLD     (stop countup)

// envelope volume output
//wire [3:0] vol_e = env_inv ? ~env_phase : env_phase;
wire [3:0] vol_e = env_inv ? env_phase : ~env_phase;

wire ec_load = (env_cnt==16'hffff);

always @(posedge clk or negedge rst_n)
begin
  if(~rst_n)
  begin
    env_en    <= 1'b0;
    env_trg   <= 1'b0;
  end else begin
    // reserve envelope reset trigger
    if(env_req) env_trg <= 1'b1;

    if(clken && phase_e)
    begin
      if(env_trg)
      begin
        env_trg   <= 1'b0;

        env_cnt   <= ~period_e;
        env_phase <= 4'h0; // 4'hf;
        env_inv   <= env_attack;
        env_en    <= 1'b1;
      end else begin
        // phase up
        env_cnt   <= (ec_load ? ~period_e : env_cnt) +1;
        if(ec_load & env_en)
        begin
//          env_phase <= env_phase - 1;
//          if(env_phase==0)
          env_phase <= env_phase + 1;
          if(env_phase==15)
          begin
            // turn over
            env_inv <= (env_inv^env_altanate) & env_continue;

            if(env_hold || ~env_continue)
            begin
//              env_phase <= 4'h0;
              env_phase <= 4'hf;
              env_en    <= 1'b0;
            end
          end
        end
      end
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// -3db volume step to linear conversion
// 0dB:-3dB == 1.0:0.707946 == 7:5
/////////////////////////////////////////////////////////////////////////////
function [9:0] vol_tbl;
input [3:0] vol;
// val 7(111) ==  0db(15),-6db(13),-12db(11),...-36dB(3),-42db(1)
// val 5(101) == -3db(14),-9db(12),-15db(10),...-39dB(2)
// val 0(000) == mute(0)
begin
  vol_tbl  = {7'h00,(vol!=0),vol[0],(vol!=0)} << vol[3:1];
end
endfunction

/////////////////////////////////////////////////////////////////////////////
// output
/////////////////////////////////////////////////////////////////////////////

wire out_ma = (out_a | ta_en) & (out_n | na_en);
wire out_mb = (out_b | tb_en) & (out_n | nb_en);
wire out_mc = (out_c | tc_en) & (out_n | nc_en);

assign A = vol_tbl(~out_ma ? 4'h0 : vol_a[4] ? vol_e : vol_a[3:0] );
assign B = vol_tbl(~out_mb ? 4'h0 : vol_b[4] ? vol_e : vol_b[3:0] );
assign C = vol_tbl(~out_mc ? 4'h0 : vol_c[4] ? vol_e : vol_c[3:0] );

`ifdef SUPPORT_IOPORT
assign pa_o = pa_r;
assign pb_o = pb_r;
assign pa_t = ~pa_od;
assign pb_t = ~pb_od;
`endif

endmodule
