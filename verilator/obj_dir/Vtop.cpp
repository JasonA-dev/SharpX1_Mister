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

VL_INLINE_OPT void Vtop::_combo__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__3\n"); );
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
    vlTOPp->top__DOT__reset = vlTOPp->reset;
    vlTOPp->top__DOT__ioctl_download = vlTOPp->ioctl_download;
    vlTOPp->top__DOT__ioctl_wr = vlTOPp->ioctl_wr;
    vlTOPp->top__DOT__ioctl_addr = vlTOPp->ioctl_addr;
    vlTOPp->top__DOT__ioctl_index = vlTOPp->ioctl_index;
    vlTOPp->top__DOT__clk_12 = vlTOPp->clk_12;
    vlTOPp->top__DOT__sharpx1__DOT__reset = vlTOPp->top__DOT__reset;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_download 
        = vlTOPp->top__DOT__ioctl_download;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_wr = vlTOPp->top__DOT__ioctl_wr;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_addr = vlTOPp->top__DOT__ioctl_addr;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_index = vlTOPp->top__DOT__ioctl_index;
    vlTOPp->top__DOT__sharpx1__DOT__clk_sys = vlTOPp->top__DOT__clk_12;
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
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__ce_pix = ((IData)(vlTOPp->top__DOT__unnamedblk1__DOT__old_clk) 
                                & (~ (IData)(vlTOPp->clk_12)));
    vlTOPp->top__DOT__unnamedblk1__DOT__old_clk = vlTOPp->clk_12;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
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
    __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__data_out 
        = vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__d
        [vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__a];
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
        [vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_a];
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
    if (vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_a) {
        __Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_a;
        __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_a;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_b) {
        __Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_b;
        __Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 = 1U;
        __Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_b;
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

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
    if (((IData)(vlTOPp->clk_48) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_48)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_12) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_12)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk_48 = vlTOPp->clk_48;
    vlTOPp->__Vclklast__TOP__clk_12 = vlTOPp->clk_12;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_48 & 0xfeU))) {
        Verilated::overWidthError("clk_48");}
    if (VL_UNLIKELY((clk_12 & 0xfeU))) {
        Verilated::overWidthError("clk_12");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((inputs & 0xf000U))) {
        Verilated::overWidthError("inputs");}
    if (VL_UNLIKELY((ioctl_download & 0xfeU))) {
        Verilated::overWidthError("ioctl_download");}
    if (VL_UNLIKELY((ioctl_upload & 0xfeU))) {
        Verilated::overWidthError("ioctl_upload");}
    if (VL_UNLIKELY((ioctl_wr & 0xfeU))) {
        Verilated::overWidthError("ioctl_wr");}
    if (VL_UNLIKELY((ioctl_addr & 0xfe000000U))) {
        Verilated::overWidthError("ioctl_addr");}
}
#endif  // VL_DEBUG
