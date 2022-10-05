//
// Z80 Compatible Bus wrapper for fz80 ver.0.52
//
// Version 1.03a
//
// Copyright (c) 2004 Tatsuyuki Sato
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation 
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included 
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

/*
note:

  It should be necessary to set "`define M1" inf fz80.
  ---------------------------------------------------

  -----------------------------
  non-compatible spesification.
  -----------------------------

  1.no internal cycle
	A internal cycle without bus cycle doesn't exist. 
	So some instruction is faster than Z80.

  2.ealy tristate after reset
	The "at" and "dt" assert after 1cycle from reset.
	The Z80 is after 2cycles from reset.

  3.busreq/busack timming are not checked yet.

  4.halt always output 1(no supported).

  -------------
  state changes
  -------------
+------+---+---+---+---+---+---+
|state |t1w|t1 |t2w|t2 |t3 |t4 |
+------+---+---+---+---+---+---+
| M1   | - | O | - | O*| O | O |
| MEM  | - | O | - | O*| x | O |
| IO   | - | O | - | O*| x | O |
| SpM1 | O | O | O | O | O | O |
+------+---+---+---+---+---+---+
 *:sense wait (wait cycle)
 *:stay t4 during busack cycle.

histry:
  2005. 4.22 ver.1.03
			   bugfix illigal tstate and rfsh in BUSACK cycle.
			   remove `MREQ_INSIDE_RD switch.

  2004. 9.16 ver.0.52a
			   bugfix power on reset error.
			   halt_n output always 1 (do not supported yet)
			   change `MREQ_INSIDE_RD logic.

  2004. 9.10 ver.0.52
			   added power on reset
			   bugfix mreq inside rd mode
  2004. 9. 9 ver.0.51
			   1st test version
*/

//`define FZ80C_NGC_LINK	 // xilinx XST link synthesized fz80c.v
`define DEBUG_OUTPUT

// ----- design option -----
//`define FZ80C_POWER_ON_RESET // power on self reset
//`define DISABLE_REFRESH_CYCLE // no refresh cycle & inst code fetch t4 fall
//`define NMI_SYNC_SENSE	 // nmi fall sense with clk
//`define DO_VAL_IF_DT 8'h00 // "do" set fixed value when output disable

module fz80c (/*AUTOARG*/
  // Inputs
  reset_n, clk, wait_n, int_n, nmi_n, busrq_n, di,
  // Outputs
  m1_n, mreq_n, iorq_n, rd_n, wr_n, rfsh_n, halt_n, busak_n,
`ifdef DEBUG_OUTPUT
  ts,
  wait_window,
`endif
  A, At,
  do,dt
);

input reset_n,clk;
input wait_n , busrq_n; 
input int_n,nmi_n; 
input [7:0] di;

output	m1_n; 
output	mreq_n; 
output	iorq_n; 
output	rd_n; 
output	wr_n; 
output	rfsh_n; 
output	halt_n; 
output	busak_n;   // (enable controll : mreq_n,iorq_n,rd_n,wr_n,rfsh_n)
output [15:0] A;   // Address Bus
output [7:0]  do;  // Data Bus
output dt;		   // tristate controll : do
output At;		   // tristate controll : A

`ifdef DEBUG_OUTPUT
output [3:0] ts;
output wait_window;
`endif

`ifndef FZ80C_NGC_LINK

// internal register
reg [15:0] adr_r;
reg [15:0] radr_r;
`ifndef DISABLE_REFRESH_CYCLE
reg [7:0] dinst_r;
`endif
reg [7:0] do_r;
reg [3:0] ts;
reg reset_s;
reg m1_r;
`ifndef DISABLE_REFRESH_CYCLE
reg rfsh_r;
`else
wire rfsh_r = 1'b1;
`endif
reg mreq_r;
reg iorq_r;
reg wr_r;
reg rd_r;
reg wait_r;
reg dt_r,dt_t4;
reg busack_n_r;
reg busreq_r;
reg busreq_r2;

//reg halt_r;

`ifdef NMI_SYNC_SENSE
reg nmi_r1,nmi_r2;
`endif

// auto wait
reg tw1,tw2;

// gate signal base
//reg t1l;
reg t3l;
reg t04l;

`ifdef FZ80C_POWER_ON_RESET
reg por_n  = 0;
reg por2_n = 0;
`endif

//////////////////////////////////////////////////////////////
// FZ80 
//////////////////////////////////////////////////////////////
wire start;
wire mreq;
wire iorq;
wire rd;
wire wr;
wire waitreq;
reg intreq;
reg nmireq;
wire m1;
`ifdef DISABLE_REFRESH_CYCLE
wire [7:0] data_in = di;
`else
wire [7:0] data_in = ~rfsh_n ? dinst_r : di;
`endif
wire [7:0] data_out;
wire [15:0] adr ,radr;
wire nmiack;
//wire halt;

// mreq,iorq inside in rd_wr
//wire req_mask = 

fz80 fz80(
  .data_in(data_in),
  .reset_in(reset_s),
  .clk(~clk),
  .adr(adr),
  .intreq(intreq),
  .nmireq(nmireq),
  .busreq(1'b0),
  .start(start),
  .mreq(mreq),
  .iorq(iorq),
  .rd(rd),
  .wr(wr),
  .data_out(data_out),
  .busack_out(),
  .intack_out(),
  .mr(),

  .m1(m1),
//	.halt(halt),
  .radr(radr),
  .nmiack_out(nmiack),
  .waitreq(waitreq)
);

///////////////////////////////////////////////////////
// wires
///////////////////////////////////////////////////////

// state value (posedge)
wire t0 = ts[3:0]==0;		// t0 : reset cycle
wire t1 = ts[0];			// t1 : spM1 = t1&t2
wire t2 = ts[1];			// t2 : spM1 = tw(1,2)
wire t3 = ts[2];			// M1.t3
wire t4 = ts[3];			// M1.t4 or MEM/IO.t3

wire t04  = ~t1 & ~t2 & ~t3; // T0 or T4

// event value
wire next_t1 = (t1&tw1) | (t04 & ~busreq_r);		// t1
wire next_t2 = (t2& ~wait_r) | (t1&~tw1);			// t2
wire next_t3 = (t2& wait_r& m1);					// t3
wire next_t4 = (t2& wait_r&~m1) | t3;				// t4

`ifdef DEBUG_OUTPUT
// wait input window
assign wait_window = t2 & ~wait_r;
`endif


// RFSH assert timming
`ifdef DISABLE_REFRESH_CYCLE
wire nxt_rfsh = 1'b0;
`else
wire nxt_rfsh = (m1&t2&wait_r)|t3; // T3 and T4
`endif



///////////////////////////////////////////////////////
// NMI eddge sense
///////////////////////////////////////////////////////

`ifndef NMI_SYNC_SENSE
wire nmi_clr = nmiack | reset_s;
always @(negedge nmi_n or posedge nmi_clr)
begin
  if(nmi_clr) nmireq <= #1 1'b0;
  else		  nmireq <= #1 1'b1;
end
`endif

///////////////////////////////////////////////////////
// Timming state controll
///////////////////////////////////////////////////////

`ifdef FZ80C_POWER_ON_RESET
always @(negedge clk)
begin
  por_n  <= #1 por2_n;
  por2_n <= #1 1'b1;
end
// with por
always @(negedge clk or negedge por_n)
  if(~por_n) reset_s <= #1 1'b1;
  else		 reset_s <= #1 ~reset_n;
`else
// without por
always @(negedge clk) reset_s <= #1 ~reset_n;
`endif

always @(posedge clk)
begin
  if (reset_s)
  begin
`ifndef DISABLE_REFRESH_CYCLE
	dinst_r  <= #1 8'h00;
`endif
	ts		 <= #1 4'b0000; // reset cycle;
	adr_r	 <= #1 16'h0000;
	intreq	 <= #1 1'b0;
`ifdef NMI_SYNC_SENSE
	nmireq	 <= #1 1'b0;
	nmi_r2	 <= #1 1'b0;
	nmi_r1	 <= #1 1'b0;
`endif
	tw1 	 <= #1 1'b0;
	tw2 	 <= #1 1'b0;
	dt_t4	 <= #1 1'b1;
	busreq_r <= #1 1'b0;
	iorq_r <= #1 1'b1;
	rd_r   <= #1 1'b1;

//	  halt_r <= #1 1'b1;
  end else begin
	// T1(M1),T2,T4(IO) on , T1(IO),T3,T4(M1) off
	iorq_r <= #1 ~iorq | t04 | tw1 | nxt_rfsh;

	// T1(MEM),T2,T4(MEM) on,T1(IO),T3,T4(M1) off
	rd_r <= #1 ~rd | (iorq&t04) | nxt_rfsh;

	// timming state controll
	ts[0] <= #1 next_t1;
	ts[1] <= #1 next_t2;
	ts[2] <= #1 next_t3;
	ts[3] <= #1 next_t4;

	// auto wait state
	tw1 <= #1 ~t1 & (m1&iorq); //  TW for SpecialM1
	tw2 <= #1 t1 & iorq;	   //  TW for IO and SpecialM1

	// address / refresh address
	adr_r  <= adr;

	// IRQ (T4 raise)
	intreq <= #1 ~int_n;

	// NMI eddge sense
`ifdef NMI_SYNC_SENSE
	nmi_r2 <= #1 nmi_r1;
	nmi_r1 <= #1 ~nmi_n;
	if(nmiack)				  nmireq <= #1 1'b0;
	else if(~nmi_r2 & nmi_r1) nmireq <= #1 1'b1;
`endif

`ifndef DISABLE_REFRESH_CYCLE
	// Opcode Latch = T3 raise
	if(t2) dinst_r <= #1 di;
`endif

	// data outpot tristate , HOLD half clock in T4
	dt_t4 <= #1 dt_r;

	// busreq / busack & Address tristate
	if(next_t4 | t0)
	  busreq_r <= #1 ~busrq_n;

	// halt fetch
//	  if(m1&t4) halt_r <= #1 ~halt;

  end
end

// clk fall event
always @(negedge clk)
begin
  if (reset_s)
  begin
//	  t1l	 <= #1 1'b0;
	t3l    <= #1 1'b0;
	t04l   <= #1 1'b1;
	wait_r <= #1 1'b1;
	dt_r   <= #1 1'b1;
	do_r   <= #1 8'h00;
	radr_r	 <= #1 16'h0000;
	busreq_r2<= #1 1'b0;
  end else begin
	// gate controll
//	  t1l  <= #1 t1;
	t3l  <= #1 t3;

	// t4l-t0l | specialM1.t1l
	t04l <= #1 t04 | (t1&m1&iorq);

	// DataOutput
	do_r <= #1 data_out;

	// wait sense (T2 raise)
	wait_r <= #1 (wait_n | (m1&iorq)) & ~tw2;

	// data bus enable , T1,T2 on , T4 off
	dt_r <= #1 ~wr | t04;

	// refresh address (t4 glidge)
	radr_r <= radr;

	busreq_r2<= #1 busreq_r;

  end
end

/////////////////////////////////////////////////////////////////////////////
// both edge signals
/////////////////////////////////////////////////////////////////////////////

//	M1 finish clear signal
reg m1_fin;
wire m1_fin_clr = m1_n & rd_n & iorq_n; //	!!!!! GATE FEEDBACK PULSE !!!!!

always @(posedge clk or posedge m1_fin_clr)
begin
  if (m1_fin_clr)
  begin
	m1_fin <= #1 1'b0;
  end else begin
	if (reset_s)
	  m1_fin <= #1 1'b0;
	else if(next_t3)
	  m1_fin <= #1 1'b1;
  end
end

// m1_n
//	clr m1.t1.raise
//	set m1.t3.raise
always @(negedge clk or posedge m1_fin)
begin
  if (m1_fin)
  begin
	m1_r <= #1 1'b1;
  end else begin
	if (reset_s)
	  m1_r <= #1 1'b1;
	else if(t1)
	  m1_r <= #1 ~m1;
  end
end

// wr_n
//	clr memwr.t2.fall
//	clr iowr .t2.raise
//	set 	  t4.fall
wire wr_async_clr = iorq & wr & t2;
always @(negedge clk or posedge wr_async_clr)
begin
  if (wr_async_clr)
  begin
	wr_r <= #1 1'b0;
  end else begin
	if (reset_s | t4)
	  wr_r <= #1 1'b1;
	else if(mreq & wr & t2)
	  wr_r <= #1 1'b0;
  end
end

// mreq
// +------+-------+-------+
// |cycle |  clr  |  set  |
// +------+-------+-------+
// | m1rd |T1.F   |T3.R(*)|
// +------+-------+-------+
// | m1rf |T3.F   |T4.F   |
// +------+-------+-------+
// | mem  |T1.F   |T4.F   |
// +------+-------+-------+
always @(negedge clk or posedge m1_fin)
begin
  if (m1_fin)
  begin
	mreq_r <= #1 1'b1;
  end else begin
	if (reset_s | t4)
	  mreq_r <= #1 1'b1;
	else if(t1 | t3)
	  mreq_r <= #1 ~mreq;
  end
end

//	rfsh_n
`ifndef DISABLE_REFRESH_CYCLE
wire rfsh_set = t1 | ~busak_n;
always @(negedge m1_fin or posedge rfsh_set)
begin
  if (rfsh_set)
  begin
	rfsh_r <= #1 1'b1;
  end else begin
	if (reset_s)
	  rfsh_r <= #1 1'b1;
	else
	  rfsh_r <= #1 1'b0;
  end
end
`endif

// rd_n
// +------+-------+-------+
// |cycle |  clr  |  set  |
// +------+-------+-------+
// | m1rd |T1.F   |T3.R(*)|
// +------+-------+-------+
// | mrd  |T1.F   |T4.F   |
// +------+-------+-------+
// | iord |T2.R(*)|T3.F   |
// +------+-------+-------+


// iorq
//	clr spm1 .tw.fall
//	set spm1 .t3.raise (*)
//	clr io	 .t2.raise (*)
//	set io	 .t4.fall

// busak
always @(posedge clk or negedge busreq_r2)
begin
  if (~busreq_r2)	   busack_n_r <= #1 1'b1;
  else begin
	if(reset_s) 	   busack_n_r <= #1 1'b1;
	else if(busreq_r2) busack_n_r <= #1 1'b0;
  end
end

/////////////////////////////////////////////////////////////////////////////
// fz80 input
/////////////////////////////////////////////////////////////////////////////
assign waitreq = ~t4;

/////////////////////////////////////////////////////////////////////////////
// output signal
/////////////////////////////////////////////////////////////////////////////

reg rd_hold_n;
always @(posedge clk or posedge mreq_n)
begin
  if(mreq_n) rd_hold_n <= #1 1'b1;
  else		 rd_hold_n <= #1 mreq_n | rd_n;
end

//`else
//wire rd_hold_n = 1;
//`endif

assign A	   = rfsh_n ? adr_r : radr_r;
assign m1_n    = m1_r;
assign rfsh_n  = rfsh_r;
assign mreq_n  = mreq_r;

assign iorq_n  = iorq_r | t04l;
assign rd_n    = (rd_r	| t04l) & rd_hold_n;
assign wr_n    = wr_r;
assign dt	   = dt_r & dt_t4;
assign busak_n = busack_n_r;

`ifdef DO_VAL_IF_DT
assign do = dt ? `DO_VAL_IF_DT : do_r;
`else
assign do = do_r;
`endif

//assign halt_n = halt_r;
assign halt_n = 1'b1;

`endif // FZ80C_USER_NGC_LINK

endmodule
