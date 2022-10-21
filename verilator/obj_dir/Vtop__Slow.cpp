// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========
VlUnpacked<CData/*3:0*/, 64> Vtop::__Vtable1_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector;

const IData Vtop::var_top__DOT__sharpx1__DOT__IPL__DOT__data_width_g(8U);
const IData Vtop::var_top__DOT__sharpx1__DOT__IPL__DOT__addr_width_g(0xdU);
const IData Vtop::var_top__DOT__sharpx1__DOT__RAM__DOT__data_width_g(8U);
const IData Vtop::var_top__DOT__sharpx1__DOT__RAM__DOT__addr_width_g(0x10U);
const IData Vtop::var_top__DOT__sharpx1__DOT__VRAM__DOT__data_width_g(8U);
const IData Vtop::var_top__DOT__sharpx1__DOT__VRAM__DOT__addr_width_g(0xcU);
const IData Vtop::var_top__DOT__sharpx1__DOT__PSGRAM__DOT__data_width_g(8U);
const IData Vtop::var_top__DOT__sharpx1__DOT__PSGRAM__DOT__addr_width_g(0xdU);
const IData Vtop::var_top__DOT__sharpx1__DOT__GRAM__DOT__data_width_g(8U);
const IData Vtop::var_top__DOT__sharpx1__DOT__GRAM__DOT__addr_width_g(0x10U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__Mode(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__T2Write(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__IOWait(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Mode(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IOWait(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Flag_C(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Flag_N(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Flag_P(2U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Flag_X(3U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Flag_H(4U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Flag_Y(5U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Flag_Z(6U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Flag_S(7U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__aNone(7U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__aBC(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__aDE(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__aXY(2U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__aIOA(4U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__aSP(5U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__aZI(6U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Mode(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Flag_C(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Flag_N(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Flag_P(2U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Flag_X(3U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Flag_H(4U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Flag_Y(5U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Flag_Z(6U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Flag_S(7U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__aNone(7U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__aBC(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__aDE(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__aXY(2U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__aIOA(4U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__aSP(5U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__aZI(6U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Mode(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Flag_C(0U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Flag_N(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Flag_P(2U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Flag_X(3U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Flag_H(4U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Flag_Y(5U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Flag_Z(6U);
const IData Vtop::var_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Flag_S(7U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__RAM_DEPTH(0xbU);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__JOY_EMU(1U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__ivec_depth(4U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__WIDTH(0x10U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__WIDTH(0xfU);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__WIDTH(0xfU);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__WIDTH(0x11U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__WIDTH(0x11U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__WIDTH(0x10U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__WIDTH(5U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__WIDTH(0xbU);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__TIMER_WIDTH(0x10U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__WIDTH(0x10U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__data_width_g(8U);
const IData Vtop::var_top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__addr_width_g(0xaU);

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(_vcontextp__, this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-9);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

// Savable
void Vtop::__Vserialize(VerilatedSerialize& os) {
    vluint64_t __Vcheckval = 0xf3a0197b75d02e4dULL;
    os << __Vcheckval;
    os << __VlSymsp->_vm_contextp__;
    os<<clk_48;
    os<<clk_12;
    os<<inputs;
    os<<VGA_R;
    os<<VGA_G;
    os<<VGA_B;
    os<<VGA_HS;
    os<<VGA_VS;
    os<<VGA_HB;
    os<<VGA_VB;
    os<<AUDIO_L;
    os<<AUDIO_R;
    os<<ioctl_download;
    os<<ioctl_upload;
    os<<ioctl_wr;
    os<<ioctl_addr;
    os<<ioctl_dout;
    os<<ioctl_din;
    os<<ioctl_index;
    os<<ioctl_wait;
    os<<top__DOT__clk_48;
    os<<top__DOT__clk_12;
    os<<top__DOT__inputs;
    os<<top__DOT__VGA_R;
    os<<top__DOT__VGA_G;
    os<<top__DOT__VGA_B;
    os<<top__DOT__VGA_HS;
    os<<top__DOT__VGA_VS;
    os<<top__DOT__VGA_HB;
    os<<top__DOT__VGA_VB;
    os<<top__DOT__AUDIO_L;
    os<<top__DOT__AUDIO_R;
    os<<top__DOT__ioctl_download;
    os<<top__DOT__ioctl_upload;
    os<<top__DOT__ioctl_wr;
    os<<top__DOT__ioctl_addr;
    os<<top__DOT__ioctl_dout;
    os<<top__DOT__ioctl_din;
    os<<top__DOT__ioctl_index;
    os<<top__DOT__ioctl_wait;
    os<<top__DOT__pause;
    os<<top__DOT__audio;
    os<<top__DOT__rgb;
    os<<top__DOT__led;
    os<<top__DOT__trakball;
    os<<top__DOT__joystick;
    os<<top__DOT__playerinput;
    os<<top__DOT__sw1;
    os<<top__DOT__sw2;
    os<<top__DOT__ce_pix;
    os<<top__DOT__reset;
    os<<top__DOT____Vcellout__sharpx1__video;
    os<<top__DOT__unnamedblk1__DOT__old_clk;
    os<<top__DOT__sharpx1__DOT__clk_sys;
    os<<top__DOT__sharpx1__DOT__clk_28636;
    os<<top__DOT__sharpx1__DOT__reset;
    os<<top__DOT__sharpx1__DOT__pal;
    os<<top__DOT__sharpx1__DOT__scandouble;
    os<<top__DOT__sharpx1__DOT__ioctl_download;
    os<<top__DOT__sharpx1__DOT__ioctl_index;
    os<<top__DOT__sharpx1__DOT__ioctl_wr;
    os<<top__DOT__sharpx1__DOT__ioctl_addr;
    os<<top__DOT__sharpx1__DOT__ioctl_dout;
    os<<top__DOT__sharpx1__DOT__ce_pix;
    os<<top__DOT__sharpx1__DOT__HBlank;
    os<<top__DOT__sharpx1__DOT__HSync;
    os<<top__DOT__sharpx1__DOT__VBlank;
    os<<top__DOT__sharpx1__DOT__VSync;
    os<<top__DOT__sharpx1__DOT__video;
    os<<top__DOT__sharpx1__DOT__romDo_SharpX1;
    os<<top__DOT__sharpx1__DOT__romA;
    os<<top__DOT__sharpx1__DOT__ramDi;
    os<<top__DOT__sharpx1__DOT__ramDo;
    os<<top__DOT__sharpx1__DOT__ramA;
    os<<top__DOT__sharpx1__DOT__ramWe;
    os<<top__DOT__sharpx1__DOT__vramDi;
    os<<top__DOT__sharpx1__DOT__vramDo;
    os<<top__DOT__sharpx1__DOT__vramA;
    os<<top__DOT__sharpx1__DOT__vramWe;
    os<<top__DOT__sharpx1__DOT__psgramDi;
    os<<top__DOT__sharpx1__DOT__psgramDo;
    os<<top__DOT__sharpx1__DOT__psgramA;
    os<<top__DOT__sharpx1__DOT__psgramWe;
    os<<top__DOT__sharpx1__DOT__gramDi;
    os<<top__DOT__sharpx1__DOT__gramDo;
    os<<top__DOT__sharpx1__DOT__gramA;
    os<<top__DOT__sharpx1__DOT__gramWe;
    os<<top__DOT__sharpx1__DOT__ce;
    os<<top__DOT__sharpx1__DOT__pe8M8;
    os<<top__DOT__sharpx1__DOT__ne8M8;
    os<<top__DOT__sharpx1__DOT__pe4M4;
    os<<top__DOT__sharpx1__DOT__ne4M4;
    os<<top__DOT__sharpx1__DOT__pe2M2;
    os<<top__DOT__sharpx1__DOT__ne2M2;
    os<<top__DOT__sharpx1__DOT__pe1M1;
    os<<top__DOT__sharpx1__DOT__ne1M1;
    os<<top__DOT__sharpx1__DOT__di;
    os<<top__DOT__sharpx1__DOT__data_out;
    os<<top__DOT__sharpx1__DOT__a;
    os<<top__DOT__sharpx1__DOT__mreq;
    os<<top__DOT__sharpx1__DOT__iorq;
    os<<top__DOT__sharpx1__DOT__wr;
    os<<top__DOT__sharpx1__DOT__rd;
    os<<top__DOT__sharpx1__DOT__dir;
    os<<top__DOT__sharpx1__DOT__dirset;
    os<<top__DOT__sharpx1__DOT__halt_n;
    os<<top__DOT__sharpx1__DOT__subDo;
    os<<top__DOT__sharpx1__DOT__subDi;
    os<<top__DOT__sharpx1__DOT__sub_rd;
    os<<top__DOT__sharpx1__DOT__sub_wr;
    os<<top__DOT__sharpx1__DOT__ipl_cs;
    os<<top__DOT__sharpx1__DOT__ram_cs;
    os<<top__DOT__sharpx1__DOT__sub_cs;
    os<<top__DOT__sharpx1__DOT__miocs;
    os<<top__DOT__sharpx1__DOT__psgram_cs;
    os<<top__DOT__sharpx1__DOT__gram_cs;
    os<<top__DOT__sharpx1__DOT__ice_bank;
    os<<top__DOT__sharpx1__DOT__dma_bank;
    os<<top__DOT__sharpx1__DOT__dma_a;
    os<<top__DOT__sharpx1__DOT__dma_do;
    os<<top__DOT__sharpx1__DOT__dma_di;
    os<<top__DOT__sharpx1__DOT__dma_mreq_n;
    os<<top__DOT__sharpx1__DOT__dma_iorq_n;
    os<<top__DOT__sharpx1__DOT__dma_rd_n;
    os<<top__DOT__sharpx1__DOT__dma_wr_n;
    os<<top__DOT__sharpx1__DOT__dma_sel;
    os<<top__DOT__sharpx1__DOT__sdi;
    os<<top__DOT__sharpx1__DOT__sdo;
    os<<top__DOT__sharpx1__DOT__sbank;
    os<<top__DOT__sharpx1__DOT__sa;
    os<<top__DOT__sharpx1__DOT__sm1_n;
    os<<top__DOT__sharpx1__DOT__smreq_n;
    os<<top__DOT__sharpx1__DOT__sireq_n;
    os<<top__DOT__sharpx1__DOT__srd_n;
    os<<top__DOT__sharpx1__DOT__swr_n;
    os<<top__DOT__sharpx1__DOT__m1;
    os<<top__DOT__sharpx1__DOT__dma_cs;
    os<<top__DOT__sharpx1__DOT__dma_iei;
    os<<top__DOT__sharpx1__DOT__dma_int_n;
    os<<top__DOT__sharpx1__DOT__dma_ieo;
    os<<top__DOT__sharpx1__DOT__ZDI;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__clock;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__ram_cs;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__wren_a;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__address_a;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__data_a;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__q_a;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__ram_cs_b;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__wren_b;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__address_b;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__data_b;
    os<<top__DOT__sharpx1__DOT__IPL__DOT__q_b;
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__IPL__DOT__mem[__Vi0];
    }
    os<<top__DOT__sharpx1__DOT__RAM__DOT__clock;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__ram_cs;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__wren_a;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__address_a;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__data_a;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__q_a;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__ram_cs_b;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__wren_b;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__address_b;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__data_b;
    os<<top__DOT__sharpx1__DOT__RAM__DOT__q_b;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__RAM__DOT__mem[__Vi0];
    }
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__clock;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__ram_cs;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__wren_a;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__address_a;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__data_a;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__q_a;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__ram_cs_b;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__wren_b;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__address_b;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__data_b;
    os<<top__DOT__sharpx1__DOT__VRAM__DOT__q_b;
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__VRAM__DOT__mem[__Vi0];
    }
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__clock;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__ram_cs;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__wren_a;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__address_a;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__data_a;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__q_a;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__ram_cs_b;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__wren_b;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__address_b;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__data_b;
    os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__q_b;
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__PSGRAM__DOT__mem[__Vi0];
    }
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__clock;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__ram_cs;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__wren_a;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__address_a;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__data_a;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__q_a;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__ram_cs_b;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__wren_b;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__address_b;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__data_b;
    os<<top__DOT__sharpx1__DOT__GRAM__DOT__q_b;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__GRAM__DOT__mem[__Vi0];
    }
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__reset_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__clock;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__cep;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__cen;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__int_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__halt_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__mreq;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__iorq;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__wr;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__rd;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__m1;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__di;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__data_out;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__a;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__dir;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__dirset;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__reset_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__clk;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__cen;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__wait_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__int_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__nmi_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busrq_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__m1_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mreq_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__rd_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__wr_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__rfsh_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__halt_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busak_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__A;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dout;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dir;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dirset;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mcycle;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__reset_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__clk;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__cen;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__wait_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__int_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__nmi_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__busrq_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__m1_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__no_read;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__write;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__rfsh_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__halt_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__busak_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__A;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dinst;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__di;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dout;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mc;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ts;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__intcycle_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__stop;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dir;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dirset;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Ap;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Fp;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusB;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ID16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_Mux;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__last_mcycle;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__last_tstate;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusReq_s;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMI_s;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__INT_s;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NextIs_XY_Fetch;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__No_BTR;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BTR_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDecZ;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Q;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC_r;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles_d;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstates;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDec_16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeDH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRp;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeAF;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRS;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_DJNZ;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CPL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CCF;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_SCF;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RLD;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RRD;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetDI;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetEI;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC16_B;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP16_A;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP16_B;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ID16_B;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Oldnmi_n;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOBL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOBH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOAL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOAH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IR;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ISet;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__MCycle;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__F;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__NMICycle;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IntCycle;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__MCycles;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__TStates;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Prefix;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Inc_PC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Inc_WZ;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IncDec_16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Read_To_Reg;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Read_To_Acc;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Set_BusA_To;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Set_BusB_To;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ALU_Op;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Save_ALU;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__PreserveC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Arith16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Set_Addr_To;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IORQ;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Jump;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__JumpE;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__JumpXY;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Call;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__RstP;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__LDZ;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__LDW;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__LDSPHL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Special_LD;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeDH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeRp;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeAF;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeRS;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_DJNZ;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_CPL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_CCF;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_SCF;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_RETN;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_BT;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_BC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_BTR;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_RLD;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_RRD;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_INRC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__SetDI;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__SetEI;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IMode;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Halt;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__NoRead;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Write;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Arith16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Z16;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__ALU_Op;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__IR;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__ISet;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BusA;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BusB;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__F_In;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__F_Out;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrC;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOBH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrA;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrB;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DIH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOAL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOCL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DIL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOBL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOCH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOAH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__clk;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__CEN;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__WEH;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__WEL;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DIRSET;
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH[__Vi0];
    }
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL[__Vi0];
    }
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__B;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__C;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__D;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__E;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__H;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__L;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__IX;
    os<<top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__IY;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_reset;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_clk;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_fa;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_fcs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_PS2C;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_PS2D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_PS2CT;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_PS2DT;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_wr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_rd;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_M1_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DOE;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_clk1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_FDC_DRQ_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_STB_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_CS;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_BANK;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_A;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_MREQ_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_IORQ_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_RD_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_WR_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_BUSRQ_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_BUSAK_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_RDY;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_WAIT_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_IEI;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_INT_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_IEO;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_PCM;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_FD_LAMP;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_SPM1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_RETI;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__I_IEI;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_INT_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_TX_BSY;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_RX_BSY;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_KEY_BRK_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_JOY_A;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__O_JOY_B;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dot_7seg;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__num_7seg;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_ivec_cycle;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_addr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__wdata;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__rdata;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__pgm_data;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__wram_data;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__mem_we;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP3;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP4;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP5;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP6;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP7;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP8;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OP9;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OPA;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__OPB;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IP0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IP1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IP2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IP3;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IA4;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IA5;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IA6;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IA7;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IA8;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IA9;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IAA;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__IAB;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__iack;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__ps2_irq;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ack;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fdc_irq;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fdc_ack;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_irq;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_ack;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__mem_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__pgm_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__wwam_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__msel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT____Vcellinp__sub_cpu__I_INT;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__mem_addr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_busy;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_rd;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_ivec_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__p8255_hs_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fw_wram_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_a;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__wram_wr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_wd;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_b;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_a;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__joya_emu;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__joyb_emu;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__hwd_full;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__hwd_clr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__hrd_set;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__irq_en;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__main_we;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__main_re;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_cmd_wr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_set;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_clr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fdc_hlt;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fdc_wprt;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs_r;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__drq_set;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__drq_clr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_r;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_rdy;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_cyc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_req;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_d_r;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_dir;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_ena;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_frc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_res;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_set;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_ena;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_cycle;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_srv;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_acc_port;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_irq;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_acc1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_iack;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fd_access;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__dma_rw;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__wram_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_RESET;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLK;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLKEN;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_A;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_MEMCS;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_WR;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_TMRG;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P3;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P4;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P5;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P6;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P7;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P8;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P9;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_PA;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_PB;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P3;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I4;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I5;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I6;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I7;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I8;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I9;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_IA;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_IB;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_INT;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_ACK;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem16_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__tmr_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_ack;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_irq;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__gpio_in_mux;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs_r;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reset;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__clk;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__clk_en;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_in;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_sel8;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_wr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__m_acc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__ivector;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__t_addr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__t_sel;
    for (int __Vi0=0; __Vi0<16; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl[__Vi0];
    }
    for (int __Vi0=0; __Vi0<16; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh[__Vi0];
    }
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_pc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cflag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__zflag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vflag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__nflag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iflag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_flag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_reg;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_addr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_addr;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__stack_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MEM;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDM;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_STM;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__STM_FLG;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_PC;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_FLG;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_REG;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH_POP;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_POP_RET;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_BCC;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_JABS;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cond;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDI;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__prefix_in;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOADF;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__set_flag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_val;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_CF;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_ZF;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_IF;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLT;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLTH;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOGICAL;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_ARITHMETIC;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_wc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_sub;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_TEST;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CMP;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_cycle;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_w8;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp11;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp16;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_in;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_in;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_regl;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_regh;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_flag;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_pc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_load;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_load;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_load;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_bl_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_bh_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rs_b_mux__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_true;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rel_pc_sel__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlth_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mltl_out;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlt32c;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_cin;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_a_in;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_in;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__atith_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__alu_out_mux__I4;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_load;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vector_a;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_sel;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_l_mux__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_h_mux__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__A;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__B;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__C;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I3;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I4;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I3;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I4;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I3;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I4;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I2;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_RESET;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_CLK;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_GATE;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_A;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_CS;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_WR;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__O_D;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__O_INT;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_IACK;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_int;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__next_timer;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_overflow;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctr_load;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_int_load;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt_load;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__S;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__I0;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__I1;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__O;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__CLK;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__A;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__DO;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__clock;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__ram_cs;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__wren_a;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__address_a;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__data_a;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__q_a;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__ram_cs_b;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__wren_b;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__address_b;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__data_b;
    os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__q_b;
    for (int __Vi0=0; __Vi0<1024; ++__Vi0) {
        os<<top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem[__Vi0];
    }
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_RESET;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_CLK;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_A;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_MREQ_n;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_IORQ_n;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_RD_n;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_WR_n;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_IPL_SEL;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_DAM;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__I_DEFCHR;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_RAM_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_MIOCS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_EMM_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_EXTROM_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_KANROM_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_FD5_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_PAL_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_CG_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_CRTC_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_SUB_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_PIA_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_PSG_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_SET_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_RES_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_ATTR_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_TEXT_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRB_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRR_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRG_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_HDD_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_FD8_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_FM_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_FMO_CTC_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_KANJI_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_BMEM_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_DMA_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_SIO_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_CTC_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_P1FDX_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_BLACK_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_DIPSW_CS;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__O_DAM_CLR;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__sys_io;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__miocs;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__storage_cs;
    os<<top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__A;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Sub;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Carry_In;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__A;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Sub;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Carry_In;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__A;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Sub;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Carry_In;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__A;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Sub;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Carry_In;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__A;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Sub;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Carry_In;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__A;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Sub;
    os<<__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Carry_In;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__nf;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__vf;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__zf;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__cf;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__sel;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__i1;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__sel;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i0;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i1;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i2;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__func;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__a;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__b;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__sel;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i0;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i1;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i2;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__sel;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i0;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i1;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i2;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i3;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i4;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__sel;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__i0;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__i1;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__i2;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__i3;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__Vfuncout;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__sel;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i0;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i1;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i2;
    os<<__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__Vfuncout;
    for (int __Vi0=0; __Vi0<64; ++__Vi0) {
        os<<__Vtablechg1[__Vi0];
    }
    os<<__Vdly__top__DOT__sharpx1__DOT__ramA;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    os<<__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r;
    os<<__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req;
    os<<__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r;
    os<<__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0;
    os<<__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1;
    os<<__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1;
    os<<__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1;
    os<<__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC;
    os<<__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC;
    os<<__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    os<<__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP;
    os<<__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate;
    os<<__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
    os<<__VinpClk__TOP__top__DOT__reset;
    os<<__Vclklast__TOP__clk_48;
    os<<__Vclklast__TOP____VinpClk__TOP__top__DOT__reset;
    os<<__Vchglast__TOP__top__DOT__reset;
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        os<<__Vm_traceActivity[__Vi0];
    }
    __VlSymsp->__Vserialize(os);
}
void Vtop::__Vdeserialize(VerilatedDeserialize& os) {
    vluint64_t __Vcheckval = 0xf3a0197b75d02e4dULL;
    os.readAssert(__Vcheckval);
    os >> __VlSymsp->_vm_contextp__;
    os>>clk_48;
    os>>clk_12;
    os>>inputs;
    os>>VGA_R;
    os>>VGA_G;
    os>>VGA_B;
    os>>VGA_HS;
    os>>VGA_VS;
    os>>VGA_HB;
    os>>VGA_VB;
    os>>AUDIO_L;
    os>>AUDIO_R;
    os>>ioctl_download;
    os>>ioctl_upload;
    os>>ioctl_wr;
    os>>ioctl_addr;
    os>>ioctl_dout;
    os>>ioctl_din;
    os>>ioctl_index;
    os>>ioctl_wait;
    os>>top__DOT__clk_48;
    os>>top__DOT__clk_12;
    os>>top__DOT__inputs;
    os>>top__DOT__VGA_R;
    os>>top__DOT__VGA_G;
    os>>top__DOT__VGA_B;
    os>>top__DOT__VGA_HS;
    os>>top__DOT__VGA_VS;
    os>>top__DOT__VGA_HB;
    os>>top__DOT__VGA_VB;
    os>>top__DOT__AUDIO_L;
    os>>top__DOT__AUDIO_R;
    os>>top__DOT__ioctl_download;
    os>>top__DOT__ioctl_upload;
    os>>top__DOT__ioctl_wr;
    os>>top__DOT__ioctl_addr;
    os>>top__DOT__ioctl_dout;
    os>>top__DOT__ioctl_din;
    os>>top__DOT__ioctl_index;
    os>>top__DOT__ioctl_wait;
    os>>top__DOT__pause;
    os>>top__DOT__audio;
    os>>top__DOT__rgb;
    os>>top__DOT__led;
    os>>top__DOT__trakball;
    os>>top__DOT__joystick;
    os>>top__DOT__playerinput;
    os>>top__DOT__sw1;
    os>>top__DOT__sw2;
    os>>top__DOT__ce_pix;
    os>>top__DOT__reset;
    os>>top__DOT____Vcellout__sharpx1__video;
    os>>top__DOT__unnamedblk1__DOT__old_clk;
    os>>top__DOT__sharpx1__DOT__clk_sys;
    os>>top__DOT__sharpx1__DOT__clk_28636;
    os>>top__DOT__sharpx1__DOT__reset;
    os>>top__DOT__sharpx1__DOT__pal;
    os>>top__DOT__sharpx1__DOT__scandouble;
    os>>top__DOT__sharpx1__DOT__ioctl_download;
    os>>top__DOT__sharpx1__DOT__ioctl_index;
    os>>top__DOT__sharpx1__DOT__ioctl_wr;
    os>>top__DOT__sharpx1__DOT__ioctl_addr;
    os>>top__DOT__sharpx1__DOT__ioctl_dout;
    os>>top__DOT__sharpx1__DOT__ce_pix;
    os>>top__DOT__sharpx1__DOT__HBlank;
    os>>top__DOT__sharpx1__DOT__HSync;
    os>>top__DOT__sharpx1__DOT__VBlank;
    os>>top__DOT__sharpx1__DOT__VSync;
    os>>top__DOT__sharpx1__DOT__video;
    os>>top__DOT__sharpx1__DOT__romDo_SharpX1;
    os>>top__DOT__sharpx1__DOT__romA;
    os>>top__DOT__sharpx1__DOT__ramDi;
    os>>top__DOT__sharpx1__DOT__ramDo;
    os>>top__DOT__sharpx1__DOT__ramA;
    os>>top__DOT__sharpx1__DOT__ramWe;
    os>>top__DOT__sharpx1__DOT__vramDi;
    os>>top__DOT__sharpx1__DOT__vramDo;
    os>>top__DOT__sharpx1__DOT__vramA;
    os>>top__DOT__sharpx1__DOT__vramWe;
    os>>top__DOT__sharpx1__DOT__psgramDi;
    os>>top__DOT__sharpx1__DOT__psgramDo;
    os>>top__DOT__sharpx1__DOT__psgramA;
    os>>top__DOT__sharpx1__DOT__psgramWe;
    os>>top__DOT__sharpx1__DOT__gramDi;
    os>>top__DOT__sharpx1__DOT__gramDo;
    os>>top__DOT__sharpx1__DOT__gramA;
    os>>top__DOT__sharpx1__DOT__gramWe;
    os>>top__DOT__sharpx1__DOT__ce;
    os>>top__DOT__sharpx1__DOT__pe8M8;
    os>>top__DOT__sharpx1__DOT__ne8M8;
    os>>top__DOT__sharpx1__DOT__pe4M4;
    os>>top__DOT__sharpx1__DOT__ne4M4;
    os>>top__DOT__sharpx1__DOT__pe2M2;
    os>>top__DOT__sharpx1__DOT__ne2M2;
    os>>top__DOT__sharpx1__DOT__pe1M1;
    os>>top__DOT__sharpx1__DOT__ne1M1;
    os>>top__DOT__sharpx1__DOT__di;
    os>>top__DOT__sharpx1__DOT__data_out;
    os>>top__DOT__sharpx1__DOT__a;
    os>>top__DOT__sharpx1__DOT__mreq;
    os>>top__DOT__sharpx1__DOT__iorq;
    os>>top__DOT__sharpx1__DOT__wr;
    os>>top__DOT__sharpx1__DOT__rd;
    os>>top__DOT__sharpx1__DOT__dir;
    os>>top__DOT__sharpx1__DOT__dirset;
    os>>top__DOT__sharpx1__DOT__halt_n;
    os>>top__DOT__sharpx1__DOT__subDo;
    os>>top__DOT__sharpx1__DOT__subDi;
    os>>top__DOT__sharpx1__DOT__sub_rd;
    os>>top__DOT__sharpx1__DOT__sub_wr;
    os>>top__DOT__sharpx1__DOT__ipl_cs;
    os>>top__DOT__sharpx1__DOT__ram_cs;
    os>>top__DOT__sharpx1__DOT__sub_cs;
    os>>top__DOT__sharpx1__DOT__miocs;
    os>>top__DOT__sharpx1__DOT__psgram_cs;
    os>>top__DOT__sharpx1__DOT__gram_cs;
    os>>top__DOT__sharpx1__DOT__ice_bank;
    os>>top__DOT__sharpx1__DOT__dma_bank;
    os>>top__DOT__sharpx1__DOT__dma_a;
    os>>top__DOT__sharpx1__DOT__dma_do;
    os>>top__DOT__sharpx1__DOT__dma_di;
    os>>top__DOT__sharpx1__DOT__dma_mreq_n;
    os>>top__DOT__sharpx1__DOT__dma_iorq_n;
    os>>top__DOT__sharpx1__DOT__dma_rd_n;
    os>>top__DOT__sharpx1__DOT__dma_wr_n;
    os>>top__DOT__sharpx1__DOT__dma_sel;
    os>>top__DOT__sharpx1__DOT__sdi;
    os>>top__DOT__sharpx1__DOT__sdo;
    os>>top__DOT__sharpx1__DOT__sbank;
    os>>top__DOT__sharpx1__DOT__sa;
    os>>top__DOT__sharpx1__DOT__sm1_n;
    os>>top__DOT__sharpx1__DOT__smreq_n;
    os>>top__DOT__sharpx1__DOT__sireq_n;
    os>>top__DOT__sharpx1__DOT__srd_n;
    os>>top__DOT__sharpx1__DOT__swr_n;
    os>>top__DOT__sharpx1__DOT__m1;
    os>>top__DOT__sharpx1__DOT__dma_cs;
    os>>top__DOT__sharpx1__DOT__dma_iei;
    os>>top__DOT__sharpx1__DOT__dma_int_n;
    os>>top__DOT__sharpx1__DOT__dma_ieo;
    os>>top__DOT__sharpx1__DOT__ZDI;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__clock;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__ram_cs;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__wren_a;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__address_a;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__data_a;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__q_a;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__ram_cs_b;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__wren_b;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__address_b;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__data_b;
    os>>top__DOT__sharpx1__DOT__IPL__DOT__q_b;
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__IPL__DOT__mem[__Vi0];
    }
    os>>top__DOT__sharpx1__DOT__RAM__DOT__clock;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__ram_cs;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__wren_a;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__address_a;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__data_a;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__q_a;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__ram_cs_b;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__wren_b;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__address_b;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__data_b;
    os>>top__DOT__sharpx1__DOT__RAM__DOT__q_b;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__RAM__DOT__mem[__Vi0];
    }
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__clock;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__ram_cs;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__wren_a;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__address_a;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__data_a;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__q_a;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__ram_cs_b;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__wren_b;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__address_b;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__data_b;
    os>>top__DOT__sharpx1__DOT__VRAM__DOT__q_b;
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__VRAM__DOT__mem[__Vi0];
    }
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__clock;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__ram_cs;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__wren_a;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__address_a;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__data_a;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__q_a;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__ram_cs_b;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__wren_b;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__address_b;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__data_b;
    os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__q_b;
    for (int __Vi0=0; __Vi0<8192; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__PSGRAM__DOT__mem[__Vi0];
    }
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__clock;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__ram_cs;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__wren_a;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__address_a;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__data_a;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__q_a;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__ram_cs_b;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__wren_b;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__address_b;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__data_b;
    os>>top__DOT__sharpx1__DOT__GRAM__DOT__q_b;
    for (int __Vi0=0; __Vi0<65536; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__GRAM__DOT__mem[__Vi0];
    }
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__reset_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__clock;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__cep;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__cen;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__int_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__halt_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__mreq;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__iorq;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__wr;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__rd;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__m1;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__di;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__data_out;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__a;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__dir;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__dirset;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__reset_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__clk;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__cen;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__wait_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__int_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__nmi_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busrq_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__m1_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mreq_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__rd_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__wr_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__rfsh_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__halt_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busak_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__A;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dout;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dir;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dirset;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mcycle;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__reset_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__clk;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__cen;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__wait_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__int_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__nmi_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__busrq_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__m1_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__no_read;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__write;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__rfsh_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__halt_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__busak_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__A;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dinst;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__di;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dout;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mc;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ts;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__intcycle_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__stop;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dir;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dirset;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Ap;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Fp;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusB;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ID16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_Mux;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__last_mcycle;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__last_tstate;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusReq_s;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMI_s;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__INT_s;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NextIs_XY_Fetch;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__No_BTR;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BTR_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDecZ;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Q;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC_r;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles_d;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstates;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDec_16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeDH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRp;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeAF;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRS;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_DJNZ;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CPL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CCF;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_SCF;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RLD;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RRD;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetDI;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetEI;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC16_B;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP16_A;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP16_B;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ID16_B;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Oldnmi_n;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOBL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOBH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOAL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOAH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IR;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ISet;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__MCycle;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__F;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__NMICycle;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IntCycle;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__MCycles;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__TStates;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Prefix;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Inc_PC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Inc_WZ;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IncDec_16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Read_To_Reg;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Read_To_Acc;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Set_BusA_To;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Set_BusB_To;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ALU_Op;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Save_ALU;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__PreserveC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Arith16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Set_Addr_To;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IORQ;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Jump;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__JumpE;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__JumpXY;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Call;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__RstP;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__LDZ;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__LDW;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__LDSPHL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Special_LD;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeDH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeRp;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeAF;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeRS;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_DJNZ;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_CPL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_CCF;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_SCF;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_RETN;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_BT;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_BC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_BTR;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_RLD;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_RRD;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_INRC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__SetDI;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__SetEI;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IMode;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Halt;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__NoRead;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Write;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Arith16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Z16;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__ALU_Op;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__IR;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__ISet;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BusA;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BusB;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__F_In;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__F_Out;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrC;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOBH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrA;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrB;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DIH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOAL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOCL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DIL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOBL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOCH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOAH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__clk;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__CEN;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__WEH;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__WEL;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DIRSET;
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH[__Vi0];
    }
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL[__Vi0];
    }
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__B;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__C;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__D;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__E;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__H;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__L;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__IX;
    os>>top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__IY;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_reset;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_clk;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_fa;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_fcs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_PS2C;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_PS2D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_PS2CT;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_PS2DT;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_wr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_rd;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_M1_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DOE;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_clk1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_FDC_DRQ_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_STB_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_CS;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_BANK;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_A;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_MREQ_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_IORQ_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_RD_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_WR_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_BUSRQ_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_BUSAK_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_RDY;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_WAIT_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_IEI;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_INT_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_IEO;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_PCM;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_FD_LAMP;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_SPM1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_RETI;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__I_IEI;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_INT_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_TX_BSY;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_RX_BSY;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_KEY_BRK_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_JOY_A;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__O_JOY_B;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dot_7seg;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__num_7seg;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_ivec_cycle;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_addr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__wdata;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__rdata;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__pgm_data;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__wram_data;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__mem_we;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP3;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP4;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP5;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP6;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP7;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP8;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OP9;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OPA;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__OPB;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IP0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IP1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IP2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IP3;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IA4;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IA5;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IA6;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IA7;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IA8;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IA9;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IAA;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__IAB;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__iack;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__ps2_irq;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ack;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fdc_irq;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fdc_ack;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_irq;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_ack;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__mem_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__pgm_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__wwam_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__msel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT____Vcellinp__sub_cpu__I_INT;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__mem_addr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_busy;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_rd;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_ivec_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__p8255_hs_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fw_wram_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_a;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__wram_wr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_wd;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_b;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_a;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__joya_emu;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__joyb_emu;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__hwd_full;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__hwd_clr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__hrd_set;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__irq_en;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__main_we;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__main_re;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_cmd_wr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_set;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_clr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fdc_hlt;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fdc_wprt;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs_r;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__drq_set;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__drq_clr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_r;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_rdy;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_cyc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_req;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_d_r;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_dir;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_ena;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_frc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_res;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_set;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_ena;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_cycle;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_srv;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_acc_port;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_irq;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_acc1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_iack;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fd_access;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__dma_rw;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__wram_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_RESET;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLK;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLKEN;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_A;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_MEMCS;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_WR;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_TMRG;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P3;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P4;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P5;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P6;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P7;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P8;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P9;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_PA;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_PB;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P3;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I4;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I5;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I6;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I7;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I8;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I9;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_IA;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_IB;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_INT;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_ACK;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem16_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__tmr_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_ack;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_irq;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__gpio_in_mux;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs_r;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reset;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__clk;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__clk_en;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_in;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_sel8;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_wr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__m_acc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__ivector;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__t_addr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__t_sel;
    for (int __Vi0=0; __Vi0<16; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl[__Vi0];
    }
    for (int __Vi0=0; __Vi0<16; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh[__Vi0];
    }
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_pc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cflag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__zflag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vflag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__nflag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iflag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_flag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_reg;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_addr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_addr;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__stack_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MEM;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDM;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_STM;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__STM_FLG;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_PC;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_FLG;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_REG;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH_POP;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_POP_RET;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_BCC;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_JABS;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cond;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDI;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__prefix_in;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOADF;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__set_flag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_val;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_CF;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_ZF;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_IF;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLT;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLTH;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOGICAL;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_ARITHMETIC;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_wc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_sub;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_TEST;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CMP;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_cycle;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_w8;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp11;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp16;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_in;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_in;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_regl;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_regh;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_flag;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_pc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_load;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_load;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_load;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_bl_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_bh_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rs_b_mux__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_true;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rel_pc_sel__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlth_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mltl_out;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlt32c;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_cin;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_a_in;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_in;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__atith_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__alu_out_mux__I4;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_load;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vector_a;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_sel;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_l_mux__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_h_mux__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__A;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__B;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__C;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I3;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I4;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I3;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I4;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I3;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I4;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I2;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_RESET;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_CLK;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_GATE;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_A;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_CS;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_WR;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__O_D;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__O_INT;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_IACK;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_int;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__next_timer;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_overflow;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctr_load;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_int_load;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt_load;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__S;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__I0;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__I1;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__O;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__CLK;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__A;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__DO;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__clock;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__ram_cs;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__wren_a;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__address_a;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__data_a;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__q_a;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__ram_cs_b;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__wren_b;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__address_b;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__data_b;
    os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__q_b;
    for (int __Vi0=0; __Vi0<1024; ++__Vi0) {
        os>>top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem[__Vi0];
    }
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_RESET;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_CLK;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_A;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_MREQ_n;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_IORQ_n;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_RD_n;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_WR_n;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_IPL_SEL;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_DAM;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__I_DEFCHR;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_RAM_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_MIOCS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_EMM_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_EXTROM_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_KANROM_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_FD5_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_PAL_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_CG_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_CRTC_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_SUB_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_PIA_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_PSG_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_SET_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_RES_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_ATTR_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_TEXT_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRB_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRR_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRG_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_HDD_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_FD8_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_FM_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_FMO_CTC_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_KANJI_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_BMEM_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_DMA_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_SIO_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_CTC_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_P1FDX_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_BLACK_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_DIPSW_CS;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__O_DAM_CLR;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__sys_io;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__miocs;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__storage_cs;
    os>>top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__A;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Sub;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Carry_In;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__A;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Sub;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Carry_In;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__A;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Sub;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Carry_In;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__A;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Sub;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Carry_In;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__A;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Sub;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Carry_In;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__A;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Sub;
    os>>__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Carry_In;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__nf;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__vf;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__zf;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__cf;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__sel;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__i1;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__sel;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i0;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i1;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i2;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__func;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__a;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__b;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__sel;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i0;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i1;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i2;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__sel;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i0;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i1;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i2;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i3;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i4;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__sel;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__i0;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__i1;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__i2;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__sel5__53__i3;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__Vfuncout;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__sel;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i0;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i1;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i2;
    os>>__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__Vfuncout;
    for (int __Vi0=0; __Vi0<64; ++__Vi0) {
        os>>__Vtablechg1[__Vi0];
    }
    os>>__Vdly__top__DOT__sharpx1__DOT__ramA;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    os>>__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r;
    os>>__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req;
    os>>__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r;
    os>>__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0;
    os>>__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1;
    os>>__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1;
    os>>__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1;
    os>>__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC;
    os>>__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC;
    os>>__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    os>>__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP;
    os>>__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate;
    os>>__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
    os>>__VinpClk__TOP__top__DOT__reset;
    os>>__Vclklast__TOP__clk_48;
    os>>__Vclklast__TOP____VinpClk__TOP__top__DOT__reset;
    os>>__Vchglast__TOP__top__DOT__reset;
    for (int __Vi0=0; __Vi0<1; ++__Vi0) {
        os>>__Vm_traceActivity[__Vi0];
    }
    __VlSymsp->__Vdeserialize(os);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__sw1 = 0U;
    vlTOPp->top__DOT__sw2 = 2U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__t_addr = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__O_D = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I0 = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I2 = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I3 = 4U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I4 = 0x1fffcU;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I4 = 0U;
    vlTOPp->ioctl_wait = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__rfsh_n = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__wait_n = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__nmi_n = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busrq_n = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_TMRG = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__int_n = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_hlt = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_wprt = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fw_wram_cs = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem16_cs = 1U;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_iack = 0U;
    vlTOPp->top__DOT__ioctl_wait = vlTOPp->ioctl_wait;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__rfsh_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__rfsh_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__wait_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__wait_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__nmi_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__nmi_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__busrq_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busrq_n;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_GATE 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_TMRG;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__int_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__int_n;
}

void Vtop::_settle__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__sharpx1__DOT__video = vlTOPp->top__DOT____Vcellout__sharpx1__video;
    vlTOPp->top__DOT__sharpx1__DOT__ZDI = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__sdi));
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__vramWe;
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_a 
        = (0xfffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__vramA) 
                     >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__vramDi;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_CS 
        = vlTOPp->top__DOT__sharpx1__DOT__dma_cs;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_IEI 
        = vlTOPp->top__DOT__sharpx1__DOT__dma_iei;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_RESET 
        = (1U & (~ (IData)(vlTOPp->top__DOT__reset)));
    vlTOPp->top__DOT__VGA_HS = vlTOPp->VGA_HS;
    vlTOPp->top__DOT__VGA_VS = vlTOPp->VGA_VS;
    vlTOPp->top__DOT__VGA_HB = vlTOPp->VGA_HB;
    vlTOPp->top__DOT__VGA_VB = vlTOPp->VGA_VB;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__dir = vlTOPp->top__DOT__sharpx1__DOT__dir;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__dirset 
        = vlTOPp->top__DOT__sharpx1__DOT__dirset;
    vlTOPp->AUDIO_L = (0xffffU & (((IData)(vlTOPp->top__DOT__audio) 
                                   << 8U) | (IData)(vlTOPp->top__DOT__audio)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_reset 
        = (1U & (~ (IData)(vlTOPp->top__DOT__reset)));
    vlTOPp->top__DOT__sharpx1__DOT__reset = vlTOPp->top__DOT__reset;
    vlTOPp->top__DOT__rgb = vlTOPp->top__DOT____Vcellout__sharpx1__video;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts_cs 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS) 
           & (0U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_fa))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_ivec_cycle 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_SPM1) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_IEI));
    vlTOPp->top__DOT__clk_12 = vlTOPp->clk_12;
    vlTOPp->top__DOT__inputs = vlTOPp->inputs;
    vlTOPp->top__DOT__ioctl_upload = vlTOPp->ioctl_upload;
    vlTOPp->top__DOT__ioctl_din = vlTOPp->ioctl_din;
    vlTOPp->top__DOT__playerinput = (0x50U | (((((0x200U 
                                                  & ((~ 
                                                      ((IData)(vlTOPp->inputs) 
                                                       >> 0xaU)) 
                                                     << 9U)) 
                                                 | (0x100U 
                                                    & ((~ 
                                                        ((IData)(vlTOPp->inputs) 
                                                         >> 9U)) 
                                                       << 8U))) 
                                                | (0x80U 
                                                   & ((~ 
                                                       ((IData)(vlTOPp->inputs) 
                                                        >> 8U)) 
                                                      << 7U))) 
                                               | (8U 
                                                  & ((~ 
                                                      ((IData)(vlTOPp->inputs) 
                                                       >> 7U)) 
                                                     << 3U))) 
                                              | ((4U 
                                                  & ((~ 
                                                      ((IData)(vlTOPp->inputs) 
                                                       >> 6U)) 
                                                     << 2U)) 
                                                 | ((2U 
                                                     & ((~ 
                                                         ((IData)(vlTOPp->inputs) 
                                                          >> 5U)) 
                                                        << 1U)) 
                                                    | (1U 
                                                       & (~ 
                                                          ((IData)(vlTOPp->inputs) 
                                                           >> 4U)))))));
    vlTOPp->top__DOT__joystick = (((0x80U & ((~ (IData)(vlTOPp->inputs)) 
                                             << 7U)) 
                                   | ((0x40U & ((~ 
                                                 ((IData)(vlTOPp->inputs) 
                                                  >> 1U)) 
                                                << 6U)) 
                                      | ((0x20U & (
                                                   (~ 
                                                    ((IData)(vlTOPp->inputs) 
                                                     >> 2U)) 
                                                   << 5U)) 
                                         | (0x10U & 
                                            ((~ ((IData)(vlTOPp->inputs) 
                                                 >> 3U)) 
                                             << 4U))))) 
                                  | ((8U & ((~ (IData)(vlTOPp->inputs)) 
                                            << 3U)) 
                                     | ((4U & ((~ ((IData)(vlTOPp->inputs) 
                                                   >> 1U)) 
                                               << 2U)) 
                                        | ((2U & ((~ 
                                                   ((IData)(vlTOPp->inputs) 
                                                    >> 2U)) 
                                                  << 1U)) 
                                           | (1U & 
                                              (~ ((IData)(vlTOPp->inputs) 
                                                  >> 3U)))))));
    vlTOPp->top__DOT__pause = (1U & ((IData)(vlTOPp->inputs) 
                                     >> 0xbU));
    vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__address_a 
        = (0x1fffU & (vlTOPp->ioctl_addr >> 0U));
    vlTOPp->top__DOT__ioctl_download = vlTOPp->ioctl_download;
    vlTOPp->top__DOT__ioctl_addr = vlTOPp->ioctl_addr;
    vlTOPp->top__DOT__ioctl_index = vlTOPp->ioctl_index;
    vlTOPp->top__DOT__ioctl_wr = vlTOPp->ioctl_wr;
    vlTOPp->top__DOT__ioctl_dout = vlTOPp->ioctl_dout;
    vlTOPp->top__DOT__clk_48 = vlTOPp->clk_48;
    vlTOPp->top__DOT__sharpx1__DOT__dma_di = vlTOPp->top__DOT__sharpx1__DOT__sdi;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP2 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_PS2C) 
            << 1U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_PS2D));
    vlTOPp->top__DOT__sharpx1__DOT__ne8M8 = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__ce)));
    vlTOPp->top__DOT__sharpx1__DOT__pe2M2 = (IData)(
                                                    (4U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__ce))));
    vlTOPp->top__DOT__sharpx1__DOT__ne2M2 = (IData)(
                                                    (0U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__ce))));
    vlTOPp->top__DOT__sharpx1__DOT__pe1M1 = (IData)(
                                                    (8U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__ce))));
    vlTOPp->top__DOT__sharpx1__DOT__ne1M1 = (IData)(
                                                    (0U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__ce))));
    vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__q_b = vlTOPp->top__DOT__sharpx1__DOT__romDo_SharpX1;
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__vramDo;
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__psgramDo;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__gramDo;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__di 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Arith16 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrC 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__B 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [0U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__C 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [0U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__D 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [1U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__E 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [1U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__H 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [2U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__L 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [2U];
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_set 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA4;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_clr 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA5;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_PS2DT 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP2));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_PS2CT 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP2) 
                 >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_FDC_DRQ_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_FD_LAMP 
        = (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP4));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_PCM 
        = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPB));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_res 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_set 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 2U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__num_7seg 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP7;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP0;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P2 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP2;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P3 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP3;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P4 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP4;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P5 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP5;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P6 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP6;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P7 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP7;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P8 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP8;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P9 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_PA 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_PB 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPB;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I4 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA4;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I5 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA5;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I6 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA6;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I7 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA7;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I8 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA8;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I9 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA9;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_IA 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IAA;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_IB 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IAB;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__ivector 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__S 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs_r;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__I0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__gpio_in_mux;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__DO 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__pgm_data;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_a;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_b;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__IX 
        = ((vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [3U] << 8U) | vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [3U]);
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__IY 
        = ((vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [7U] << 8U) | vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [7U]);
    vlTOPp->top__DOT__sharpx1__DOT__pe8M8 = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__ce));
    vlTOPp->top__DOT__sharpx1__DOT__ne4M4 = (IData)(
                                                    (0U 
                                                     == 
                                                     (3U 
                                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__ce))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__joya_emu 
        = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP6));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__joyb_emu 
        = (0xffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP6) 
                    >> 8U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_set 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA6;
    vlTOPp->top__DOT__sharpx1__DOT__dma_do = (0xffU 
                                              & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP0));
    vlTOPp->top__DOT__sharpx1__DOT__dma_bank = (0xfU 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9));
    vlTOPp->top__DOT__sharpx1__DOT__dma_a = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP8;
    vlTOPp->top__DOT__sharpx1__DOT__dma_mreq_n = (1U 
                                                  & (~ 
                                                     ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                                                      >> 0xcU)));
    vlTOPp->top__DOT__sharpx1__DOT__dma_iorq_n = (1U 
                                                  & (~ 
                                                     ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                                                      >> 0xdU)));
    vlTOPp->top__DOT__sharpx1__DOT__dma_rd_n = (1U 
                                                & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                                                    >> 0xeU)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_w8 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                 >> 7U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_irq 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl));
    vlTOPp->top__DOT__sharpx1__DOT__dma_wr_n = (1U 
                                                & ((~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                                                     >> 0xfU)) 
                                                   | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_BUSAK_n) 
                                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_STB_n))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_clr 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA7;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_TX_BSY 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_full;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_RX_BSY 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS) 
            & (3U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_fa)))) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_irq 
        = (2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_irq 
        = (2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__next_timer 
        = (0xffffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt) 
                      - (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl) 
                               >> 1U))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_KEY_BRK_n 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1) 
                 >> 2U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_clk1 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1) 
                 >> 4U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__irq_en 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1) 
                 >> 3U));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCH 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC];
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_BUSRQ_n 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                    >> 0xbU)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_frc 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_dir 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 3U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_ena 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 6U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_rd 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_a;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts 
        = (0xffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP3) 
                    | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq) 
                       << 1U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_req 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                 >> 8U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vector_a 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector) 
           << 1U);
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__zflag 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag) 
                 >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vflag 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag) 
                 >> 2U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__nflag 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag) 
                 >> 3U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cflag 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iflag 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag) 
                 >> 4U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                 >> 0xaU));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                 >> 8U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                 >> 9U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wram_data 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_b;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_ena 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 5U));
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__ramWe;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__ramDi;
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__psgramWe;
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__address_a 
        = (0x1fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__psgramA) 
                      >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__psgramDi;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__gramWe;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_a 
        = vlTOPp->top__DOT__sharpx1__DOT__gramA;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__gramDi;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_wr 
        = vlTOPp->top__DOT__sharpx1__DOT__sub_wr;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_rd 
        = vlTOPp->top__DOT__sharpx1__DOT__sub_rd;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_D 
        = vlTOPp->top__DOT__sharpx1__DOT__subDi;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_wd 
        = vlTOPp->top__DOT__sharpx1__DOT__subDi;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_MREQ_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__mreq)));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_IORQ_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__iorq)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_cmd_wr 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS) 
            & (0U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_fa)))) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_access 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_rd) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rw 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__dma_cs) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_rd) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__mreq 
        = vlTOPp->top__DOT__sharpx1__DOT__mreq;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__iorq 
        = vlTOPp->top__DOT__sharpx1__DOT__iorq;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wram_wr 
        = vlTOPp->top__DOT__sharpx1__DOT__sub_wr;
    vlTOPp->top__DOT__sharpx1__DOT__dma_int_n = (1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__dma_iei) 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s))));
    vlTOPp->top__DOT__sharpx1__DOT__ram_cs = vlTOPp->top__DOT__sharpx1__DOT__mreq;
    vlTOPp->top__DOT__sharpx1__DOT__dma_ieo = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__dma_iei) 
                                                & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s))) 
                                               & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_srv)));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r 
        = vlTOPp->top__DOT__sharpx1__DOT__iorq;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_a 
        = vlTOPp->top__DOT__sharpx1__DOT__ramA;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_a = vlTOPp->top__DOT__sharpx1__DOT__ramDo;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Z16 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_A 
        = vlTOPp->top__DOT__sharpx1__DOT__a;
    vlTOPp->top__DOT__sharpx1__DOT__romA = (0x3fffU 
                                            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__a));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__wr = vlTOPp->top__DOT__sharpx1__DOT__wr;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__rd = vlTOPp->top__DOT__sharpx1__DOT__rd;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__data_out 
        = vlTOPp->top__DOT__sharpx1__DOT__data_out;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__a = vlTOPp->top__DOT__sharpx1__DOT__a;
    vlTOPp->top__DOT__sharpx1__DOT__ipl_cs = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__mreq) 
                                                & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_RD_n))) 
                                               & (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_IPL_SEL)) 
                                              & (~ 
                                                 ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                                  >> 0xfU)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ISet 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IntCycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__ALU_Op 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__ISet 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BusA 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BusB 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_M1_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__m1)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busak_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__m1 = vlTOPp->top__DOT__sharpx1__DOT__m1;
    vlTOPp->top__DOT__sharpx1__DOT__halt_n = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF)));
    vlTOPp->top__DOT__sharpx1__DOT__pe4M4 = (IData)(
                                                    (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__ce))));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IR 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__F 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__NMICycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__IR 
        = (0x3fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                    >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__F_In 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode = 3U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode 
                                            = ((1U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                                                ? 2U
                                                : 1U);
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode = 0U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode = 0U;
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode = 2U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode = 0U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetDI = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetDI = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRS = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRS = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetEI = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetEI = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_SCF = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_SCF = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CCF = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CCF = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeAF = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeAF = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD = 0U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 5U)))) {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD = 5U;
                                        }
                                    }
                                }
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD = 4U;
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD = 7U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD = 6U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x36U == (0x3fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CPL = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CPL = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix = 3U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix = 2U;
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix = 3U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRp = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x36U != (0x3fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U != (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRp = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask 
        = ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
            ? ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                ? ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                    ? 0x80U : 0x40U) : ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                                         ? 0x20U : 0x10U))
            : ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                ? ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                    ? 8U : 4U) : ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                                   ? 2U : 1U)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry 
        = (IData)((1U == (5U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Carry_In 
        = (1U & (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r) 
                  >> 1U) ^ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry) 
                            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F))));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Sub 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B 
        = (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__A 
        = (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Vfuncout 
        = (0x1fU & (((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__A) 
                     + (0xfU & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Sub)
                                 ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B))
                                 : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B)))) 
                    + (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Carry_In)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v 
        = (1U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Vfuncout) 
                 >> 4U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Carry_In 
        = (1U & (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r) 
                  >> 1U) ^ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry) 
                            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F))));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Sub 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B 
        = (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__A 
        = (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Vfuncout 
        = (0x1fU & (((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__A) 
                     + (0xfU & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Sub)
                                 ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B))
                                 : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B)))) 
                    + (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Carry_In)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v 
        = ((0xf0U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v)) 
           | (0xfU & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Vfuncout)));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Carry_In 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Sub 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B 
        = (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                 >> 4U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__A 
        = (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                 >> 4U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Vfuncout 
        = (0xfU & (((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__A) 
                    + (7U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Sub)
                              ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B))
                              : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B)))) 
                   + (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Carry_In)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v 
        = (1U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Vfuncout) 
                 >> 3U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Carry_In 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Sub 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B 
        = (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                 >> 4U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__A 
        = (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                 >> 4U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Vfuncout 
        = (0xfU & (((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__A) 
                    + (7U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Sub)
                              ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B))
                              : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B)))) 
                   + (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Carry_In)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v 
        = ((0x8fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v)) 
           | (0x70U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Vfuncout) 
                       << 4U)));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Carry_In 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Sub 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                 >> 7U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__A 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                 >> 7U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Vfuncout 
        = (3U & (((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__A) 
                  + (1U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Sub)
                            ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B))
                            : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B)))) 
                 + (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Carry_In)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v 
        = (1U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Vfuncout) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Carry_In 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Sub 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                 >> 7U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__A 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                 >> 7U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Vfuncout 
        = (3U & (((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__A) 
                  + (1U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Sub)
                            ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B))
                            : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B)))) 
                 + (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Carry_In)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v 
        = ((0x7fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v)) 
           | (0x80U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Vfuncout) 
                       << 7U)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v) 
           ^ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeDH = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeDH = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__reset = (1U & (~ (IData)(vlTOPp->ioctl_download)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__MCycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__last_mcycle 
        = (1U & ((1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles))
                  ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)
                  : ((2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles))
                      ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                         >> 1U) : ((3U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles))
                                    ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                       >> 2U) : ((4U 
                                                  == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles))
                                                  ? 
                                                 ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 3U)
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles))
                                                   ? 
                                                  ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 4U)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles))
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 5U)
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles)) 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                       >> 6U)))))))));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait = 0U;
    if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle) 
         | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle))) {
        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait = 1U;
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mcycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RRD = 0U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 4U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 2U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RRD = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 0U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 1U)))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                }
            } else if ((6U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            }
        }
    } else if ((1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                             | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                >> 6U))))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
            }
        }
    } else if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            }
        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((1U & (~ 
                                                  ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            } else if ((6U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x36U != (0x3fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((6U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            }
        } else if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            }
        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                } else if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 3U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 1U)))) {
            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            }
        }
    } else if ((1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                             | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                >> 6U))))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        }
    } else if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    if ((6U != (7U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 2U)))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                                }
                                            }
                                        } else {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                    >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC = 0U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR = 0U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR = 1U;
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RLD = 0U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 4U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 2U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RLD = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op 
        = (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                 >> 3U));
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                                }
                                            }
                                        } else {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                        }
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                    >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xcU;
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                                }
                            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                        }
                                    }
                                } else {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                }
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            }
                        } else {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                    }
                }
            }
        }
    } else if ((1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                             | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                >> 6U))))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
            }
        } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 9U;
            }
        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                     | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                        >> 6U))))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                    }
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 8U;
            }
        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 8U;
        }
    } else if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 7U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xdU;
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 0xeU;
                            }
                        }
                    }
                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                    }
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                    }
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                }
            }
        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 3U)))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 3U)))) {
                                        if ((0x10U 
                                             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 3U)))) {
                                        if ((0x10U 
                                             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT = 0U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 0U;
    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                }
            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    }
                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle)))) {
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
        if (((0x36U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)) 
             | (1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet)))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC = 1U;
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                    }
                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 4U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle)))) {
                                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                        >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_DJNZ = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_DJNZ = 1U;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_DJNZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                        }
                                    } else if ((1U 
                                                & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    }
                                } else if ((1U & (~ 
                                                  ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    }
                                } else if ((1U & (~ 
                                                  ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    } else if ((8U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
                        }
                    }
                }
            }
        }
    }
    if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
        if ((1U & (~ ((0x36U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)) 
                      | (1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet)))))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read = 1U;
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                            } else if (
                                                       (0x10U 
                                                        & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    } else if ((1U 
                                                & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                        if ((0x10U 
                                             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         >> 1U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 2U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x36U != (0x3fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((6U != (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                        }
                    }
                }
            }
        } else if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 2U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                        }
                    }
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 3U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                        }
                    }
                }
            }
        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                }
            }
        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                    }
                }
            } else if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                    }
                }
            }
        }
    } else if ((1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 6U))))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         >> 6U))))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         >> 6U))))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 2U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 2U)))) {
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 2U)))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 2U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                 >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 0U;
    if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc 
                                                    = 
                                                    (7U 
                                                     & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                        >> 3U));
                                                vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF 
                                                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                                                vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__Vfuncout 
                                                    = 
                                                    (1U 
                                                     & ((4U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                         ? 
                                                        ((2U 
                                                          & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                           ? 
                                                          ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                           >> 7U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                            >> 7U)))
                                                          : 
                                                         ((1U 
                                                           & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                           ? 
                                                          ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                           >> 2U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                            >> 2U))))
                                                         : 
                                                        ((2U 
                                                          & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                           ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF)
                                                           : 
                                                          (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF)))
                                                          : 
                                                         ((1U 
                                                           & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                           ? 
                                                          ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                           >> 6U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                            >> 6U))))));
                                                if (vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__Vfuncout) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc 
                                                = (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF 
                                                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                         ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF)
                                                         : 
                                                        (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                          >> 6U))))));
                                            if (vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__Vfuncout) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc 
                                                = (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF 
                                                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                         ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF)
                                                         : 
                                                        (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                          >> 6U))))));
                                            if (vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__Vfuncout) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF 
                                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__Vfuncout) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc 
                                                = (7U 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF 
                                                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                                            vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                         ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF)
                                                         : 
                                                        (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                          >> 6U))))));
                                            if (vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__Vfuncout) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF 
                                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__Vfuncout) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF 
                                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__Vfuncout) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc 
                                    = (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF 
                                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                                vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__Vfuncout 
                                    = (1U & ((4U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                    >> 6U))))));
                                if (vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__Vfuncout) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle)))) {
                                        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                             >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                                 >> 3U)))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
