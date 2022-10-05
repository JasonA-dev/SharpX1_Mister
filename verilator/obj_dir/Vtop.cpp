// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

VerilatedContext* Vtop::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 6000)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 4, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 6000)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sim.v", 4, "",
                "Verilated model didn't DC converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__clk_48 = vlTOPp->clk_48;
    vlTOPp->top__DOT__inputs = vlTOPp->inputs;
    vlTOPp->top__DOT__ioctl_upload = vlTOPp->ioctl_upload;
    vlTOPp->top__DOT__ioctl_dout = vlTOPp->ioctl_dout;
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
    vlTOPp->top__DOT__ioctl_download = vlTOPp->ioctl_download;
    vlTOPp->top__DOT__ioctl_wr = vlTOPp->ioctl_wr;
    vlTOPp->top__DOT__ioctl_addr = vlTOPp->ioctl_addr;
    vlTOPp->top__DOT__ioctl_index = vlTOPp->ioctl_index;
    vlTOPp->top__DOT__clk_12 = vlTOPp->clk_12;
    vlTOPp->top__DOT__reset = vlTOPp->reset;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_download 
        = vlTOPp->top__DOT__ioctl_download;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_wr = vlTOPp->top__DOT__ioctl_wr;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_addr = vlTOPp->top__DOT__ioctl_addr;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_index = vlTOPp->top__DOT__ioctl_index;
    vlTOPp->top__DOT__sharpx1__DOT__clk_sys = vlTOPp->top__DOT__clk_12;
    vlTOPp->top__DOT__sharpx1__DOT__reset = vlTOPp->top__DOT__reset;
    vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__reset 
        = vlTOPp->top__DOT__sharpx1__DOT__reset;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__reset_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__reset;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__reset_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__reset_n;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ce_pix = ((IData)(vlTOPp->top__DOT__unnamedblk1__DOT__old_clk) 
                                & (~ (IData)(vlTOPp->clk_12)));
    vlTOPp->top__DOT__unnamedblk1__DOT__old_clk = vlTOPp->clk_12;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    SData/*11:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    SData/*12:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0;
    SData/*12:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    // Body
    __Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_b];
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_a];
    vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__address_b];
    vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__address_a];
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_b];
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_a];
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_b = 
        vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_b];
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_a = 
        vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__romA];
    if (vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_a) {
        __Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_a;
        __Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_a;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_b) {
        __Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_b;
        __Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_b;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__wren_a) {
        __Vdlyvval__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__data_a;
        __Vdlyvset__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__address_a;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__wren_b) {
        __Vdlyvval__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__data_b;
        __Vdlyvset__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__address_b;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__wren_a) {
        __Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__data_a;
        __Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_a;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__wren_b) {
        __Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__data_b;
        __Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_b;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_b) {
        __Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_b;
        __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_b;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__wr) {
        __Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__q;
        __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__romA;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__mem[__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__mem[__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__mem[__Vdlyvdim0__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__mem[__Vdlyvdim0__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__PCGRAM__DOT__mem__v1;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__mem[__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__mem[__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__mem[__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__mem[__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__top__DOT__sharpx1__DOT__pris32m;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__cpu_clk;
    // Body
    __Vdly__top__DOT__sharpx1__DOT__pris32m = vlTOPp->top__DOT__sharpx1__DOT__pris32m;
    __Vdly__top__DOT__sharpx1__DOT__cpu_clk = vlTOPp->top__DOT__sharpx1__DOT__cpu_clk;
    if (vlTOPp->reset) {
        __Vdly__top__DOT__sharpx1__DOT__pris32m = 0U;
        __Vdly__top__DOT__sharpx1__DOT__cpu_clk = 0U;
    } else {
        __Vdly__top__DOT__sharpx1__DOT__pris32m = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlTOPp->top__DOT__sharpx1__DOT__pris32m)));
        if ((IData)((3U == (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__pris32m))))) {
            __Vdly__top__DOT__sharpx1__DOT__cpu_clk 
                = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__cpu_clk)));
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__pris32m = __Vdly__top__DOT__sharpx1__DOT__pris32m;
    vlTOPp->top__DOT__sharpx1__DOT__cpu_clk = __Vdly__top__DOT__sharpx1__DOT__cpu_clk;
    vlTOPp->top__DOT__sharpx1__DOT__clk2M = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__pris32m) 
                                                   >> 3U));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__8\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__Vfuncout;
    CData/*6:0*/ __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc;
    CData/*6:0*/ __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__Vfuncout;
    CData/*2:0*/ __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num;
    CData/*7:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2;
    CData/*2:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    SData/*15:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
    // Body
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__sharpx1__DOT__wr = 1U;
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mcycle)))) {
            if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate) 
                  >> 1U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write))) {
                vlTOPp->top__DOT__sharpx1__DOT__wr = 0U;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__wr = 1U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__sharpx1__DOT__rd = 1U;
        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mcycle))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate))) {
                vlTOPp->top__DOT__sharpx1__DOT__rd 
                    = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n)));
            }
        } else if ((1U & ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate) 
                            >> 1U) & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read))) 
                          & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write))))) {
            vlTOPp->top__DOT__sharpx1__DOT__rd = 0U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__rd = 1U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__sharpx1__DOT__iorq = 1U;
        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mcycle))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate))) {
                vlTOPp->top__DOT__sharpx1__DOT__iorq 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n;
            }
        } else {
            if ((1U & ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate) 
                         >> 1U) & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read))) 
                       & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write))))) {
                vlTOPp->top__DOT__sharpx1__DOT__iorq 
                    = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq)));
            }
            if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate) 
                  >> 1U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write))) {
                vlTOPp->top__DOT__sharpx1__DOT__iorq 
                    = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq)));
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__iorq = 1U;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__sharpx1__DOT__mreq = 1U;
        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mcycle))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate))) {
                vlTOPp->top__DOT__sharpx1__DOT__mreq 
                    = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n)));
            }
        } else {
            if ((1U & ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate) 
                         >> 1U) & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__no_read))) 
                       & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write))))) {
                vlTOPp->top__DOT__sharpx1__DOT__mreq 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq;
            }
            if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate) 
                  >> 1U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write))) {
                vlTOPp->top__DOT__sharpx1__DOT__mreq 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__mreq = 1U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r = 0U;
    }
    if (vlTOPp->reset) {
        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg 
                = vlTOPp->top__DOT__sharpx1__DOT__romDo_Sharpx1;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg = 0U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles_d;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles = 0U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                          & (IData)((0U != (0xeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate)))))))) {
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRS) {
                    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate 
                        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate)));
                }
            }
        }
    } else {
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate = 0U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r 
                = ((((2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet)) 
                     & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op) 
                           >> 2U))) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op)) 
                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                      >> 2U));
            if ((1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                       & (IData)((0U != (0xeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))))))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
                    if ((1U & (((((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump)) 
                                  & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call))) 
                                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle))) 
                                & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle))) 
                               & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF) 
                                     | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt)))))) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC16;
                    }
                    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                        if ((3U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State 
                                = ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                                    ? 2U : 1U);
                        } else if ((2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State = 0U;
                        }
                    } else {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State = 0U;
                    }
                    if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle) 
                         & (1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus)))) {
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR = 0xffU;
                    } else if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF) 
                                 | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle) 
                                    & (2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus)))) 
                                | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle))) {
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR = 0U;
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr 
                            = ((0xff00U & (IData)(__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)) 
                               | (IData)(vlTOPp->top__DOT__sharpx1__DOT__romDo_Sharpx1));
                    } else {
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR 
                            = vlTOPp->top__DOT__sharpx1__DOT__romDo_Sharpx1;
                    }
                }
            } else {
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump) {
                        vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a 
                            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg) 
                                << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg) 
                                << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)));
                    } else if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY) {
                        vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC;
                    } else if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call) 
                                | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP))) {
                        vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
                    } else if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__last_mcycle) 
                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a = 0x66U;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC = 0x66U;
                    } else if (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 2U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle)) 
                                & (2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus)))) {
                        vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a 
                            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I) 
                                << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I) 
                                << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)));
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a 
                            = (0xffffU & ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To))
                                           ? ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To))
                                                   ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC)
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_WZ)
                                                    ? 
                                                   ((IData)(1U) 
                                                    + (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr))
                                                    : 
                                                   (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg) 
                                                     << 8U) 
                                                    | (0xffU 
                                                       & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)))))
                                               : ((1U 
                                                   & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To))
                                                   ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP)
                                                   : 
                                                  (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC) 
                                                    << 8U) 
                                                   | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg))))
                                           : ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To))
                                                   ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC)
                                                   : 
                                                  ((0U 
                                                    == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State))
                                                    ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NextIs_XY_Fetch)
                                                     ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC)
                                                     : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr))))
                                               : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC))));
                    }
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CPL) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC 
                            = (0xffU & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0xcfU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | (0x10U | (0x20U & 
                                           ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC) 
                                                >> 5U)) 
                                            << 5U))));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0xf7U & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | (8U & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC) 
                                            >> 3U)) 
                                        << 3U)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = (2U | (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                    }
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CCF) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0xfeU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F))));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0xc7U & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC)) 
                                  | ((0x10U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                               << 4U)) 
                                     | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC)))));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = (0xfdU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                    }
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_SCF) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = (1U | (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0xc7U & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | (0x28U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = (0xfdU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                    }
                }
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpE) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC16;
                    } else if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Inc_PC) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC16;
                    }
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP) {
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr 
                            = (0x38U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR));
                    }
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BTR_r) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC16;
                    }
                    if (((1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet)) 
                         & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                            >> 6U))) {
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR 
                            = vlTOPp->top__DOT__sharpx1__DOT__romDo_Sharpx1;
                    }
                }
                if ((1U & (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                            >> 2U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                                       >> 4U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))))) {
                    if ((7U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDec_16)))) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP16;
                    }
                }
                if ((1U & (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                            >> 3U) & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 5U)))) {
                    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP16;
                }
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL) {
                    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC;
                }
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeAF) {
                    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Ap;
                    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Fp;
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Ap 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC;
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Fp 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
                }
            }
            if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD))) {
                    if ((0U == (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD)))) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0xfbU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2) 
                                  << 2U));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0x3fU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I)) 
                                  | ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I)) 
                                     << 6U)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = (0xefU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = (0xfdU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                    } else if ((1U == (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD)))) {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0xfbU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2) 
                                  << 2U));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC = 0U;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = ((0x3fU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                               | ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I)) 
                                  | ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I)) 
                                     << 6U)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = (0xefU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                            = (0xfdU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                    } else if ((2U == (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC;
                    }
                }
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDZ) {
                    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr 
                        = ((0xff00U & (IData)(__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)) 
                           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg));
                }
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDW) {
                    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr 
                        = ((0xffU & (IData)(__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)) 
                           | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg) 
                              << 8U));
                }
            }
            if ((((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_DJNZ)) 
                  & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r)) 
                 | (9U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                    = ((1U & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                       | (0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)));
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC_r)))) {
                    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                        = ((0xfeU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                           | (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)));
                }
            }
            if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) 
                 & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_INRC))) {
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                    = (0xefU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                    = (0xfdU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                    = ((0x3fU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                       | ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg)) 
                          | ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg)) 
                             << 6U)));
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                    = ((0xfbU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                       | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg))) 
                                << 2U)));
            }
            if ((1U & (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                        >> 1U) & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1))))) {
                vlTOPp->top__DOT__sharpx1__DOT__q = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB;
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RLD) {
                    vlTOPp->top__DOT__sharpx1__DOT__q 
                        = ((0xf0U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                                     << 4U)) | (0xfU 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)));
                }
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RRD) {
                    vlTOPp->top__DOT__sharpx1__DOT__q 
                        = ((0xf0U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                     << 4U)) | (0xfU 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                                                   >> 4U)));
                }
            }
            if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                  >> 1U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT))) {
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                    = ((0xc7U & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                       | ((0x20U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Q) 
                                    << 4U)) | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Q))));
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                    = (0xfdU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F));
            }
            if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC) 
                 | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT))) {
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                    = ((0xfbU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)) 
                       | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDecZ) 
                          << 2U));
            }
            if ((1U & (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                          >> 1U) & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r))) 
                        & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1))) 
                       | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r) 
                          & (7U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r)))))) {
                if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                                    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
                                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_Mux;
                                }
                            } else {
                                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP 
                                    = ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r))
                                        ? ((0xffU & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP)) 
                                           | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_Mux) 
                                              << 8U))
                                        : ((0xff00U 
                                            & (IData)(vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP)) 
                                           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_Mux)));
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                        if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC 
                                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_Mux;
                            } else {
                                vlTOPp->top__DOT__sharpx1__DOT__q 
                                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_Mux;
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC = 0U;
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F = 0xffU;
        vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR = 0U;
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__q = 0U;
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC = 0xffU;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Ap = 0xffU;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Fp = 0xffU;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I = 0U;
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP = 0xffffU;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__wr;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__wr = vlTOPp->top__DOT__sharpx1__DOT__wr;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__rd = vlTOPp->top__DOT__sharpx1__DOT__rd;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__iorq 
        = vlTOPp->top__DOT__sharpx1__DOT__iorq;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__mreq 
        = vlTOPp->top__DOT__sharpx1__DOT__mreq;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Arith16 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__di 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__q;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__q = vlTOPp->top__DOT__sharpx1__DOT__q;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__a = vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a;
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            if ((3U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus = 0U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC_r 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC_r = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Z16 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r;
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r = 0U;
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r 
                    = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg) 
                        << 4U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To));
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Acc) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r = 0x17U;
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r = 0U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r = 0U;
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                          & (IData)((0U != (0xeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate)))))))) {
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op;
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r = 0U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                          & (IData)((0U != (0xeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate)))))))) {
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BTR_r 
                        = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT) 
                             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC)) 
                            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR)) 
                           & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__No_BTR)));
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BTR_r = 0U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            if ((1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                       & (IData)((0U != (0xeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))))))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet = 0U;
                    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                        if ((3U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet 
                                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix;
                        }
                    }
                }
            } else if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                if ((1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet = 1U;
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet = 0U;
    }
    if (vlTOPp->reset) {
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1 
            = ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res)) 
               & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait) 
                  | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i) 
                     & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2)))));
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2 
            = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1) 
               & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res)));
        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetEI) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle)))) {
                    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1 = 1U;
                }
                __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2 = 1U;
            }
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RETN) {
                __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2;
            }
        }
        if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetDI) {
                __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1 = 0U;
                __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2 = 0U;
            }
        }
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF = 0U;
        }
        if ((1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                      >> 2U)))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__m1 = 1U;
        }
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusReq_s) 
                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck))))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck = 0U;
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF = 1U;
                }
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusReq_s) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck = 1U;
                } else {
                    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate = 2U;
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NextIs_XY_Fetch) {
                        __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
                        __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__Vfuncout 
                            = ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                ? 7U : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                         ? 6U : ((0x10U 
                                                  & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                                  ? 5U
                                                  : 
                                                 ((8U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                                   ? 4U
                                                   : 
                                                  ((4U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                                    ? 3U
                                                    : 
                                                   ((2U 
                                                     & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                                     ? 2U
                                                     : 1U))))));
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M 
                            = __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__Vfuncout;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle = 0x20U;
                        if ((0x36U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                            __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M = 2U;
                        }
                    } else if ((0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                        __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num 
                            = (7U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M)));
                        __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__Vfuncout 
                            = ((1U == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                ? 1U : ((2U == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                         ? 2U : ((3U 
                                                  == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                                  ? 4U
                                                  : 
                                                 ((4U 
                                                   == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                                   ? 8U
                                                   : 
                                                  ((5U 
                                                    == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                                    ? 0x10U
                                                    : 
                                                   ((6U 
                                                     == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                                     ? 0x20U
                                                     : 
                                                    ((7U 
                                                      == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                                      ? 0x40U
                                                      : 0U)))))));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle 
                            = __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__Vfuncout;
                    } else if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__last_mcycle) 
                                 | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__No_BTR)) 
                                | ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                     >> 1U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_DJNZ)) 
                                   & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDecZ)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__m1 = 0U;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle = 1U;
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle = 0U;
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle = 0U;
                        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMI_s) 
                             & (0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix)))) {
                            __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle = 1U;
                            __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1 = 0U;
                        } else if (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1) 
                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__INT_s)) 
                                     & (0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) 
                                    & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetEI)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle = 1U;
                            __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1 = 0U;
                            __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2 = 0U;
                        }
                    } else {
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle 
                            = ((0x7eU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                         << 1U)) | 
                               (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 6U)));
                    }
                }
            } else if ((1U & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait) 
                                  & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2)))) 
                              & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i) 
                                    & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1))))))) {
                vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate 
                    = ((0x7eU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                                 << 1U)) | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                                                  >> 6U)));
            }
        }
        if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__m1 = 0U;
        }
    } else {
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1 = 0U;
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle = 1U;
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate = 1U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2 = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1 = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2 = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__m1 = 1U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__wr_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__wr;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__rd_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__rd;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__iorq;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mreq_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__mreq;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dout 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__q;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__A 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__a;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dout 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dout;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__A 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__A;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__ALU_Op 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ISet 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__ISet 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusReq_s = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__INT_s = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__halt_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__m1_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__m1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busak_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IntCycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle)));
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMI_s = 0U;
        } else if (((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__nmi)) 
                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Oldnmi_n))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMI_s = 1U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMI_s = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__No_BTR 
        = ((IData)(vlTOPp->reset) & ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT) 
                                       & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                              >> 4U)) 
                                          | (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                                >> 2U)))) 
                                      | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC) 
                                         & (IData)(
                                                   ((0x10U 
                                                     != 
                                                     (0x10U 
                                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) 
                                                    | (4U 
                                                       != 
                                                       (0x44U 
                                                        & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F))))))) 
                                     | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR) 
                                        & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U)) 
                                           | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                              >> 6U)))));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__halt_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__halt_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__m1_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__m1_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__busak_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busak_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__intcycle_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Oldnmi_n 
        = ((IData)(vlTOPp->reset) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__nmi));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__NMICycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IR 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__IR 
        = (0x3fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                    >> 0U));
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
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IMode 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__SetDI 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetDI;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeRS 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRS;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__SetEI 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SetEI;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_SCF 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_SCF;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_CCF 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CCF;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeAF 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeAF;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Special_LD 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Special_LD;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Halt 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_CPL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CPL;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeRp 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRp;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeDH 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeDH;
}

VL_INLINE_OPT void Vtop::_combo__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__9\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__cpu_clk;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__clk 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__clock;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__clk 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__clk;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__clk 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__clk;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__10(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__10\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    // Body
    __Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 0U;
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA_r 
            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEL) {
            __Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIL;
            __Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 1U;
            __Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA;
        }
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEH) {
            __Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIH;
            __Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 1U;
            __Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA;
        }
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA 
            = (0xffU & ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                         ? ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                             ? 0U : ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                                      ? 0U : ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                                               ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP) 
                                                  >> 8U)
                                               : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP))))
                         : ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                             ? ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                                 ? ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                                     ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC)
                                     : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg))
                                 : ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                                     ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA)
                                     : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA) 
                                        >> 8U))) : 
                            ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To))
                              ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA)
                              : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA) 
                                 >> 8U)))));
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC 
            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate) 
                << 2U) | (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_Addr_To)));
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC 
                = (2U | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate) 
                         << 2U));
        }
        if ((1U & ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY) 
                     | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL)) 
                    & (0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State))) 
                   | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                      >> 5U)))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC 
                = (3U | (4U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State) 
                               << 1U)));
        }
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB 
            = (0xffU & ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                         ? ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                             ? ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                                 ? 0U : ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                                          ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC) 
                                             >> 8U)
                                          : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC)))
                             : ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                                 ? ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                                     ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)
                                     : 1U) : ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                                               ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP) 
                                                  >> 8U)
                                               : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP))))
                         : ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                             ? ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                                 ? ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                                     ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC)
                                     : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg))
                                 : ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                                     ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusB)
                                     : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusB) 
                                        >> 8U))) : 
                            ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To))
                              ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusB)
                              : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusB) 
                                 >> 8U)))));
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB_r 
            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate) 
                << 2U) | (3U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To) 
                                >> 1U)));
        if ((((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind)) 
              & (0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State))) 
             & (2U == (3U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusB_To) 
                             >> 1U))))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB_r 
                = (3U | (4U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State) 
                               << 1U)));
        }
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA_r 
            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate) 
                << 2U) | (3U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To) 
                                >> 1U)));
        if ((((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind)) 
              & (0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State))) 
             & (2U == (3U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Set_BusA_To) 
                             >> 1U))))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA_r 
                = (3U | (4U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State) 
                               << 1U)));
        }
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_DJNZ) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDecZ 
                = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out) 
                         >> 6U));
        }
        if (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
               >> 2U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                          >> 3U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) 
             & (4U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDec_16))))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IncDecZ 
                = (0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ID16));
        }
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL[__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    }
    if (__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH[__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0] 
            = __Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__C 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [0U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__E 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [1U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__L 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [2U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__B 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [0U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__D 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [1U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__H 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [2U];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__IX 
        = ((vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [3U] << 8U) | vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [3U]);
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__IY 
        = ((vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [7U] << 8U) | vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [7U]);
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BusA 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrC 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCH 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BusB 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOCH 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCH;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOCL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCL;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCH) 
            << 8U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCL));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__11(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__11\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__sharpx1__DOT__romDo_Sharpx1 = 
        vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__d
        [(0x1fffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__romA))];
    vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__data_out 
        = vlTOPp->top__DOT__sharpx1__DOT__romDo_Sharpx1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__d = vlTOPp->top__DOT__sharpx1__DOT__romDo_Sharpx1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__d;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dinst 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__12(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__12\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate;
    vlTOPp->top__DOT__sharpx1__DOT__romA = (0x3fffU 
                                            & (IData)(vlTOPp->top__DOT__sharpx1__DOT____Vcellout__Cpu__a));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__JumpXY 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__LDSPHL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__F 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__F_In 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
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
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            if ((1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                       & (IData)((0U != (0xeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))))))) {
                if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
                    if ((0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                        if ((3U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                            if ((2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind = 0U;
                            }
                        }
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind = 0U;
                    }
                }
            } else if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind = 1U;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind = 0U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r = 0U;
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                          & (IData)((0U != (0xeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate)))))))) {
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU;
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__a 
        = (0x1fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__romA) 
                      >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_a 
        = vlTOPp->top__DOT__sharpx1__DOT__romA;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0xf0U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)) 
                           | (0xfU & ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))
                                       ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                                          >> 4U) : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB))));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = (0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = (0xfdU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xf7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0x1fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                              | (((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                                  << 6U) | (0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                                    << 2U)));
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0xf0U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)) 
                       | (0xfU & ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))
                                   ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                                      >> 4U) : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB))));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = (0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = (0xfdU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x1fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                          | (((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                              << 6U) | (0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                                << 2U)));
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA;
                if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F))) {
                    if ((1U & ((9U < (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                               | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                  >> 4U)))) {
                        if ((5U < (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                                = (0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
                        }
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = ((0x100U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)) 
                               | (0xffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                           - (IData)(6U))));
                    }
                    if ((1U & ((0x99U < (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)) 
                               | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                         - (IData)(0x160U)));
                    }
                } else {
                    if ((1U & ((9U < (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                               | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                  >> 4U)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                               | ((9U < (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                                  << 4U));
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(6U) 
                                         + (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                    }
                    if ((1U & ((9U < (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                               >> 4U))) 
                               | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(0x60U) 
                                         + (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                    }
                }
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xdfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                   >> 8U))));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x3fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)) 
                          | ((0U == (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                             << 6U)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                                << 2U)));
            }
        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))
                    ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                       & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask)))
                    : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                       | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask)));
        } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                   & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0x7fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = (0x40U | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = (4U | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = (0xbfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = (0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            }
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = (0x10U | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = (0xfdU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = (0xf7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = (0xdfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            if ((6U != (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR)))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xdfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB)));
            }
        } else {
            if ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                            = (0x7fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                        >> 1U));
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                               | (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)));
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                            = (1U | (0xfeU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                              << 1U)));
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                               | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                        >> 7U)));
                    }
                } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)) 
                           | (0x7fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                       >> 1U)));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)));
                } else {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = (0xfeU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                    << 1U));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                    >> 7U)));
                }
            } else if ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0x80U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                     << 7U)) | (0x7fU 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                                   >> 1U)));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)));
                } else {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0xfeU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                     << 1U)) | (1U 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                    >> 7U)));
                }
            } else if ((8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0x80U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                 << 7U)) | (0x7fU & 
                                            ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                             >> 1U)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)));
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0xfeU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                 << 1U)) | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                                  >> 7U)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                                >> 7U)));
            }
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = (0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = (0xfdU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0x1fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                      | (((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                          << 6U) | (0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                            << 2U)));
            if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x3fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0xc0U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)));
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
            = (0xfcU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfcU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (2U | (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v)))));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (0x10U & ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v)) 
                                       << 4U)));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                              << 2U));
                } else {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB));
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = (0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
                }
            } else if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                       ^ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = (0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA) 
                       & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB));
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = (0x10U | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            }
        } else if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfcU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (2U | (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v)))));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x10U & ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v)) 
                               << 4U)));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                      << 2U));
        } else {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfeU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xefU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v) 
                      << 4U));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                      << 2U));
        }
        if ((7U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB)));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xdfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB)));
        } else {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xdfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
        }
        if ((0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = (0x40U | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xbfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x40U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)));
            }
        } else {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = (0xbfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out));
        }
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
            = ((0x7fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
               | (0x80U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
        if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                           | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                                    << 2U)));
                }
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                                << 2U)));
            }
        }
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0x3fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0xc0U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)));
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out)) 
                   | (4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F)));
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Q 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t;
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
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__F_Out 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F_Out;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Q 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Q;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Prefix 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__CEN 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_Mux 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRp)
            ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB)
            : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Save_ALU_r)
                ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Q)
                : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeDH) 
            & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
               >> 3U)) ? (1U | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate) 
                                << 2U)) : (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB_r));
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
