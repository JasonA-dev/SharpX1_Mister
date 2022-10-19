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

VL_INLINE_OPT void Vtop::_combo__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_RESET 
        = (1U & (~ (IData)(vlTOPp->top__DOT__reset)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_reset 
        = (1U & (~ (IData)(vlTOPp->top__DOT__reset)));
    vlTOPp->top__DOT__sharpx1__DOT__reset = vlTOPp->top__DOT__reset;
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
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_RESET 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_reset;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__reset_n 
        = vlTOPp->top__DOT__sharpx1__DOT__reset;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_download 
        = vlTOPp->top__DOT__ioctl_download;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_addr = vlTOPp->top__DOT__ioctl_addr;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_index = vlTOPp->top__DOT__ioctl_index;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_wr = vlTOPp->top__DOT__ioctl_wr;
    vlTOPp->top__DOT__sharpx1__DOT__ioctl_dout = vlTOPp->top__DOT__ioctl_dout;
    vlTOPp->top__DOT__sharpx1__DOT__clk_sys = vlTOPp->top__DOT__clk_48;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reset 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_RESET;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_RESET 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_RESET;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__reset_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__reset_n;
    vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__ioctl_wr;
    vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__ioctl_dout;
    vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_CLK 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_clk 
        = vlTOPp->top__DOT__sharpx1__DOT__clk_sys;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__reset_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__reset_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__clk 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__clock;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__CLK 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_clk;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__clock 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_clk;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLK 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_clk;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__clk 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__clk;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__clk 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLK;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_CLK 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLK;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__clk 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__clk;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vtableidx1;
    SData/*10:0*/ __Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr;
    // Body
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1 = 0U;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 0U;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__ramA = vlTOPp->top__DOT__sharpx1__DOT__ramA;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0 = 0U;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_b];
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__address_b];
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_b];
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_b = 
        vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_b];
    vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__q_a = 
        vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__mem
        [(0x1fffU & vlTOPp->ioctl_addr)];
    vlTOPp->top__DOT__ce_pix = ((IData)(vlTOPp->top__DOT__unnamedblk1__DOT__old_clk) 
                                & (~ (IData)(vlTOPp->clk_12)));
    vlTOPp->top__DOT__sharpx1__DOT__vramDo = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__mem
        [(0xfffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__vramA))];
    if (vlTOPp->top__DOT__sharpx1__DOT__vramWe) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__vramDi;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0 
            = (0xfffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__vramA));
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__wren_b) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__data_b;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_b;
    }
    if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_cycle) 
         & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_RD_n)))) {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_d_r 
            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_D;
    }
    if (vlTOPp->ioctl_wr) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0 
            = vlTOPp->ioctl_dout;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0 
            = (0x1fffU & vlTOPp->ioctl_addr);
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__wren_b) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__data_b;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1 
            = (0x1fffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__romA));
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs_r 
        = ((IData)(vlTOPp->top__DOT__reset) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs));
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_acc1) 
             & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_access)))) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_irq = 1U;
        } else if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_iack) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_irq = 0U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_irq = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ack) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r = 0U;
        } else if ((2U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r))) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r 
                = ((2U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r) 
                          << 1U)) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_PS2C));
        }
    } else {
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_ack) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r = 0U;
        } else if ((2U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r))) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r 
                = ((2U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r) 
                          << 1U)) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_cmd_wr));
        }
    } else {
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_ack) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r = 0U;
        } else if ((2U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r))) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r 
                = ((2U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r) 
                          << 1U)) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rw));
        }
    } else {
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__main_we) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_full = 1U;
        } else if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_clr) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_full = 0U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_full = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__romDo_SharpX1 = 
        vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__mem
        [(0x1fffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__romA))];
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__main_re) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full = 0U;
        } else if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_set) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full = 1U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full = 0U;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA_r 
            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__mem_we) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1 
            = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wdata));
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1 
            = (0x3ffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__mem_addr));
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wram_wr) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0 
            = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_rd));
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_a;
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_a];
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__drq_set) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq = 1U;
        } else if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__drq_clr) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq = 0U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_r)) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_n))) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_cyc = 0U;
        }
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_req) {
            if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_rdy) 
                  & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_r)) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_n)))) {
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_rdy = 0U;
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_cyc = 1U;
            }
        } else {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_rdy = 1U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_rdy = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_cyc = 0U;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEL) {
            vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIL;
            vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 = 1U;
            vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA;
        }
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
        if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEH) {
            vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIH;
            vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 = 1U;
            vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0 
                = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA;
        }
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
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_set) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req = 1U;
        }
        if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_IEI) 
              & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_SPM1)) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s))) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_srv = 1U;
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req = 0U;
        }
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_RETI) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_srv = 0U;
        }
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_res) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req = 0U;
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_srv = 0U;
        }
    } else {
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_srv = 0U;
    }
    __Vtableidx1 = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_irq) 
                     << 5U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellinp__sub_cpu__I_INT) 
                                << 1U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n)));
    if (vlTOPp->__Vtablechg1[__Vtableidx1]) {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector 
            = vlTOPp->__Vtable1_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector
            [__Vtableidx1];
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_access) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_acc_port 
                = ((0xeU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_fa) 
                            << 1U)) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_rd));
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__gramDo = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__gramA];
    vlTOPp->top__DOT__sharpx1__DOT__psgramDo = vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__mem
        [(0x1fffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__psgramA))];
    if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_load) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_in;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_addr;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_load) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_in;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_addr;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_b) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_b;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_b;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__ramWe) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__ramDi;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__ramA;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_b) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_b;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_b;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__gramWe) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__gramDi;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__gramA;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__wren_b) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__data_b;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1 
            = vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__address_b;
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__psgramWe) {
        vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0 
            = vlTOPp->top__DOT__sharpx1__DOT__psgramDi;
        vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0 
            = (0x1fffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__psgramA));
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs_r 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__msel 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__pgm_cs;
    __Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__mem_addr;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__Vfuncout 
        = ((0x400U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
            ? ((0x200U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                ? ((0x100U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                    ? ((0x80U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                        ? ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? 0U : ((4U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 
                                                ((2U 
                                                  & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0U
                                                   : 0x39U))
                                                 : 
                                                ((2U 
                                                  & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0x3837U
                                                   : 0x3635U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0x3433U
                                                   : 0x3231U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x302eU
                                                    : 0xd2bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2d2aU
                                                    : 0x2f0bU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c1fU
                                                    : 0x1d1eU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb0fU
                                                    : 0xe00U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0U
                                                    : 0x13feU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xdU
                                                    : 0U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0U
                                                    : 0x401dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e00U
                                                    : 0x3039U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3837U
                                                    : 0x3635U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3433U
                                                    : 0x3231U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xff39U
                                                    : 0x3837U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3635U
                                                    : 0x3433U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3231U
                                                    : 0x302eU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd2bU
                                                    : 0x2d2aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f0cU
                                                    : 0x1c1fU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d1eU
                                                    : 0xc0fU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe12U
                                                    : 0x127aU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7978U
                                                    : 0x7776U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3feU
                                                    : 0x1b1bU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x920U
                                                    : 0x120dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5f3fU
                                                    : 0x3e3cU))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2a2bU
                                                    : 0x7c7bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x607dU
                                                    : 0x603dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7e29U
                                                    : 0x2827U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2625U
                                                    : 0x2423U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2221U
                                                    : 0xff39U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3837U
                                                    : 0x3635U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3433U
                                                    : 0x3231U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x302eU
                                                    : 0xd2bU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2d2aU
                                                    : 0x2f0bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c1fU
                                                    : 0x1d1eU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb0fU
                                                    : 0xe08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x875U
                                                    : 0x7473U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7271U
                                                    : 0x13feU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1b1bU
                                                    : 0x920U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x80dU
                                                    : 0x5f2fU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2e2cU
                                                    : 0x3a3bU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5c5bU
                                                    : 0x405dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5e2dU
                                                    : 0x3039U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3837U
                                                    : 0x3635U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3433U
                                                    : 0x3231U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0U
                                                    : 0x4000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x41U
                                                    : 0U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0U
                                                    : 0x4346U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x45U
                                                    : 0x3f3eU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0U
                                                    : 0x42U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x4400U
                                                    : 0U))
                                            : 0U) : 
                                       ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? 0U : 
                                            ((1U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                              ? 0x4cU
                                              : 0U))
                                         : 0U))))) : 
                       ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                         ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                             ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                 ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                     ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? 0U : 
                                            ((1U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                              ? 0x48U
                                              : 0U))
                                         : 0U) : 0U)
                                 : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                     ? 0U : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                              ? 0U : 
                                             ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                               ? ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0U
                                                   : 0x88U)
                                               : ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0U
                                                   : 0x8c00U)))))
                             : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                 ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                     ? 0U : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                              ? ((2U 
                                                  & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0x38U
                                                   : 0x5749U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0x4a51U
                                                   : 0x4b00U))
                                              : ((2U 
                                                  & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0x4736U
                                                   : 0x5654U)
                                                  : 
                                                 ((1U 
                                                   & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                   ? 0x5350U
                                                   : 0x4d4eU))))
                                 : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                     ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0U
                                                 : 0x55U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x522aU
                                                 : 0x4f00U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x32U
                                                 : 0x37U)
                                             : 0U))
                                     : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0U
                                                 : 0x2700U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x2931U
                                                 : 0x8983U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0U
                                                 : 0x2628U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x2cU
                                                 : 0x3000U))))))
                         : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                             ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                 ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                     ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x25U
                                                 : 0x102bU)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0xc2fU
                                                 : 0x2e00U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x23U
                                                 : 0x240fU)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x90bU
                                                 : 0x2d00U)))
                                     : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x22U
                                                 : 0x2115U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0xa0dU
                                                 : 0U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x20U
                                                 : 0x1907U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x802U
                                                 : 0xe00U))))
                                 : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                     ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x1fU
                                                 : 0x1214U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x616U
                                                 : 0x3300U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x1dU
                                                 : 0x1e05U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x418U
                                                 : 0x300U)))
                                     : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x1cU
                                                 : 0x1701U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x131aU
                                                 : 0U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x1bU
                                                 : 0x1180U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x8281U
                                                 : 0x8400U)))))
                             : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                 ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                     ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x35U
                                                 : 0x343cU)
                                             : 0U) : 
                                        ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                          ? ((1U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                              ? 0xff3aU
                                              : 0x393bU)
                                          : ((1U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                              ? 0x3d00U
                                              : 0U)))
                                     : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0xf00U
                                                 : 0x1b13U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x7100U
                                                 : 0x2780U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x1010U
                                                 : 0x710aU)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x270cU
                                                 : 0x702eU))))
                                 : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                     ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x2711U
                                                 : 0xf00U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0xf00U
                                                 : 0x1e09U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x7000U
                                                 : 0x29fdU)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0xc000U
                                                 : 0x2702U)))
                                     : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0xe00U
                                                 : 0xf00U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x29faU
                                                 : 0xc000U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x2701U
                                                 : 0xe00U)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x1e09U
                                                 : 0x7000U))))))))
                    : ((0x80U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                        ? ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2708U
                                                    : 0x2f04U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f0fU
                                                    : 0x270eU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x6000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2730U
                                                    : 0x2103U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc108U
                                                    : 0x7000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2718U
                                                    : 0x1206U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x9002U
                                                    : 0x2902U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc110U
                                                    : 0x7001U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2905U
                                                    : 0xc120U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x21cU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x3f00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf01U
                                                    : 0x1f01U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf01U
                                                    : 0x1f01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf01U
                                                    : 0x1f01U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0xf11U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf21U
                                                    : 0x1e09U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x2903U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc020U
                                                    : 0x20fU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29bdU
                                                    : 0xc000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0xe00U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2108U
                                                    : 0xc060U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x20fU
                                                    : 0x1201U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f0cU
                                                    : 0x1e0aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x120eU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x40bfU
                                                    : 0x20eU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2807U
                                                    : 0x1e07U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x9001U
                                                    : 0x201U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x721aU
                                                    : 0x2711U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e09U
                                                    : 0x7000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2708U
                                                    : 0x1e09U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6000U
                                                    : 0x2780U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x204U
                                                    : 0x2fc9U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270dU
                                                    : 0xf11U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1202U
                                                    : 0x8000U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3018U
                                                    : 0x216U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x202U
                                                    : 0x1f11U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e09U
                                                    : 0x204U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e09U
                                                    : 0x6000U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2780U
                                                    : 0x204U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e08U
                                                    : 0x202U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x229U
                                                    : 0x721aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2711U
                                                    : 0x1e00U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe00U
                                                    : 0x2fc9U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270dU
                                                    : 0x1e09U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x2708U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf11U
                                                    : 0x1202U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8000U
                                                    : 0x3018U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x216U
                                                    : 0x202U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f11U
                                                    : 0x1e09U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x204U
                                                    : 0x1e08U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x202U
                                                    : 0x228U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x721aU
                                                    : 0x2711U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ff9U
                                                    : 0x270dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f21U
                                                    : 0x1f11U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f88U
                                                    : 0x7102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2701U
                                                    : 0x2f8bU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7101U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fedU
                                                    : 0x7100U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2701U
                                                    : 0x6008U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2105U
                                                    : 0xc008U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70fU
                                                    : 0x3107U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f95U
                                                    : 0xc018U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x710cU
                                                    : 0x270dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f00U
                                                    : 0x3f80U)))))))
                        : ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e07U
                                                    : 0x70e0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x27eeU
                                                    : 0x2106U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc063U
                                                    : 0x170fU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3017U
                                                    : 0x2ff6U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe100U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x42ffU
                                                    : 0x729U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6008U
                                                    : 0x2107U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc008U
                                                    : 0x2fc1U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1729U
                                                    : 0x3215U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x4200U
                                                    : 0x27ffU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x729U
                                                    : 0x6004U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2108U
                                                    : 0xc004U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x705U
                                                    : 0x3107U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fb6U
                                                    : 0x171eU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fc5U
                                                    : 0x171dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6008U
                                                    : 0x2104U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc008U
                                                    : 0x704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3107U
                                                    : 0x2fbfU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x170cU
                                                    : 0x2fc1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x170bU
                                                    : 0x2fc3U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x172aU
                                                    : 0x3215U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe100U
                                                    : 0x2701U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x42ffU
                                                    : 0x72aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fceU
                                                    : 0x172aU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3215U
                                                    : 0x4200U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x27ffU
                                                    : 0x72aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6020U
                                                    : 0x2108U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc020U
                                                    : 0x2ff6U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe100U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x42ffU
                                                    : 0x728U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6010U
                                                    : 0x2107U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc010U
                                                    : 0x2fdfU))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1728U
                                                    : 0x3215U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x4200U
                                                    : 0x27ffU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x728U
                                                    : 0x6008U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2108U
                                                    : 0xc008U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x701U
                                                    : 0x3107U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fe5U
                                                    : 0xc01cU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x71ccU
                                                    : 0x270cU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1705U
                                                    : 0x2feaU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc018U
                                                    : 0x71baU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270cU
                                                    : 0x2f5dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270bU
                                                    : 0x2103U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc040U
                                                    : 0x1704U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ff2U
                                                    : 0x71b6U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270cU
                                                    : 0x1703U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ff7U
                                                    : 0xc078U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x716cU
                                                    : 0x270cU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1701U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1710U
                                                    : 0x710aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270cU
                                                    : 0x2903U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc040U
                                                    : 0x71b2U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270cU
                                                    : 0x1702U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x1706U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x71b6U
                                                    : 0x270cU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29ccU
                                                    : 0x270bU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc001U
                                                    : 0x2123U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc002U
                                                    : 0x211cU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc003U
                                                    : 0x2115U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc080U
                                                    : 0x210eU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc083U
                                                    : 0x211eU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc087U
                                                    : 0xb82U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb76U
                                                    : 0xb48U)
                                                : 0xb48U))))))))
                : ((0x100U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                    ? ((0x80U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                        ? ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb48U
                                                    : 0xb6cU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb48U
                                                    : 0xb66U))
                                            : 0xb48U)
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? 0xb48U
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? 0xb48U
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb56U
                                                    : 0xb48U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f02U
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x80e0U
                                                    : 0x270bU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x403eU
                                                    : 0xf000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2780U
                                                    : 0x28bcU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd0d4U
                                                    : 0x1707U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fbfU
                                                    : 0x1101U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x9001U
                                                    : 0x2902U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3005U
                                                    : 0x70aU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x711aU
                                                    : 0x2711U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf21U
                                                    : 0xf31U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1204U
                                                    : 0x5000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2780U
                                                    : 0x2fd9U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270dU
                                                    : 0xf21U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1204U
                                                    : 0x5000U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2740U
                                                    : 0x2fd9U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270dU
                                                    : 0x3217U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f21U
                                                    : 0x1329U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1318U
                                                    : 0x9202U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8102U
                                                    : 0x2903U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc004U
                                                    : 0x701U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3317U
                                                    : 0x721cU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2711U
                                                    : 0x711aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2711U
                                                    : 0x1f31U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f21U
                                                    : 0x1103U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x709U
                                                    : 0x1102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x708U
                                                    : 0x711aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2711U
                                                    : 0x2f61U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fedU
                                                    : 0x1710U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7174U
                                                    : 0x270bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ff1U
                                                    : 0x5101U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x716U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e0aU
                                                    : 0x3015U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x714U
                                                    : 0x706U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1714U
                                                    : 0x5140U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x714U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1714U
                                                    : 0x41bfU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x714U
                                                    : 0x1716U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x41feU
                                                    : 0x716U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf90U
                                                    : 0xff1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf01U
                                                    : 0xf11U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf71U
                                                    : 0x2f29U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270dU
                                                    : 0x2103U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc000U
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe00U
                                                    : 0x3f13U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x710U
                                                    : 0x772eU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2711U
                                                    : 0x1b13U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7100U
                                                    : 0x2780U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2308U
                                                    : 0x3005U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb03U
                                                    : 0x1f71U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f11U
                                                    : 0x1f01U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1ff1U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1200U
                                                    : 0x7000U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1212U
                                                    : 0x1201U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7107U
                                                    : 0x7000U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2780U
                                                    : 0x72faU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x2f0dU)))))))
                        : ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270bU
                                                    : 0x7101U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x72f4U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x1a08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x1b0cU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7080U
                                                    : 0x1b0bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7010U
                                                    : 0x1b0aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7001U
                                                    : 0x1b09U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0xf00U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf31U
                                                    : 0x3235U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe200U
                                                    : 0x2701U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fadU
                                                    : 0x270aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3327U
                                                    : 0x2fadU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270aU
                                                    : 0x1f31U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x3f90U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e29U
                                                    : 0x42ffU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe20U
                                                    : 0x29fdU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc200U
                                                    : 0x2702U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe20U
                                                    : 0xa100U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8001U
                                                    : 0x1e19U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5100U
                                                    : 0x2751U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e08U
                                                    : 0x3f80U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x3f30U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f5bU
                                                    : 0x270aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x3f20U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2903U
                                                    : 0xd200U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcdU
                                                    : 0x270aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2907U
                                                    : 0xd2b0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2702U
                                                    : 0x2fcdU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270aU
                                                    : 0xa100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8004U
                                                    : 0x2f0eU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2102U
                                                    : 0xd220U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2104U
                                                    : 0xd210U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2106U
                                                    : 0xd200U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fadU
                                                    : 0x270aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a38U
                                                    : 0x5340U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa38U
                                                    : 0x2104U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd200U
                                                    : 0x2fadU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270aU
                                                    : 0xa100U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3028U
                                                    : 0x721aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa1bU
                                                    : 0xa0aU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f5bU
                                                    : 0x270aU)
                                                : 0xf00U)
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a1bU
                                                    : 0x1a0aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa100U
                                                    : 0x800cU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a27U
                                                    : 0x2fadU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270aU
                                                    : 0x1a26U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fadU
                                                    : 0x270aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a25U
                                                    : 0x2fadU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270aU
                                                    : 0x1a24U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fadU
                                                    : 0x270aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ff8U
                                                    : 0xa100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3028U
                                                    : 0x2fcdU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270aU
                                                    : 0xa100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x800eU
                                                    : 0x2008U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x9301U
                                                    : 0x1a39U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7300U
                                                    : 0x1a30U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8301U
                                                    : 0xa30U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2005U
                                                    : 0x332dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8301U
                                                    : 0xa39U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb100U
                                                    : 0x9006U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcdU
                                                    : 0x270aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa100U
                                                    : 0x8004U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x312aU
                                                    : 0x3038U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa1bU
                                                    : 0xa0aU))))))))
                    : ((0x80U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                        ? ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcdU
                                                    : 0x270aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3327U
                                                    : 0x2fcdU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270aU
                                                    : 0xa100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3028U
                                                    : 0xa1bU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa2aU
                                                    : 0x8020U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe004U
                                                    : 0x2f71U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2709U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f20U
                                                    : 0x1a07U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7001U
                                                    : 0x1a08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x40c7U
                                                    : 0xa08U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a1bU
                                                    : 0x1a0aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x312aU
                                                    : 0xa2bU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3028U
                                                    : 0xa2aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf100U
                                                    : 0x2701U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe000U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3107U
                                                    : 0x3028U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe010U
                                                    : 0x9201U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a26U
                                                    : 0x8201U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a29U
                                                    : 0x7200U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a20U
                                                    : 0x8201U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa20U
                                                    : 0x2005U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd210U
                                                    : 0x8201U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa29U
                                                    : 0x1a15U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x4101U
                                                    : 0x3107U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a14U
                                                    : 0xf100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2780U
                                                    : 0x3107U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f71U
                                                    : 0x2709U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x282aU
                                                    : 0x2f5dU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270aU
                                                    : 0x2f71U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2709U
                                                    : 0xf00U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5001U
                                                    : 0x2102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc110U
                                                    : 0xb1cU))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3008U
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a2bU
                                                    : 0x1a1aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x22U
                                                    : 0x11U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f01U
                                                    : 0x2709U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x1a08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x40fbU
                                                    : 0xa08U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1010U
                                                    : 0x712bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2003U
                                                    : 0xd12bU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x1a08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5004U
                                                    : 0xa08U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1010U
                                                    : 0x7100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2807U
                                                    : 0xd101U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x10U
                                                    : 0x2f01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2709U
                                                    : 0x2f04U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1010U
                                                    : 0x9102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2902U
                                                    : 0xc610U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8101U
                                                    : 0x10U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f01U
                                                    : 0x2709U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f71U
                                                    : 0x2705U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x71a0U
                                                    : 0x7000U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ff7U
                                                    : 0x21fbU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5180U
                                                    : 0x70f4U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x1e04U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0xf00U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a18U
                                                    : 0x1a0dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x417fU
                                                    : 0x80f4U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0xe006U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e14U
                                                    : 0x8101U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3107U
                                                    : 0x4001U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x290cU
                                                    : 0xc002U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x210eU
                                                    : 0xc080U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa18U
                                                    : 0xb0cU)))))))
                        : ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f4eU
                                                    : 0x2706U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f4eU
                                                    : 0x2706U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ffcU
                                                    : 0x3f80U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e07U
                                                    : 0x70f0U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x27ffU
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f90U
                                                    : 0x1e13U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3125U
                                                    : 0x3206U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3205U
                                                    : 0xe23U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3104U
                                                    : 0xa18U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f80U
                                                    : 0x70c6U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2902U
                                                    : 0xc780U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70c8U
                                                    : 0x2f4bU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2709U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f30U
                                                    : 0x1e13U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5110U
                                                    : 0xe13U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fdfU
                                                    : 0xf00U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f20U
                                                    : 0x2fe2U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fb1U
                                                    : 0x2705U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf000U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x804eU
                                                    : 0xa01U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2108U
                                                    : 0x301dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa14U
                                                    : 0xb09U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcfU
                                                    : 0x2708U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a01U
                                                    : 0x3008U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2002U
                                                    : 0x9101U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3008U
                                                    : 0x2005U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x9101U
                                                    : 0x3008U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2008U
                                                    : 0x9101U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7080U
                                                    : 0xa17U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x201cU
                                                    : 0x2f8bU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2709U
                                                    : 0x2820U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd005U
                                                    : 0xa00U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ff7U
                                                    : 0x2fb1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x7002U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x2102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc000U
                                                    : 0x2701U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe03U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fd2U
                                                    : 0x2fb1U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x7004U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fe2U
                                                    : 0xe06U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2103U
                                                    : 0x1a01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x9001U
                                                    : 0xa01U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f90U
                                                    : 0x1e09U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x29fdU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc000U
                                                    : 0x2702U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe00U
                                                    : 0xf11U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1a0aU
                                                    : 0x1a1bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa100U
                                                    : 0x8001U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e19U
                                                    : 0x5100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2791U
                                                    : 0xa1bU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e08U
                                                    : 0xa0aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f11U
                                                    : 0x1e00U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb0bU
                                                    : 0x3f80U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fb1U
                                                    : 0x2705U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7002U
                                                    : 0xc701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe06U
                                                    : 0x2f4eU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2706U
                                                    : 0x2fbbU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1b0aU
                                                    : 0x40ffU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8001U
                                                    : 0xb0aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x214eU
                                                    : 0x2706U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc710U
                                                    : 0x2fb1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x7004U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29ecU
                                                    : 0x9301U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe06U
                                                    : 0x3f90U))))))))))
            : ((0x200U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                ? ((0x100U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                    ? ((0x80U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                        ? ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e09U
                                                    : 0x7000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1b0bU
                                                    : 0x40ffU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe00U
                                                    : 0x29fdU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc000U
                                                    : 0x2702U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe00U
                                                    : 0xa200U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8101U
                                                    : 0x1e29U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e18U
                                                    : 0x3f80U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fb1U
                                                    : 0x2705U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7002U
                                                    : 0xa31U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5200U
                                                    : 0x2751U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xa2bU
                                                    : 0xa1aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2928U
                                                    : 0xc720U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e03U
                                                    : 0x40f7U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe03U
                                                    : 0x2fe7U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e03U
                                                    : 0x5008U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe03U
                                                    : 0x2105U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc008U
                                                    : 0xa08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29eeU
                                                    : 0x301dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb1aU
                                                    : 0xa06U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29f2U
                                                    : 0xc001U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6001U
                                                    : 0x2102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc708U
                                                    : 0xa05U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2107U
                                                    : 0xc702U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2b6cU
                                                    : 0x2706U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x300cU
                                                    : 0xb08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2042U
                                                    : 0x2f81U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2708U
                                                    : 0x1a00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0xc000U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2702U
                                                    : 0xe03U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2104U
                                                    : 0xc720U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5601U
                                                    : 0x2002U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd02cU
                                                    : 0xb09U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x46feU
                                                    : 0x2f6dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2708U
                                                    : 0x2fb1U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x70a9U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2703U
                                                    : 0x2105U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc704U
                                                    : 0x5608U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29eeU
                                                    : 0xc080U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe03U
                                                    : 0x2fb1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x7010U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcfU
                                                    : 0x2708U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e03U
                                                    : 0x5001U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x4080U
                                                    : 0xe03U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f4eU
                                                    : 0x2706U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e13U
                                                    : 0x5140U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe13U
                                                    : 0x2f4eU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2706U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5608U
                                                    : 0x2fb1U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x70a9U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2703U
                                                    : 0x2105U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc704U
                                                    : 0x2f8dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e13U
                                                    : 0x41f7U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe13U
                                                    : 0x3034U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2707U
                                                    : 0x2f81U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2708U
                                                    : 0x1a00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x2f37U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2707U
                                                    : 0x210cU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc704U
                                                    : 0x21d0U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc7e0U
                                                    : 0x2fb1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x7053U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2707U
                                                    : 0x2103U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc701U
                                                    : 0x70e2U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x2107U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc702U
                                                    : 0x3008U)))))))
                        : ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x210aU
                                                    : 0xc703U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7077U
                                                    : 0x2701U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f31U
                                                    : 0x2709U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f14U
                                                    : 0x1b09U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x2104U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc004U
                                                    : 0xe03U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2907U
                                                    : 0xc610U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcfU
                                                    : 0x2708U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1b09U
                                                    : 0x9002U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2902U
                                                    : 0xc610U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8001U
                                                    : 0xb09U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2107U
                                                    : 0xc710U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6610U
                                                    : 0x2102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc720U
                                                    : 0x5610U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f07U
                                                    : 0x6610U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2802U
                                                    : 0x212dU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x301dU
                                                    : 0xb19U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb0bU
                                                    : 0x5610U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5710U
                                                    : 0x1b1bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7100U
                                                    : 0x1b19U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x71ffU
                                                    : 0x2906U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc710U
                                                    : 0x2914U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc720U
                                                    : 0x2912U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc740U
                                                    : 0x2fb1U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x70bbU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5608U
                                                    : 0x2102U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc708U
                                                    : 0x46f7U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcfU
                                                    : 0x2708U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe07U
                                                    : 0x1e03U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5001U
                                                    : 0x4080U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe03U
                                                    : 0x2ffcU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2708U
                                                    : 0x20eeU))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2708U
                                                    : 0xd7f0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x216dU
                                                    : 0xc740U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2108U
                                                    : 0xc780U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1b08U
                                                    : 0x7000U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2780U
                                                    : 0x3707U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29ffU
                                                    : 0x9001U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70a0U
                                                    : 0x2ff8U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fb1U
                                                    : 0x2705U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7010U
                                                    : 0x2fcfU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2708U
                                                    : 0x2b0aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x300cU
                                                    : 0xb08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e13U
                                                    : 0x41feU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe13U
                                                    : 0x7700U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7600U
                                                    : 0x1b08U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x2780U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fe3U
                                                    : 0x270aU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe07U
                                                    : 0x1e03U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0xf90U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xff1U
                                                    : 0xf01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fdfU
                                                    : 0x2705U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7001U
                                                    : 0x1b08U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x40ffU
                                                    : 0xb08U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f01U
                                                    : 0x1ff1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf90U
                                                    : 0xff1U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf01U
                                                    : 0xf11U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf21U
                                                    : 0xf31U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf41U
                                                    : 0xf51U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf61U
                                                    : 0xf71U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xdf7U
                                                    : 0x1df8U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f71U
                                                    : 0x1f61U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f51U
                                                    : 0x1f41U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f31U
                                                    : 0x1f21U))))))))
                    : ((0x80U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                        ? ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f11U
                                                    : 0x2911U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d06U
                                                    : 0x2313U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x9001U
                                                    : 0xd06U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f01U
                                                    : 0x2f07U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f01U
                                                    : 0x1ff1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d06U
                                                    : 0x7000U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf90U
                                                    : 0x2902U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd000U
                                                    : 0xd06U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f80U
                                                    : 0xf90U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xff1U
                                                    : 0xf01U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf11U
                                                    : 0xf21U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf31U
                                                    : 0xf41U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf51U
                                                    : 0xf61U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf71U
                                                    : 0xdf8U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1df7U
                                                    : 0x1f71U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f61U
                                                    : 0x1f51U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f41U
                                                    : 0x1f31U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f21U
                                                    : 0x1f11U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f01U
                                                    : 0x1ff1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d06U
                                                    : 0x3f80U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f01U
                                                    : 0x70ffU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x27ffU
                                                    : 0x2f04U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7001U
                                                    : 0x1f01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7fc0U
                                                    : 0x2717U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1df8U
                                                    : 0x1f71U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f61U
                                                    : 0x1f51U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f41U
                                                    : 0x1f31U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f21U
                                                    : 0x1f11U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f01U
                                                    : 0x1ff1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f80U
                                                    : 0x3f02U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7f00U
                                                    : 0x2718U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d16U
                                                    : 0x71ffU))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x27ffU
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf21U
                                                    : 0x1211U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1200U
                                                    : 0x7200U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2711U
                                                    : 0x1f21U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0xf000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2701U
                                                    : 0U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x40ffU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0U
                                                    : 0x2904U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc001U
                                                    : 0x2f5eU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0xf00U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x401fU
                                                    : 0x2902U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc101U
                                                    : 0x6020U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2902U
                                                    : 0xc102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6020U
                                                    : 0x2902U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc108U
                                                    : 0x5060U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f0cU
                                                    : 0x8091U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270fU
                                                    : 0x2004U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd01bU
                                                    : 0x2f5eU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x8053U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270fU
                                                    : 0x2f5eU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x8015U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270fU
                                                    : 0x2105U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc102U
                                                    : 0x2010U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd01bU
                                                    : 0x210dU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc101U
                                                    : 0x211eU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3057U
                                                    : 0U))
                                            : 0U) : 
                                       ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                         ? ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? 0U : 
                                            ((1U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                              ? 0U : 3U))
                                         : ((2U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                             ? ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 0x18U
                                                 : 0x1aU)
                                             : ((1U 
                                                 & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                 ? 1U
                                                 : 0x54U)))))))
                        : ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x52U
                                                    : 0x50U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x56U
                                                    : 0xf00U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29fbU
                                                    : 0x3008U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8102U
                                                    : 0x2104U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x325dU
                                                    : 0x120U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x71faU
                                                    : 0x2704U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7001U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29f4U
                                                    : 0x9101U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8001U
                                                    : 0x29feU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc201U
                                                    : 0xe21U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe24U
                                                    : 0x1b20U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf200U
                                                    : 0x2701U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2103U
                                                    : 0xc001U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x20U
                                                    : 0xf00U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29f1U
                                                    : 0x9101U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8001U
                                                    : 0xe25U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1020U
                                                    : 0x3235U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x43ffU
                                                    : 0x30U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe200U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2106U
                                                    : 0xc001U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xb21U
                                                    : 0x21feU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc202U
                                                    : 0xe21U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8000U
                                                    : 0x4000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2000U
                                                    : 0x1000U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x800U
                                                    : 0x400U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x200U
                                                    : 0x100U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x80U
                                                    : 0x40U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x20U
                                                    : 0x10U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 8U
                                                    : 4U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 2U
                                                    : 1U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8088U
                                                    : 0x2704U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3008U
                                                    : 0x400fU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x1c16U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7105U
                                                    : 0x1c04U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5000U
                                                    : 0x2706U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f41U
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5000U
                                                    : 0x2701U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e12U
                                                    : 0x7101U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c15U
                                                    : 0x7180U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c16U
                                                    : 0x7100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x1c16U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7100U
                                                    : 0x1c15U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x710bU
                                                    : 0xf00U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29faU
                                                    : 0x41ffU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3118U
                                                    : 0x6000U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2701U
                                                    : 0x2103U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x301cU
                                                    : 0x7101U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x3f90U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e01U
                                                    : 0x40fbU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe01U
                                                    : 0x3f80U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f04U
                                                    : 0x5004U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe01U
                                                    : 0x1100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7188U
                                                    : 0x2710U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7001U
                                                    : 0x3f80U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2909U
                                                    : 0xd003U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x1c61U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c70U
                                                    : 0x2f5dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x70edU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2104U
                                                    : 0xc702U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x473fU
                                                    : 0x2f21U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x1100U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d11U
                                                    : 0x2103U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x321dU
                                                    : 0xd22U)))))))))
                : ((0x100U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                    ? ((0x80U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                        ? ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x71b8U
                                                    : 0x2710U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2903U
                                                    : 0xd1d8U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x8102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x210bU
                                                    : 0x3225U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd23U
                                                    : 0xd11U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3015U
                                                    : 0xe000U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2701U
                                                    : 0x2f1bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x41ffU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3164U
                                                    : 0xf100U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2701U
                                                    : 0x3167U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d5bU
                                                    : 0x2902U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc640U
                                                    : 0x1d5bU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7500U
                                                    : 0x5660U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2922U
                                                    : 0xc620U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f35U
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2108U
                                                    : 0xc780U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6620U
                                                    : 0x2902U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x305dU
                                                    : 0xd0bU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2905U
                                                    : 0xc640U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6680U
                                                    : 0x2002U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd539U
                                                    : 0x7500U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5702U
                                                    : 0x3606U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2902U
                                                    : 0xc780U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3605U
                                                    : 0x2902U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc00cU
                                                    : 0x2f7dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x3057U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x21daU
                                                    : 0xd5ffU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f0eU
                                                    : 0x6640U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2903U
                                                    : 0xc580U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x56e0U
                                                    : 0x2f43U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e16U
                                                    : 0x1d1cU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3106U
                                                    : 0x2902U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc780U
                                                    : 0x3105U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd1cU
                                                    : 0x2109U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3005U
                                                    : 0x2fe7U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x210dU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc701U
                                                    : 0x2151U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3507U
                                                    : 0x2f5fU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x8030U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x270eU
                                                    : 0x5080U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2102U
                                                    : 0xc740U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f0eU
                                                    : 0x2704U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcdU
                                                    : 0x2702U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5702U
                                                    : 0x6701U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x290eU
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc780U
                                                    : 0x2f14U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x5702U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7500U
                                                    : 0x2f1aU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x2f1aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x2f5dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x5001U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2102U
                                                    : 0xc701U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5004U
                                                    : 0x2902U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc608U
                                                    : 0x5002U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2902U
                                                    : 0xc604U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x47fdU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f1aU
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5740U
                                                    : 0x2f1aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x5780U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f1aU
                                                    : 0x2704U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x211aU
                                                    : 0xd0aaU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x211aU
                                                    : 0xd0e1U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x210dU
                                                    : 0xd0faU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x210cU
                                                    : 0xd0e0U)))))))
                        : ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x210bU
                                                    : 0xd0f0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2131U
                                                    : 0xc080U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x40ffU
                                                    : 0x2127U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc000U
                                                    : 0x2701U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f41U
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x212cU
                                                    : 0xc000U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2702U
                                                    : 0xf000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0xc61U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc70U
                                                    : 0x3f90U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f53U
                                                    : 0x2704U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc04U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e06U
                                                    : 0x1d0cU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70ffU
                                                    : 0x27ffU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x2fcaU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x7102U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d02U
                                                    : 0x70b8U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x2903U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd0d8U
                                                    : 0x2710U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8002U
                                                    : 0xd02U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f90U
                                                    : 0x1e01U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6008U
                                                    : 0xe01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f80U
                                                    : 0x2fcbU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x7101U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7086U
                                                    : 0x2710U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f90U
                                                    : 0x1e01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5008U
                                                    : 0xe01U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x3f80U
                                                    : 0x211bU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x40ffU
                                                    : 0xd03U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x211eU
                                                    : 0xd00aU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2120U
                                                    : 0xd002U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd04U
                                                    : 0x2123U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x301dU
                                                    : 0xd12U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd01U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fa9U
                                                    : 0x2704U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7103U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fa9U
                                                    : 0x2704U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7103U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fa9U
                                                    : 0x2704U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x2fa9U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x2fcaU))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0xd01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7102U
                                                    : 0xf00U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d02U
                                                    : 0xd01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fa9U
                                                    : 0x2704U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcaU
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7103U
                                                    : 0x10aeU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x24aU
                                                    : 0x10aeU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x276U
                                                    : 0x10aaU)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x24aU
                                                    : 0x10aaU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x26eU
                                                    : 0x108aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x4caU
                                                    : 0x1088U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x4caU
                                                    : 0x1088U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x268U
                                                    : 0x10a2U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x4caU
                                                    : 0x10a2U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x262U
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x25aU
                                                    : 0U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x19eU
                                                    : 0x1086U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x250U
                                                    : 0x10b2U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x24aU
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x19eU
                                                    : 0U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x19eU
                                                    : 0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x19eU
                                                    : 0x3f22U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7101U
                                                    : 1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x20U
                                                    : 0x800aU))))))))
                    : ((0x80U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                        ? ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2702U
                                                    : 0xe004U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x400fU
                                                    : 0x2fcaU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x7106U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70a4U
                                                    : 0x2710U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fa8U
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7106U
                                                    : 0x70a4U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e07U
                                                    : 0U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x9002U
                                                    : 0x2fa9U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x7102U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70b6U
                                                    : 0x2710U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf00U
                                                    : 0x2102U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd0f0U
                                                    : 0xf00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x280eU
                                                    : 0xd0d0U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2815U
                                                    : 0xd0d8U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x281cU
                                                    : 0xd0e0U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2808U
                                                    : 0xd0f0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xd00U
                                                    : 0x2fa9U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x7101U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7080U
                                                    : 0x2710U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2ff8U
                                                    : 0x2f7fU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2702U
                                                    : 0x2ffbU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fb1U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2104U
                                                    : 0xc002U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe01U
                                                    : 0x3f90U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f5dU
                                                    : 0x2704U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70ffU
                                                    : 0x1e1dU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e0cU
                                                    : 0x710eU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f8bU
                                                    : 0x2705U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7200U
                                                    : 0x7150U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x703aU
                                                    : 0x2706U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fcdU
                                                    : 0x2702U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c00U
                                                    : 0x7003U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d15U
                                                    : 0x1d04U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x71ffU
                                                    : 0x7001U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1010U
                                                    : 0x1d02U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1d01U
                                                    : 0x71ffU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70b8U
                                                    : 0x2710U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c01U
                                                    : 0x70f7U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x27ffU
                                                    : 0x2f7eU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0x7200U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2718U
                                                    : 0x7150U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x705eU
                                                    : 0x2701U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f1fU
                                                    : 0x270eU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29fdU
                                                    : 0x301dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8002U
                                                    : 0x1020U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7200U
                                                    : 0x7100U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2718U
                                                    : 0x7000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x1e0dU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x1e01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7000U
                                                    : 0x1e02U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7003U
                                                    : 0xe05U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7800U
                                                    : 0x7ad8U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x7b00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x7c92U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x7d80U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2710U
                                                    : 0x7e00U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2720U
                                                    : 0x7f00U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2718U
                                                    : 0x2fecU)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c04U
                                                    : 0x2f53U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x3017U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2904U
                                                    : 0xf000U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2780U
                                                    : 0xe12U)))))))
                        : ((0x40U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                            ? ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e12U
                                                    : 0x5101U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2102U
                                                    : 0xc001U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7102U
                                                    : 0xc04U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29fbU
                                                    : 0xc080U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf90U
                                                    : 0xff1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf01U
                                                    : 0xf11U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf21U
                                                    : 0xf31U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf41U
                                                    : 0xf51U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf61U
                                                    : 0xf71U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fd7U
                                                    : 0x2702U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f71U
                                                    : 0x1f61U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f51U
                                                    : 0x1f41U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f31U
                                                    : 0x1f21U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f0fU
                                                    : 0x1c06U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x700fU
                                                    : 0x2104U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c05U
                                                    : 0x9001U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc05U
                                                    : 0x1c04U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x5000U
                                                    : 0x2780U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2103U
                                                    : 0x4101U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xe12U
                                                    : 0xf000U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2780U
                                                    : 0xc04U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2923U
                                                    : 0xc0c0U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc05U
                                                    : 0x1f11U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f01U
                                                    : 0x1ff1U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fb6U
                                                    : 0x1200U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8001U
                                                    : 0x1e1bU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf100U
                                                    : 0x2701U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2103U
                                                    : 0xc201U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x10U
                                                    : 0x28bfU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x301dU
                                                    : 0x211U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x200U
                                                    : 0x7200U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2711U
                                                    : 0x1f21U))))))
                            : ((0x20U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                ? ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f11U
                                                    : 0x1f01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fc9U
                                                    : 0x2f53U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2704U
                                                    : 0x1f11U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1e02U
                                                    : 0x7003U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fd0U
                                                    : 0x1c05U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7040U
                                                    : 0x1c06U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x70eaU
                                                    : 0x1e02U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x7002U
                                                    : 0x2fd6U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2f53U
                                                    : 0x2704U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f11U
                                                    : 0x290cU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc040U
                                                    : 0x2907U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc080U
                                                    : 0xc05U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x29e0U
                                                    : 0x1c06U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x23e2U
                                                    : 0x9001U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc06U
                                                    : 0x1f01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2fe6U
                                                    : 0x1e01U)))))
                                : ((0x10U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                    ? ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x6010U
                                                    : 0xe01U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1c07U
                                                    : 0x8024U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x27f4U
                                                    : 0x29edU)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x308dU
                                                    : 0xc07U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x1f01U
                                                    : 0xf90U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xff1U
                                                    : 0x212aU))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc808U
                                                    : 0x2110U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc804U
                                                    : 0x2107U))))
                                    : ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                        ? ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xc802U
                                                    : 0x29f2U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x2705U
                                                    : 0xc801U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x8801U
                                                    : 0x1ff1U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf90U
                                                    : 0xff1U)))
                                        : ((4U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                            ? ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf01U
                                                    : 0xf11U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0xf21U
                                                    : 0xb16U))
                                            : ((2U 
                                                & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                ? (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x624U
                                                    : 0xa0U)
                                                : (
                                                   (1U 
                                                    & (IData)(__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__addr))
                                                    ? 0x14U
                                                    : 0x112U)))))))))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__pgm_data 
        = vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__rom__55__Vfuncout;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem
        [(0x3ffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__mem_addr))];
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__VRAM__DOT__mem__v1;
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r;
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__IPL__DOT__mem__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__IPL__DOT__mem__v1;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__GRAM__DOT__mem__v1;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__PSGRAM__DOT__mem__v1;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__mem__v1;
    }
    vlTOPp->top__DOT__unnamedblk1__DOT__old_clk = vlTOPp->clk_12;
    vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__vramDo;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_acc1 
        = ((IData)(vlTOPp->top__DOT__reset) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_access));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_irq 
        = (2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ct_r));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_irq 
        = (2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_tarp_r));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_TX_BSY 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_full;
    vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__q_b = vlTOPp->top__DOT__sharpx1__DOT__romDo_SharpX1;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_RX_BSY 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_a;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_rd 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_a;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_FDC_DRQ_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS) 
            & (3U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_fa)))) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_r 
        = ((IData)(vlTOPp->top__DOT__reset) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_n));
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
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__AddrC 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCH 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
        [vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC];
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
        [vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC];
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__m1)))) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s 
                = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req) 
                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_IEI)) 
                   & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_ena));
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__ivector 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vector_a 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector) 
           << 1U);
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__gramDo;
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__q_a 
        = vlTOPp->top__DOT__sharpx1__DOT__psgramDo;
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->ioctl_download))))) {
        VL_WRITEF("A=%x, D=%x wr=%x halt_n=%x mreq=%x iorq=%x rd=%x m1=%x ram_cs=%x sub_cs=%x psgram_cs=%x gram_cs=%x\n",
                  16,vlTOPp->top__DOT__sharpx1__DOT__a,
                  8,(IData)(vlTOPp->top__DOT__sharpx1__DOT__data_out),
                  1,vlTOPp->top__DOT__sharpx1__DOT__wr,
                  1,(IData)(vlTOPp->top__DOT__sharpx1__DOT__halt_n),
                  1,vlTOPp->top__DOT__sharpx1__DOT__mreq,
                  1,(IData)(vlTOPp->top__DOT__sharpx1__DOT__iorq),
                  1,vlTOPp->top__DOT__sharpx1__DOT__rd,
                  1,(IData)(vlTOPp->top__DOT__sharpx1__DOT__m1),
                  1,vlTOPp->top__DOT__sharpx1__DOT__ram_cs,
                  1,(IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_cs),
                  1,vlTOPp->top__DOT__sharpx1__DOT__psgram_cs,
                  1,(IData)(vlTOPp->top__DOT__sharpx1__DOT__gram_cs));
    }
    if (vlTOPp->top__DOT__sharpx1__DOT__ram_cs) {
        if (vlTOPp->top__DOT__sharpx1__DOT__wr) {
            vlTOPp->top__DOT__sharpx1__DOT__ramDi = vlTOPp->top__DOT__sharpx1__DOT__data_out;
            vlTOPp->top__DOT__sharpx1__DOT__ramWe = 1U;
        } else if (VL_UNLIKELY(vlTOPp->top__DOT__sharpx1__DOT__rd)) {
            VL_WRITEF("RAM read %x %x\n",16,vlTOPp->top__DOT__sharpx1__DOT__a,
                      8,(IData)(vlTOPp->top__DOT__sharpx1__DOT__ramDo));
            vlTOPp->top__DOT__sharpx1__DOT__ramWe = 0U;
        }
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__ramA 
            = vlTOPp->top__DOT__sharpx1__DOT__a;
    } else if (vlTOPp->top__DOT__sharpx1__DOT__gram_cs) {
        if (vlTOPp->top__DOT__sharpx1__DOT__wr) {
            vlTOPp->top__DOT__sharpx1__DOT__gramDi 
                = vlTOPp->top__DOT__sharpx1__DOT__data_out;
            vlTOPp->top__DOT__sharpx1__DOT__gramWe = 1U;
        } else if (vlTOPp->top__DOT__sharpx1__DOT__rd) {
            vlTOPp->top__DOT__sharpx1__DOT__gramWe = 0U;
        }
        vlTOPp->top__DOT__sharpx1__DOT__gramA = vlTOPp->top__DOT__sharpx1__DOT__a;
    } else if (vlTOPp->top__DOT__sharpx1__DOT__psgram_cs) {
        if (vlTOPp->top__DOT__sharpx1__DOT__wr) {
            vlTOPp->top__DOT__sharpx1__DOT__psgramDi 
                = vlTOPp->top__DOT__sharpx1__DOT__data_out;
            vlTOPp->top__DOT__sharpx1__DOT__psgramWe = 1U;
        } else if (vlTOPp->top__DOT__sharpx1__DOT__rd) {
            vlTOPp->top__DOT__sharpx1__DOT__psgramWe = 0U;
        }
        vlTOPp->top__DOT__sharpx1__DOT__psgramA = vlTOPp->top__DOT__sharpx1__DOT__a;
    } else if (vlTOPp->top__DOT__sharpx1__DOT__sub_cs) {
        if (VL_UNLIKELY(vlTOPp->top__DOT__sharpx1__DOT__wr)) {
            VL_WRITEF("SUB CPU write %x %x\n",16,vlTOPp->top__DOT__sharpx1__DOT__a,
                      8,(IData)(vlTOPp->top__DOT__sharpx1__DOT__data_out));
            vlTOPp->top__DOT__sharpx1__DOT__subDi = vlTOPp->top__DOT__sharpx1__DOT__data_out;
            vlTOPp->top__DOT__sharpx1__DOT__sub_wr = 1U;
            vlTOPp->top__DOT__sharpx1__DOT__sub_rd = 0U;
        } else if (VL_UNLIKELY(vlTOPp->top__DOT__sharpx1__DOT__rd)) {
            VL_WRITEF("SUB CPU read %x %x\n",16,vlTOPp->top__DOT__sharpx1__DOT__a,
                      8,(IData)(vlTOPp->top__DOT__sharpx1__DOT__subDo));
            vlTOPp->top__DOT__sharpx1__DOT__sub_wr = 0U;
            vlTOPp->top__DOT__sharpx1__DOT__sub_rd = 1U;
        }
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__S 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs_r;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_rom__DOT__DO 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__pgm_data;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__q_b 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_b;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wram_data 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_w_ram__q_b;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__data_a 
        = (0xffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_rd) 
                    >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOCH 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCH;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_reg__DOT__DOCL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT____Vcellout__i_reg__DOCL;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req 
        = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I3 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vector_a;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rdata 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__msel)
            ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__pgm_data)
            : (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wram_data));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_INT_n 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_IEI) 
                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_IEO 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_IEI) 
            & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_req_s))) 
           & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_srv)));
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__ramDi;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__ramWe;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__gramDi;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__gramWe;
    vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_a 
        = vlTOPp->top__DOT__sharpx1__DOT__gramA;
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__data_a 
        = vlTOPp->top__DOT__sharpx1__DOT__psgramDi;
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__psgramWe;
    vlTOPp->top__DOT__sharpx1__DOT__PSGRAM__DOT__address_a 
        = (0x1fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__psgramA) 
                      >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_D 
        = vlTOPp->top__DOT__sharpx1__DOT__subDi;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_wd 
        = vlTOPp->top__DOT__sharpx1__DOT__subDi;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_rd 
        = vlTOPp->top__DOT__sharpx1__DOT__sub_rd;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_wr 
        = vlTOPp->top__DOT__sharpx1__DOT__sub_wr;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_cmd_wr 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS) 
            & (0U == (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_fa)))) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_access 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_rd) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rw 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_CS) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_rd) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wram_wr 
        = vlTOPp->top__DOT__sharpx1__DOT__sub_wr;
    vlTOPp->top__DOT__sharpx1__DOT__ramDo = vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__mem
        [vlTOPp->top__DOT__sharpx1__DOT__ramA];
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_D 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rdata;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_ivec_sel 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_IEI) 
            & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_IEO))) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_SPM1));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__wren_a 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wram_wr;
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0) {
        vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v0;
    }
    if (vlTOPp->__Vdlyvset__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1) {
        vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__mem[vlTOPp->__Vdlyvdim0__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1] 
            = vlTOPp->__Vdlyvval__top__DOT__sharpx1__DOT__RAM__DOT__mem__v1;
    }
    vlTOPp->top__DOT__sharpx1__DOT__ramA = vlTOPp->__Vdly__top__DOT__sharpx1__DOT__ramA;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__I1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_D;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_a 
        = vlTOPp->top__DOT__sharpx1__DOT__ramA;
    vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_a = vlTOPp->top__DOT__sharpx1__DOT__ramDo;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*2:0*/ __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__Vfuncout;
    CData/*6:0*/ __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc;
    CData/*6:0*/ __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__Vfuncout;
    CData/*2:0*/ __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num;
    CData/*1:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State;
    CData/*7:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF1;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntE_FF2;
    CData/*2:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    CData/*0:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    CData/*2:0*/ __Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl;
    SData/*15:0*/ __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
    // Body
    __Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl;
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
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State;
    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F;
    __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Oldnmi_n = 1U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Oldnmi_n = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
            vlTOPp->top__DOT__sharpx1__DOT__wr = 1U;
            if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mcycle)))) {
                if ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate) 
                      >> 1U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__write))) {
                    vlTOPp->top__DOT__sharpx1__DOT__wr = 0U;
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__wr = 1U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
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
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__rd = 1U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_ack) {
            __Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl 
                = (6U & (IData)(__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl));
        } else if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_overflow) {
            __Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl 
                = ((6U & (IData)(__Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl)) 
                   | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl) 
                            >> 2U)));
        }
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctr_load) {
            __Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl 
                = (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out));
        }
    } else {
        __Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt 
            = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt_load)
                ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_int)
                : (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__next_timer));
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA8 
            = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) 
                & (8U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                  >> 1U)))) & 1U);
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA9 
            = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) 
                & (9U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                  >> 1U)))) & 1U);
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IAA 
            = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) 
                & (0xaU == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) & 1U);
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IAB 
            = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) 
                & (0xbU == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) & 1U);
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA4 
            = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) 
                & (4U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                  >> 1U)))) & 1U);
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA5 
            = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) 
                & (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                  >> 1U)))) & 1U);
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA6 
            = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) 
                & (6U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                  >> 1U)))) & 1U);
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA8 = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA9 = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IAA = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IAB = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA4 = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA5 = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA6 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA7 
        = ((IData)(vlTOPp->top__DOT__reset) & (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
                                                & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) 
                                               & (7U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))));
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                       >> 1U))) | (1U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                       >> 1U)))) 
                      | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) | 
                     (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (4U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (6U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                   >> 1U))))) {
                if ((0U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((1U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        if ((2U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U)))) {
                            if ((3U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) {
                                if ((4U != (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                             >> 1U)))) {
                                    if ((5U == (0xfU 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                   >> 1U)))) {
                                        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP5 
                                            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP5 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                       >> 1U))) | (1U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                       >> 1U)))) 
                      | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) | 
                     (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (4U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (6U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                   >> 1U))))) {
                if ((0U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((1U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        if ((2U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U)))) {
                            if ((3U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) {
                                if ((4U != (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                             >> 1U)))) {
                                    if ((5U != (0xfU 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                   >> 1U)))) {
                                        if ((6U != 
                                             (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                 >> 1U)))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP7 
                                                = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP7 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                       >> 1U))) | (1U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                       >> 1U)))) 
                      | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) | 
                     (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (4U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (6U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                   >> 1U))))) {
                if ((0U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((1U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        if ((2U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U)))) {
                            if ((3U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) {
                                if ((4U == (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                             >> 1U)))) {
                                    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP4 
                                        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP4 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                       >> 1U))) | (1U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                       >> 1U)))) 
                      | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) | 
                     (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (4U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (6U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                   >> 1U))))) {
                if ((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP0 
                        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP0 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U))) 
                                | (1U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                  >> 1U)))) 
                               | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                 >> 1U)))) 
                              | (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) 
                             | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                               >> 1U)))) 
                            | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                              >> 1U)))) 
                           | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                             >> 1U)))) 
                          | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U))))))) {
                if ((8U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((9U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        if ((0xaU != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                              >> 1U)))) {
                            if ((0xbU == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                  >> 1U)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPB 
                                    = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPB = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U))) 
                                | (1U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                  >> 1U)))) 
                               | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                 >> 1U)))) 
                              | (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) 
                             | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                               >> 1U)))) 
                            | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                              >> 1U)))) 
                           | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                             >> 1U)))) 
                          | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U))))))) {
                if ((8U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP8 
                        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP8 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                       >> 1U))) | (1U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                       >> 1U)))) 
                      | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) | 
                     (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (4U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (6U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                   >> 1U))))) {
                if ((0U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((1U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        if ((2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP2 
                                = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP2 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                       >> 1U))) | (1U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                       >> 1U)))) 
                      | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) | 
                     (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (4U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (6U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                   >> 1U))))) {
                if ((0U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((1U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        if ((2U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U)))) {
                            if ((3U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) {
                                if ((4U != (0xfU & 
                                            ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                             >> 1U)))) {
                                    if ((5U != (0xfU 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                   >> 1U)))) {
                                        if ((6U == 
                                             (0xfU 
                                              & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                 >> 1U)))) {
                                            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP6 
                                                = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP6 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
            if ((4U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__tstate))) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg 
                    = vlTOPp->top__DOT__sharpx1__DOT__di;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                       >> 1U))) | (1U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                       >> 1U)))) 
                      | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) | 
                     (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (4U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (6U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                   >> 1U))))) {
                if ((0U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((1U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1 
                            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
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
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__mreq = 1U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if (((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                       >> 1U))) | (1U 
                                                   == 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                       >> 1U)))) 
                      | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) | 
                     (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (4U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                   | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                     >> 1U)))) | (6U 
                                                  == 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                      >> 1U)))) 
                 | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                   >> 1U))))) {
                if ((0U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((1U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        if ((2U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U)))) {
                            if ((3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) {
                                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP3 
                                    = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP3 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U))) 
                                | (1U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                  >> 1U)))) 
                               | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                 >> 1U)))) 
                              | (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) 
                             | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                               >> 1U)))) 
                            | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                              >> 1U)))) 
                           | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                             >> 1U)))) 
                          | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U))))))) {
                if ((8U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((9U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9 
                            = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9 = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__io_cs) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16))) {
            if ((1U & (~ ((((((((0U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U))) 
                                | (1U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                  >> 1U)))) 
                               | (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                 >> 1U)))) 
                              | (3U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                >> 1U)))) 
                             | (4U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                               >> 1U)))) 
                            | (5U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                              >> 1U)))) 
                           | (6U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                             >> 1U)))) 
                          | (7U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                            >> 1U))))))) {
                if ((8U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                    >> 1U)))) {
                    if ((9U != (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                        >> 1U)))) {
                        if ((0xaU == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                              >> 1U)))) {
                            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA 
                                = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles_d;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycles = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
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
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_Ind = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_pc 
                = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_pc = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                              & (IData)((0U != (0xeU 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate)))))))) {
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRS) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate 
                            = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate)));
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
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
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__iorq = 1U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__dirset) {
            vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                = vlTOPp->top__DOT__sharpx1__DOT__dir;
        } else if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
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
                            __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State 
                                = ((0x20U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))
                                    ? 2U : 1U);
                        } else if ((2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix))) {
                            __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State = 0U;
                        }
                    } else {
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State = 0U;
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
                               | (IData)(vlTOPp->top__DOT__sharpx1__DOT__di));
                    } else {
                        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR 
                            = vlTOPp->top__DOT__sharpx1__DOT__di;
                    }
                }
            } else {
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Jump) {
                        vlTOPp->top__DOT__sharpx1__DOT__a 
                            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg) 
                                << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__DI_Reg) 
                                << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)));
                    } else if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY) {
                        vlTOPp->top__DOT__sharpx1__DOT__a 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC;
                    } else if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Call) 
                                | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RstP))) {
                        vlTOPp->top__DOT__sharpx1__DOT__a 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
                    } else if (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__last_mcycle) 
                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle))) {
                        vlTOPp->top__DOT__sharpx1__DOT__a = 0x66U;
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC = 0x66U;
                    } else if (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 2U) & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle)) 
                                & (2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus)))) {
                        vlTOPp->top__DOT__sharpx1__DOT__a 
                            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I) 
                                << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)));
                        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC 
                            = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I) 
                                << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr)));
                    } else {
                        vlTOPp->top__DOT__sharpx1__DOT__a 
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
                            = vlTOPp->top__DOT__sharpx1__DOT__di;
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
                vlTOPp->top__DOT__sharpx1__DOT__data_out 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB;
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RLD) {
                    vlTOPp->top__DOT__sharpx1__DOT__data_out 
                        = ((0xf0U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusB) 
                                     << 4U)) | (0xfU 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusA)));
                }
                if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_RRD) {
                    vlTOPp->top__DOT__sharpx1__DOT__data_out 
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
                                vlTOPp->top__DOT__sharpx1__DOT__data_out 
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
        vlTOPp->top__DOT__sharpx1__DOT__a = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR = 0U;
        __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State = 0U;
        vlTOPp->top__DOT__sharpx1__DOT__data_out = 0U;
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC = 0xffU;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Ap = 0xffU;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Fp = 0xffU;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I = 0U;
        vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP = 0xffffU;
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix 
                = ((0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix)) 
                   | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack) 
                       << 0xaU) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_cycle) 
                                    << 9U) | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDI) 
                                              << 8U))));
            if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_cycle) {
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix 
                    = ((0x707U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix)) 
                       | ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack)
                             ? 0xfU : (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__prefix_in) 
                                               >> 4U))) 
                           << 4U) | ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_REG) 
                                       & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle)) 
                                      | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack)) 
                                     << 3U)));
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix 
                    = ((0x7fbU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix)) 
                       | (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_REG) 
                             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle)) 
                            & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_w8))) 
                           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack)) 
                          << 2U));
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix 
                    = ((0x7fcU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix)) 
                       | ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_FLG) 
                            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle)) 
                           << 1U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_PC) 
                                      & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle)) 
                                     | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack))));
            } else {
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix 
                    = ((0x700U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix)) 
                       | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDI)
                           ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__prefix_in)
                           : 0U));
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix = 0x701U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n) {
            if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_flag) {
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag 
                    = ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag)) 
                       | (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in)));
            } else if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_load) {
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag 
                    = ((0x10U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag)) 
                       | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_flag));
            } else {
                if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_CF) {
                    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag 
                        = ((0x1eU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag)) 
                           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_val));
                }
                if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_ZF) {
                    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag 
                        = ((0x1dU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag)) 
                           | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_val) 
                              << 1U));
                }
            }
            if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack) {
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag 
                    = (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag));
            } else if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_IF) {
                vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag 
                    = ((0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag)) 
                       | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_val) 
                          << 4U));
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__gpio_in_mux 
        = ((IData)(vlTOPp->top__DOT__reset) ? ((3U 
                                                == 
                                                (3U 
                                                 & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                    >> 1U)))
                                                ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP3)
                                                : (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                        >> 1U)))
                                                    ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP2)
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_addr) 
                                                         >> 1U)))
                                                     ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP1)
                                                     : (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP0))))
            : 0U);
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl 
        = __Vdly__top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__TmpAddr;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__XY_State;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__wr = vlTOPp->top__DOT__sharpx1__DOT__wr;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__rd = vlTOPp->top__DOT__sharpx1__DOT__rd;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_irq 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__next_timer 
        = (0xffffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt) 
                      - (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_ctrl) 
                               >> 1U))));
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_int_load) {
            vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_int 
                = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_int = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I8 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA8;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I9 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA9;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_IA 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IAA;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_IB 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IAB;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_set 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA4;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I4 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA4;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_clr 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA5;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I5 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA5;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I6 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA6;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_set 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA6;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Arith16 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Arith16_r;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_I7 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA7;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_clr 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IA7;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P5 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP5;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__num_7seg 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP7;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P7 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP7;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_FD_LAMP 
        = (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP4));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P4 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP4;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_D 
        = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP0));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP0;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_PCM 
        = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPB));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_PB 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPB;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_A 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP8;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P8 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP8;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_PS2DT 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP2));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_PS2CT 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP2) 
                 >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P2 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP2;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P6 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP6;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__joya_emu 
        = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP6));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__joyb_emu 
        = (0xffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP6) 
                    >> 8U));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__di 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di_reg;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_KEY_BRK_n 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1) 
                 >> 2U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_clk1 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1) 
                 >> 4U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__irq_en 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP1) 
                 >> 3U));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_MREQ_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__mreq)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__mreq 
        = vlTOPp->top__DOT__sharpx1__DOT__mreq;
    vlTOPp->top__DOT__sharpx1__DOT__ram_cs = vlTOPp->top__DOT__sharpx1__DOT__mreq;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P3 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP3;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP3 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq) 
            << 0xaU) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_wprt) 
                         << 9U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_hlt) 
                                    << 8U) | (0xffU 
                                              & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP3)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts 
        = (0xffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP3) 
                    | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq) 
                       << 1U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_BANK 
        = (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_MREQ_n 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                    >> 0xcU)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_IORQ_n 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                    >> 0xdU)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_RD_n 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                    >> 0xeU)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_P9 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_WR_n 
        = (1U & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                     >> 0xfU)) | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_BUSAK_n) 
                                  & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_STB_n))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_BUSRQ_n 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                    >> 0xbU)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_req 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OP9) 
                 >> 8U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_res 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_set 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 2U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_PA 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_frc 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_dir 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 3U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_ena 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 6U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_int_ena 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__OPA) 
                 >> 5U));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_IORQ_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__iorq)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__iorq 
        = vlTOPp->top__DOT__sharpx1__DOT__iorq;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r 
        = vlTOPp->top__DOT__sharpx1__DOT__iorq;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__data_out 
        = vlTOPp->top__DOT__sharpx1__DOT__data_out;
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
                if ((3U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode))) {
                    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus 
                        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IMode;
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IStatus = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC_r 
                    = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PreserveC_r = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_alu__DOT__Z16 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Z16_r;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_A 
        = vlTOPp->top__DOT__sharpx1__DOT__a;
    vlTOPp->top__DOT__sharpx1__DOT__romA = (0x3fffU 
                                            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__a));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__a = vlTOPp->top__DOT__sharpx1__DOT__a;
    vlTOPp->top__DOT__sharpx1__DOT__ipl_cs = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__mreq) 
                                                & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_RD_n))) 
                                               & (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_IPL_SEL)) 
                                              & (~ 
                                                 ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                                  >> 0xfU)));
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
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
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Read_To_Reg_r = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r = 0U;
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                              & (IData)((0U != (0xeU 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate)))))))) {
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r 
                            = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op;
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ALU_Op_r = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ClkEn) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                              & (IData)((0U != (0xeU 
                                                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate)))))))) {
                    if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__T_Res) {
                        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BTR_r 
                            = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT) 
                                 | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC)) 
                                | (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR)) 
                               & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__No_BTR)));
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BTR_r = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__dirset)))) {
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
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ISet = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
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
                vlTOPp->top__DOT__sharpx1__DOT__m1 = 1U;
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
                                    ? 7U : ((0x20U 
                                             & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                             ? 6U : 
                                            ((0x10U 
                                              & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                              ? 5U : 
                                             ((8U & (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcyc_to_number__0__mcyc))
                                               ? 4U
                                               : ((4U 
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
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Pre_XY_F_M)));
                            __Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__Vfuncout 
                                = ((1U == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                    ? 1U : ((2U == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                             ? 2U : 
                                            ((3U == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                              ? 4U : 
                                             ((4U == (IData)(__Vfunc_top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__number_to_bitvec__1__num))
                                               ? 8U
                                               : ((5U 
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
                            vlTOPp->top__DOT__sharpx1__DOT__m1 = 0U;
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
                                             << 1U)) 
                                   | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U)));
                        }
                    }
                } else if ((1U & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait) 
                                      & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t2)))) 
                                  & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__iorq_i) 
                                        & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Auto_Wait_t1))))))) {
                    vlTOPp->__Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate 
                        = ((0x7eU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                                     << 1U)) | (1U 
                                                & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate) 
                                                   >> 6U)));
                }
            }
            if ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__tstate))) {
                vlTOPp->top__DOT__sharpx1__DOT__m1 = 0U;
            }
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
        vlTOPp->top__DOT__sharpx1__DOT__m1 = 1U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_w8 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                 >> 7U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                 >> 0xaU));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                 >> 8U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                 >> 9U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag;
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
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__I0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__gpio_in_mux;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__mem_cs_r)
            ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rdata)
            : (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__gpio_in_mux));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__wr_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__wr;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__rd_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__rd;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__O_INT 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_irq;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_overflow 
        = (1U & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__timer_cnt) 
                     >> 0xfU)) & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__next_timer) 
                                  >> 0xfU)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__drq_set 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_set;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__drq_clr 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_drq_clr) 
           | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs_r) 
              & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_dat_cs))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_JOY_A 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__joya_emu;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_JOY_B 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__joyb_emu;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_INT_n 
        = (1U & (~ (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__irq_en) 
                     & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full)) 
                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_IEI))));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__mreq_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__mreq;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_RAM_CS 
        = vlTOPp->top__DOT__sharpx1__DOT__ram_cs;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P3 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP3;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dot_7seg 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_TX_BSY) 
            << 3U) | ((4U & ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_RX_BSY)) 
                             << 2U)) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_drq) 
                                         << 1U) | (1U 
                                                   & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts)))));
    vlTOPp->top__DOT__sharpx1__DOT__subDo = (0xffU 
                                             & ((1U 
                                                 & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_ivec_cycle) 
                                                    | (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts_cs))))
                                                 ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_rd)
                                                 : (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fd_sts)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n 
        = (1U & (~ ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DMA_BUSRQ_n)) 
                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_BUSAK_n))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_busy 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_req) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_rdy) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_cyc)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__iorq_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__iorq;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_DAM_CLR 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r) 
           & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_RD_n)));
    vlTOPp->top__DOT__sharpx1__DOT__gram_cs = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r) 
                                               & ((1U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                                       >> 0xeU))) 
                                                  ^ (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_DAM)));
    vlTOPp->top__DOT__sharpx1__DOT__gram_cs = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r) 
                                               & ((2U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                                       >> 0xeU))) 
                                                  ^ (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_DAM)));
    vlTOPp->top__DOT__sharpx1__DOT__gram_cs = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r) 
                                               & ((3U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                                       >> 0xeU))) 
                                                  ^ (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_DAM)));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__sys_io 
        = ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__I_DAM)) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__iorq_r));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__dout 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__data_out;
    vlTOPp->top__DOT__sharpx1__DOT__IPL__DOT__address_b 
        = (0x1fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__romA) 
                      >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__A 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__a;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_CS 
        = vlTOPp->top__DOT__sharpx1__DOT__ipl_cs;
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
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_sel8 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_w8;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__m_acc 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_flag 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
              >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_regl 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
              >> 3U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_regh 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
              >> 2U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_pc 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__C 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cflag;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0xffffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cflag) 
              << 0x10U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack 
        = (((((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op)) 
              & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2))) 
             & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op))) 
            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iflag)) 
           & (0U != (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_in 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I2 
        = (0x7fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in) 
                      >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__top_din_mux__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__alu_out_mux__I4 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cflag) 
            << 0x10U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_D 
        = vlTOPp->top__DOT__sharpx1__DOT__subDo;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLKEN 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_cycle 
        = (1U & ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_BUSAK_n)) 
                 | ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_RFSH_n)) 
                    & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_busy))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy 
        = (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_RDY) 
              == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_dir)) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_frc)) 
            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy_ena)) 
           & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_busy)));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRB_CS 
        = vlTOPp->top__DOT__sharpx1__DOT__gram_cs;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRR_CS 
        = vlTOPp->top__DOT__sharpx1__DOT__gram_cs;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRG_CS 
        = vlTOPp->top__DOT__sharpx1__DOT__gram_cs;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_ATTR_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__sys_io) 
           & (2U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                             >> 0xcU))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_TEXT_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__sys_io) 
           & (6U == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                              >> 0xbU))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_KANJI_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__sys_io) 
           & (7U == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                              >> 0xbU))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__sys_io) 
           & (0U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 0xdU))));
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
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busak_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusAck)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_M1_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__m1)));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__m1 = vlTOPp->top__DOT__sharpx1__DOT__m1;
    vlTOPp->top__DOT__sharpx1__DOT__halt_n = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt_FF)));
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusReq_s = 0U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__BusReq_s = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__INT_s = 0U;
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__INT_s = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__IntCycle 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n 
        = (1U & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IntCycle)));
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
            if (vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle) {
                vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMI_s = 0U;
            }
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMI_s = 0U;
    }
    if (vlTOPp->top__DOT__reset) {
        if (vlTOPp->top__DOT__sharpx1__DOT__pe4M4) {
            vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__No_BTR 
                = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BT) 
                     & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                            >> 4U)) | (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                          >> 2U)))) 
                    | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BC) 
                       & (IData)(((0x10U != (0x10U 
                                             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR))) 
                                  | (4U != (0x44U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F))))))) 
                   | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_BTR) 
                      & ((~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR) 
                             >> 4U)) | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F) 
                                        >> 6U))));
        }
    } else {
        vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__No_BTR = 0U;
    }
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_ack 
        = ((1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector)) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK 
        = ((0xcU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK)) 
           | ((((3U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector)) 
                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack)) 
               << 1U) | ((2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector)) 
                         & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK 
        = ((3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK)) 
           | ((((5U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector)) 
                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack)) 
               << 3U) | (((4U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__vector)) 
                          & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack)) 
                         << 2U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle 
        = (1U & (((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op)) 
                  & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack))) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I4 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__alu_out_mux__I4;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__prefix_in 
        = (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_val 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                 >> 4U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_sel 
        = (0xfU == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                            >> 4U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp11 
        = ((0x7e0U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                      << 5U)) | ((0x1eU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                                           << 1U)) 
                                 | (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                                          >> 6U))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rel_pc_sel__I1 
        = ((0x7f00U & ((- (IData)((1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                                         >> 7U)))) 
                       << 8U)) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rs_b_mux__I0 
        = ((0xff00U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                       << 8U)) | (0xffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cond 
        = (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                   >> 8U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__stack_sel 
        = (0xfU == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                            >> 8U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_addr 
        = (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op)
                    ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_prefix) 
                       >> 4U) : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                                 >> 8U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_addr 
        = (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                   >> 4U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op 
        = (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
                   >> 0xcU));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__clk_en 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_CLKEN;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP0 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy) 
            << 0xaU) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__rfsh_busy) 
                         << 9U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_BUSAK_n) 
                                    << 8U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_d_r))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_irq 
        = ((2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_tarp_r)) 
           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_rdy));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_FM_CS 
        = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs))) 
                   & (0x700U == (0x1f04U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__a)))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_FMO_CTC_CS 
        = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs))) 
                   & (0x704U == (0x1f04U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__a)))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_BMEM_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0xbU == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                >> 8U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_EMM_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0xdU == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                >> 8U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_EXTROM_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0x1cU == (0x3fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                 >> 7U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_KANROM_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0x1dU == (0x3fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                 >> 7U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_PAL_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (4U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 0xaU))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_CG_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (5U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 0xaU))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_CRTC_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0x18U == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                 >> 8U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_PIA_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0x1aU == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                 >> 8U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_SET_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0x1dU == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                 >> 8U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_RES_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0x1eU == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                 >> 8U))));
    vlTOPp->top__DOT__sharpx1__DOT__miocs = vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__storage_cs 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0x3fU == (0x7fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                 >> 6U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
           & (0x3fU == (0x3fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                 >> 7U))));
    vlTOPp->top__DOT__sharpx1__DOT__psgram_cs = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
                                                 & ((0x1bU 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                                         >> 8U))) 
                                                    | (0x1cU 
                                                       == 
                                                       (0x1fU 
                                                        & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                                           >> 8U)))));
    vlTOPp->top__DOT__sharpx1__DOT__sub_cs = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__miocs) 
                                              & (0x19U 
                                                 == 
                                                 (0x1fU 
                                                  & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                                                     >> 8U))));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__busak_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__busak_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__m1_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__m1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__halt_n 
        = vlTOPp->top__DOT__sharpx1__DOT__halt_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__intcycle_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__intcycle_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__NMICycle;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR 
        = __Vdly__top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__IR;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_IACK 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer_ack;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__iack 
        = ((7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__iack)) 
           | (8U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_ack 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK) 
                 >> 2U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_ack 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK) 
                 >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_ack 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_ACK 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellout__sub_cpu__O_ACK;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp16 
        = ((0xf800U & ((- (IData)((1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp11) 
                                         >> 0xaU)))) 
                       << 0xbU)) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp11));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__I1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rel_pc_sel__I1;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__I0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rs_b_mux__I0;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__cf 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cflag;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__zf 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__zflag;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__vf 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__vflag;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__nf 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__nflag;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel 
        = (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cond));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel))
            ? ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel))
                ? ((~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel)) 
                   & (((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__nf) 
                       ^ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__vf)) 
                      & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__zf)))
                : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel))
                    ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__nf) 
                       ^ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__vf))
                    : (((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__vf) 
                        & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__zf)) 
                       & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__cf))))
            : ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel))
                ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel))
                    ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__nf)
                    : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__vf))
                : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__sel))
                    ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__zf)
                    : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__cf))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_true 
        = (1U & ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_table__32__Vfuncout) 
                 ^ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cond) 
                    >> 3U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__STM_FLG 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__stack_sel) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_sel));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_out 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl
        [vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_addr];
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_out 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh
        [vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_addr];
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_bl_out 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rl
        [vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_addr];
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_bh_out 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_rh
        [vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_addr];
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_FLG 
        = (((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op)) 
            & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__stack_sel) 
               & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_sel))) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDM 
        = (0U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_PC 
        = (((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op)) 
            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__stack_sel)) 
           & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_STM 
        = (1U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_BCC 
        = (2U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MEM 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op) 
                        >> 1U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_reg 
        = (3U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP0;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellinp__sub_cpu__I_INT 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_irq) 
            << 2U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fdc_irq) 
                       << 1U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__ps2_irq)));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_MIOCS 
        = vlTOPp->top__DOT__sharpx1__DOT__miocs;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_HDD_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__storage_cs) 
           & (4U == (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                             >> 2U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_FD8_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__storage_cs) 
           & (5U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 3U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_FD5_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__storage_cs) 
           & (7U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 3U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_DMA_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx) 
           & (0U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 4U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_SIO_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx) 
           & (4U == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                              >> 2U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_CTC_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx) 
           & (8U == (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                              >> 2U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_P1FDX_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx) 
           & (5U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 4U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_BLACK_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx) 
           & (6U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 4U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_DIPSW_CS 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__io1fxx) 
           & (7U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__a) 
                           >> 4U))));
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_PSG_CS 
        = vlTOPp->top__DOT__sharpx1__DOT__psgram_cs;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_cs 
        = vlTOPp->top__DOT__sharpx1__DOT__sub_cs;
    vlTOPp->top__DOT__sharpx1__DOT__x1_adec__DOT__O_SUB_CS 
        = vlTOPp->top__DOT__sharpx1__DOT__sub_cs;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_cs 
        = ((((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_FDCS) 
               | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_CS)) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_cs)) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_ivec_cycle)) 
            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fw_wram_cs)) 
           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_ivec_sel));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__p8255_hs_cs 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_ivec_cycle) 
           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_cs));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__main_we 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_cs) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__main_re 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_cs) 
            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_rd)) 
           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_ivec_cycle));
    vlTOPp->top__DOT__sharpx1__DOT__di = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__ram_cs)
                                           ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__ramDo)
                                           : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__ipl_cs)
                                               ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__romDo_SharpX1)
                                               : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_cs)
                                                   ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subDo)
                                                   : 
                                                  ((IData)(vlTOPp->top__DOT__sharpx1__DOT__gram_cs)
                                                    ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__gramDo)
                                                    : 
                                                   ((IData)(vlTOPp->top__DOT__sharpx1__DOT__psgram_cs)
                                                     ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__psgramDo)
                                                     : 0xffU)))));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__m1_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__m1_n;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__halt_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__halt_n;
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
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I2 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp16) 
            << 1U) | 0U);
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_out 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_out) 
            << 8U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_out));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_bh_out) 
            << 8U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_bl_out));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_REG 
        = (1U & ((IData)((0U == (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op)))) 
                 & (~ ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_PC) 
                       | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_FLG)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDI 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_BCC) 
            & (7U == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cond))) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_sel 
        = ((2U & ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle)) 
                  << 1U)) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_BCC) 
                              & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op))) 
                             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_true)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH_POP 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MEM) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__stack_sel));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__S 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_reg;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOADF 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_reg) 
           & (0U == (0xfU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix 
        = (0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_reg)
                    ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst)
                    : (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_INT 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT____Vcellinp__sub_cpu__I_INT;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_DOE 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_cs;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_a 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__dma_ivec_sel)
            ? 4U : (0x3ffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__p8255_hs_cs)
                               ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr)
                               : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_DMA_CS)
                                   ? (2U | (IData)(vlTOPp->top__DOT__sharpx1__DOT__sub_wr))
                                   : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__fw_wram_cs)
                                       ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_fa) 
                                          >> 1U) : 
                                      (8U | (7U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__I_fa))))))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP1 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_clk1) 
            << 4U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__irq_en) 
                       << 3U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__O_KEY_BRK_n) 
                                  << 2U) | ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hwd_full) 
                                              & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__main_we))) 
                                             << 1U) 
                                            | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__hrd_full) 
                                               | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__main_re))))));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__di = vlTOPp->top__DOT__sharpx1__DOT__di;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__halt_n 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__halt_n;
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
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__LDSPHL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__LDSPHL;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__JumpXY 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__JumpXY;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Halt 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Halt;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__I_CPL 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I_CPL;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__Prefix 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Prefix;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeRp 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeRp;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__i_mcode__DOT__ExchangeDH 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ExchangeDH;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__I1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I0 
        = (0x1fU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out) 
                    >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__I0 
        = (0x7ffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out) 
                     >> 5U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_reg)
            ? (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out)
            : (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rs_b_mux__I0));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__S 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_sel;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__i1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__rel_pc_sel__I1;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__sel 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_sel;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__Vfuncout 
        = ((2U == (2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__sel)))
            ? 0U : ((1U == (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__sel))
                     ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__i1)
                     : 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc 
        = vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__sel3__33__Vfuncout;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH_POP) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_POP_RET 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH_POP) 
           & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__set_flag 
        = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LDM) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__LDM_PC)) 
            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOADF)) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__S 
        = (3U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix) 
                 >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_TEST 
        = (3U == (3U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix) 
                        >> 2U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOGICAL 
        = (1U == (3U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix) 
                        >> 2U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CMP 
        = (0xdU == (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_ARITHMETIC 
        = (2U == (3U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix) 
                        >> 2U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLT 
        = (7U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix) 
                        >> 1U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_wc 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix) 
                 >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_sub 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_JABS 
        = ((1U == (7U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix) 
                         >> 1U))) & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_reg) 
                                     | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__address_a 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__h_wram_a;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__I_P1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__IP1;
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__di;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__A 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I1 
        = (((0x7fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                        >> 1U)) << 1U) | 0U);
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b_mux__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I1 
        = (0x7fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                      >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__B 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I0 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
            << 1U) | 1U);
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__I1 
        = (((0xffffU & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b))) 
            << 1U) | 1U);
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__b 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__a 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1fffeU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__35__Vfuncout));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1fffdU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__36__Vfuncout) 
              << 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 2U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 2U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1fffbU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__37__Vfuncout) 
              << 2U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 3U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 3U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1fff7U & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__38__Vfuncout) 
              << 3U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 4U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 4U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1ffefU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__39__Vfuncout) 
              << 4U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 5U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 5U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1ffdfU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__40__Vfuncout) 
              << 5U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 6U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 6U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1ffbfU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__41__Vfuncout) 
              << 6U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 7U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 7U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1ff7fU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__42__Vfuncout) 
              << 7U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 8U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 8U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1feffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__43__Vfuncout) 
              << 8U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 9U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 9U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1fdffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__44__Vfuncout) 
              << 9U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 0xaU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 0xaU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1fbffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__45__Vfuncout) 
              << 0xaU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 0xbU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 0xbU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1f7ffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__46__Vfuncout) 
              << 0xbU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 0xcU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 0xcU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1efffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__47__Vfuncout) 
              << 0xcU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 0xdU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 0xdU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1dfffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__48__Vfuncout) 
              << 0xdU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 0xeU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 0xeU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x1bfffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__49__Vfuncout) 
              << 0xeU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__b 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 >> 0xfU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__a 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                 >> 0xfU));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__func 
        = (3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__Vfuncout 
        = (1U & ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__func))
                  ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__func))
                      ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__b)
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__a)
                          ? (~ (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__b))
                          : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__b)))
                  : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__func))
                      ? ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__a) 
                         | (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__b))
                      : ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__a) 
                         & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__b)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out 
        = ((0x17fffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out) 
           | ((IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__logic1__50__Vfuncout) 
              << 0xfU));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlt32c 
        = (0x1ffffffffULL & ((QData)((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a)) 
                             * (QData)((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc_sel__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc 
        = (0x7fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_pc) 
                      + (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rel_pc)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_CF 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__set_flag) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
              >> 5U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_ZF 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__set_flag) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
              >> 6U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOAD_IF 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__set_flag) 
           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst) 
              >> 7U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__flag_load 
        = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_ARITHMETIC) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOGICAL)) 
            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_TEST)) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLTH 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLT) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__op_mix));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_cin 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_wc) 
            & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cflag)) 
           ^ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_sub));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_sel 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_pc) 
            << 1U) | ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle) 
                        & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_JABS)) 
                       & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__cc_true)) 
                      & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_JABS) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst));
    vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__dinst 
        = vlTOPp->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__di;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_unit__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlth_out 
        = (0x1ffffU & (IData)((vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlt32c 
                               >> 0x10U)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mltl_out 
        = (0x1ffffU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlt32c));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__I0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__I2 
        = (((0xfU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc) 
                     >> 0U)) << 1U) | 0U);
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__I1 
        = (0x7ffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc) 
                     >> 4U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_a_in 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_sub) 
            << 0x11U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                          << 1U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_cin)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__S 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_sel;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i2 
        = (0x7fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_in) 
                      >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i1 
        = (0x7fffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                      >> 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__sel 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_sel;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__Vfuncout 
        = ((2U == (2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__sel)))
            ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i2)
            : ((1U == (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__sel))
                ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i1)
                : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__i0)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc 
        = vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__sel3__34__Vfuncout;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__t_sel 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL) 
            << 3U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH) 
                       << 2U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2) 
                                  << 1U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_ARITHMETIC))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_load 
        = ((((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL) 
               | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH_POP)) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_LOGICAL)) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_ARITHMETIC)) 
            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLT)) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr 
        = ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr)) 
           | ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL) 
                | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_STM)) 
               & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle)) 
              | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2) 
                 & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op)))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr 
        = ((1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr)) 
           | (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL) 
                 | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_STM)) 
                & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle)) 
               | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2) 
                  & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__pfx_op)))) 
              << 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__atith_sel 
        = (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_ARITHMETIC) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CMP)) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MEM)) 
            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL)) 
           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_sel 
        = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2)) 
            << 1U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__STM_FLG));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mem_cycle 
        = (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MEM)) 
             & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inst_cycle)) 
            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__iack)) 
           | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_sel 
        = (((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_CALL) 
              | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_PUSH)) 
             | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2)) 
            << 3U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_POP_RET) 
                       << 2U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MEM) 
                                  << 1U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arith_sub))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I2 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlth_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mltl_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc_mux__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I2 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__next_pc) 
            << 1U) | 0U);
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_load 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_load) 
            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_regl)) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_load 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_a_load) 
            | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_load_regh)) 
           & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__scpu_wait_n));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_wr 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__mem_we 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16 
        = (1U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_wr));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_sel 
        = ((((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mc2_op) 
             & (~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__iack2))) 
            << 3U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__atith_sel) 
                       << 2U) | (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLTH) 
                                  << 1U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__OP_MLT))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__S 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_sel;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__S 
        = (1U & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_sel) 
                 >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_h_mux__O 
        = (0x7ffU & ((2U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_sel))
                      ? ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc) 
                         >> 4U) : ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out) 
                                   >> 5U)));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i2 
        = (0x1eU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__inc_pc) 
                    << 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_flag;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i0 
        = (0x1fU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_b_out));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__sel 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_sel;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__Vfuncout 
        = ((2U == (2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__sel)))
            ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i2)
            : ((1U == (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__sel))
                ? (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i1)
                : (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__i0)));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_l_mux__O 
        = vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__sel3__54__Vfuncout;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__S 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_sel;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i2 
        = ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__disp16) 
           << 1U);
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i1 
        = (1U | (0x1fffeU & ((~ (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b)) 
                             << 1U)));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i0 
        = (1U | ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_b) 
                 << 1U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__sel 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_sel;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__Vfuncout 
        = ((8U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__sel))
            ? 0x1fffcU : ((4U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__sel))
                           ? 4U : ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__sel))
                                    ? vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i2
                                    : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__sel))
                                        ? vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i1
                                        : vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__i0))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_in 
        = vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__sel5__51__Vfuncout;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_WR 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__mem_we;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__wren_b 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__mem_we;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_WR 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__wr16;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__S 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_sel;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_h_mux__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_h_mux__O;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out_l_mux__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_l_mux__O;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out 
        = (((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_h_mux__O) 
            << 5U) | (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellout__d_bus_out_l_mux__O));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_mux__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_in;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_out 
        = (0x1ffffU & ((vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_a_in 
                        + vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_b_in) 
                       >> 1U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_bus_out 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__timer__DOT__I_D 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wdata 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__d_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__I3 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__d_addr_mux__DOT__I0 
        = (0xffffU & (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_out 
                      >> 0U));
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i4 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT____Vcellinp__alu_out_mux__I4;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i3 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__arithmetic_out;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i2 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mlth_out;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i1 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__mltl_out;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i0 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__logical_out;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__sel 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_sel;
    vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__Vfuncout 
        = ((8U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__sel))
            ? vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i4
            : ((4U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__sel))
                ? vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i3
                : ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__sel))
                    ? vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i2
                    : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__sel))
                        ? vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i1
                        : vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__i0))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out 
        = vlTOPp->__Vfunc_top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__sel5__52__Vfuncout;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__O_D 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wdata;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_w_ram__DOT__data_b 
        = (0xffU & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__wdata) 
                    >> 0U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_al_in 
        = (0xffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out);
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__reg_ah_in 
        = (0xffU & (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out 
                    >> 8U));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out_mux__DOT__O 
        = vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out;
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_flag 
        = ((0xcU & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_flag)) 
           | (((0U == (0xffffU & vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out)) 
               << 1U) | (1U & (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out 
                               >> 0x10U))));
    vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_flag 
        = ((3U & (IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_flag)) 
           | ((8U & (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out 
                     >> 0xcU)) | (4U & ((0x7fffcU & 
                                         (vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__alu_out 
                                          >> 0xdU)) 
                                        ^ (0x7fffcU 
                                           & ((IData)(vlTOPp->top__DOT__sharpx1__DOT__subCPU__DOT__sub_cpu__DOT__cpu__DOT__rs_a) 
                                              >> 0xdU))))));
}
