//
// mr16core.v - minimal RISC 16bit CPU , develop version 2005.4.12
//
// Copyright(C) 2005 Tatsuyuki Satoh
//
// WARNING! This code is provided for free on an as is basis. There are
// no promises, warranties, guaranties etc. of any kind. Use it at your
// own risk.
//
// histry:
//
// note:
//  Do not supported SHARED_DATA_BUS switch(LDMB/STMB instruction) yet
//
//

/////////////////////////////////////////////////////////////////////////////
// archtecture option selector
/////////////////////////////////////////////////////////////////////////////

// ---- select MuLTiplex or SHIFT unit -----

`define ENABLE_MLT   // enable MLT unit and disable right SHIFT unit
`define ENABLE_MLT32 // enable MLT high word (32bit result).

// ---- dual dbus or shared dbus select ----

// un define SHARED_DATA_BUS : 32Kx16bit + 64K(MAX 16M)x8bit bus. (small)
//
// d_en[0]         =  8bit bus enable
// d_en[1]         = 16bit bus enable
// d_bus_out[15:8] = d_addr[23:16] (*optional)

// define SHARED_DATA_BUS : 32Kx16bit with 8bit bus.              (large)
//
// d_en[0]         = low  byte enable
// d_en[1]         = high byte enable
//

//`define SHARED_DATA_BUS

// Flag Controll Operation (1slice per flag)
`define ENABLE_CLC_STC // CLC / STC operation
`define ENABLE_CLZ_STZ // CLZ / STZ operation

/////////////////////////////////////////////////////////////////////////////
// module entry
/////////////////////////////////////////////////////////////////////////////

module mr16core(
  reset,clk, clk_en,
  d_addr, d_bus_in, d_bus_out, d_sel8,d_wr,m_acc,

t_addr,t_sel,

  ivector,iack
);

// ----- interrupt auto vector size -----
parameter ivec_depth = 1; // set 1(max 1) or 4(max 15) to 12(max 4095)
// grobal
input reset;              // ASYNC reset input
input clk;                // clock
input clk_en;             // clock enable for wait controll

// memory bus
output [15:0] d_addr;     // 16bit address
input  [15:0] d_bus_in;   // data-in
output [15:0] d_bus_out;  // data-out
output d_sel8;            // 8bit access
output [1:0] d_wr;        // write enable
output m_acc;             // memory cycle

// interrupt controll
input  [ivec_depth-1:0] ivector;
output iack;

output [15:0] t_addr;
output [3:0] t_sel;

/////////////////////////////////////////////////////////////////////////////
// Registers
/////////////////////////////////////////////////////////////////////////////
reg [7:0]  reg_rl[15:0]; // 16x8bit dual port RAM
reg [7:0]  reg_rh[15:0]; // 16x8bit dual port RAM
reg [14:0] reg_pc;       // program counter
reg [4:0]  reg_flag;     // flag register
reg [10:0] reg_prefix;   // iack2,mcycle flag , prefix flag + prefix value

// special cycle
wire pfx_op = reg_prefix[8];  // 2nd opcode
wire mc2_op = reg_prefix[9];  // 2nd memory cycle
wire iack2  = reg_prefix[10]; // IACK2 change PC

// flags
wire cflag = reg_flag[0];
wire zflag = reg_flag[1];
wire vflag = reg_flag[2];
wire nflag = reg_flag[3];
wire iflag = reg_flag[4];

/////////////////////////////////////////////////////////////////////////////
// generic wires
/////////////////////////////////////////////////////////////////////////////
wire[15:0]  reg_a_out;
wire[15:0]  reg_b_out;
wire [15:0] rs_a,rs_b;

// alu output
wire [16:0] alu_out , logical_out , arithmetic_out;
wire [3:0]  alu_flag;

wire [15:0] inst;

/////////////////////////////////////////////////////////////////////////////
// instruction decoder
/////////////////////////////////////////////////////////////////////////////

// block separation
wire[3:0] op       = inst[15:12];
wire op_reg        = (op[3:0]==4'b0011);
wire[3:0] op_mix   = op_reg ? inst[3:0] : op;

// register selector
wire [3:0] reg_a_addr = mc2_op ? reg_prefix[7:4] : inst[11:8];
wire [3:0] reg_b_addr = inst[7:4];

// stack selector
wire stack_sel        = (inst[11:8] ==4'b1111);
wire flag_sel         = (inst[7:4]  ==4'b1111);

// instruction cycle
wire inst_cycle       = ~mc2_op & ~iack & ~iack2;

// Memory Access
wire OP_MEM        = (op[3:1] == 3'b000);
wire OP_LDM        = (op == 4'b0000);
wire OP_STM        = (op == 4'b0001);
 wire STM_FLG       =  (stack_sel & flag_sel);                     // PUSH FLAG
 wire LDM_PC        = ~op[0] &   stack_sel             & ~inst[0]; // RET
 wire LDM_FLG       = ~op[0] &  (stack_sel & flag_sel) &  inst[0]; // POP FLAG
 wire LDM_REG       = ~op[1] & ~op[0] & ~(LDM_PC | LDM_FLG);

wire OP_PUSH_POP   = OP_MEM      & stack_sel;
wire OP_POP_RET    = OP_PUSH_POP & ~op[0];
wire OP_PUSH       = OP_PUSH_POP &  op[0];

wire OP_BCC         = (op==4'b0010);                             // (override with JABS)
wire OP_JABS        = (op_mix[3:1] == 3'b001) & (op_reg|pfx_op); // Jcc/JSR
wire OP_CALL        = (OP_JABS & inst[0]);
 wire [3:0] cond    = inst[11:8];

wire OP_LDI         = OP_BCC & (cond==4'b0111) & inst_cycle;
 wire[7:0] prefix_in = inst[7:0];

// FLAG set
wire OP_LOADF        = op_reg & (inst[3:0]==4'b0000);

wire set_flag        = ( (OP_LDM&LDM_PC) | OP_LOADF) & inst_cycle;
 wire flag_val       = inst[4];
`ifdef ENABLE_CLC_STC
  wire OP_LOAD_CF    = set_flag & inst[5];
`endif
`ifdef ENABLE_CLZ_STZ
  wire OP_LOAD_ZF    = set_flag & inst[6];
`endif
  wire OP_LOAD_IF    = set_flag & inst[7];

`ifdef ENABLE_MLT
wire OP_MLT           = (op_mix[3:1] == 3'b111); // multiplex
wire OP_MLTH          = OP_MLT & op_mix[0];
`else
wire OP_SHIFT        = op_reg & (inst[3:0]==4'b0001);
 wire sh_mod         = inst[4];
`endif

wire OP_LOGICAL       = (op_mix[3:2] == 2'b01); // 
wire OP_ARITHMETIC    = (op_mix[3:2] == 2'b10); // 10ACDDDDSSSSIIII
 wire arith_wc         = (op_mix[1]); // 1=ADC/SBB 0=ADD/SUB
 wire arith_sub        = (op_mix[0]); // 1=SUB/SBB 0=ADD/ADC
wire OP_TEST          = (op_mix[3:2] == 2'b11);
// wire OP_TST           = (op_mix == 4'b1100);  // AND no reg load
 wire OP_CMP           = (op_mix == 4'b1101);  // SUB no reg load

/////////////////////////////////////////////////////////////////////////////
// subfunctions
/////////////////////////////////////////////////////////////////////////////

// memory cycle
wire mem_cycle = ((OP_CALL | OP_MEM) & inst_cycle) | iack | iack2;

// memory prefix
wire mem_w8        = reg_prefix[7];
wire [10:0] disp11 = {reg_prefix[5:0],inst[3:0],reg_prefix[6]};
wire [15:0] disp16 = { {5{disp11[10]}},disp11};

/////////////////////////////////////////////////////////////////////////////
// input data byte size multiplex
/////////////////////////////////////////////////////////////////////////////
wire [7:0] reg_al_in , reg_ah_in;

`ifdef SHARED_DATA_BUS
// shared
wire mem_even   = mem_w8 & ~d_addr[0];
wire mem_odd    = mem_w8 &  d_addr[0];

mux_2 #(8) reg_al_in_mux(
  .I0(alu_out[ 7:0]), // normal
  .I1(alu_out[15:8]), // high word -> low wod
  .S(mc2_swap),.O(reg_al_in)
);
`else
// separate
assign reg_al_in = alu_out[ 7:0];
`endif
assign reg_ah_in = alu_out[15:8]; // high word -> through

// memory read latch state
wire mc2_load_regl = mc2_op & reg_prefix[3];
wire mc2_load_regh = mc2_op & reg_prefix[2];
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
always @ (posedge clk or posedge reset)
begin
  if(reset)
  begin
    reg_prefix    <= 11'b111_0000_0001;
  end else if(clk_en)
  begin
    reg_prefix[10] <= iack;
    reg_prefix[9]  <= mem_cycle;
    reg_prefix[8]  <= OP_LDI;

`ifdef SHARED_DATA_BUS
    mc2_swap      <= (OP_LDM & inst_cycle) & reg_prefix[1]; // SWAP read byte
`endif
    if(mem_cycle)
    begin
      reg_prefix[7:4] <= iack ? 4'b1111 : prefix_in[7:4];                  // dst reg
      reg_prefix[3]   <=(LDM_REG & inst_cycle)           | iack;  // regl
      reg_prefix[2]   <=(LDM_REG & inst_cycle & ~mem_w8) | iack;  // regh
      reg_prefix[1]   <=(LDM_FLG & inst_cycle);                   // flag
      reg_prefix[0]   <=(LDM_PC  & inst_cycle)           | iack;  // pc

`ifdef SHARED_DATA_BUS
//      reg_prefix[3]   <=(~op[0] & LDM_REG & inst_cycle)           | iack;  // regl
//      reg_prefix[2]   <=(~op[0] & LDM_REG & inst_cycle & ~mem_w8) | iack;  // regh
`endif
    end else if(OP_LDI)
    begin
      reg_prefix[7:0] <= prefix_in;
    end else begin
      reg_prefix[7:0] <= 8'h00;
    end
  end
end

/////////////////////////////////////////////////////////////////////////////
// ALU input selector
/////////////////////////////////////////////////////////////////////////////
assign rs_a = reg_a_out;

`ifdef SHARED_DATA_BUS
// byte swap
wire [1:0] reg_bh_out_sel = {OP_STM & mem_w8,op_reg};
mux_3 #(8) reg_bh_out_mux(
  .I0(reg_prefix[7:0]), // immidate
  .I1(reg_b_out[15:8]), // RB normal
  .I2(reg_b_out[7:0]),  // RB low sel
  .S(reg_bh_out_sel),.O(rs_b[15:8]));

mux_2 #(8) rs_bl_out_mux(
  .I0(inst[7:0]),      // immidate
  .I1(reg_b_out[7:0]), // RB
  .S(op_reg),.O(rs_b[7:0]));
`else
mux_2 #(16) rs_b_mux(
  .I0({reg_prefix[7:0],inst[7:0]}), // immidate
  .I1(reg_b_out),                   // RB
  .S(op_reg),.O(rs_b));
`endif

/////////////////////////////////////////////////////////////////////////////
// Condition Controll
/////////////////////////////////////////////////////////////////////////////
wire cc_true;

function cc_table;
input [2:0] sel;
input nf,vf,zf,cf;
begin
  case(sel)
  3'b000: cc_table = cf;             // HS / LO
  3'b001: cc_table = zf;             // EQ / NE
  3'b010: cc_table = vf;             // VS / VC
  3'b011: cc_table = nf;             // MI / PL
  3'b100: cc_table = vf & zf & cf;   // HI / LO
  3'b101: cc_table = (nf^vf);        // LT / GE
  3'b110: cc_table = (nf^vf) & zf;   // LE / GT
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
  .I0({14'h0000,inst_cycle}),     // IACK / IACK2 / MEM CYCLE2==0 : inst / preload==1
  .I1({ {7{inst[7]}},inst[7:0]}), // BCC -256..+254 (ignore JABS) / MEM CYCLE2
  .S(rel_sel),.O(rel_pc));
assign inc_pc = reg_pc + rel_pc;
`else
//wire [1:0] rel_sel = {~inst_cycle,OP_BCC & cc_true};
wire [1:0] rel_sel = {~inst_cycle,OP_BCC & ~pfx_op & cc_true};
mux_3 #(15) rel_pc_sel(
  .I0(15'h0001),                  // next pc / preload
  .I1({ {7{inst[7]}},inst[7:0]}), // BCC -256..+254 (ignore JABS) / MEM CYCLE2
  .I2(15'h0000),                  // IACK / IACK2 / MEM CYCLE2
  .S(rel_sel),.O(rel_pc));
`endif
assign inc_pc = reg_pc + rel_pc;

wire [1:0] next_pc_sel = {mc2_load_pc,inst_cycle & OP_JABS & cc_true & ~iack};
//wire [1:0] next_pc_sel = {mc2_load_pc,OP_JABS & cc_true};
mux_3 #(15) next_pc_mux(
  .I0(inc_pc),            // Bcc / inst / preload
  .I1(rs_b[15:1]),        // Jcc / JSR
  .I2(d_bus_in[15:1] ),   // RET / IACK2 / RESET
  .S(next_pc_sel),.O(next_pc));

always @ (posedge clk or posedge reset)
begin
  if(reset)
  begin
    reg_pc <= 15'h0000;
  end else if(clk_en)
//  end else if(clk_en & ~iack)
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
assign shiftr_out = {sh_src[0]  , (sh_mod ? sh_src[15] : cflag) , sh_src[15:1]};

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
  .I0( { rs_b,1'b1}),        // ADD/ADC
  .I1( {~rs_b,1'b1}),        // SUB/SBC
  .I2( {disp16,1'b0}),       // LDM/STM
  .I3( {16'h0002,1'b0}),     // POP/RET (RA+2)
  .I4( {16'hfffe,1'b0}),     // PUSH/CALL (RA-2) / IACK2
  .S(arithmetic_b_sel),.O(arithmetic_b_in));

// arithmetic logic
assign arithmetic_out = (arithmetic_a_in + arithmetic_b_in)>>1;

assign t_addr = 0;
assign t_sel  = {OP_CALL|OP_PUSH|iack2,OP_CALL,OP_PUSH,iack2,OP_ARITHMETIC};


/////////////////////////////////////////////////////////////////////////////
// ALU multiplex
/////////////////////////////////////////////////////////////////////////////
`ifdef ENABLE_MLT

wire atith_sel = OP_ARITHMETIC | OP_CMP | OP_MEM | OP_CALL | iack2;

wire [3:0] alu_sel = {mc2_op & ~iack2,atith_sel,OP_MLTH,OP_MLT};
mux_5 #(17) alu_out_mux(
  .I0(logical_out),        // LOGIC
  .I1(mltl_out),           // MLT
  .I2(mlth_out),           // MLTH
  .I3(arithmetic_out),     // ARITH , STACK
  .I4({cflag,d_bus_in}),   // LDM / POP / RET
  .S(alu_sel),.O(alu_out));

`else
wire [2:0] alu_sel = {OP_LOGICAL|OP_TST,OP_SHIFT,mc2_op};

mux_4 #(17) alu_out_mux(
  .I0(arithmetic_out),     // ARITH , STACK
  .I1({cflag,d_bus_in}),   // LDM
  .I2(shiftr_out),         // SHIFT
  .I3(logical_out),        // LOGIC
  .S(alu_sel),.O(alu_out));
`endif

assign alu_flag[0] = alu_out[16];                  // cf
assign alu_flag[1] = (alu_out[15:0] == 16'h0000);  // zf
assign alu_flag[2] = alu_out[15]^rs_a[15];         // vf
assign alu_flag[3] = alu_out[15];                  // nf

/////////////////////////////////////////////////////////////////////////////
// flag register
/////////////////////////////////////////////////////////////////////////////
`ifdef ENABLE_MLT
wire flag_load = (OP_ARITHMETIC | OP_LOGICAL | OP_TEST) & inst_cycle;
`else
wire flag_load = (OP_ARITHMETIC | OP_LOGICAL | OP_TEST | OP_SHIFT) & inst_cycle;
`endif

always @ (posedge clk or posedge reset)
begin
  if(reset)
    reg_flag <= 5'b00000;
  else if (clk_en)
  begin
    // CF,ZF,NF,VF
    if(mc2_load_flag)  reg_flag[3:0] <= d_bus_in[3:0]; // POP FLAG
    else if(flag_load) reg_flag[3:0] <= alu_flag;      // ALU
    else begin
`ifdef ENABLE_CLC_STC
      if(OP_LOAD_CF)   reg_flag[0] <= flag_val;
`endif
`ifdef ENABLE_CLZ_STZ
      if(OP_LOAD_ZF)   reg_flag[1] <= flag_val;
`endif
    end

    // IFF CONTROLL
    if(iack)            reg_flag[4] <= 1'b0;
    else if(OP_LOAD_IF) reg_flag[4] <= flag_val; // CLI,STI
  end
end

/////////////////////////////////////////////////////////////////////////////
// RSESET / IRQ
/////////////////////////////////////////////////////////////////////////////

// IRQ assert
assign iack = ~mc2_op &  ~iack2 & ~pfx_op & iflag & (ivector!=0);
assign inst = d_bus_in;

/////////////////////////////////////////////////////////////////////////////
// OUTPUT MULTIPLEXER
/////////////////////////////////////////////////////////////////////////////
wire [15:0] vector_a = { {15-ivec_depth{1'b0}},ivector,1'b0};
wire [3:0] d_addr_sel = {reset,iack,~mem_cycle,OP_POP_RET&~iack2};

mux_5 #(16) d_addr_mux(
  .I0(arithmetic_out[15:0]),    // RA+INDEX  : CALL / PUSH / LDM / STM , IACK2
  .I1({rs_a[15:1],1'b0}),       // RA        : RET / POP
  .I2({next_pc,1'b0}),          // next PC   : instruction
//  .I3(ivector*2),               // ivector   : ISR entry
  .I3(vector_a),                // ivector   : ISR entry
  .I4(16'h0000),                // 0000H     : reset entry
  .S(d_addr_sel),.O(d_addr));

// data bus data out
wire [1:0] d_bus_out_sel = {OP_CALL | iack2,STM_FLG};
mux_3 #(5) d_bus_out_l_mux(
  .I0(reg_b_out[4:0]),                    //  RB   : STM / PUSH REG
  .I1(reg_flag),                          //  FLAG : PUSH FLAG
  .I2({inc_pc[3:0],1'b0}),                //  PC   : CALL / IACK2
  .S(d_bus_out_sel),.O(d_bus_out[4:0]));

mux_2 #(11) d_bus_out_h_mux(
  .I0(reg_b_out[15:5]),                    //  RB   : STM / PUSH
  .I1(inc_pc[14:4]),                       //  PC   : CALL / IACK2
  .S(d_bus_out_sel[1]),.O(d_bus_out[15:5]));


`ifdef SHARED_DATA_BUS
// shared
//assign d_wr[0] = stack_push | (OP_STM & ~mem_odd);  // low word
//assign d_wr[1] = stack_push | (OP_STM & ~mem_even); // high word
`else
// separate
assign d_wr[0] = ((OP_CALL|OP_STM)&inst_cycle) | (iack2 & ~pfx_op); // WR
assign d_wr[1] = ((OP_CALL|OP_STM)&inst_cycle) | (iack2 & ~pfx_op); // WR
`endif

assign d_sel8 = mem_w8;  // 8bit access
wire m_acc    = mc2_op;  // mem cycle

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

`ifdef  USE_MUX_4
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
