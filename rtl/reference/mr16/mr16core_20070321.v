//
// mr16core.v - minimal RISC 16bit CPU , develop beta2 2007.3.21
//
// Copyright(C) 2005,2007 Tatsuyuki Satoh
//
// WARNING! This code is provided for free on an as is basis. There are
// no promises, warranties, guaranties etc. of any kind. Use it at your
// own risk.
//
// histry:
//	 2007. 3.21 bugfix condtion code logic LT/GE , LE/GT
//	 2007. 3.19 support BYTE ACCESS mode (not tseted yet)
//	 2007. 3. 6 rename all I/F name,reset to SYNC signal,added InterruptRequest
//	 2007. 1.26 change reset signale selectable ASYNC or SYNC
//	 2007. 1.19 JSR buffix , JSR #xFFx can't execute.  (LDM_PC,LDM_FLG,LDM_REG)
//	 2005. 4.12 1st develop version
//
// note:
//	Do not test ENABLE_BYTE_ACCESS yet
//

/////////////////////////////////////////////////////////////////////////////
// archtecture option selector
/////////////////////////////////////////////////////////////////////////////

// ---- select reset type -----
//`define RESET_ASYNC

// ---- select MuLTiplex or SHIFT unit -----

`define ENABLE_MLT	 // enable MLT unit and disable right SHIFT unit
`define ENABLE_MLT32 // enable MLT high word (32bit result).

// ---- enable data bus selector in 8bit access ----
//`define ENABLE_BYTE_ACCESS
//`define BIG_ENDIAN

//			  speed 	 , area
// ver.070126 262/68.964 , 232/47.125


// BYTE on	: 256/74.062 , 230/48.221
// BYTE off : 268/71.499 , 226/47.125

/*
core single size

| ver    |speed         | area         | Byte,speed   | Byte,area    |
| 070129 | 261 / 67.829 | 213 / 46.405 | --- / ------ | --- / -----  |
| 070319 | 268 / 71.499 | 227 / 47.203 | 264 / 73.350 | 238 / 47.336 |
| 070321 | 268 / 71.499 | 227 / 47.203 | 264 / 73.350 | 238 / 47.336 |

condition:
  core synthesize on ISE 7.1.04i
  RESET == SYNC


| ver    |speed         | area         | Byte,speed   | Byte,area    |
| 070228 | 373 / 56.602 | ??? / ??.??? | --- / ------ | --- / -----  |
| 070306 | 387 / 58.246 | 282 / 31.443 | --- / ------ | --- / -----  |
| 070321 | 384 / 58.151 | 286 / 31.485 | 
| 070321 | 379 / 58.298 | 284 / 31.536 | 404 / 58.270 | 295 / 30.949 |reset & ivec FIX


core single size
condition:
  core synthesize on ISE 7.1.04i
  RESET == SYNC


core only size
| ver    |speed            |area             |Byte,speed   |Byte,area    |
| 070228 |???/38/475/67.829|???/34/360/46.405|
| 070317 |???/38/468/68.964|224/32/378/46.722|
| 070321 |???/36/485/71.499|???/33/380/47.203| 37/480/73.350|33/402/47.336|

note:
  core synthesize on ISE 7.1.04i
  RESET == SYNC
  result = synthesize {FlipFlop/LUT/MHz}

*/

// Flag Controll Operation (1slice per flag)
`define ENABLE_CLC_STC // CLC / STC operation
`define ENABLE_CLZ_STZ // CLZ / STZ operation

/////////////////////////////////////////////////////////////////////////////
// module entry
/////////////////////////////////////////////////////////////////////////////
module mr16core(
	Reset,Clock,ClockEnable,ResetVector,
	Address,WriteData,ReadData,
	ByteAccess,WriteEnable,
	IntReq,IntAck,IntVector,
	LoadCycle
);

/////////////////////////////////////////////////////////////////////////////
// Interface
/////////////////////////////////////////////////////////////////////////////

// grobal
input			Reset;				// ASYNC rst input
input			Clock;				// clock
input			ClockEnable;		// clock enable for wait controll
input [15:1]	ResetVector;		// Reset Vector

// memory bus
output	[15:0]	Address;			// 16bit address
output	[15:0]	WriteData;			// write data
input	[15:0]	ReadData;			// read data
output	[1:0]	WriteEnable;		// write enable
output			ByteAccess;			// 8bit access

// interrupt controll
input			IntReq;				// Interrupt Request
output			IntAck;				// Interrupt Acknowledge
input	[15:1]	IntVector;			// Interrupt Vector

output LoadCycle;

/////////////////////////////////////////////////////////////////////////////
// Registers
/////////////////////////////////////////////////////////////////////////////
reg [7:0]  reg_rl[15:0]; // 16x8bit dual port RAM
reg [7:0]  reg_rh[15:0]; // 16x8bit dual port RAM
reg [14:0] reg_pc;		 // program counter
reg [4:0]  reg_flag;	 // flag register
reg [10:0] reg_prefix;	 // iack2,mcycle flag , prefix flag + prefix value

/////////////////////////////////////////////////////////////////////////////
// generic wires
/////////////////////////////////////////////////////////////////////////////

//
wire rst = Reset;
wire clk = Clock;
wire clk_en = ClockEnable;
wire [15:0] d_bus_in = ReadData;
wire irq	= IntReq;
wire [15:0] vector_a = { IntVector[15:1],1'b0};

// memory bus
wire [15:0] d_addr;		// 16bit address
wire [15:0] d_bus_out;	// data-out

wire iack;
wire wcycle;

// gp register
wire[15:0]	reg_a_out;
wire[15:0]	reg_b_out;
wire [15:0] rs_a,rs_b;

// alu output
wire [16:0] alu_out , logical_out , arithmetic_out;
wire [3:0]	alu_flag;

// instruction code
wire [15:0] inst = d_bus_in;

// special cycle
wire pfx_op = reg_prefix[8];  // 2nd opcode
wire mc2_op = reg_prefix[9];  // 2nd memory cycle
wire iack2	= reg_prefix[10]; // IACK2 change PC

// flags
wire cflag = reg_flag[0];
wire zflag = reg_flag[1];
wire vflag = reg_flag[2];
wire nflag = reg_flag[3];
wire iflag = reg_flag[4];

/////////////////////////////////////////////////////////////////////////////
// instruction decoder
/////////////////////////////////////////////////////////////////////////////

// block separation
wire[3:0] op	   = inst[15:12];
wire op_reg 	   = (op[3:0]==4'b0011);
wire[3:0] op_mix   = op_reg ? inst[3:0] : op;

// register selector
wire [3:0] reg_a_addr = mc2_op ? reg_prefix[7:4] : inst[11:8];
wire [3:0] reg_b_addr = inst[7:4];

// stack selector
wire stack_sel		  = (inst[11:8] ==4'b1111);
wire flag_sel		  = (inst[7:4]	==4'b1111);

// instruction cycle
wire inst_cycle 	  = ~mc2_op & ~iack & ~iack2;

// Memory Access
wire OP_MEM 	   = (op[3:1] == 3'b000);
wire OP_LDM 	   = (op == 4'b0000);
wire OP_STM 	   = (op == 4'b0001);
 wire STM_FLG		= stack_sel & flag_sel; 					 //(PUSH FLAG)
 wire LDM_PC		= OP_LDM &	stack_sel			 & ~inst[0]; // RET
 wire LDM_FLG		= OP_LDM &	stack_sel & flag_sel &	inst[0]; // POP FLAG
 wire LDM_REG		= OP_LDM & ~(LDM_PC | LDM_FLG); 			 // POP  REG
wire OP_PUSH_POP   = OP_MEM 	 & stack_sel;
wire OP_POP_RET    = OP_PUSH_POP & ~op[0];
wire OP_PUSH	   = OP_PUSH_POP &	op[0];

wire OP_BCC 		= (op==4'b0010);							 // (override with JABS)
wire OP_JABS		= (op_mix[3:1] == 3'b001) & (op_reg|pfx_op); // Jcc/JSR
wire OP_CALL		= (OP_JABS & inst[0]);
 wire [3:0] cond	= inst[11:8];

wire OP_LDI 		= OP_BCC & (cond==4'b0111) & inst_cycle;
 wire[7:0] prefix_in = inst[7:0];

// FLAG set
wire OP_LOADF		 = op_reg & (inst[3:0]==4'b0000);

wire set_flag		 = ( (OP_LDM&LDM_PC) | OP_LOADF) & inst_cycle;
 wire flag_val		 = inst[4];
`ifdef ENABLE_CLC_STC
  wire OP_LOAD_CF	 = set_flag & inst[5];
`endif
`ifdef ENABLE_CLZ_STZ
  wire OP_LOAD_ZF	 = set_flag & inst[6];
`endif
  wire OP_LOAD_IF	 = set_flag & inst[7];

`ifdef ENABLE_MLT
wire OP_MLT 		  = (op_mix[3:1] == 3'b111); // multiplex
wire OP_MLTH		  = OP_MLT & op_mix[0];
`else
wire OP_SHIFT		 = op_reg & (inst[3:0]==4'b0001);
 wire sh_mod		 = inst[4];
`endif

wire OP_LOGICAL 	  = (op_mix[3:2] == 2'b01); // 
wire OP_ARITHMETIC	  = (op_mix[3:2] == 2'b10); // 10ACDDDDSSSSIIII
 wire arith_wc		   = (op_mix[1]); // 1=ADC/SBB 0=ADD/SUB
 wire arith_sub 	   = (op_mix[0]); // 1=SUB/SBB 0=ADD/ADC
wire OP_TEST		  = (op_mix[3:2] == 2'b11);
// wire OP_TST			 = (op_mix == 4'b1100);  // AND no reg load
 wire OP_CMP		   = (op_mix == 4'b1101);  // SUB no reg load

/////////////////////////////////////////////////////////////////////////////
// subfunctions
/////////////////////////////////////////////////////////////////////////////

// memory cycle
wire mem_cycle = ((OP_CALL | OP_MEM) & inst_cycle) | iack | iack2;

// memory prefix
wire mem_w8 	   = reg_prefix[7];
wire [10:0] disp11 = {reg_prefix[5:0],inst[3:0],reg_prefix[6]};
wire [15:0] disp16 = { {5{disp11[10]}},disp11};

// memory write byte select
wire byte_sel = arithmetic_out[0];

/////////////////////////////////////////////////////////////////////////////
// input data byte size multiplex
/////////////////////////////////////////////////////////////////////////////
wire [7:0] reg_al_in , reg_ah_in;

wire load_even = reg_prefix[3];
wire load_odd  = reg_prefix[2];

`ifdef BIG_ENDIAN
wire load_lb = ( load_even | load_odd);
wire load_hb = ( load_even & load_odd);
wire bswap2  = ( load_even &~load_odd) & mc2_op;
`else
wire load_lb = ( load_even | load_odd);
wire load_hb = ( load_even & load_odd);
wire bswap2  = (~load_even & load_odd) & mc2_op;
`endif

// BUS swap 8bit read data
`ifdef ENABLE_BYTE_ACCESS

mux_2 #(8) reg_al_in_mux(
  .I0(alu_out[ 7:0]), // normal
  .I1(alu_out[15:8]), // high word -> low wod
  .S(bswap2),.O(reg_al_in)
);
`else
assign reg_al_in = alu_out[ 7:0]; // low byte -> through
`endif
assign reg_ah_in = alu_out[15:8]; // high byte -> through

// memory read latch state
wire mc2_load_regl = mc2_op & load_lb;
wire mc2_load_regh = mc2_op & load_hb;
wire mc2_load_flag = mc2_op & reg_prefix[1];
wire mc2_load_pc   = mc2_op & reg_prefix[0];

/////////////////////////////////////////////////////////////////////////////
// Generic Register
/////////////////////////////////////////////////////////////////////////////
`ifdef ENABLE_MLT
wire reg_a_load  = (OP_CALL | OP_PUSH_POP | OP_LOGICAL | OP_ARITHMETIC | OP_MLT) & inst_cycle;
`else
wire reg_a_load  = ((OP_LOGICAL | OP_ARITHMETIC | OP_SHIFT) & inst_cycle) | stack_load;
`endif

wire reg_al_load = (reg_a_load | mc2_load_regl) & clk_en;
wire reg_ah_load = (reg_a_load | mc2_load_regh) & clk_en;

// Generic Register (16bit x 16 dual port RAM)
always @ (posedge clk)
  if (reg_al_load) reg_rl[reg_a_addr] <= reg_al_in;
wire [7:0] reg_al_out = reg_rl[reg_a_addr];
wire [7:0] reg_bl_out = reg_rl[reg_b_addr];

always @ (posedge clk)
  if (reg_ah_load) reg_rh[reg_a_addr] <= reg_ah_in;
wire [7:0] reg_ah_out = reg_rh[reg_a_addr];
wire [7:0] reg_bh_out = reg_rh[reg_b_addr];
  
assign reg_a_out = {reg_ah_out,reg_al_out};
assign reg_b_out = {reg_bh_out,reg_bl_out};

/////////////////////////////////////////////////////////////////////////////
// prefix register & cycle state
/////////////////////////////////////////////////////////////////////////////

`ifdef RESET_ASYNC
always @ (posedge clk or posedge rst)
`else
always @ (posedge clk)
`endif
begin
	if(rst)
	begin
		reg_prefix	  <= 11'b111_0000_0001;
	end else if(clk_en)
	begin
		// grobal state
		reg_prefix[10] <= iack;
		reg_prefix[9]  <= mem_cycle;
		reg_prefix[8]  <= OP_LDI;
		if(mem_cycle)
		begin
			// state for 2nd MemoryReadCycle
			reg_prefix[7:4] <= iack ? 4'b1111 : prefix_in[7:4];			// dst reg
// 16bit	  : 11
//	8bit EVEN : 01
//	8bit ODD  : 10
			reg_prefix[3]	<=(LDM_REG & inst_cycle & (~mem_w8|  byte_sel)) | iack; // reg ODD	load
			reg_prefix[2]	<=(LDM_REG & inst_cycle & (~mem_w8| ~byte_sel)) | iack; // reg EVEN load
			reg_prefix[1]	<=(LDM_FLG & inst_cycle); 				  // flag
			reg_prefix[0]	<=(LDM_PC  & inst_cycle)			 | iack;  // pc
		end else if(OP_LDI)
		begin
			// prefix immidate
			reg_prefix[7:0] <= prefix_in;
		end else begin
			// clear prefix
			reg_prefix[7:0] <= 8'h00;
		end
	end
end

/////////////////////////////////////////////////////////////////////////////
// ALU input selector
/////////////////////////////////////////////////////////////////////////////
assign rs_a = reg_a_out;

mux_2 #(16) rs_b_mux(
  .I0({reg_prefix[7:0],inst[7:0]}), // immidate
  .I1(reg_b_out),					// RB
  .S(op_reg),.O(rs_b));

/////////////////////////////////////////////////////////////////////////////
// Condition Controll
/////////////////////////////////////////////////////////////////////////////
wire cc_true;

function cc_table;
input [2:0] sel;
input nf,vf,zf,cf;
begin
  case(sel)
  3'b000: cc_table = cf;			 // LO / HS
  3'b001: cc_table = zf;			 // EQ / NE
  3'b010: cc_table = vf;			 // VS / VC
  3'b011: cc_table = nf;			 // MI / PL
  3'b100: cc_table = zf | cf; 		 // LS / HI
  3'b101: cc_table = (nf^vf);		 // LT / GE
  3'b110: cc_table = (nf^vf) | zf;	 // LE / GT
  3'b111: cc_table = 1'b0;
  endcase
end
endfunction

assign cc_true = cc_table(cond[2:0],nflag,vflag,zflag,cflag) ^ cond[3];

/////////////////////////////////////////////////////////////////////////////
// Program counter Controll
/////////////////////////////////////////////////////////////////////////////

wire [14:0] next_pc , rel_pc , inc_pc;

`ifdef MINIMIZE_2SLICE_SLOW_2NS
wire rel_sel = OP_BCC & ~pfx_op & inst_cycle & cc_true;
//wire rel_sel = OP_BCC & inst_cycle & cc_true;
mux_2 #(15) rel_pc_sel(
  .I0({14'h0000,inst_cycle}),	  // IACK / IACK2 / MEM CYCLE2==0 : inst / preload==1
  .I1({ {7{inst[7]}},inst[7:0]}), // BCC -256..+254 (ignore JABS) / MEM CYCLE2
  .S(rel_sel),.O(rel_pc));
assign inc_pc = reg_pc + rel_pc;
`else
//wire [1:0] rel_sel = {~inst_cycle,OP_BCC & cc_true};
wire [1:0] rel_sel = {~inst_cycle,OP_BCC & ~pfx_op & cc_true};
mux_3 #(15) rel_pc_sel(
  .I0(15'h0001),				  // next pc / preload
  .I1({ {7{inst[7]}},inst[7:0]}), // BCC -256..+254 (ignore JABS) / MEM CYCLE2
  .I2(15'h0000),				  // IACK / IACK2 / MEM CYCLE2
  .S(rel_sel),.O(rel_pc));
`endif
assign inc_pc = reg_pc + rel_pc;

wire [1:0] next_pc_sel = {mc2_load_pc,inst_cycle & OP_JABS & cc_true & ~iack};
//wire [1:0] next_pc_sel = {mc2_load_pc,OP_JABS & cc_true};
mux_3 #(15) next_pc_mux(
  .I0(inc_pc),			  // Bcc / inst / preload
  .I1(rs_b[15:1]),		  // Jcc / JSR
  .I2(d_bus_in[15:1] ),   // RET / IACK2 / RESET
  .S(next_pc_sel),.O(next_pc));

`ifdef RESET_ASYNC
always @ (posedge clk or posedge rst)
`else
always @ (posedge clk)
`endif
begin
  if(rst)
  begin
	reg_pc <= ResetVector;	// Reset Vector
  end else if(clk_en)
//	end else if(clk_en & ~iack)
  begin
	reg_pc <= next_pc;
  end
end

`ifdef ENABLE_MLT
/////////////////////////////////////////////////////////////////////////////
// MLT Unit
/////////////////////////////////////////////////////////////////////////////

wire [16:0] mlth_out , mltl_out;

`ifdef ENABLE_MLT32
// 16bit x 16bit to 32bit+carry answer

//
// auto impremented to 'MULT18X18' primitive by Xilinx XST
//
// Xilinx multiplex primitive
//wire [35:0] mlt_p;
//wire [17:0] mlt_a = {rs_a[15],rs_a,1'b0};
//wire [17:0] mlt_b = {rs_b[15],rs_b,1'b0};
//MULT18X18 MULT18X18_inst (.P(mlt_p),.A(mlt_a),.B(mlt_b));
//assign mlth_out = mlt_p[34:18];
//assign mltl_out = mlt_p[18:2];
wire [32:0] mlt32c = rs_a * rs_b;

assign mlth_out = mlt32c[32:16];
assign mltl_out = mlt32c[16: 0];

`else // ENABLE_MLT32

// 16bit x 16bit to 16bit+carry answer
wire [17:0] mlt16c = rs_a * rs_b;
assign mlth_out = mlt16c;
assign mltl_out = mlt16c;

`endif // ENABLE_MLT32

`else // ENABLE_MLT
/////////////////////////////////////////////////////////////////////////////
// SHIFT Unit
/////////////////////////////////////////////////////////////////////////////


//
// when enable MLT operation , remove shift unit
// because shift operation can reprace with MLT operation
//
// SHR R,num_shift -> MLTH R,(8000H>>num_shift)
// SHL R,num_shift -> MLT  R,(0001H<<num_shift)
//

//
// when disable MLT operation , suooprt only right shift operation
// because SHL can execute by ADC
// SHL0 R,1 -> ADD R,R
// SHLC R,1 -> ADC R,R
//

wire [16:0] shiftr_out;
wire [15:0] sh_src = rs_a;
// output
assign shiftr_out = {sh_src[0]	, (sh_mod ? sh_src[15] : cflag) , sh_src[15:1]};

`endif // ENABLE_MLT

/////////////////////////////////////////////////////////////////////////////
// Logical Unit
/////////////////////////////////////////////////////////////////////////////
mr16_logic logical_unit(
  .A(rs_a),
  .B(rs_b),
  .C(cflag),
  .S(op_mix[1:0]),
  .O(logical_out));

/////////////////////////////////////////////////////////////////////////////
// Arithmetic Unit
/////////////////////////////////////////////////////////////////////////////

//Arithmetic A
wire arith_cin = (arith_wc & cflag) ^ arith_sub;
wire [17:0] arithmetic_a_in = {arith_sub,rs_a,arith_cin};

//Arithmetic B sel
wire [16:0] arithmetic_b_in;

wire [3:0] arithmetic_b_sel = {OP_CALL|OP_PUSH|iack2,OP_POP_RET,OP_MEM,arith_sub};
mux_5 #(17) arithmetic_b_mux(
  .I0( { rs_b,1'b1}),		 // ADD/ADC
  .I1( {~rs_b,1'b1}),		 // SUB/SBC
  .I2( {disp16,1'b0}),		 // LDM/STM
  .I3( {16'h0002,1'b0}),	 // POP/RET (RA+2)
  .I4( {16'hfffe,1'b0}),	 // PUSH/CALL (RA-2) / IACK2
  .S(arithmetic_b_sel),.O(arithmetic_b_in));

// arithmetic logic
assign arithmetic_out = (arithmetic_a_in + arithmetic_b_in)>>1;

/////////////////////////////////////////////////////////////////////////////
// ALU multiplex
/////////////////////////////////////////////////////////////////////////////
`ifdef ENABLE_MLT

wire atith_sel = OP_ARITHMETIC | OP_CMP | OP_MEM | OP_CALL | iack2;

wire [3:0] alu_sel = {mc2_op & ~iack2,atith_sel,OP_MLTH,OP_MLT};
mux_5 #(17) alu_out_mux(
  .I0(logical_out), 	   // LOGIC
  .I1(mltl_out),		   // MLT
  .I2(mlth_out),		   // MLTH
  .I3(arithmetic_out),	   // ARITH , STACK
  .I4({cflag,d_bus_in}),   // LDM / POP / RET
  .S(alu_sel),.O(alu_out));

`else
wire [2:0] alu_sel = {OP_LOGICAL|OP_TST,OP_SHIFT,mc2_op};

mux_4 #(17) alu_out_mux(
  .I0(arithmetic_out),	   // ARITH , STACK
  .I1({cflag,d_bus_in}),   // LDM
  .I2(shiftr_out),		   // SHIFT
  .I3(logical_out), 	   // LOGIC
  .S(alu_sel),.O(alu_out));
`endif

assign alu_flag[0] = alu_out[16];				   // cf
assign alu_flag[1] = (alu_out[15:0] == 16'h0000);  // zf
assign alu_flag[2] = alu_out[15]^rs_a[15];		   // vf
assign alu_flag[3] = alu_out[15];				   // nf

/////////////////////////////////////////////////////////////////////////////
// flag register
/////////////////////////////////////////////////////////////////////////////
`ifdef ENABLE_MLT
wire flag_load = (OP_ARITHMETIC | OP_LOGICAL | OP_TEST) & inst_cycle;
`else
wire flag_load = (OP_ARITHMETIC | OP_LOGICAL | OP_TEST | OP_SHIFT) & inst_cycle;
`endif

`ifdef RESET_ASYNC
always @ (posedge clk or posedge rst)
`else
always @ (posedge clk)
`endif
begin
  if(rst)
	reg_flag <= 5'b00000;
  else if (clk_en)
  begin
	// CF,ZF,NF,VF
	if(mc2_load_flag)  reg_flag[3:0] <= d_bus_in[3:0]; // POP FLAG
	else if(flag_load) reg_flag[3:0] <= alu_flag;	   // ALU
	else begin
`ifdef ENABLE_CLC_STC
	  if(OP_LOAD_CF)   reg_flag[0] <= flag_val;
`endif
`ifdef ENABLE_CLZ_STZ
	  if(OP_LOAD_ZF)   reg_flag[1] <= flag_val;
`endif
	end

	// IFF CONTROLL
	if(iack)			reg_flag[4] <= 1'b0;
	else if(OP_LOAD_IF) reg_flag[4] <= flag_val; // CLI,STI
  end
end

/////////////////////////////////////////////////////////////////////////////
// RSESET / IRQ
/////////////////////////////////////////////////////////////////////////////

// IRQ assert
assign iack = ~mc2_op &  ~iack2 & ~pfx_op & iflag & irq;

/////////////////////////////////////////////////////////////////////////////
// OUTPUT MULTIPLEXER
/////////////////////////////////////////////////////////////////////////////
wire [3:0] d_addr_sel = {rst,iack,~mem_cycle,OP_POP_RET&~iack2};

mux_5 #(16) d_addr_mux(
  .I0(arithmetic_out[15:0]),	// RA+INDEX  	: CALL / PUSH / LDM / STM , IACK2
  .I1({rs_a[15:1],1'b0}),		// RA		 	: RET / POP
  .I2({next_pc,1'b0}),			// next PC	 	: instruction
  .I3(vector_a),				// ivector	 	: ISR entry
  .I4({ResetVector,1'b0}),		// ResetVector	: reset vector read
  .S(d_addr_sel),.O(d_addr));

// data bus data out
wire [15:0] d_bus_out_;
wire [1:0] d_bus_out_sel = {OP_CALL | iack2,STM_FLG};
mux_3 #(5) d_bus_out_l_mux(
  .I0(reg_b_out[4:0]),					  //  RB   : STM / PUSH REG
  .I1(reg_flag),						  //  FLAG : PUSH FLAG
  .I2({inc_pc[3:0],1'b0}),				  //  PC   : CALL / IACK2
  .S(d_bus_out_sel),.O(d_bus_out_[4:0]));

mux_2 #(11) d_bus_out_h_mux(
  .I0(reg_b_out[15:5]), 				   //  RB	: STM / PUSH
  .I1(inc_pc[14:4]),					   //  PC	: CALL / IACK2
  .S(d_bus_out_sel[1]),.O(d_bus_out_[15:5]));

// Write Cycle
assign wcycle = ((OP_CALL|OP_STM)&inst_cycle) | (iack2 & ~pfx_op);

`ifdef ENABLE_BYTE_ACCESS

wire wm_even = OP_STM & mem_w8 & ~byte_sel;
wire wm_odd  = OP_STM & mem_w8 &  byte_sel;

// data output select
`ifdef BIG_ENDIAN
assign d_bus_out[15:8] = d_bus_out_[15:8];
assign d_bus_out[ 7:0] = wm_even ? d_bus_out_[15:8] : d_bus_out_[ 7:0];
wire wen_lo = OP_STM & (~mem_w8 |  byte_sel);
wire wen_hi = OP_STM & (~mem_w8 | ~byte_sel);
`else
assign d_bus_out[15:8] = wm_odd  ? d_bus_out_[ 7:0] : d_bus_out_[15:8];
assign d_bus_out[ 7:0] = d_bus_out_[7:0];
wire wen_lo = OP_STM & (~mem_w8 | ~byte_sel);
wire wen_hi = OP_STM & (~mem_w8 |  byte_sel);
`endif

// 8bit memory write cycle

assign WriteEnable[0] = ((OP_CALL|wen_lo)&inst_cycle) | (iack2 & ~pfx_op); // WR
assign WriteEnable[1] = ((OP_CALL|wen_hi)&inst_cycle) | (iack2 & ~pfx_op); // WR

`else

// data bus
assign d_bus_out = d_bus_out_;

// separate
assign WriteEnable[0] = ((OP_CALL|OP_STM)&inst_cycle) | (iack2 & ~pfx_op); // WR
assign WriteEnable[1] = ((OP_CALL|OP_STM)&inst_cycle) | (iack2 & ~pfx_op); // WR
`endif

assign ByteAccess = mem_w8;  // 8bit access
assign LoadCycle  = mc2_op;

assign Address = d_addr;
assign WriteData = d_bus_out;

assign IntAck = iack;

endmodule

/////////////////////////////////////////////////////////////////////////////
// Logical Unit module
/////////////////////////////////////////////////////////////////////////////
module mr16_logic(A,B,C,S,O);
input [15:0] A;
input [15:0] B;
input [1:0]  S;
input C;
output [16:0] O;

function logic1;
input [1:0] func;
input a;
input b;
begin
  case ({func,a,b})
// AND
  4'b0000:logic1 = 1'b0;
  4'b0001:logic1 = 1'b0;
  4'b0010:logic1 = 1'b0;
  4'b0011:logic1 = 1'b1;
// OR
  4'b0100:logic1 = 1'b0;
  4'b0101:logic1 = 1'b1;
  4'b0110:logic1 = 1'b1;
  4'b0111:logic1 = 1'b1;
// XOR
  4'b1000:logic1 = 1'b0;
  4'b1001:logic1 = 1'b1;
  4'b1010:logic1 = 1'b1;
  4'b1011:logic1 = 1'b0;
// B (LOAD)
  4'b1100:logic1 = 1'b0;
  4'b1101:logic1 = 1'b1;
  4'b1110:logic1 = 1'b0;
  4'b1111:logic1 = 1'b1;
  endcase
end
endfunction

assign O[ 0] = logic1(S,A[ 0],B[ 0]);
assign O[ 1] = logic1(S,A[ 1],B[ 1]);
assign O[ 2] = logic1(S,A[ 2],B[ 2]);
assign O[ 3] = logic1(S,A[ 3],B[ 3]);
assign O[ 4] = logic1(S,A[ 4],B[ 4]);
assign O[ 5] = logic1(S,A[ 5],B[ 5]);
assign O[ 6] = logic1(S,A[ 6],B[ 6]);
assign O[ 7] = logic1(S,A[ 7],B[ 7]);
assign O[ 8] = logic1(S,A[ 8],B[ 8]);
assign O[ 9] = logic1(S,A[ 9],B[ 9]);
assign O[10] = logic1(S,A[10],B[10]);
assign O[11] = logic1(S,A[11],B[11]);
assign O[12] = logic1(S,A[12],B[12]);
assign O[13] = logic1(S,A[13],B[13]);
assign O[14] = logic1(S,A[14],B[14]);
assign O[15] = logic1(S,A[15],B[15]);
assign O[16] = C;

endmodule

/////////////////////////////////////////////////////////////////////////////
// primitive
/////////////////////////////////////////////////////////////////////////////

//2 to 1 multiplexer
module mux_2(S,I0,I1,O);
parameter WIDTH = 1;
  input  S;
  input  [WIDTH-1:0] I0,I1;
  output [WIDTH-1:0] O;
  assign O = ~S ? I0 : I1;
endmodule

//3 to 1 multiplexer
module mux_3(S,I0,I1,I2,O);
parameter WIDTH = 1;
  input  [1:0] S;
  input  [WIDTH-1:0] I0,I1,I2;
  output [WIDTH-1:0] O;
  function [WIDTH-1:0] sel3;
	input [1:0] sel;
	input [WIDTH-1:0] i0,i1,i2;
	begin
	  casex(sel)
	  2'b1x:   sel3 = i2;
	  2'b01:   sel3 = i1;
	  default: sel3 = i0;
	  endcase
	end
  endfunction
  assign O = sel3(S,I0,I1,I2);
endmodule

`ifdef	USE_MUX_4
//4 to 1 multiplexer
module mux_4(S,I0,I1,I2,I3,O);
parameter WIDTH = 1;
  input  [2:0] S;
  input  [WIDTH-1:0] I0,I1,I2,I3;
  output [WIDTH-1:0] O;
  function [WIDTH-1:0] sel4;
	input [2:0] sel;
	input [WIDTH-1:0] i0,i1,i2,i3;
	begin
	  casex(sel)
	  3'b1xx:  sel4 = i3;
	  3'b01x:  sel4 = i2;
	  3'b001:  sel4 = i1;
	  default: sel4 = i0;
	  endcase
	end
  endfunction
  assign O = sel4(S,I0,I1,I2,I3);
endmodule
`endif

//`ifdef  USE_MUX_5
//5 to 1 multiplexer
module mux_5(S,I0,I1,I2,I3,I4,O);
parameter WIDTH = 1;
  input  [3:0] S;
  input  [WIDTH-1:0] I0,I1,I2,I3,I4;
  output [WIDTH-1:0] O;
  function [WIDTH-1:0] sel5;
	input [3:0] sel;
	input [WIDTH-1:0] i0,i1,i2,i3,i4;
	begin
	  casex(sel)
	  4'b1xxx: sel5 = i4;
	  4'b01xx: sel5 = i3;
	  4'b001x: sel5 = i2;
	  4'b0001: sel5 = i1;
	  default: sel5 = i0;
	  endcase
	end
  endfunction
  assign O = sel5(S,I0,I1,I2,I3,I4);
endmodule
//`endif
