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
            VL_FATAL_MT("centipede_sim.v", 4, "",
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
            VL_FATAL_MT("centipede_sim.v", 4, "",
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
    vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__rclk = vlTOPp->top__DOT__uut__DOT__hs_clk;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__reset = vlTOPp->top__DOT__uut__DOT__mpu_reset;
    vlTOPp->top__DOT__uut__DOT__s_128h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                                >> 8U));
    vlTOPp->top__DOT__uut__DOT__mpu_reset_n = (1U & 
                                               (~ (IData)(vlTOPp->top__DOT__uut__DOT__mpu_reset)));
    vlTOPp->top__DOT__uut__DOT__s_16h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                               >> 5U));
    vlTOPp->top__DOT__uut__DOT__s_8h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                              >> 4U));
    vlTOPp->top__DOT__uut__DOT__s_6mhz = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__h_counter));
    vlTOPp->top__DOT__uut__DOT__s_1h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                              >> 1U));
    vlTOPp->top__DOT__clk_48 = vlTOPp->clk_48;
    vlTOPp->top__DOT__inputs = vlTOPp->inputs;
    vlTOPp->top__DOT__ioctl_download = vlTOPp->ioctl_download;
    vlTOPp->top__DOT__ioctl_upload = vlTOPp->ioctl_upload;
    vlTOPp->top__DOT__ioctl_addr = vlTOPp->ioctl_addr;
    vlTOPp->top__DOT__ioctl_dout = vlTOPp->ioctl_dout;
    vlTOPp->top__DOT__ioctl_index = vlTOPp->ioctl_index;
    vlTOPp->top__DOT__uut__DOT__dn_addr = (0xffffU 
                                           & (vlTOPp->ioctl_addr 
                                              >> 0U));
    vlTOPp->top__DOT__uut__DOT__s_12mhz_n = (1U & (~ (IData)(vlTOPp->clk_12)));
    vlTOPp->top__DOT__clk_12 = vlTOPp->clk_12;
    vlTOPp->top__DOT__ioctl_wr = vlTOPp->ioctl_wr;
    vlTOPp->top__DOT__ioctl_din = vlTOPp->ioctl_din;
    vlTOPp->top__DOT__reset = vlTOPp->reset;
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
    vlTOPp->top__DOT__uut__DOT__s_12mhz = vlTOPp->clk_12;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset_n 
        = vlTOPp->top__DOT__uut__DOT__mpu_reset_n;
    vlTOPp->top__DOT__uut__DOT__s_8h_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__s_8h)));
    vlTOPp->top__DOT__uut__DOT__clk_6mhz_o = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->top__DOT__uut__DOT__vprom__DOT__clk = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->top__DOT__uut__DOT__rom__DOT__clk = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->top__DOT__uut__DOT__ram__DOT__clk = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__clk_a 
        = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__clk_b 
        = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__clk_a 
        = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->top__DOT__uut__DOT__s_6mhz_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz)));
    vlTOPp->top__DOT__uut__DOT__mpu_clk = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->top__DOT__uut__DOT__clk_12mhz = vlTOPp->top__DOT__clk_12;
    vlTOPp->top__DOT__uut__DOT__dn_wr = vlTOPp->top__DOT__ioctl_wr;
    vlTOPp->top__DOT__uut__DOT__dn_data = vlTOPp->top__DOT__ioctl_din;
    vlTOPp->top__DOT__uut__DOT__reset = vlTOPp->top__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__joystick_i = vlTOPp->top__DOT__joystick;
    vlTOPp->top__DOT__uut__DOT__js1_right = (1U & ((IData)(vlTOPp->top__DOT__joystick) 
                                                   >> 7U));
    vlTOPp->top__DOT__uut__DOT__js1_left = (1U & ((IData)(vlTOPp->top__DOT__joystick) 
                                                  >> 6U));
    vlTOPp->top__DOT__uut__DOT__js1_down = (1U & ((IData)(vlTOPp->top__DOT__joystick) 
                                                  >> 5U));
    vlTOPp->top__DOT__uut__DOT__js1_up = (1U & ((IData)(vlTOPp->top__DOT__joystick) 
                                                >> 4U));
    vlTOPp->top__DOT__uut__DOT__js2_right = (1U & ((IData)(vlTOPp->top__DOT__joystick) 
                                                   >> 3U));
    vlTOPp->top__DOT__uut__DOT__js2_left = (1U & ((IData)(vlTOPp->top__DOT__joystick) 
                                                  >> 2U));
    vlTOPp->top__DOT__uut__DOT__js2_down = (1U & ((IData)(vlTOPp->top__DOT__joystick) 
                                                  >> 1U));
    vlTOPp->top__DOT__uut__DOT__js2_up = (1U & (IData)(vlTOPp->top__DOT__joystick));
    vlTOPp->top__DOT__uut__DOT__playerinput_i = vlTOPp->top__DOT__playerinput;
    vlTOPp->top__DOT__uut__DOT__self_test = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                                   >> 6U));
    vlTOPp->top__DOT__uut__DOT__cocktail = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                                  >> 5U));
    vlTOPp->top__DOT__uut__DOT__coin_r = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                                >> 9U));
    vlTOPp->top__DOT__uut__DOT__coin_c = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                                >> 8U));
    vlTOPp->top__DOT__uut__DOT__coin_l = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                                >> 7U));
    vlTOPp->top__DOT__uut__DOT__slam = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                              >> 4U));
    vlTOPp->top__DOT__uut__DOT__start2 = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                                >> 3U));
    vlTOPp->top__DOT__uut__DOT__start1 = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                                >> 2U));
    vlTOPp->top__DOT__uut__DOT__fire2 = (1U & ((IData)(vlTOPp->top__DOT__playerinput) 
                                               >> 1U));
    vlTOPp->top__DOT__uut__DOT__fire1 = (1U & (IData)(vlTOPp->top__DOT__playerinput));
    vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__clk = vlTOPp->top__DOT__uut__DOT__s_12mhz;
    vlTOPp->top__DOT__uut__DOT__s_6_12 = (1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz) 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__s_12mhz))));
    vlTOPp->top__DOT__uut__DOT__blank_clk = ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_12mhz)) 
                                             & (0xfU 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlTOPp->top__DOT__uut__DOT__h_counter))));
    vlTOPp->top__DOT__uut__DOT__pf_rom1__DOT__clk = vlTOPp->top__DOT__uut__DOT__s_6mhz_n;
    vlTOPp->top__DOT__uut__DOT__pf_rom0__DOT__clk = vlTOPp->top__DOT__uut__DOT__s_6mhz_n;
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__clk_b 
        = vlTOPp->top__DOT__uut__DOT__s_6mhz_n;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__clk = vlTOPp->top__DOT__uut__DOT__mpu_clk;
    vlTOPp->top__DOT__uut__DOT__vprom__DOT__reset = vlTOPp->top__DOT__uut__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__rom__DOT__reset = vlTOPp->top__DOT__uut__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__ram__DOT__reset = vlTOPp->top__DOT__uut__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__pf_rom1__DOT__reset 
        = vlTOPp->top__DOT__uut__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__pf_rom0__DOT__reset 
        = vlTOPp->top__DOT__uut__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__reset 
        = vlTOPp->top__DOT__uut__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__reset 
        = vlTOPp->top__DOT__uut__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__playerin_out1 = (((IData)(vlTOPp->top__DOT__uut__DOT__coin_r) 
                                                  << 7U) 
                                                 | (((IData)(vlTOPp->top__DOT__uut__DOT__coin_c) 
                                                     << 6U) 
                                                    | (((IData)(vlTOPp->top__DOT__uut__DOT__coin_l) 
                                                        << 5U) 
                                                       | (((IData)(vlTOPp->top__DOT__uut__DOT__slam) 
                                                           << 4U) 
                                                          | (((IData)(vlTOPp->top__DOT__uut__DOT__fire2) 
                                                              << 3U) 
                                                             | (((IData)(vlTOPp->top__DOT__uut__DOT__fire1) 
                                                                 << 2U) 
                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__start2) 
                                                                    << 1U) 
                                                                   | (IData)(vlTOPp->top__DOT__uut__DOT__start1))))))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__hs_cs1) 
          & (IData)(vlTOPp->top__DOT__uut__DOT__hs_c1)) 
         & (~ (IData)(vlTOPp->top__DOT__uut__DOT__hs_c2)))) {
        vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__d 
            = vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__mem
            [vlTOPp->top__DOT__uut__DOT__hs_addr];
    }
    vlTOPp->top__DOT__uut__DOT__hs_out = vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__d;
    vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__dout = vlTOPp->top__DOT__uut__DOT__hs_out;
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
    // Body
    vlTOPp->top__DOT__uut__DOT__hsync = ((~ (IData)(vlTOPp->top__DOT__uut__DOT__hsync_reset)) 
                                         & (IData)(vlTOPp->top__DOT__uut__DOT__s_32h));
    vlTOPp->VGA_HS = vlTOPp->top__DOT__uut__DOT__hsync;
    vlTOPp->top__DOT__uut__DOT__hsync_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__hsync)));
    vlTOPp->top__DOT__VGA_HS = vlTOPp->VGA_HS;
    vlTOPp->top__DOT__uut__DOT__hsync_o = vlTOPp->top__DOT__VGA_HS;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vtableidx1;
    CData/*7:0*/ __Vdlyvval__top__DOT__uut__DOT__ram__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__ram__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0;
    CData/*7:0*/ __Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0;
    CData/*7:0*/ __Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0;
    CData/*7:0*/ __Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__uut__DOT__ram__DOT__mem__v0;
    // Body
    vlTOPp->__Vdly__top__DOT__uut__DOT__pf_shift0 = vlTOPp->top__DOT__uut__DOT__pf_shift0;
    vlTOPp->__Vdly__top__DOT__uut__DOT__pf_shift1 = vlTOPp->top__DOT__uut__DOT__pf_shift1;
    __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0 = 0U;
    __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0 = 0U;
    __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0 = 0U;
    __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0 = 0U;
    __Vdlyvset__top__DOT__uut__DOT__ram__DOT__mem__v0 = 0U;
    vlTOPp->__Vdlyvset__top__DOT__uut__DOT__color_ram__DOT__ram__v0 = 0U;
    __Vtableidx1 = vlTOPp->top__DOT__uut__DOT__vprom_addr;
    vlTOPp->top__DOT__uut__DOT__vprom__DOT__q = vlTOPp->__Vtable1_top__DOT__uut__DOT__vprom__DOT__q
        [__Vtableidx1];
    vlTOPp->__Vdlyvval__top__DOT__uut__DOT__line_ram__v0 
        = vlTOPp->top__DOT__uut__DOT__y;
    vlTOPp->__Vdlyvset__top__DOT__uut__DOT__line_ram__v0 = 1U;
    vlTOPp->__Vdlyvdim0__top__DOT__uut__DOT__line_ram__v0 
        = vlTOPp->top__DOT__uut__DOT__line_ram_addr;
    if (vlTOPp->reset) {
        vlTOPp->__Vdly__top__DOT__uut__DOT__pf_shift0 = 0U;
        vlTOPp->__Vdly__top__DOT__uut__DOT__pf_shift1 = 0U;
        vlTOPp->top__DOT__uut__DOT__line_ram_ctr = 0U;
    } else {
        vlTOPp->__Vdly__top__DOT__uut__DOT__pf_shift0 
            = ((IData)(vlTOPp->top__DOT__uut__DOT__pload_n)
                ? (0xfeU & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_shift0) 
                            << 1U)) : (IData)(vlTOPp->top__DOT__uut__DOT__pf_mux0));
        vlTOPp->__Vdly__top__DOT__uut__DOT__pf_shift1 
            = ((IData)(vlTOPp->top__DOT__uut__DOT__pload_n)
                ? (0xfeU & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_shift1) 
                            << 1U)) : (IData)(vlTOPp->top__DOT__uut__DOT__pf_mux1));
        vlTOPp->top__DOT__uut__DOT__line_ram_ctr = 
            ((IData)(vlTOPp->top__DOT__uut__DOT__line_ram_ctr_clr)
              ? 0U : (0xffU & ((IData)(vlTOPp->top__DOT__uut__DOT__line_ram_ctr_load)
                                ? (IData)(vlTOPp->top__DOT__uut__DOT__pfd_hold)
                                : ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__line_ram_ctr)))));
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__last_pokey_rd = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey_n)))) {
        vlTOPp->top__DOT__uut__DOT__last_pokey_rd = vlTOPp->top__DOT__uut__DOT__pokey_out;
    }
    if ((1U & ((~ (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a)) 
               | (~ (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a))))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a)))) {
            __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0 
                = vlTOPp->top__DOT__uut__DOT__db_out;
            __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0 = 1U;
            __Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0 
                = vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a;
        }
    }
    if ((IData)(((8U != (8U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))) 
                 | (8U != (8U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a)))))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a) 
                      >> 3U)))) {
            __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0 
                = vlTOPp->top__DOT__uut__DOT__db_out;
            __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0 = 1U;
            __Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0 
                = vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a;
        }
    }
    if ((IData)(((2U != (2U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))) 
                 | (2U != (2U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a)))))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a) 
                      >> 1U)))) {
            __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0 
                = vlTOPp->top__DOT__uut__DOT__db_out;
            __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0 = 1U;
            __Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0 
                = vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a;
        }
    }
    if ((IData)(((4U != (4U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))) 
                 | (4U != (4U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a)))))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a) 
                      >> 2U)))) {
            __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0 
                = vlTOPp->top__DOT__uut__DOT__db_out;
            __Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0 = 1U;
            __Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0 
                = vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a)) 
               | (~ (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a))))) {
        if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a))) {
            vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_a0 
                = vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram0
                [vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a];
        }
    }
    if ((IData)(((8U != (8U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))) 
                 | (8U != (8U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a)))))) {
        if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a))) {
            vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_a3 
                = vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram3
                [vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a];
        }
    }
    if ((IData)(((2U != (2U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))) 
                 | (2U != (2U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a)))))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a))) {
            vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_a1 
                = vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram1
                [vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a];
        }
    }
    if ((IData)(((4U != (4U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))) 
                 | (4U != (4U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a)))))) {
        if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a))) {
            vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_a2 
                = vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram2
                [vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a];
        }
    }
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__d_a 
        = ((IData)(vlTOPp->reset) ? 0U : vlTOPp->top__DOT__uut__DOT__color_ram__DOT__ram
           [(0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))]);
    if (vlTOPp->top__DOT__uut__DOT__ram__DOT__ram_write) {
        __Vdlyvval__top__DOT__uut__DOT__ram__DOT__mem__v0 
            = vlTOPp->top__DOT__uut__DOT__db_out;
        __Vdlyvset__top__DOT__uut__DOT__ram__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__uut__DOT__ram__DOT__mem__v0 
            = (0x3ffU & (IData)(vlTOPp->top__DOT__uut__DOT__ab));
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__coloram_w_n)))) {
        vlTOPp->__Vdlyvval__top__DOT__uut__DOT__color_ram__DOT__ram__v0 
            = (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__db_out));
        vlTOPp->__Vdlyvset__top__DOT__uut__DOT__color_ram__DOT__ram__v0 = 1U;
        vlTOPp->__Vdlyvdim0__top__DOT__uut__DOT__color_ram__DOT__ram__v0 
            = (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab));
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__ram__DOT__d = 0U;
    } else if (vlTOPp->top__DOT__uut__DOT__ram__DOT__ram_read) {
        vlTOPp->top__DOT__uut__DOT__ram__DOT__d = vlTOPp->top__DOT__uut__DOT__ram__DOT__mem
            [(0x3ffU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))];
    }
    vlTOPp->top__DOT__uut__DOT__coloren_temp = ((~ (IData)(vlTOPp->reset)) 
                                                & (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd));
    if (__Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0) {
        vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram0[__Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0] 
            = __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram0__v0;
    }
    if (__Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0) {
        vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram3[__Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0] 
            = __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram3__v0;
    }
    if (__Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0) {
        vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram1[__Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0] 
            = __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram1__v0;
    }
    if (__Vdlyvset__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0) {
        vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram2[__Vdlyvdim0__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0] 
            = __Vdlyvval__top__DOT__uut__DOT__pf_ram__DOT__ram2__v0;
    }
    if (__Vdlyvset__top__DOT__uut__DOT__ram__DOT__mem__v0) {
        vlTOPp->top__DOT__uut__DOT__ram__DOT__mem[__Vdlyvdim0__top__DOT__uut__DOT__ram__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__uut__DOT__ram__DOT__mem__v0;
    }
    vlTOPp->top__DOT__uut__DOT__coloram_out = vlTOPp->top__DOT__uut__DOT__color_ram__DOT__d_a;
    vlTOPp->top__DOT__uut__DOT__ram_out = vlTOPp->top__DOT__uut__DOT__ram__DOT__d;
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__dout_a 
        = vlTOPp->top__DOT__uut__DOT__coloram_out;
    vlTOPp->top__DOT__uut__DOT__ram__DOT__dout = vlTOPp->top__DOT__uut__DOT__ram_out;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__8(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__8\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__pfd_hold2 = 0U;
    } else if ((0U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                             >> 1U)))) {
        vlTOPp->top__DOT__uut__DOT__pfd_hold2 = vlTOPp->top__DOT__uut__DOT__pfd_hold;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__match_sum_hold = 0U;
    } else if ((3U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                             >> 1U)))) {
        vlTOPp->top__DOT__uut__DOT__match_sum_hold 
            = (((IData)(vlTOPp->top__DOT__uut__DOT__match_sum_top) 
                << 5U) | (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__match_sum)));
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__pic = 0U;
    } else if ((3U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                             >> 1U)))) {
        vlTOPp->top__DOT__uut__DOT__pic = vlTOPp->top__DOT__uut__DOT__pf;
    }
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__pfd_hold = 0U;
    } else if ((3U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                             >> 1U)))) {
        vlTOPp->top__DOT__uut__DOT__pfd_hold = (0x3fffU 
                                                & (vlTOPp->top__DOT__uut__DOT__pfd 
                                                   >> 0x10U));
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__9(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__9\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*13:0*/ __Vtableidx2;
    // Body
    __Vtableidx2 = ((0x3ffeU & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                << 1U)) | (IData)(vlTOPp->reset));
    vlTOPp->top__DOT__uut__DOT__rom__DOT__q = vlTOPp->__Vtable2_top__DOT__uut__DOT__rom__DOT__q
        [__Vtableidx2];
    vlTOPp->top__DOT__uut__DOT__rom_out = vlTOPp->top__DOT__uut__DOT__rom__DOT__q;
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__cc_latch = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__out0_n)))) {
        vlTOPp->top__DOT__uut__DOT__cc_latch = (((~ 
                                                  ((IData)(1U) 
                                                   << 
                                                   (7U 
                                                    & (IData)(vlTOPp->top__DOT__uut__DOT__ab)))) 
                                                 & (IData)(vlTOPp->top__DOT__uut__DOT__cc_latch)) 
                                                | (0xffU 
                                                   & ((1U 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                                                          >> 7U)) 
                                                      << 
                                                      (7U 
                                                       & (IData)(vlTOPp->top__DOT__uut__DOT__ab)))));
    }
    vlTOPp->top__DOT__uut__DOT__rom__DOT__dout = vlTOPp->top__DOT__uut__DOT__rom_out;
    vlTOPp->top__DOT__led = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__cc_latch) 
                                     >> 3U));
    vlTOPp->top__DOT__uut__DOT__led_o = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__cc_latch) 
                                                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__coin_ctr_r_drive = 
        (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__cc_latch) 
               >> 2U));
    vlTOPp->top__DOT__uut__DOT__coin_ctr_c_drive = 
        (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__cc_latch) 
               >> 1U));
    vlTOPp->top__DOT__uut__DOT__coin_ctr_l_drive = 
        (1U & (IData)(vlTOPp->top__DOT__uut__DOT__cc_latch));
    vlTOPp->top__DOT__uut__DOT__flip = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__cc_latch) 
                                              >> 7U));
    vlTOPp->top__DOT__uut__DOT__flip_o = vlTOPp->top__DOT__uut__DOT__flip;
    vlTOPp->top__DOT__uut__DOT__tb_mux = ((IData)(vlTOPp->top__DOT__uut__DOT__flip)
                                           ? (((IData)(vlTOPp->top__DOT__uut__DOT__s_1_horiz_dir) 
                                               << 3U) 
                                              | (((IData)(vlTOPp->top__DOT__uut__DOT__s_1_horiz_ck) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->top__DOT__uut__DOT__s_1_vert_dir) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->top__DOT__uut__DOT__s_1_vert_ck))))
                                           : (((IData)(vlTOPp->top__DOT__uut__DOT__s_2_horiz_dir) 
                                               << 3U) 
                                              | (((IData)(vlTOPp->top__DOT__uut__DOT__s_2_horiz_ck) 
                                                  << 2U) 
                                                 | (((IData)(vlTOPp->top__DOT__uut__DOT__s_2_vert_dir) 
                                                     << 1U) 
                                                    | (IData)(vlTOPp->top__DOT__uut__DOT__s_2_vert_ck)))));
    vlTOPp->top__DOT__uut__DOT__tb_v_ck = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__tb_mux));
    vlTOPp->top__DOT__uut__DOT__tb_h_ck = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__tb_mux) 
                                                 >> 2U));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__10(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__10\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__phi0a_temp = (1U & 
                                              ((~ (IData)(vlTOPp->reset)) 
                                               & (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                   | (IData)(vlTOPp->top__DOT__uut__DOT__s_4h))
                                                   ? 
                                                  ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_2h)) 
                                                   | (~ (IData)(vlTOPp->top__DOT__uut__DOT__phi0a_temp)))
                                                   : 
                                                  ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_2h)) 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__phi0a_temp)))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__11(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__11\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__phi0a = ((~ (IData)(vlTOPp->reset)) 
                                         & (IData)(vlTOPp->top__DOT__uut__DOT__phi0a_temp));
    vlTOPp->top__DOT__uut__DOT__phi0 = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__phi0a)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__phi0 = vlTOPp->top__DOT__uut__DOT__phi0;
    vlTOPp->top__DOT__uut__DOT__phi2 = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__phi0)));
    vlTOPp->top__DOT__uut__DOT__phi2 = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__phi0)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__clk 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__phi0;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__phi2 = vlTOPp->top__DOT__uut__DOT__phi2;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__phi2 = vlTOPp->top__DOT__uut__DOT__phi2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__clk 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__clk;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__phi2;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__clk_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__clk_i;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__12(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__12\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__h_counter = ((IData)(vlTOPp->reset)
                                              ? 0xd00U
                                              : ((0xfffU 
                                                  == (IData)(vlTOPp->top__DOT__uut__DOT__h_counter))
                                                  ? 0xd00U
                                                  : 
                                                 (0xfffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->top__DOT__uut__DOT__h_counter)))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__13(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__13\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vdlyvdim0__top__DOT__uut__DOT__hs_ram__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__uut__DOT__hs_ram__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__hs_ram__DOT__mem__v0;
    CData/*5:0*/ __Vdlyvdim0__top__DOT__uut__DOT__hs_ram__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__hs_ram__DOT__mem__v1;
    // Body
    vlTOPp->__Vdly__top__DOT__uut__DOT__mpu_reset_cntr 
        = vlTOPp->top__DOT__uut__DOT__mpu_reset_cntr;
    __Vdlyvset__top__DOT__uut__DOT__hs_ram__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__uut__DOT__hs_ram__DOT__mem__v1 = 0U;
    vlTOPp->top__DOT__uut__DOT__pf_ce_d = ((~ (IData)(vlTOPp->reset)) 
                                           & (IData)(vlTOPp->top__DOT__uut__DOT__pf_ce));
    if (vlTOPp->top__DOT__uut__DOT__hs_cs1) {
        if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__hs_c1)) 
                               & (~ (IData)(vlTOPp->top__DOT__uut__DOT__hs_c2)))))) {
            VL_WRITEF("hs_write\n");
            __Vdlyvval__top__DOT__uut__DOT__hs_ram__DOT__mem__v0 
                = vlTOPp->top__DOT__uut__DOT__hs_data;
            __Vdlyvset__top__DOT__uut__DOT__hs_ram__DOT__mem__v0 = 1U;
            __Vdlyvdim0__top__DOT__uut__DOT__hs_ram__DOT__mem__v0 
                = vlTOPp->top__DOT__uut__DOT__hs_addr;
        }
        if (VL_UNLIKELY(((~ (IData)(vlTOPp->top__DOT__uut__DOT__hs_c1)) 
                         & (IData)(vlTOPp->top__DOT__uut__DOT__hs_c2)))) {
            VL_WRITEF("hs_erase\n");
            __Vdlyvset__top__DOT__uut__DOT__hs_ram__DOT__mem__v1 = 1U;
            __Vdlyvdim0__top__DOT__uut__DOT__hs_ram__DOT__mem__v1 
                = vlTOPp->top__DOT__uut__DOT__hs_addr;
        }
    }
    if (__Vdlyvset__top__DOT__uut__DOT__hs_ram__DOT__mem__v0) {
        vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__mem[__Vdlyvdim0__top__DOT__uut__DOT__hs_ram__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__uut__DOT__hs_ram__DOT__mem__v0;
    }
    if (__Vdlyvset__top__DOT__uut__DOT__hs_ram__DOT__mem__v1) {
        vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__mem[__Vdlyvdim0__top__DOT__uut__DOT__hs_ram__DOT__mem__v1] = 0U;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__14(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__14\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*10:0*/ __Vtableidx4;
    SData/*10:0*/ __Vtableidx5;
    // Body
    __Vtableidx4 = vlTOPp->top__DOT__uut__DOT__pf_rom1_addr;
    vlTOPp->top__DOT__uut__DOT__pf_rom1__DOT__q = vlTOPp->__Vtable4_top__DOT__uut__DOT__pf_rom1__DOT__q
        [__Vtableidx4];
    __Vtableidx5 = vlTOPp->top__DOT__uut__DOT__pf_rom0_addr;
    vlTOPp->top__DOT__uut__DOT__pf_rom0__DOT__q = vlTOPp->__Vtable5_top__DOT__uut__DOT__pf_rom0__DOT__q
        [__Vtableidx5];
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__color_ram__DOT__d_b = 0U;
        vlTOPp->top__DOT__uut__DOT__area = 0U;
        vlTOPp->top__DOT__uut__DOT__gry = 0U;
        vlTOPp->top__DOT__uut__DOT__rgbi = 0xfU;
    } else {
        vlTOPp->top__DOT__uut__DOT__color_ram__DOT__d_b 
            = vlTOPp->top__DOT__uut__DOT__color_ram__DOT__ram
            [vlTOPp->top__DOT__uut__DOT__rama];
        vlTOPp->top__DOT__uut__DOT__area = ((2U & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_shift1) 
                                                   >> 6U)) 
                                            | (1U & 
                                               ((IData)(vlTOPp->top__DOT__uut__DOT__pf_shift0) 
                                                >> 7U)));
        vlTOPp->top__DOT__uut__DOT__gry = ((IData)(vlTOPp->top__DOT__uut__DOT__mob_n)
                                            ? (IData)(vlTOPp->top__DOT__uut__DOT__mr)
                                            : 0U);
        vlTOPp->top__DOT__uut__DOT__rgbi = ((IData)(vlTOPp->top__DOT__uut__DOT__blank_disp_n)
                                             ? (IData)(vlTOPp->top__DOT__uut__DOT__coloram_rgbi)
                                             : 0xfU);
    }
    vlTOPp->top__DOT__uut__DOT__pf_rom1_out = vlTOPp->top__DOT__uut__DOT__pf_rom1__DOT__q;
    vlTOPp->top__DOT__uut__DOT__pf_rom0_out = vlTOPp->top__DOT__uut__DOT__pf_rom0__DOT__q;
    vlTOPp->top__DOT__uut__DOT__pf_rom1__DOT__d = vlTOPp->top__DOT__uut__DOT__pf_rom1_out;
    vlTOPp->top__DOT__uut__DOT__pf_rom1_out_rev = (
                                                   (0x80U 
                                                    & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out) 
                                                       << 7U)) 
                                                   | ((0x40U 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out) 
                                                          << 5U)) 
                                                      | ((0x20U 
                                                          & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out) 
                                                             << 3U)) 
                                                         | ((0x10U 
                                                             & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out) 
                                                                << 1U)) 
                                                            | ((8U 
                                                                & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out) 
                                                                   >> 1U)) 
                                                               | ((4U 
                                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out) 
                                                                      >> 3U)) 
                                                                  | ((2U 
                                                                      & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out) 
                                                                         >> 5U)) 
                                                                     | (1U 
                                                                        & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out) 
                                                                           >> 7U)))))))));
    vlTOPp->top__DOT__uut__DOT__pf_rom0__DOT__d = vlTOPp->top__DOT__uut__DOT__pf_rom0_out;
    vlTOPp->top__DOT__uut__DOT__pf_rom0_out_rev = (
                                                   (0x80U 
                                                    & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out) 
                                                       << 7U)) 
                                                   | ((0x40U 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out) 
                                                          << 5U)) 
                                                      | ((0x20U 
                                                          & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out) 
                                                             << 3U)) 
                                                         | ((0x10U 
                                                             & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out) 
                                                                << 1U)) 
                                                            | ((8U 
                                                                & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out) 
                                                                   >> 1U)) 
                                                               | ((4U 
                                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out) 
                                                                      >> 3U)) 
                                                                  | ((2U 
                                                                      & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out) 
                                                                         >> 5U)) 
                                                                     | (1U 
                                                                        & ((IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out) 
                                                                           >> 7U)))))))));
    vlTOPp->top__DOT__uut__DOT__coloram_rgbi = vlTOPp->top__DOT__uut__DOT__color_ram__DOT__d_b;
    vlTOPp->top__DOT__uut__DOT__gry0_or_1 = (IData)(
                                                    (0U 
                                                     != 
                                                     (3U 
                                                      & (IData)(vlTOPp->top__DOT__uut__DOT__gry))));
    vlTOPp->top__DOT__rgb = ((0U == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                              ? 0x13fU : ((1U == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                           ? 0x138U
                                           : ((2U == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                               ? 0x107U
                                               : ((3U 
                                                   == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                   ? 0x100U
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                    ? 0x27U
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                     ? 0x20U
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                      ? 7U
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                       ? 0U
                                                       : 
                                                      ((8U 
                                                        == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                        ? 0x1ffU
                                                        : 
                                                       ((9U 
                                                         == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                         ? 0x1f8U
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                          ? 0x1c7U
                                                          : 
                                                         ((0xbU 
                                                           == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                           ? 0x1c0U
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                            ? 0x3fU
                                                            : 
                                                           ((0xdU 
                                                             == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                             ? 0x38U
                                                             : 
                                                            ((0xeU 
                                                              == (IData)(vlTOPp->top__DOT__uut__DOT__rgbi))
                                                              ? 7U
                                                              : 0U)))))))))))))));
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__dout_b 
        = vlTOPp->top__DOT__uut__DOT__coloram_rgbi;
    vlTOPp->top__DOT__uut__DOT__rama = ((IData)(vlTOPp->top__DOT__uut__DOT__gry0_or_1)
                                         ? (4U | (((IData)(vlTOPp->top__DOT__uut__DOT__gry0_or_1) 
                                                   << 3U) 
                                                  | (IData)(vlTOPp->top__DOT__uut__DOT__gry)))
                                         : (4U | (((IData)(vlTOPp->top__DOT__uut__DOT__gry0_or_1) 
                                                   << 3U) 
                                                  | (IData)(vlTOPp->top__DOT__uut__DOT__area))));
    vlTOPp->top__DOT__uut__DOT__rgb_o = vlTOPp->top__DOT__rgb;
    vlTOPp->top__DOT__VGA_R = ((0xe0U & ((IData)(vlTOPp->top__DOT__rgb) 
                                         << 5U)) | 
                               ((0x1cU & ((IData)(vlTOPp->top__DOT__rgb) 
                                          << 2U)) | 
                                (3U & ((IData)(vlTOPp->top__DOT__rgb) 
                                       >> 1U))));
    vlTOPp->top__DOT__VGA_G = ((0xe0U & ((IData)(vlTOPp->top__DOT__rgb) 
                                         << 2U)) | 
                               ((0x1cU & ((IData)(vlTOPp->top__DOT__rgb) 
                                          >> 1U)) | 
                                (3U & ((IData)(vlTOPp->top__DOT__rgb) 
                                       >> 4U))));
    vlTOPp->top__DOT__VGA_B = ((0xe0U & ((IData)(vlTOPp->top__DOT__rgb) 
                                         >> 1U)) | 
                               ((0x1cU & ((IData)(vlTOPp->top__DOT__rgb) 
                                          >> 4U)) | 
                                (3U & ((IData)(vlTOPp->top__DOT__rgb) 
                                       >> 7U))));
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__addr_b 
        = vlTOPp->top__DOT__uut__DOT__rama;
    vlTOPp->VGA_R = vlTOPp->top__DOT__VGA_R;
    vlTOPp->VGA_G = vlTOPp->top__DOT__VGA_G;
    vlTOPp->VGA_B = vlTOPp->top__DOT__VGA_B;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__15(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__15\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__pccount 
            = ((IData)(1U) + vlTOPp->top__DOT__uut__DOT__p6502__DOT__pccount);
        if ((0x3e8U == vlTOPp->top__DOT__uut__DOT__p6502__DOT__pccount)) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__pccount = 0U;
        }
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__16(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__16\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__xxx1 = ((~ (IData)(vlTOPp->reset)) 
                                        & (IData)(vlTOPp->top__DOT__uut__DOT__coloren));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__17(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__17\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__vblankd = ((~ (IData)(vlTOPp->reset)) 
                                           & (IData)(vlTOPp->top__DOT__uut__DOT__vblank));
    vlTOPp->top__DOT__uut__DOT__s_256h2d = ((~ (IData)(vlTOPp->reset)) 
                                            & (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd));
    vlTOPp->top__DOT__uut__DOT__vblankd_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__vblankd)));
    vlTOPp->top__DOT__uut__DOT__s_256h2d_n = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256h2d)));
    vlTOPp->top__DOT__uut__DOT__s_256hd = ((~ (IData)(vlTOPp->reset)) 
                                           & (IData)(vlTOPp->top__DOT__uut__DOT__s_256h));
    vlTOPp->top__DOT__uut__DOT__s_256hd_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)));
}

VL_INLINE_OPT void Vtop::_combo__TOP__18(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__18\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__s_32h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                               >> 6U));
    vlTOPp->top__DOT__uut__DOT__s_2h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                              >> 2U));
    vlTOPp->top__DOT__uut__DOT__s_4h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                              >> 3U));
    vlTOPp->top__DOT__uut__DOT__s_256h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                                >> 9U));
    vlTOPp->top__DOT__uut__DOT__pf_ce = (1U & (~ ((
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__s_1h) 
                                                    & (IData)(vlTOPp->top__DOT__uut__DOT__s_2h)) 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__s_4h)) 
                                                  & (IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz))));
    vlTOPp->top__DOT__uut__DOT__pload_n = (1U & (~ 
                                                 (((IData)(vlTOPp->top__DOT__uut__DOT__s_1h) 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__s_2h)) 
                                                  & (IData)(vlTOPp->top__DOT__uut__DOT__s_4h))));
    vlTOPp->top__DOT__uut__DOT__s_4h_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__s_4h)));
    vlTOPp->top__DOT__uut__DOT__s_256h_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256h)));
    vlTOPp->top__DOT__uut__DOT__line_ram_ctr_load = 
        (1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__pload_n) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__s_256h))));
    vlTOPp->top__DOT__uut__DOT__line_ram_ctr_clr = 
        (1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__pload_n) 
                  | (~ ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h) 
                        & (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd_n))))));
    vlTOPp->top__DOT__uut__DOT__mob_n = (1U & ((~ ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n) 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd))) 
                                               & (~ 
                                                  ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h2d_n) 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)))));
    vlTOPp->top__DOT__uut__DOT__match_n = (((IData)(vlTOPp->top__DOT__uut__DOT__match_sum_hold) 
                                            >> 5U) 
                                           & (IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n));
    vlTOPp->top__DOT__uut__DOT__pf_romx_haddr = ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n) 
                                                 & (IData)(vlTOPp->top__DOT__uut__DOT__pic));
    vlTOPp->top__DOT__uut__DOT__pf_addr_stamp = ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n) 
                                                 & (IData)(vlTOPp->top__DOT__uut__DOT__s_4h_n));
    if (vlTOPp->top__DOT__uut__DOT__match_n) {
        vlTOPp->top__DOT__uut__DOT__pf_mux0 = 0U;
        vlTOPp->top__DOT__uut__DOT__pf_mux1 = 0U;
    } else {
        vlTOPp->top__DOT__uut__DOT__pf_mux0 = ((0x40U 
                                                & (IData)(vlTOPp->top__DOT__uut__DOT__pic))
                                                ? (IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out_rev)
                                                : (IData)(vlTOPp->top__DOT__uut__DOT__pf_rom0_out));
        vlTOPp->top__DOT__uut__DOT__pf_mux1 = ((0x40U 
                                                & (IData)(vlTOPp->top__DOT__uut__DOT__pic))
                                                ? (IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out_rev)
                                                : (IData)(vlTOPp->top__DOT__uut__DOT__pf_rom1_out));
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__20(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__20\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__tb_v_ctr = ((IData)(vlTOPp->top__DOT__uut__DOT__tb_v_ctr_clr)
                                             ? 0U : 
                                            (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__uut__DOT__tb_v_reg)
                                               ? ((IData)(1U) 
                                                  + (IData)(vlTOPp->top__DOT__uut__DOT__tb_v_ctr))
                                               : ((IData)(vlTOPp->top__DOT__uut__DOT__tb_v_ctr) 
                                                  - (IData)(1U)))));
    vlTOPp->top__DOT__uut__DOT__trb = vlTOPp->top__DOT__uut__DOT__tb_v_ctr;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__22(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__22\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__tb_h_ctr = ((IData)(vlTOPp->top__DOT__uut__DOT__tb_h_ctr_clr)
                                             ? 0U : 
                                            (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__uut__DOT__tb_h_reg)
                                               ? ((IData)(1U) 
                                                  + (IData)(vlTOPp->top__DOT__uut__DOT__tb_h_ctr))
                                               : ((IData)(vlTOPp->top__DOT__uut__DOT__tb_h_ctr) 
                                                  - (IData)(1U)))));
    vlTOPp->top__DOT__uut__DOT__tra = vlTOPp->top__DOT__uut__DOT__tb_h_ctr;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__23(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__23\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync;
    // Body
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync;
    __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cres 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset)
            ? 0xffU : (0xfeU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cres) 
                                << 1U)));
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg = 0xfffcU;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg 
            = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_nxt;
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__prev_nmi = 0U;
    } else if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__prev_nmi = 0U;
    } else if (((~ (IData)(vlTOPp->top__DOT__pause)) 
                & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync))) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__prev_nmi = 0U;
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync)))) {
                if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) {
                    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__taken 
                        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__takb;
                }
            }
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__y_reg = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
              & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iny) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dey)) 
                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tay))) 
             | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0)) 
                & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldy)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__y_reg 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__x_reg = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
              & ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__inx) 
                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dex)) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tax)) 
                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tsx))) 
             | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2)) 
                & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldx)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__x_reg 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tmp = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if ((((((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset2) 
                    | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4)) 
                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1)) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti2)) 
                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1)) 
                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1)) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1)) 
              | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absxy))) 
             | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jsr) 
                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__branch))))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tmp 
                = vlTOPp->top__DOT__uut__DOT__db_in;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__firq = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__firq = 0U;
        }
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__firq = 0U;
        }
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nmi_edge)))) {
                    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__firq = 1U;
                }
            }
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg = 0xffU;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if ((((((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1) 
                    | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2)) 
                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1)) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2)) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                    & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int))) 
                | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__brk) 
                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__psh)) 
                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pul)) 
                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rts)) 
                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rti)))) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1)) 
              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti2))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_addo;
        } else if (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                    & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txs))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1 = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1 = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1 = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1 = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1 = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1 = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1 = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1 = 0U;
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1 
                = (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                    & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int)) 
                   | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                      & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__brk)));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                   & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int)));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync 
                = (((((((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset3) 
                            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite)) 
                           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ld_pch)) 
                          | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul)) 
                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts3)) 
                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti3)) 
                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi5)) 
                      | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
                         & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmp))) 
                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch)) 
                    | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                       & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0) 
                           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1)) 
                          | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2x)))) 
                   | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                      & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__mop)));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__branch));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rts));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rti));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pul));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jsr));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmpi));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch 
                = ((~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy)) 
                   & (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
                         & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmp) 
                               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmpi)))) 
                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2)) 
                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2)) 
                      | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                         & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpxy))));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch) 
                   | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                      & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__imm)));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite 
                = ((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2) 
                       | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                          & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2m))) 
                      | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
                         & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy))) 
                     | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2) 
                        & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy))) 
                    | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2) 
                       & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy))) 
                   | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                      & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpxy) 
                          & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy)) 
                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__psh))));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ix));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iy));
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1 
                = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absxy));
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf = 0U;
        }
        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync)))) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) {
                if ((0x80U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                  >> 6U)))) {
                        if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf = 0U;
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
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf 
                = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                         >> 6U));
        }
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vfo0;
            }
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vfo1;
            }
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf = 0U;
        }
        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync)))) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) {
                if ((0x80U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                    if ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 4U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                                    = 
                                                    (0U 
                                                     == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                             >> 4U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                            = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                    }
                                }
                            }
                        }
                    } else if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                                = (0U 
                                                   == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                        = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                            = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 2U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                    = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                            }
                        }
                    }
                } else if ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 4U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                                = (0U 
                                                   == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                         >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                            = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                            = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                     >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                                        = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                         >> 1U));
        }
        if (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
             & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pla))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
        }
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo0;
            }
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo1;
            }
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo2;
            }
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf = 0U;
        }
        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync)))) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) {
                if ((0x80U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                    if ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 4U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                                    = 
                                                    (1U 
                                                     & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                        >> 7U));
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                             >> 4U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                            = (1U & 
                                               ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                >> 7U));
                                    }
                                }
                            }
                        }
                    } else if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                                = (1U 
                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                      >> 7U));
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                 >> 7U));
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                            = (1U & 
                                               ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                >> 7U));
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 2U)))) {
                            if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                    = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                             >> 7U));
                            }
                        }
                    }
                } else if ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                    if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 4U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                                = (1U 
                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                      >> 7U));
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                         >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                            = (1U & 
                                               ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                >> 7U));
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                            = (1U & 
                                               ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                >> 7U));
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                     >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                                        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                                                 >> 7U));
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                         >> 7U));
        }
        if (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
             & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pla))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                         >> 7U));
        }
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo0;
            }
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo1;
            }
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo2;
            }
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__im = 1U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__im = 1U;
        }
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__im = 1U;
        }
        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync)))) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                              >> 7U)))) {
                    if ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__im = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__im = 0U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__im 
                = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                         >> 2U));
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__bf = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__bf = 0U;
        }
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__bf 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__fbrk;
        }
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__bf 
                = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                         >> 4U));
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df = 0U;
        }
        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync)))) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) {
                if ((0x80U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                    if ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df = 0U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df 
                = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res) 
                         >> 3U));
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma = 0xfffcU;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma 
            = vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma_nxt;
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
             & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__imm))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil 
                = vlTOPp->top__DOT__uut__DOT__db_in;
        } else if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil 
                = vlTOPp->top__DOT__uut__DOT__db_in;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf = 0U;
        }
        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync)))) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                              >> 7U)))) {
                    if ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 4U)))) {
                                if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 2U)))) {
                                        if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf 
                                                    = 
                                                    (1U 
                                                     & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg));
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                             >> 4U)))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf 
                                                = (1U 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg));
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf 
                                            = (1U & 
                                               ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                                                >> 7U));
                                    }
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf = 0U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) {
                                if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf 
                                        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                                                 >> 7U));
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf 
                = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res));
        }
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo0;
            }
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo1;
            }
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_us) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf 
                    = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo2;
            }
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__rw = 1U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__rw 
            = vlTOPp->top__DOT__uut__DOT__p6502__DOT__rw_nxt;
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__y_reg 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__y_reg;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__x_reg 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__x_reg;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__a 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_afterWrite 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_branch 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_abs1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ld_pch = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ld_pch 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti3 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti3 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti2;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts3 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts3 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts2;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset3 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset3 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset2;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi5 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi5 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4;
        }
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__vi 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__vi 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__zi 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__zi 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__zi 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__ni 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__ni 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__ni 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__fbrk = 0U;
            }
            if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4) {
                vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__fbrk = 0U;
            }
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync)))) {
                if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                  >> 7U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 6U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 5U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                              >> 4U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                  >> 3U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) {
                                                    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__fbrk = 1U;
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
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__dec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ma 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_dataFetch 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__d 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__b 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__b 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                   >> 4U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__b 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__b 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                   >> 4U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__d 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__d 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__w_cpy 
        = (0x1ffU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__y_reg) 
                     - (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__w_cpx 
        = (0x1ffU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__x_reg) 
                     - (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ci 
        = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__flags = 
        (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf) 
          << 4U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf) 
                     << 3U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf) 
                                << 2U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf) 
                                           << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__taken)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sr_reg 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf) 
            << 7U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf) 
                       << 6U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__bf) 
                                  << 4U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df) 
                                             << 3U) 
                                            | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__im) 
                                                << 2U) 
                                               | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf) 
                                                   << 1U) 
                                                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf)))))));
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
               & ((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tya) 
                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txa)) 
                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ror_a)) 
                    | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__lsr_a)) 
                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rol_a)) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__asl_a))) 
              | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pla))) 
             | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1)) 
                & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cmp))))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res;
        }
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rw 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__rw;
    vlTOPp->top__DOT__uut__DOT__rw_n = vlTOPp->top__DOT__uut__DOT__p6502__DOT__rw;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__dec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__dec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__dec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__dec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__b 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__d;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__b 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__d;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ci;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__flags 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__flags;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__ci;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__rw_n = vlTOPp->top__DOT__uut__DOT__rw_n;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__r_w_n = vlTOPp->top__DOT__uut__DOT__rw_n;
    vlTOPp->top__DOT__uut__DOT__brw_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__rw_n)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_jmpi1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_ld_pch 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ld_pch;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_ix1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_ix2 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_iy1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_iy2 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_rti3 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti3;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti2 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti2 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1;
        }
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_rts3 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts3;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts2 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts2 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1;
        }
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_reset3 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset3;
    if (VL_UNLIKELY(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1)) {
        VL_WRITEF("cpu: out of reset ****\n");
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset2 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset2 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1;
        }
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_jsr2 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_jsr1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_nmi5 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi5;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi3;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir = 0xeaU;
    } else if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir = 0xeaU;
    } else if (((~ (IData)(vlTOPp->top__DOT__pause)) 
                & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync))) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir 
            = vlTOPp->top__DOT__uut__DOT__db_in;
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__dec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__dec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__dec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__dec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__dec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__dec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__dec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__dec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__ci;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_pul 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_update 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_exec 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__a_reg 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__a 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__a 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                   >> 4U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__a 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__a 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                   >> 4U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__bin_sum 
        = (0x3ffU & ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                       << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf)) 
                     + (1U | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                              << 1U))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__bin_dif 
        = (0x3ffU & ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                       << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf)) 
                     - (1U | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                              << 1U))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__a_reg 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__w_bit 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
           & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp_tmp 
        = (0x1ffU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                     - (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__tmp1 
        = (0x3fU & (((0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                               << 1U)) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf)) 
                    + (1U | (0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                      << 1U)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__tmp1 
        = (0x3fU & (((0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                               << 1U)) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf)) 
                    - (1U | (0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                      << 1U)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__a 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__a_reg;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__a 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__a_reg;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp_c 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp_tmp) 
                 >> 8U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp_o 
        = (0xffU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp_tmp));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__hc1 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__tmp1) 
                 >> 5U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__sum 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__tmp1) 
                   >> 1U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__dif 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__tmp1) 
                   >> 1U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__hb1 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__tmp1) 
                 >> 5U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_rti2 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_rti1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_rts1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_rts2 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_reset2 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_nmi4 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi3 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi3 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset = 1U;
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1 = 0U;
    } else if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset) {
        __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset = 1U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset) {
            __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset = 0U;
        }
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1 
            = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset;
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_sync 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__sync = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldy 
        = (5U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__styy 
        = (4U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cmp 
        = (6U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__ir 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__ir 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__ir 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldy_i 
        = (0xa0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cpy_i 
        = (0xc0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cpx_i 
        = (0xe0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cond 
        = (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                 >> 5U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__d_shift 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                    >> 7U)));
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                  >> 7U)))) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__sc 
            = (1U & ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                      ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)
                      : ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                          ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                             >> 7U) : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                       >> 7U))));
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp 
        = (6U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sta 
        = (4U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmp 
        = (0x4cU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmpi 
        = (0x6cU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__ldy 
        = (5U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc 
        = (3U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc 
        = (7U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__res 
        = (0xffU & ((7U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                  >> 5U))) ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__w_cpx)
                     : ((6U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                      >> 5U))) ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__w_cpy)
                         : ((1U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                                          >> 5U))) ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__w_bit)
                             : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__bitt 
        = (1U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__cpy 
        = (6U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__cpx 
        = (7U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_o 
        = (0xffU & ((0x80U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                     ? ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                         ? ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                             ? ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil))
                             : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                - (IData)(1U))) : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil))
                     : ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                         ? ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                             ? (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf) 
                                 << 7U) | (0x7fU & 
                                           ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                            >> 1U)))
                             : (0x7fU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                         >> 1U))) : 
                        ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                          ? ((0xfeU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                       << 1U)) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf))
                          : (0xfeU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                      << 1U))))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sta 
        = (((((((0x85U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)) 
                | (0x95U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) 
               | (0x81U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) 
              | (0x91U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) 
             | (0x8dU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) 
            | (0x9dU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) 
           | (0x99U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rts 
        = (0x60U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rti 
        = (0x40U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__branch 
        = (0x10U == (0x1fU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jsr 
        = (0x20U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iy 
        = (IData)((0x11U == (0x1dU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0 
        = (0U == (3U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1 
        = (1U == (3U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp 
        = (0x28U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pla 
        = (0x68U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldx 
        = (5U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nop 
        = (0xeaU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__clc 
        = (0x18U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cld 
        = (0xd8U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__clv 
        = (0xb8U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cli 
        = (0x58U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sec 
        = (0x38U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sed 
        = (0xf8U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sei 
        = (0x78U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__stxx 
        = (4U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tay 
        = (0xa8U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tax 
        = (0xaaU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tsx 
        = (0xbaU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ror_a 
        = (0x6aU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__lsr_a 
        = (0x4aU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rol_a 
        = (0x2aU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__asl_a 
        = (0xaU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldx_i 
        = (0xa2U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__abs 
        = (3U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 2U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ror 
        = (3U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rol 
        = (1U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__lsr 
        = (2U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__asl 
        = (0U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__inc 
        = (7U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dec 
        = (6U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 5U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ix 
        = (IData)((1U == (0x1dU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zp 
        = (1U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                        >> 2U)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sty 
        = (((0x84U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)) 
            | (0x94U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) 
           | (0x8cU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__stx 
        = (((0x86U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)) 
            | (0x96U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) 
           | (0x8eU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2 
        = (2U == (3U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__inx 
        = (0xe8U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iny 
        = (0xc8U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tya 
        = (0x98U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txa 
        = (0x8aU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txs 
        = (0x9aU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dex 
        = (0xcaU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dey 
        = (0x88U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__brk 
        = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absy 
        = ((IData)((0x19U == (0x1dU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) 
           | (0xbeU == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpy 
        = ((0x96U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)) 
           | (0xb6U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__php 
        = (8U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pha 
        = (0x48U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__tmp2 
        = (0x1fU & ((0xaU <= (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__sum))
                     ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__sum) 
                        + (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df) 
                            << 2U) | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df) 
                                      << 1U))) : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__sum)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__tmp2 
        = (0x1fU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__dif) 
                    - ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__hb1) 
                         & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df)) 
                        << 2U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__hb1) 
                                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df)) 
                                  << 1U))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sync 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__sync;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_us 
        = (((4U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))) 
            | (0xcU == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) 
           | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldy_i) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cpy_i)) 
              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cpx_i)));
    vlTOPp->__Vtableidx3 = (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf) 
                             << 6U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf) 
                                        << 5U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf) 
                                                   << 4U) 
                                                  | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf) 
                                                      << 3U) 
                                                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cond)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__takb 
        = vlTOPp->__Vtable3_top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__takb
        [vlTOPp->__Vtableidx3];
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo2 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__d_shift)
            ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__sc)
            : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__jmp 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmp;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__jmpi 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmpi;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vfo0 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__bitt)
                  ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                     >> 6U) : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo0 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__cpy)
                  ? (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__w_cpy) 
                        >> 8U)) : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__cpx)
                                    ? (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__w_cpx) 
                                          >> 8U)) : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo0 
        = (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__cpy) 
              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__cpx)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__bitt)) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__ldy))
            ? (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__res))
            : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo0 
        = (1U & ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__cpy) 
                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__cpx)) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__ldy))
                  ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__res) 
                     >> 7U) : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__bitt)
                                ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                   >> 7U) : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__o 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_o;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__rts 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rts;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__rti 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rti;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__branch 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__branch;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__jsr 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jsr;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__iy 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iy;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__grp0 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_us 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__grp1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pul 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__plp) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pla));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__ldx 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldx;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__stxx 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__stxx;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__stxx) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo2 
            = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf));
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo2 
            = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf;
    } else {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo2 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_o) 
                     >> 7U));
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo2 
            = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_o));
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__imm 
        = (((IData)((9U == (0x1dU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir)))) 
            | (IData)((0x80U == (0x9fU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))))) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldx_i));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__ix 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ix;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sta) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__stx)) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sty));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_us 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2) 
           & (0xaU != (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2x 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ldx) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__stxx)) 
           & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2m 
        = (((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__asl) 
                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rol)) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__lsr)) 
              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ror)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dec)) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__inc)) 
           & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__mop 
        = ((((((((((((((((((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nop) 
                               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__inx)) 
                              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dex)) 
                             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iny)) 
                            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dey)) 
                           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txa)) 
                          | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tax)) 
                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tya)) 
                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tay)) 
                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txs)) 
                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tsx)) 
                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cld)) 
                    | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sed)) 
                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sei)) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cli)) 
                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sec)) 
                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__clc)) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__clv)) 
              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__asl_a)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__lsr_a)) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ror_a)) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rol_a));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dex) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dey));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_reg 
        = ((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__inx) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dex)) 
              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__stx)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txa)) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txs))
            ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__x_reg)
            : (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iny) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dey)) 
                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sty)) 
                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tya))
                ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__y_reg)
                : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__brk 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__brk;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absx 
        = ((7U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                         >> 2U))) & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absy)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpx 
        = ((5U == (7U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir) 
                         >> 2U))) & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpy)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__psh 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__php) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pha));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__o 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__tmp2) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__hc2 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__tmp2) 
                 >> 4U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__o 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__tmp2) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__hb2 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__tmp2) 
                 >> 4U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_nmi3 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi3;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vec 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi3)
            ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__firq)
                ? 0xfffeU : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__fbrk)
                              ? 0xfffeU : 0xfffaU))
            : 0xfffcU);
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2 = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2 
                = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1;
        }
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_reset 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_reset1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__v 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vfo0;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo0;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__z 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo0;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0_inst__DOT__n 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo0;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__pul 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pul;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__n 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_inst__DOT__z 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__imm 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__imm;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__staxy 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__grp2x 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2x;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__grp2m 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2m;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__mop 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__mop;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__op 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__a 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_reg;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__sum 
                = (0x3ffU & ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_reg) 
                               << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op)) 
                             - (IData)(3U)));
        }
    } else {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__sum 
            = (0x3ffU & ((IData)(3U) + (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_reg) 
                                         << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op))));
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absxy 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__abs) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absx)) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absy));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__xyz_reg 
        = ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
             & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absx)) 
            | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
               & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpx) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ix))))
            ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__x_reg)
            : (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
                  & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absy)) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                    & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpy))) 
                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2))
                ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__y_reg)
                : 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpxy 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zp) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpx)) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpy));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__psh 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__psh;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__c4 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__hc1) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__hc2));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__c4 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__hb1) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__hb2));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cres) 
                 >> 7U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1 
        = __Vdly__top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__co 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__sum) 
                 >> 9U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_addo 
        = (0xffU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__sum) 
                    >> 1U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__absxy 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absxy;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__zpxy 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpxy;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__c4;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__c4;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__tmp1 
        = (0x3fU & (((0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                               >> 3U)) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__c4)) 
                    + (1U | (0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                      >> 3U)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__c4;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__c4;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__tmp1 
        = (0x3fU & (((0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                               >> 3U)) | (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__c4)))) 
                    - (1U | (0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil) 
                                      >> 3U)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__creset 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__creset;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_nmi2 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__s_nmi1 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__state = 
        (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset) 
          << 0x1fU) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1) 
                        << 0x1eU) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset2) 
                                      << 0x1dU) | (
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset3) 
                                                    << 0x1cU) 
                                                   | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1) 
                                                       << 0x1bU) 
                                                      | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2) 
                                                          << 0x1aU) 
                                                         | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi3) 
                                                             << 0x19U) 
                                                            | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4) 
                                                                << 0x18U) 
                                                               | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi5) 
                                                                   << 0x17U) 
                                                                  | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ld_pch) 
                                                                      << 0x16U) 
                                                                     | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                                                         << 0x15U) 
                                                                        | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch) 
                                                                            << 0x14U) 
                                                                           | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch) 
                                                                               << 0x13U) 
                                                                              | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2) 
                                                                                << 9U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul) 
                                                                                << 8U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1) 
                                                                                << 7U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts2) 
                                                                                << 6U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts3) 
                                                                                << 5U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1) 
                                                                                << 4U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti2) 
                                                                                << 3U) 
                                                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti3) 
                                                                                << 2U) 
                                                                                | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                                                                                << 1U)))))))))))))))))))))))))))))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__o 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_addo;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_adder__DOT__v 
        = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op) 
                  ^ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_addo) 
                     >> 7U)) & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__axy_adder__op)) 
                                ^ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_reg) 
                                   >> 7U))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__hc1 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__tmp1) 
                 >> 5U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__sum 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__tmp1) 
                   >> 1U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__dif 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__tmp1) 
                   >> 1U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__hb1 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__tmp1) 
                 >> 5U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__state 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__state;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__tmp2 
        = (0x1fU & ((0xaU <= (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__sum))
                     ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__sum) 
                        + (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df) 
                            << 2U) | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df) 
                                      << 1U))) : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__sum)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__tmp2 
        = (0x1fU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__dif) 
                    - ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__hb1) 
                         & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df)) 
                        << 2U) | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__hb1) 
                                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__df)) 
                                  << 1U))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__o 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__tmp2) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__hc2 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__tmp2) 
                 >> 4U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__dec_sum 
        = ((0xf0U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__tmp2) 
                     << 4U)) | (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na0__DOT__tmp2)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__o 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__tmp2) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__hb2 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__tmp2) 
                 >> 4U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__dec_dif 
        = ((0xf0U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__tmp2) 
                     << 4U)) | (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns0__DOT__tmp2)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__c8 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__hc1) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__hc2));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc_o 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__dec_sum;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__c8 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__hb1) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__hb2));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc_o 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__dec_dif;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__na1__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__c8;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc_c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__c8;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__o 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc_o;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__ns1__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__c8;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc_c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__c8;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__o 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc_o;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_o 
        = ((0x80U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
            ? ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                ? ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                    ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc_o)
                    : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp_o))
                : ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                    ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)
                    : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg)))
            : ((0x40U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                ? ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                    ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc_o)
                    : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                       ^ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)))
                : ((0x20U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ir))
                    ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                       & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil))
                    : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__add0__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc_c;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sub0__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc_c;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo1 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc)
                  ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc_c)
                  : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc)
                      ? (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc_c))
                      : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp)
                          ? (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__cmp_c))
                          : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__o 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_o;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sta) {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo1 
            = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nf));
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo1 
            = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zf;
    } else {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo1 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_o) 
                     >> 7U));
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo1 
            = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_o));
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vfo1 
        = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__adc) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__sbc))
                  ? ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_o) 
                       ^ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg)) 
                      & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_o) 
                         ^ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil))) 
                     >> 7U) : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vf)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__c 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cfo1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__n 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nfo1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__z 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zfo1;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_inst__DOT__v 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vfo1;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__24(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__24\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr__v8;
    CData/*7:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count;
    CData/*2:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift;
    CData/*2:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift;
    CData/*5:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57;
    CData/*1:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4;
    CData/*7:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6;
    CData/*7:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6;
    CData/*7:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6;
    CData/*7:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf;
    CData/*0:0*/ __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf;
    // Body
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count;
    __Vdlyvset__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr__v0 = 0U;
    __Vdlyvset__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr__v8 = 0U;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__filter_reg = 0U;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__filter_reg = 0U;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__last_key_break = 0U;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__last_key_pressed = 0U;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serin_ack_o = 0U;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__last_serin_rdy_i = 0U;
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift 
        = ((6U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift) 
                  << 1U)) | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17));
    __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift 
        = ((6U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift) 
                  << 1U)) | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__shift 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst)
            ? (0xeU & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__shift) 
                       << 1U)) : ((0xeU & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__shift) 
                                           << 1U)) 
                                  | (1U & (~ (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__shift) 
                                               >> 3U) 
                                              ^ ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__shift) 
                                                 >> 2U))))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5_shift 
        = ((6U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5_shift) 
                  << 1U)) | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__shift 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst)
            ? (0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__shift) 
                        << 1U)) : ((0x1eU & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__shift) 
                                             << 1U)) 
                                   | (1U & (~ (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__shift) 
                                                >> 4U) 
                                               ^ ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__shift) 
                                                  >> 2U))))));
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57 = 0U;
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4 = 0U;
    } else if ((0x38U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4 
            = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4)));
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57 = 0U;
    } else {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57 
            = (0x3fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57)));
    }
    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__no_poly5 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 7U));
    }
    if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__no_poly5 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 7U));
    }
    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__no_poly5 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 7U));
    }
    if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__no_poly5 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 7U));
    }
    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__vol 
            = (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__db_out));
    }
    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__vol_only 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 4U));
    }
    if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__vol 
            = (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__db_out));
    }
    if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__vol_only 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 4U));
    }
    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__vol 
            = (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__db_out));
    }
    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__vol_only 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 4U));
    }
    if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__vol 
            = (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__db_out));
    }
    if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__vol_only 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 4U));
    }
    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6 
            = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__freq;
    } else if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6 
            = (0xffU & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6) 
                        - (IData)(1U)));
    }
    if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6 
            = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__freq;
    } else if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6 
            = (0xffU & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6) 
                        - (IData)(1U)));
    }
    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6 
            = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__freq;
    } else if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6 
            = (0xffU & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6) 
                        - (IData)(1U)));
    }
    if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6 
            = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__freq;
    } else if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6 
            = (0xffU & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6) 
                        - (IData)(1U)));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf = 0U;
    } else if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__change) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__no_poly17_4)
                      ? (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf))
                      : ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__poly4_sel)
                          ? ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift) 
                             >> 2U) : ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift) 
                                       >> 2U))));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf = 0U;
    } else if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__change) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__no_poly17_4)
                      ? (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf))
                      : ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__poly4_sel)
                          ? ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift) 
                             >> 1U) : ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift) 
                                       >> 1U))));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf = 0U;
    } else if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__change) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__no_poly17_4)
                      ? (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf))
                      : ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__poly4_sel)
                          ? (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift)
                          : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift))));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf = 0U;
    } else if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__change) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__no_poly17_4)
                      ? (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf))
                      : ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__poly4_sel)
                          ? (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4)
                          : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17))));
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst)))) {
        if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
              & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
             & (0xdU == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
            vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout 
                = vlTOPp->top__DOT__uut__DOT__db_out;
        }
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fast_ch0 = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (8U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fast_ch0 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 6U));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fast_ch2 = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (8U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fast_ch2 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 5U));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ch23 = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (8U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ch23 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 3U));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ch01 = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (8U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ch01 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 4U));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base15 = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (8U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base15 
            = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__db_out));
    }
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
          & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
         & (0xbU == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_done = 0U;
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count = 0U;
    } else if ((0xffU != (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count))) {
        __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count)));
    } else {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_done = 0xffU;
    }
    if ((1U & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi13)) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer)))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__filter_reg = 0U;
    } else if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__filter_reg 
            = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf;
    }
    if ((1U & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi02)) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer)))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__filter_reg = 0U;
    } else if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__filter_reg 
            = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf;
    }
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
          & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
         & (0xbU == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        __Vdlyvset__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr__v0 = 1U;
    } else {
        __Vdlyvset__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr__v8 = 1U;
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__shift 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst)
            ? 0U : ((0x1fe00U & (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__shift 
                                 << 1U)) | ((0x100U 
                                             & (((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly9)
                                                    ? (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__new_bit)
                                                    : 
                                                   (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__shift 
                                                    >> 7U)) 
                                                  & (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst))) 
                                                 & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__last_short) 
                                                    | (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly9)))) 
                                                << 8U)) 
                                            | ((0xfeU 
                                                & (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__shift 
                                                   << 1U)) 
                                               | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__new_bit)))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqen) 
           & (((0xf0U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst)) 
               | ((8U & (((~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout_ack_i)) 
                          & (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout_rdy_o))) 
                         << 3U)) | (7U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst)))) 
              | ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout_ack_i) 
                   & (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__last_serout_ack_i))) 
                  << 4U) | ((4U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                                   >> 1U)) | (3U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow))))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_count;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf 
        = __Vdly__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf;
    if (__Vdlyvset__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr__v0) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[0U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[1U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[2U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[3U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[4U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[5U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[6U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[7U] = 0U;
    }
    if (__Vdlyvset__top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr__v8) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[0U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[1U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[2U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[3U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[4U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[5U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[6U] = 0U;
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr[7U] = 0U;
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__shift) 
                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__poly5 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5_shift) 
                 >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__poly5 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5_shift) 
                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__poly5 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5_shift) 
                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__shift) 
                 >> 4U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__borrow 
        = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ctr_out 
        = ((0xffffffU & vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ctr_out) 
           | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6) 
              << 0x18U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow 
        = ((7U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow)) 
           | ((0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr3____pinNumber6)) 
              << 3U));
    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__freq 
            = vlTOPp->top__DOT__uut__DOT__db_out;
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__borrow 
        = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ctr_out 
        = ((0xff00ffffU & vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ctr_out) 
           | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6) 
              << 0x10U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow 
        = ((0xbU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow)) 
           | ((0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr2____pinNumber6)) 
              << 2U));
    if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__freq 
            = vlTOPp->top__DOT__uut__DOT__db_out;
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__borrow 
        = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ctr_out 
        = ((0xffff00ffU & vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ctr_out) 
           | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6) 
              << 8U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow 
        = ((0xdU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow)) 
           | ((0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr1____pinNumber6)) 
              << 1U));
    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__freq 
            = vlTOPp->top__DOT__uut__DOT__db_out;
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__borrow 
        = (0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ctr_out 
        = ((0xffffff00U & vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ctr_out) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow 
        = ((0xeU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow)) 
           | (0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT____Vcellout__u_ctr0____pinNumber6)));
    if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__freq 
            = vlTOPp->top__DOT__uut__DOT__db_out;
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__ch_out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__nf;
    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__no_poly17_4 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 5U));
    }
    if ((8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__poly4_sel 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 6U));
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__ch_out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__nf;
    if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__no_poly17_4 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 5U));
    }
    if ((4U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__poly4_sel 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 6U));
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__poly4 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift) 
                 >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__poly4 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift) 
                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__poly4 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4_shift) 
                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__poly17 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift) 
                 >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__poly17 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift) 
                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__poly17 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17_shift) 
                 >> 2U));
    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__no_poly17_4 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 5U));
    }
    if ((2U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__poly4_sel 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 6U));
    }
    if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__no_poly17_4 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 5U));
    }
    if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__poly4_sel 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 6U));
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__base15 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base15;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base 
        = ((0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div57)) 
           & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base15)) 
              | (0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__div4))));
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi13 = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (8U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi13 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 1U));
    }
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi02 = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (8U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi02 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 2U));
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__new_bit 
        = (1U & (~ ((vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__shift 
                     >> 0x10U) ^ (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__shift 
                                  >> 0xbU))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17 
        = (1U & (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__shift 
                 >> 0x10U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__random 
        = (0xffU & (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__shift 
                    >> 9U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__last_short 
        = ((~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst)) 
           & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly9));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__last_serout_ack_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout_ack_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq = 0U;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq) 
                 | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst) 
                    >> 1U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst) 
                    >> 2U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst) 
                    >> 3U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst) 
                    >> 4U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst) 
                    >> 5U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst) 
                    >> 6U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irq) 
                 | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst) 
                    >> 7U)));
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout_rdy_o = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (0xdU == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout_rdy_o = 1U;
    } else if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout_ack_i) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__serout_rdy_o = 0U;
    }
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
          & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
         & (0xeU == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqen 
            = vlTOPp->top__DOT__uut__DOT__db_out;
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__poly4 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly4;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__poly5 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__in 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                 >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__filter_in 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__in 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__filter_in 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__in 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__in 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__change 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
           & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__no_poly5) 
              | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__change 
        = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                  >> 1U) & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__no_poly5) 
                            | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5_shift))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__change 
        = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                  >> 2U) & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__no_poly5) 
                            | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5_shift) 
                               >> 1U))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__change 
        = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                  >> 3U) & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__no_poly5) 
                            | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly5_shift) 
                               >> 2U))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout3 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__ch_out) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__vol_only))
            ? (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__vol)
            : 0U);
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout2 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__ch_out) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__vol_only))
            ? (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__vol)
            : 0U);
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en 
        = ((0xcU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en)) 
           | ((2U & (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ch01)
                       ? (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow)
                       : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base)) 
                     << 1U)) | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fast_ch0) 
                                | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en 
        = ((3U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en)) 
           | ((8U & (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ch23)
                       ? ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                          >> 2U) : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base)) 
                     << 3U)) | (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fast_ch2) 
                                 | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__base)) 
                                << 2U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__poly17 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly17;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__random 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__random;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout3;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout2;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__cnt_en 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en) 
                 >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__cnt_en 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en) 
                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__cnt_en 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en) 
                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__cnt_en 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__cnt_en) 
                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__filter_en 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi13;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__ch_out 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi13)
            ? ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__filter_reg) 
               ^ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf))
            : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__nf));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__filter_en 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi02;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__ch_out 
        = ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__fi02)
            ? ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__filter_reg) 
               ^ (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf))
            : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__nf));
    if (vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly9 = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (8U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly9 
            = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                     >> 7U));
    }
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout1 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__ch_out) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__vol_only))
            ? (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__vol)
            : 0U);
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout0 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__ch_out) 
            | (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__vol_only))
            ? (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__vol)
            : 0U);
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout1;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__out 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout0;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__audout 
        = (0x3fU & ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout0) 
                      + (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout1)) 
                     + (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout2)) 
                    + (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout3)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__short 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__poly9;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audout 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__audout;
    vlTOPp->top__DOT__uut__DOT__audio = vlTOPp->top__DOT__uut__DOT__pokey__DOT__audout;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__aud = vlTOPp->top__DOT__uut__DOT__audio;
    vlTOPp->top__DOT__audio = vlTOPp->top__DOT__uut__DOT__audio;
    vlTOPp->top__DOT__uut__DOT__audio_o = vlTOPp->top__DOT__audio;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__25(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__25\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__uut__DOT__mpu_reset) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst_bits = 0U;
    } else if ((((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
                 & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
                & (0xfU == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))))) {
        vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst_bits 
            = (3U & (IData)(vlTOPp->top__DOT__uut__DOT__db_out));
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__26(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__26\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__top__DOT__uut__DOT__color_ram__DOT__ram__v0) {
        vlTOPp->top__DOT__uut__DOT__color_ram__DOT__ram[vlTOPp->__Vdlyvdim0__top__DOT__uut__DOT__color_ram__DOT__ram__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__uut__DOT__color_ram__DOT__ram__v0;
    }
    vlTOPp->top__DOT__uut__DOT__pf_shift1 = vlTOPp->__Vdly__top__DOT__uut__DOT__pf_shift1;
    vlTOPp->top__DOT__uut__DOT__pf_shift0 = vlTOPp->__Vdly__top__DOT__uut__DOT__pf_shift0;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__27(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__27\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__mr = ((IData)(vlTOPp->reset)
                                       ? 0U : vlTOPp->top__DOT__uut__DOT__line_ram
                                      [vlTOPp->top__DOT__uut__DOT__line_ram_addr]);
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__mpu_reset = 1U;
        vlTOPp->__Vdly__top__DOT__uut__DOT__mpu_reset_cntr = 0U;
    } else if ((0x10U != (IData)(vlTOPp->top__DOT__uut__DOT__mpu_reset_cntr))) {
        vlTOPp->__Vdly__top__DOT__uut__DOT__mpu_reset_cntr 
            = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__mpu_reset_cntr)));
    } else {
        vlTOPp->top__DOT__uut__DOT__mpu_reset = 0U;
    }
    vlTOPp->top__DOT__uut__DOT__mpu_reset_cntr = vlTOPp->__Vdly__top__DOT__uut__DOT__mpu_reset_cntr;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__28(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__28\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__coloren = ((~ (IData)(vlTOPp->reset)) 
                                           & (IData)(vlTOPp->top__DOT__uut__DOT__coloren_temp));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__29(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__29\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__y = ((2U & (((0U == (IData)(vlTOPp->top__DOT__uut__DOT__area))
                                              ? ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)) 
                                                 & ((IData)(vlTOPp->top__DOT__uut__DOT__gry) 
                                                    >> 1U))
                                              : ((1U 
                                                  == (IData)(vlTOPp->top__DOT__uut__DOT__area))
                                                  ? 
                                                 ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)) 
                                                  & ((IData)(vlTOPp->top__DOT__uut__DOT__pfd_hold2) 
                                                     >> 9U))
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlTOPp->top__DOT__uut__DOT__area))
                                                   ? 
                                                  ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)) 
                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__pfd_hold2) 
                                                      >> 0xbU))
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlTOPp->top__DOT__uut__DOT__area)) 
                                                   & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)) 
                                                      & ((IData)(vlTOPp->top__DOT__uut__DOT__pfd_hold2) 
                                                         >> 0xdU)))))) 
                                            << 1U)) 
                                     | (1U & ((0U == (IData)(vlTOPp->top__DOT__uut__DOT__area))
                                               ? ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)) 
                                                  & (IData)(vlTOPp->top__DOT__uut__DOT__gry))
                                               : ((1U 
                                                   == (IData)(vlTOPp->top__DOT__uut__DOT__area))
                                                   ? 
                                                  ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)) 
                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__pfd_hold2) 
                                                      >> 8U))
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->top__DOT__uut__DOT__area))
                                                    ? 
                                                   ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)) 
                                                    & ((IData)(vlTOPp->top__DOT__uut__DOT__pfd_hold2) 
                                                       >> 0xaU))
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->top__DOT__uut__DOT__area)) 
                                                    & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256hd)) 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__pfd_hold2) 
                                                          >> 0xcU))))))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__30(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__30\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__hs = ((IData)(vlTOPp->top__DOT__uut__DOT__hs_set) 
                                      | (IData)(vlTOPp->top__DOT__uut__DOT__s_64h));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__31(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__31\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->top__DOT__uut__DOT__vprom_reg = 0U;
        vlTOPp->top__DOT__uut__DOT__v_counter = 0U;
    } else {
        vlTOPp->top__DOT__uut__DOT__vprom_reg = vlTOPp->top__DOT__uut__DOT__vprom_out;
        vlTOPp->top__DOT__uut__DOT__v_counter = ((IData)(vlTOPp->top__DOT__uut__DOT__vreset_n)
                                                  ? 
                                                 (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->top__DOT__uut__DOT__v_counter)))
                                                  : 0U);
    }
    vlTOPp->top__DOT__uut__DOT__vreset = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__vprom_reg) 
                                                >> 2U));
    vlTOPp->top__DOT__uut__DOT__vblank_n = (1U & (~ 
                                                  ((IData)(vlTOPp->top__DOT__uut__DOT__vprom_reg) 
                                                   >> 3U)));
    vlTOPp->top__DOT__uut__DOT__vreset_n = (1U & (~ 
                                                  ((IData)(vlTOPp->top__DOT__uut__DOT__vprom_reg) 
                                                   >> 2U)));
    vlTOPp->top__DOT__uut__DOT__vsync_n = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__vprom_reg)));
    vlTOPp->top__DOT__uut__DOT__vsync = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__vprom_reg));
    vlTOPp->top__DOT__uut__DOT__vblank = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__vprom_reg) 
                                                >> 3U));
    vlTOPp->top__DOT__uut__DOT__s_8v = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__v_counter) 
                                              >> 3U));
    vlTOPp->top__DOT__uut__DOT__s_1v = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__v_counter));
    vlTOPp->top__DOT__uut__DOT__s_2v = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__v_counter) 
                                              >> 1U));
    vlTOPp->top__DOT__uut__DOT__s_4v = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__v_counter) 
                                              >> 2U));
    vlTOPp->top__DOT__uut__DOT__s_64v = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__v_counter) 
                                               >> 6U));
    vlTOPp->top__DOT__uut__DOT__s_128v = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__v_counter) 
                                                >> 7U));
    vlTOPp->top__DOT__uut__DOT__s_16v = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__v_counter) 
                                               >> 4U));
    vlTOPp->VGA_VS = vlTOPp->top__DOT__uut__DOT__vsync;
    vlTOPp->VGA_VB = vlTOPp->top__DOT__uut__DOT__vblank;
    vlTOPp->top__DOT__VGA_VS = vlTOPp->VGA_VS;
    vlTOPp->top__DOT__VGA_VB = vlTOPp->VGA_VB;
    vlTOPp->top__DOT__uut__DOT__vsync_o = vlTOPp->top__DOT__VGA_VS;
    vlTOPp->top__DOT__uut__DOT__vblank_o = vlTOPp->top__DOT__VGA_VB;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__32(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__32\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__tb_v_reg = ((~ (IData)(vlTOPp->reset)) 
                                            & (IData)(vlTOPp->top__DOT__uut__DOT__tb_v_dir));
    vlTOPp->top__DOT__uut__DOT__dir2 = vlTOPp->top__DOT__uut__DOT__tb_v_reg;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__33(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__33\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__tb_h_reg = ((~ (IData)(vlTOPp->reset)) 
                                            & (IData)(vlTOPp->top__DOT__uut__DOT__tb_h_dir));
    vlTOPp->top__DOT__uut__DOT__dir1 = vlTOPp->top__DOT__uut__DOT__tb_h_reg;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__34(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__34\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__write_n = (1U & (~ 
                                                 ((IData)(vlTOPp->top__DOT__uut__DOT__phi2) 
                                                  & (~ (IData)(vlTOPp->top__DOT__uut__DOT__rw_n)))));
    vlTOPp->top__DOT__uut__DOT__ram__DOT__we_n = vlTOPp->top__DOT__uut__DOT__write_n;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__35(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__35\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__we = (1U 
                                                  & (~ (IData)(vlTOPp->top__DOT__uut__DOT__rw_n)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__we_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__we;
}

VL_INLINE_OPT void Vtop::_combo__TOP__36(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__36\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst 
        = ((0U == (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst_bits)) 
           | (IData)(vlTOPp->top__DOT__uut__DOT__mpu_reset));
    vlTOPp->top__DOT__uut__DOT__hs_set = (1U & ((IData)(vlTOPp->reset) 
                                                | (~ (IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n))));
    vlTOPp->top__DOT__uut__DOT__s_64h = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__h_counter) 
                                               >> 7U));
    vlTOPp->top__DOT__uut__DOT__hsync_reset = ((IData)(vlTOPp->reset) 
                                               | (IData)(vlTOPp->top__DOT__uut__DOT__hs));
    vlTOPp->top__DOT__uut__DOT__v_counter_reset = (1U 
                                                   & ((IData)(vlTOPp->reset) 
                                                      | (~ (IData)(vlTOPp->top__DOT__uut__DOT__vreset_n))));
    vlTOPp->top__DOT__uut__DOT__pf_sel = ((IData)(vlTOPp->top__DOT__uut__DOT__pf_addr_stamp)
                                           ? 0U : (
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__s_8v) 
                                                    << 1U) 
                                                   | (IData)(vlTOPp->top__DOT__uut__DOT__s_128h)));
    vlTOPp->top__DOT__uut__DOT__match_mux = (0xfU & 
                                             ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h)
                                               ? ((8U 
                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__pic) 
                                                      << 3U)) 
                                                  | (((IData)(vlTOPp->top__DOT__uut__DOT__s_4v) 
                                                      << 2U) 
                                                     | (((IData)(vlTOPp->top__DOT__uut__DOT__s_2v) 
                                                         << 1U) 
                                                        | (IData)(vlTOPp->top__DOT__uut__DOT__s_1v))))
                                               : (IData)(vlTOPp->top__DOT__uut__DOT__match_sum_hold)));
    vlTOPp->top__DOT__uut__DOT__playerin_out0 = (((IData)(vlTOPp->top__DOT__uut__DOT__dir1) 
                                                  << 7U) 
                                                 | (((IData)(vlTOPp->top__DOT__uut__DOT__vblank) 
                                                     << 6U) 
                                                    | (((IData)(vlTOPp->top__DOT__uut__DOT__self_test) 
                                                        << 5U) 
                                                       | (((IData)(vlTOPp->top__DOT__uut__DOT__cocktail) 
                                                           << 4U) 
                                                          | (IData)(vlTOPp->top__DOT__uut__DOT__tra)))));
    vlTOPp->top__DOT__uut__DOT__write2_n = (1U & (~ 
                                                  ((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz) 
                                                   & (~ (IData)(vlTOPp->top__DOT__uut__DOT__write_n)))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_base__DOT__rst 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly4__DOT__rst 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly5__DOT__rst 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_poly17__DOT__rst 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__rst;
    vlTOPp->top__DOT__uut__DOT__pfa3210 = (((IData)(vlTOPp->top__DOT__uut__DOT__s_64h) 
                                            << 3U) 
                                           | (((IData)(vlTOPp->top__DOT__uut__DOT__s_32h) 
                                               << 2U) 
                                              | (((IData)(vlTOPp->top__DOT__uut__DOT__s_16h) 
                                                  << 1U) 
                                                 | (IData)(vlTOPp->top__DOT__uut__DOT__s_8h))));
    vlTOPp->top__DOT__uut__DOT__mga = ((8U & ((0xfffffff8U 
                                               & (IData)(vlTOPp->top__DOT__uut__DOT__match_mux)) 
                                              ^ (0xffffff8U 
                                                 & (((IData)(vlTOPp->top__DOT__uut__DOT__pic) 
                                                     >> 4U) 
                                                    & ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n) 
                                                       << 3U))))) 
                                       | ((4U & ((0xfffffffcU 
                                                  & (IData)(vlTOPp->top__DOT__uut__DOT__match_mux)) 
                                                 ^ 
                                                 (0x7fffffcU 
                                                  & ((IData)(vlTOPp->top__DOT__uut__DOT__pic) 
                                                     >> 5U)))) 
                                          | ((2U & 
                                              ((0xfffffffeU 
                                                & (IData)(vlTOPp->top__DOT__uut__DOT__match_mux)) 
                                               ^ (0x3fffffeU 
                                                  & ((IData)(vlTOPp->top__DOT__uut__DOT__pic) 
                                                     >> 6U)))) 
                                             | (1U 
                                                & ((IData)(vlTOPp->top__DOT__uut__DOT__match_mux) 
                                                   ^ 
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__pic) 
                                                    >> 7U))))));
    vlTOPp->top__DOT__uut__DOT__ea_addr_clk = ((IData)(vlTOPp->top__DOT__uut__DOT__ea_addr_n) 
                                               | (IData)(vlTOPp->top__DOT__uut__DOT__write2_n));
    vlTOPp->top__DOT__uut__DOT__pf_rom1_addr = (((IData)(vlTOPp->top__DOT__uut__DOT__pf_romx_haddr) 
                                                 << 0xaU) 
                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__s_256h) 
                                                    << 9U) 
                                                   | ((0x1f0U 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__pic) 
                                                          << 3U)) 
                                                      | (IData)(vlTOPp->top__DOT__uut__DOT__mga))));
    vlTOPp->top__DOT__uut__DOT__pf_rom0_addr = (((IData)(vlTOPp->top__DOT__uut__DOT__pf_romx_haddr) 
                                                 << 0xaU) 
                                                | (((IData)(vlTOPp->top__DOT__uut__DOT__s_256h) 
                                                    << 9U) 
                                                   | ((0x1f0U 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__pic) 
                                                          << 3U)) 
                                                      | (IData)(vlTOPp->top__DOT__uut__DOT__mga))));
    vlTOPp->top__DOT__uut__DOT__pf_rom1__DOT__a = vlTOPp->top__DOT__uut__DOT__pf_rom1_addr;
    vlTOPp->top__DOT__uut__DOT__pf_rom0__DOT__a = vlTOPp->top__DOT__uut__DOT__pf_rom0_addr;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__37(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__37\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__top__DOT__uut__DOT__line_ram__v0) {
        vlTOPp->top__DOT__uut__DOT__line_ram[vlTOPp->__Vdlyvdim0__top__DOT__uut__DOT__line_ram__v0] 
            = vlTOPp->__Vdlyvval__top__DOT__uut__DOT__line_ram__v0;
    }
    vlTOPp->top__DOT__uut__DOT__line_ram_addr = vlTOPp->top__DOT__uut__DOT__line_ram_ctr;
    vlTOPp->top__DOT__uut__DOT__vprom_out = vlTOPp->top__DOT__uut__DOT__vprom__DOT__q;
    vlTOPp->top__DOT__uut__DOT__vprom__DOT__d = vlTOPp->top__DOT__uut__DOT__vprom_out;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__38(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__38\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__hblank_n = (1U & (~ 
                                                  ((~ (IData)(vlTOPp->top__DOT__uut__DOT__xxx1)) 
                                                   & (~ (IData)(vlTOPp->top__DOT__uut__DOT__coloren)))));
    vlTOPp->top__DOT__uut__DOT__hblank = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__hblank_n)));
    vlTOPp->VGA_HB = vlTOPp->top__DOT__uut__DOT__hblank;
    vlTOPp->top__DOT__VGA_HB = vlTOPp->VGA_HB;
    vlTOPp->top__DOT__uut__DOT__hblank_o = vlTOPp->top__DOT__VGA_HB;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__39(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__39\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__comp_sync = ((IData)(vlTOPp->top__DOT__uut__DOT__hsync_n) 
                                             & (IData)(vlTOPp->top__DOT__uut__DOT__vsync_n));
    vlTOPp->top__DOT__uut__DOT__sync_o = vlTOPp->top__DOT__uut__DOT__comp_sync;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__40(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__40\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__irq = (1U & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__irqres_n)) 
                                             | (~ (IData)(vlTOPp->top__DOT__uut__DOT__s_32v))));
    vlTOPp->top__DOT__uut__DOT__irq_n = vlTOPp->top__DOT__uut__DOT__irq;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__irq = vlTOPp->top__DOT__uut__DOT__irq_n;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__irq 
        = (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__irq_n)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__41(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__41\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__tb_v_dir = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__tb_mux) 
                                                  >> 1U));
    vlTOPp->top__DOT__uut__DOT__tb_h_dir = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__tb_mux) 
                                                  >> 3U));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__42(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__42\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__hs_data = vlTOPp->top__DOT__uut__DOT__db_out;
    vlTOPp->top__DOT__uut__DOT__hs_addr = (0x3fU & (IData)(vlTOPp->top__DOT__uut__DOT__ab));
    vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__din = vlTOPp->top__DOT__uut__DOT__hs_data;
    vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__a = vlTOPp->top__DOT__uut__DOT__hs_addr;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__43(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__43\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__blank_disp_n = ((IData)(vlTOPp->top__DOT__uut__DOT__hblank_n) 
                                                & (IData)(vlTOPp->top__DOT__uut__DOT__vblankd_n));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__44(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__44\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__s_32v = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__v_counter) 
                                               >> 5U));
    vlTOPp->top__DOT__uut__DOT__vprom_addr = (((IData)(vlTOPp->top__DOT__uut__DOT__vblank) 
                                               << 7U) 
                                              | (((IData)(vlTOPp->top__DOT__uut__DOT__s_128v) 
                                                  << 6U) 
                                                 | (((IData)(vlTOPp->top__DOT__uut__DOT__s_64v) 
                                                     << 5U) 
                                                    | (((IData)(vlTOPp->top__DOT__uut__DOT__s_32v) 
                                                        << 4U) 
                                                       | (((IData)(vlTOPp->top__DOT__uut__DOT__s_8v) 
                                                           << 3U) 
                                                          | (((IData)(vlTOPp->top__DOT__uut__DOT__s_4v) 
                                                              << 2U) 
                                                             | (((IData)(vlTOPp->top__DOT__uut__DOT__s_2v) 
                                                                 << 1U) 
                                                                | (IData)(vlTOPp->top__DOT__uut__DOT__s_1v))))))));
    vlTOPp->top__DOT__uut__DOT__match_line = (((IData)(vlTOPp->top__DOT__uut__DOT__s_128v) 
                                               << 7U) 
                                              | (((IData)(vlTOPp->top__DOT__uut__DOT__s_64v) 
                                                  << 6U) 
                                                 | (((IData)(vlTOPp->top__DOT__uut__DOT__s_32v) 
                                                     << 5U) 
                                                    | (((IData)(vlTOPp->top__DOT__uut__DOT__s_16v) 
                                                        << 4U) 
                                                       | (((IData)(vlTOPp->top__DOT__uut__DOT__s_8v) 
                                                           << 3U) 
                                                          | (((IData)(vlTOPp->top__DOT__uut__DOT__s_4v) 
                                                              << 2U) 
                                                             | (((IData)(vlTOPp->top__DOT__uut__DOT__s_2v) 
                                                                 << 1U) 
                                                                | (IData)(vlTOPp->top__DOT__uut__DOT__s_1v))))))));
    vlTOPp->top__DOT__uut__DOT__vprom__DOT__a = vlTOPp->top__DOT__uut__DOT__vprom_addr;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__45(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__45\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__nmi_edge) 
                 | ((~ (IData)(vlTOPp->top__DOT__uut__DOT__irq_n)) 
                    & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__im)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__any_int 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__rw_nxt 
        = (1U & (~ ((((((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                            & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int)) 
                           | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                               & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpxy)) 
                              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy))) 
                          | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                             & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__brk) 
                                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__psh)))) 
                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1)) 
                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2)) 
                       | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy) 
                          & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2) 
                              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2)) 
                             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1)))) 
                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1)) 
                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2)) 
                    | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                       & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2m)))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op 
        = ((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1) 
               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2)) 
              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1)) 
             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2)) 
            | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
               & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int))) 
           | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
              & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__brk) 
                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__psh))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rw_nxt 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__rw_nxt;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__op 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__ci 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op;
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op) {
        if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op) {
            vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__sum 
                = (0x3ffU & ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg) 
                               << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op)) 
                             - (IData)(3U)));
        }
    } else {
        vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__sum 
            = (0x3ffU & ((IData)(3U) + (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg) 
                                         << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op))));
    }
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__co 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__sum) 
                 >> 9U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_addo 
        = (0xffU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__sum) 
                    >> 1U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__o 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_addo;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__spadder__DOT__v 
        = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op) 
                  ^ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_addo) 
                     >> 7U)) & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT____Vcellinp__spadder__op)) 
                                ^ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg) 
                                   >> 7U))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__46(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__46\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__ab = vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma;
    vlTOPp->top__DOT__uut__DOT__rom__DOT__a = (0x1fffU 
                                               & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                  >> 0U));
    vlTOPp->top__DOT__uut__DOT__ram__DOT__a = (0x3ffU 
                                               & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                  >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__a = vlTOPp->top__DOT__uut__DOT__ab;
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__addr_a 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a 
        = ((0xf0U & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                     >> 2U)) | (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__a = (0xfU 
                                                 & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                    >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we 
        = ((0xcU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we)) 
           | (((2U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))) 
               << 1U) | (0U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab)))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we 
        = ((3U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we)) 
           | (((6U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))) 
               << 3U) | ((4U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))) 
                         << 2U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we 
        = ((0xcU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we)) 
           | (((3U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))) 
               << 1U) | (1U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab)))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we 
        = ((3U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we)) 
           | (((7U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))) 
               << 3U) | ((5U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))) 
                         << 2U)));
    vlTOPp->top__DOT__uut__DOT__switch_out = ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                               ? (IData)(vlTOPp->top__DOT__sw2)
                                               : (IData)(vlTOPp->top__DOT__sw1));
    vlTOPp->top__DOT__uut__DOT__rom_n = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__brw_n) 
                                               | (~ 
                                                  ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                   >> 0xdU))));
    vlTOPp->top__DOT__uut__DOT__pfrd3_n = (1U & (((0U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                       >> 4U)))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (3U 
                                                     & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                        >> 4U)))
                                                    ? 0xdU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                         >> 4U)))
                                                     ? 0xbU
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (3U 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                          >> 4U)))
                                                      ? 7U
                                                      : 0xfU)))) 
                                                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__pfrd2_n = (1U & (((0U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                       >> 4U)))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (3U 
                                                     & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                        >> 4U)))
                                                    ? 0xdU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                         >> 4U)))
                                                     ? 0xbU
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (3U 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                          >> 4U)))
                                                      ? 7U
                                                      : 0xfU)))) 
                                                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pfrd1_n = (1U & (((0U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                       >> 4U)))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (3U 
                                                     & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                        >> 4U)))
                                                    ? 0xdU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                         >> 4U)))
                                                     ? 0xbU
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (3U 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                          >> 4U)))
                                                      ? 7U
                                                      : 0xfU)))) 
                                                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pfrd0_n = ((0U == (3U 
                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                      >> 4U)))
                                            ? 0U : 1U);
    vlTOPp->top__DOT__uut__DOT__adecode = ((0U == (0xfU 
                                                   & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                      >> 0xaU)))
                                            ? 0x3feU
                                            : ((1U 
                                                == 
                                                (0xfU 
                                                 & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                    >> 0xaU)))
                                                ? 0x3fdU
                                                : (
                                                   (2U 
                                                    == 
                                                    (0xfU 
                                                     & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                        >> 0xaU)))
                                                    ? 0x3fbU
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (0xfU 
                                                      & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                         >> 0xaU)))
                                                     ? 0x3f7U
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (0xfU 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                          >> 0xaU)))
                                                      ? 0x3efU
                                                      : 
                                                     ((5U 
                                                       == 
                                                       (0xfU 
                                                        & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                           >> 0xaU)))
                                                       ? 0x3dfU
                                                       : 
                                                      ((6U 
                                                        == 
                                                        (0xfU 
                                                         & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                            >> 0xaU)))
                                                        ? 0x3bfU
                                                        : 
                                                       ((7U 
                                                         == 
                                                         (0xfU 
                                                          & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                             >> 0xaU)))
                                                         ? 0x37fU
                                                         : 
                                                        ((8U 
                                                          == 
                                                          (0xfU 
                                                           & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                              >> 0xaU)))
                                                          ? 0x2ffU
                                                          : 
                                                         ((9U 
                                                           == 
                                                           (0xfU 
                                                            & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                               >> 0xaU)))
                                                           ? 0x1ffU
                                                           : 0x3ffU))))))))));
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__addr_a 
        = vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__addr_a;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__adr_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__a;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__freq_ld 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we) 
                 >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__freq_ld 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we) 
                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__freq_ld 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we) 
                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__freq_ld 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audf_we) 
                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__audc_we 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we) 
                 >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__audc_we 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we) 
                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__audc_we 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we) 
                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__audc_we 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__audc_we) 
                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__rom__DOT__cs_n = vlTOPp->top__DOT__uut__DOT__rom_n;
    vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__pfrd3_n) 
            << 3U) | (((IData)(vlTOPp->top__DOT__uut__DOT__pfrd2_n) 
                       << 2U) | (((IData)(vlTOPp->top__DOT__uut__DOT__pfrd1_n) 
                                  << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__pfrd0_n))));
    vlTOPp->top__DOT__uut__DOT__coloram_n = (1U & (
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                                    >> 5U) 
                                                   | ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                      >> 9U)));
    vlTOPp->top__DOT__uut__DOT__swrd_n = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                                >> 2U));
    vlTOPp->top__DOT__uut__DOT__in0_n = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                                >> 3U) 
                                               | ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                  >> 1U)));
    vlTOPp->top__DOT__uut__DOT__in1_n = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                                >> 3U) 
                                               | (~ 
                                                  ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                   >> 1U))));
    vlTOPp->top__DOT__uut__DOT__ram0_n = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__adecode));
    vlTOPp->top__DOT__uut__DOT__pf_n = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                              >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey_n = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                                 >> 4U));
    vlTOPp->top__DOT__uut__DOT__C5 = (1U & ((~ ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                >> 9U)) 
                                            | ((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                               >> 5U)));
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ce_a = vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a;
    vlTOPp->top__DOT__uut__DOT__ram__DOT__cs_n = vlTOPp->top__DOT__uut__DOT__ram0_n;
    vlTOPp->top__DOT__uut__DOT__pframrd_n = ((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                             | (IData)(vlTOPp->top__DOT__uut__DOT__brw_n));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__cs1_n = vlTOPp->top__DOT__uut__DOT__pokey_n;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb = (1U 
                                                   & (~ (IData)(vlTOPp->top__DOT__uut__DOT__pokey_n)));
    vlTOPp->top__DOT__uut__DOT__ea_addr_n = ((0U == 
                                              (((IData)(vlTOPp->top__DOT__uut__DOT__C5) 
                                                << 2U) 
                                               | (3U 
                                                  & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                     >> 7U))))
                                              ? 0U : 1U);
    vlTOPp->top__DOT__uut__DOT__ea_read_n = (1U & (
                                                   ((0U 
                                                     == 
                                                     (((IData)(vlTOPp->top__DOT__uut__DOT__C5) 
                                                       << 2U) 
                                                      | (3U 
                                                         & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                            >> 7U))))
                                                     ? 6U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (((IData)(vlTOPp->top__DOT__uut__DOT__C5) 
                                                        << 2U) 
                                                       | (3U 
                                                          & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                             >> 7U))))
                                                      ? 5U
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (((IData)(vlTOPp->top__DOT__uut__DOT__C5) 
                                                         << 2U) 
                                                        | (3U 
                                                           & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                              >> 7U))))
                                                       ? 3U
                                                       : 7U))) 
                                                   >> 2U));
    vlTOPp->top__DOT__uut__DOT__ea_ctrl_n = (1U & (
                                                   ((0U 
                                                     == 
                                                     (((IData)(vlTOPp->top__DOT__uut__DOT__C5) 
                                                       << 2U) 
                                                      | (3U 
                                                         & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                            >> 7U))))
                                                     ? 6U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (((IData)(vlTOPp->top__DOT__uut__DOT__C5) 
                                                        << 2U) 
                                                       | (3U 
                                                          & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                             >> 7U))))
                                                      ? 5U
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (((IData)(vlTOPp->top__DOT__uut__DOT__C5) 
                                                         << 2U) 
                                                        | (3U 
                                                           & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                              >> 7U))))
                                                       ? 3U
                                                       : 7U))) 
                                                   >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__stb_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ack_o 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__we) 
            & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__stb)) 
           & (9U == (0xfU & (IData)(vlTOPp->top__DOT__uut__DOT__ab))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__rst 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__rst 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__rst 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__rst 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer;
}

VL_INLINE_OPT void Vtop::_combo__TOP__47(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__47\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__pfa7654 = ((IData)(vlTOPp->top__DOT__uut__DOT__pf_addr_stamp)
                                            ? 0xfU : 
                                           (((IData)(vlTOPp->top__DOT__uut__DOT__s_128v) 
                                             << 3U) 
                                            | (((IData)(vlTOPp->top__DOT__uut__DOT__s_64v) 
                                                << 2U) 
                                               | (((IData)(vlTOPp->top__DOT__uut__DOT__s_32v) 
                                                   << 1U) 
                                                  | (IData)(vlTOPp->top__DOT__uut__DOT__s_16v)))));
    if ((1U & (IData)(vlTOPp->top__DOT__uut__DOT__ab))) {
        vlTOPp->top__DOT__uut__DOT__joystick_out = 
            (((IData)(vlTOPp->top__DOT__uut__DOT__js1_right) 
              << 7U) | (((IData)(vlTOPp->top__DOT__uut__DOT__js1_left) 
                         << 6U) | (((IData)(vlTOPp->top__DOT__uut__DOT__js1_down) 
                                    << 5U) | (((IData)(vlTOPp->top__DOT__uut__DOT__js1_up) 
                                               << 4U) 
                                              | (((IData)(vlTOPp->top__DOT__uut__DOT__js2_right) 
                                                  << 3U) 
                                                 | (((IData)(vlTOPp->top__DOT__uut__DOT__js2_left) 
                                                     << 2U) 
                                                    | (((IData)(vlTOPp->top__DOT__uut__DOT__js2_down) 
                                                        << 1U) 
                                                       | (IData)(vlTOPp->top__DOT__uut__DOT__js2_up))))))));
        vlTOPp->top__DOT__uut__DOT__playerin_out = vlTOPp->top__DOT__uut__DOT__playerin_out1;
    } else {
        vlTOPp->top__DOT__uut__DOT__joystick_out = 
            (((IData)(vlTOPp->top__DOT__uut__DOT__dir2) 
              << 7U) | (IData)(vlTOPp->top__DOT__uut__DOT__trb));
        vlTOPp->top__DOT__uut__DOT__playerin_out = vlTOPp->top__DOT__uut__DOT__playerin_out0;
    }
    vlTOPp->top__DOT__uut__DOT__watchdog_n = (1U & 
                                              (((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                                >> 8U) 
                                               | (IData)(vlTOPp->top__DOT__uut__DOT__write2_n)));
    vlTOPp->top__DOT__uut__DOT__out0_n = (1U & (((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                                 >> 7U) 
                                                | (IData)(vlTOPp->top__DOT__uut__DOT__write2_n)));
    vlTOPp->top__DOT__uut__DOT__steerclr_n = (1U & 
                                              (((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                                >> 9U) 
                                               | (IData)(vlTOPp->top__DOT__uut__DOT__write2_n)));
    vlTOPp->top__DOT__uut__DOT__irqres_n = ((((IData)(vlTOPp->top__DOT__uut__DOT__adecode) 
                                              >> 6U) 
                                             | (IData)(vlTOPp->top__DOT__uut__DOT__write2_n)) 
                                            & (IData)(vlTOPp->top__DOT__uut__DOT__mpu_reset_n));
    vlTOPp->top__DOT__uut__DOT__ea_ctrl_clk = ((IData)(vlTOPp->top__DOT__uut__DOT__ea_ctrl_n) 
                                               | (IData)(vlTOPp->top__DOT__uut__DOT__write2_n));
    vlTOPp->top__DOT__uut__DOT__pfa = (((IData)(vlTOPp->top__DOT__uut__DOT__pfa7654) 
                                        << 4U) | (IData)(vlTOPp->top__DOT__uut__DOT__pfa3210));
    vlTOPp->top__DOT__uut__DOT__tb_h_ctr_clr = (1U 
                                                & ((IData)(vlTOPp->reset) 
                                                   | (~ (IData)(vlTOPp->top__DOT__uut__DOT__steerclr_n))));
    vlTOPp->top__DOT__uut__DOT__tb_v_ctr_clr = (1U 
                                                & ((IData)(vlTOPp->reset) 
                                                   | (~ (IData)(vlTOPp->top__DOT__uut__DOT__steerclr_n))));
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__addr_b 
        = vlTOPp->top__DOT__uut__DOT__pfa;
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_b3 = 
        vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram3
        [vlTOPp->top__DOT__uut__DOT__pfa];
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_b2 = 
        vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram2
        [vlTOPp->top__DOT__uut__DOT__pfa];
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_b1 = 
        vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram1
        [vlTOPp->top__DOT__uut__DOT__pfa];
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_b0 = 
        vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram0
        [vlTOPp->top__DOT__uut__DOT__pfa];
    vlTOPp->top__DOT__uut__DOT__pfd = (((IData)(vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_b3) 
                                        << 0x18U) | 
                                       (((IData)(vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_b2) 
                                         << 0x10U) 
                                        | (((IData)(vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_b1) 
                                            << 8U) 
                                           | (IData)(vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_b0))));
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__dout_b 
        = vlTOPp->top__DOT__uut__DOT__pfd;
    vlTOPp->top__DOT__uut__DOT__pf = (0xffU & ((0U 
                                                == (IData)(vlTOPp->top__DOT__uut__DOT__pf_sel))
                                                ? vlTOPp->top__DOT__uut__DOT__pfd
                                                : (
                                                   (1U 
                                                    == (IData)(vlTOPp->top__DOT__uut__DOT__pf_sel))
                                                    ? 
                                                   (vlTOPp->top__DOT__uut__DOT__pfd 
                                                    >> 8U)
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlTOPp->top__DOT__uut__DOT__pf_sel))
                                                     ? 
                                                    (vlTOPp->top__DOT__uut__DOT__pfd 
                                                     >> 0x10U)
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlTOPp->top__DOT__uut__DOT__pf_sel))
                                                      ? 
                                                     (vlTOPp->top__DOT__uut__DOT__pfd 
                                                      >> 0x18U)
                                                      : 0U)))));
    vlTOPp->top__DOT__uut__DOT__match_sum = (0xffU 
                                             & ((IData)(vlTOPp->top__DOT__uut__DOT__match_line) 
                                                + (vlTOPp->top__DOT__uut__DOT__pfd 
                                                   >> 8U)));
    vlTOPp->top__DOT__uut__DOT__match_sum_top = (1U 
                                                 & (~ (IData)(
                                                              (0xf0U 
                                                               == 
                                                               (0xf0U 
                                                                & (IData)(vlTOPp->top__DOT__uut__DOT__match_sum))))));
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__48(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__48\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__pokey_out = (0xffU 
                                             & ((8U 
                                                 & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                                 ? 
                                                ((4U 
                                                  & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                                    ? 0xffU
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqst) 
                                                     & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__irqen))))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                                    ? 0U
                                                    : 0xffU))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                                    ? 0xffU
                                                    : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__random))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__uut__DOT__ab))
                                                    ? 0U
                                                    : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_done))))
                                                 : 
                                                vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__pot_cntr
                                                [(7U 
                                                  & (IData)(vlTOPp->top__DOT__uut__DOT__ab))]));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start 
        = ((0xdU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start)) 
           | (2U & (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer) 
                     << 1U) | (0xfffffffeU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow)))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start 
        = ((7U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start)) 
           | (8U & (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer) 
                     << 3U) | (0xfffffff8U & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow)))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start 
        = ((0xeU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start)) 
           | (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer) 
                    | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ch01)
                        ? ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                           >> 1U) : (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow)))));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start 
        = ((0xbU & (IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start)) 
           | (4U & (((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start_timer) 
                     | ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__ch23)
                         ? ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                            >> 3U) : ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__borrow) 
                                      >> 2U))) << 2U)));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__d_out = vlTOPp->top__DOT__uut__DOT__pokey_out;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__start 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start) 
                 >> 0U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__start 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start) 
                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__start 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start) 
                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__start 
        = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__start) 
                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_o 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__d_out;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__49(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__49\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__pf_out = ((8U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))
                                           ? ((4U & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))
                                               ? ((2U 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a))
                                                    ? 0U
                                                    : (IData)(vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_a0))
                                                   : (IData)(vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_a1))
                                               : (IData)(vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_a2))
                                           : (IData)(vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__d_a3));
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__dout_a 
        = vlTOPp->top__DOT__uut__DOT__pf_out;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__50(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__50\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__coloram_w_n = ((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                               | (IData)(vlTOPp->top__DOT__uut__DOT__coloram_n));
    vlTOPp->top__DOT__uut__DOT__ram__DOT__ram_read 
        = ((~ (IData)(vlTOPp->top__DOT__uut__DOT__ram0_n)) 
           & (IData)(vlTOPp->top__DOT__uut__DOT__write_n));
    vlTOPp->top__DOT__uut__DOT__ram__DOT__ram_write 
        = (1U & ((~ (IData)(vlTOPp->top__DOT__uut__DOT__ram0_n)) 
                 & (~ (IData)(vlTOPp->top__DOT__uut__DOT__write_n))));
    vlTOPp->top__DOT__uut__DOT__pfwr3_n = (1U & (((0U 
                                                   == 
                                                   (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                     << 3U) 
                                                    | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                        << 2U) 
                                                       | (3U 
                                                          & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                             >> 4U)))))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                      << 3U) 
                                                     | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                         << 2U) 
                                                        | (3U 
                                                           & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                              >> 4U)))))
                                                    ? 0xdU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                       << 3U) 
                                                      | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                          << 2U) 
                                                         | (3U 
                                                            & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                               >> 4U)))))
                                                     ? 0xbU
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                        << 3U) 
                                                       | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                           << 2U) 
                                                          | (3U 
                                                             & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                                >> 4U)))))
                                                      ? 7U
                                                      : 0xfU)))) 
                                                 >> 3U));
    vlTOPp->top__DOT__uut__DOT__pfwr2_n = (1U & (((0U 
                                                   == 
                                                   (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                     << 3U) 
                                                    | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                        << 2U) 
                                                       | (3U 
                                                          & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                             >> 4U)))))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                      << 3U) 
                                                     | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                         << 2U) 
                                                        | (3U 
                                                           & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                              >> 4U)))))
                                                    ? 0xdU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                       << 3U) 
                                                      | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                          << 2U) 
                                                         | (3U 
                                                            & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                               >> 4U)))))
                                                     ? 0xbU
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                        << 3U) 
                                                       | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                           << 2U) 
                                                          | (3U 
                                                             & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                                >> 4U)))))
                                                      ? 7U
                                                      : 0xfU)))) 
                                                 >> 2U));
    vlTOPp->top__DOT__uut__DOT__pfwr1_n = (1U & (((0U 
                                                   == 
                                                   (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                     << 3U) 
                                                    | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                        << 2U) 
                                                       | (3U 
                                                          & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                             >> 4U)))))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                      << 3U) 
                                                     | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                         << 2U) 
                                                        | (3U 
                                                           & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                              >> 4U)))))
                                                    ? 0xdU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                       << 3U) 
                                                      | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                          << 2U) 
                                                         | (3U 
                                                            & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                               >> 4U)))))
                                                     ? 0xbU
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                        << 3U) 
                                                       | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                           << 2U) 
                                                          | (3U 
                                                             & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                                >> 4U)))))
                                                      ? 7U
                                                      : 0xfU)))) 
                                                 >> 1U));
    vlTOPp->top__DOT__uut__DOT__pfwr0_n = ((0U == (
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__pf_n) 
                                                    << 3U) 
                                                   | (((IData)(vlTOPp->top__DOT__uut__DOT__write_n) 
                                                       << 2U) 
                                                      | (3U 
                                                         & ((IData)(vlTOPp->top__DOT__uut__DOT__ab) 
                                                            >> 4U)))))
                                            ? 0U : 1U);
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__we_n_a 
        = vlTOPp->top__DOT__uut__DOT__coloram_w_n;
    vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a 
        = (((IData)(vlTOPp->top__DOT__uut__DOT__pfwr3_n) 
            << 3U) | (((IData)(vlTOPp->top__DOT__uut__DOT__pfwr2_n) 
                       << 2U) | (((IData)(vlTOPp->top__DOT__uut__DOT__pfwr1_n) 
                                  << 1U) | (IData)(vlTOPp->top__DOT__uut__DOT__pfwr0_n))));
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__we_a = vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a;
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__ram_read_a 
        = ((0xfU != (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__ce_a)) 
           & (0xfU == (IData)(vlTOPp->top__DOT__uut__DOT____Vcellinp__pf_ram__we_a)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__51(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__51\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__hs_clk = (1U & (IData)(vlTOPp->top__DOT__uut__DOT__db_out));
    vlTOPp->top__DOT__uut__DOT__hs_c2 = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                                               >> 2U));
    vlTOPp->top__DOT__uut__DOT__hs_cs1 = (1U & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                                                >> 3U));
    vlTOPp->top__DOT__uut__DOT__hs_c1 = (1U & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                                                  >> 1U)));
    vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__c2 = vlTOPp->top__DOT__uut__DOT__hs_c2;
    vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__cs1 = vlTOPp->top__DOT__uut__DOT__hs_cs1;
    vlTOPp->top__DOT__uut__DOT__hs_ram__DOT__c1 = vlTOPp->top__DOT__uut__DOT__hs_c1;
}

VL_INLINE_OPT void Vtop::_combo__TOP__52(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__52\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__db_in = ((IData)(vlTOPp->top__DOT__uut__DOT__rom_n)
                                          ? ((IData)(vlTOPp->top__DOT__uut__DOT__ram0_n)
                                              ? ((IData)(vlTOPp->top__DOT__uut__DOT__pframrd_n)
                                                  ? 
                                                 ((IData)(vlTOPp->top__DOT__uut__DOT__ea_read_n)
                                                   ? 
                                                  ((IData)(vlTOPp->top__DOT__uut__DOT__in0_n)
                                                    ? 
                                                   ((IData)(vlTOPp->top__DOT__uut__DOT__in1_n)
                                                     ? 
                                                    ((IData)(vlTOPp->top__DOT__uut__DOT__swrd_n)
                                                      ? 
                                                     ((IData)(vlTOPp->top__DOT__uut__DOT__pokey_n)
                                                       ? 0U
                                                       : (IData)(vlTOPp->top__DOT__uut__DOT__pokey_out))
                                                      : (IData)(vlTOPp->top__DOT__uut__DOT__switch_out))
                                                     : (IData)(vlTOPp->top__DOT__uut__DOT__joystick_out))
                                                    : (IData)(vlTOPp->top__DOT__uut__DOT__playerin_out))
                                                   : (IData)(vlTOPp->top__DOT__uut__DOT__hs_out))
                                                  : (IData)(vlTOPp->top__DOT__uut__DOT__pf_out))
                                              : (IData)(vlTOPp->top__DOT__uut__DOT__ram_out))
                                          : (IData)(vlTOPp->top__DOT__uut__DOT__rom_out));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__din = vlTOPp->top__DOT__uut__DOT__db_in;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__res 
        = (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
              & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__inx) 
                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iny))) 
             | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dex) 
                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dey)))
             ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_addo)
             : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                 & (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tay) 
                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tax)) 
                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txa)) 
                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tya)) 
                    | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txs)))
                 ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_reg)
                 : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                     & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tsx))
                     ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg)
                     : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                         & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ror_a))
                         ? (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf) 
                             << 7U) | (0x7fU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                                                >> 1U)))
                         : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                             & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__lsr_a))
                             ? (0x7fU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                                         >> 1U)) : 
                            (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                              & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rol_a))
                              ? ((0xfeU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                                           << 1U)) 
                                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__cf))
                              : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                  & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__asl_a))
                                  ? (0xfeU & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__a_reg) 
                                              << 1U))
                                  : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul)
                                      ? (IData)(vlTOPp->top__DOT__uut__DOT__db_in)
                                      : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1)
                                          ? (IData)(vlTOPp->top__DOT__uut__DOT__db_in)
                                          : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                                              & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0) 
                                                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2)))
                                              ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dil)
                                              : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                                                  & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1))
                                                  ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1_o)
                                                  : 0U))))))))))) 
           & ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__inx) 
                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iny))) 
               | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dex) 
                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dey)))
               ? 0xffU : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                           & (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tay) 
                                 | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tax)) 
                                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txa)) 
                               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tya)) 
                              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__txs)))
                           ? 0xffU : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                       & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tsx))
                                       ? 0xffU : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                                   & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ror_a))
                                                   ? 0xffU
                                                   : 
                                                  (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                                    & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__lsr_a))
                                                    ? 0xffU
                                                    : 
                                                   (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                                     & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rol_a))
                                                     ? 0xffU
                                                     : 
                                                    (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                                      & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__asl_a))
                                                      ? 0xffU
                                                      : 
                                                     ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul)
                                                       ? 0xffU
                                                       : 
                                                      ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1)
                                                        ? 0xffU
                                                        : 
                                                       (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                                                         & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0) 
                                                            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2)))
                                                         ? 0xffU
                                                         : 
                                                        (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                                                          & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1))
                                                          ? 0xffU
                                                          : 0U))))))))))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__di 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__din;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__53(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__53\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) {
        vlTOPp->top__DOT__uut__DOT__db_out = 0U;
    } else if ((1U & (~ (IData)(vlTOPp->top__DOT__pause)))) {
        vlTOPp->top__DOT__uut__DOT__db_out = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dout_nxt;
    }
    vlTOPp->top__DOT__uut__DOT__ram__DOT__din = vlTOPp->top__DOT__uut__DOT__db_out;
    vlTOPp->top__DOT__uut__DOT__pf_ram__DOT__din_a 
        = vlTOPp->top__DOT__uut__DOT__db_out;
    vlTOPp->top__DOT__uut__DOT__color_ram__DOT__din_a 
        = (0xfU & ((IData)(vlTOPp->top__DOT__uut__DOT__db_out) 
                   >> 0U));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__dout = vlTOPp->top__DOT__uut__DOT__db_out;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__d_in = vlTOPp->top__DOT__uut__DOT__db_out;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dout 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__dout;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__d_in;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr0__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr1__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr2__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_ctr3__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout0__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout1__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout2__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i;
    vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__u_audout3__DOT__dat_i 
        = vlTOPp->top__DOT__uut__DOT__pokey__DOT__pokey__DOT__dat_i;
}

VL_INLINE_OPT void Vtop::_combo__TOP__54(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__54\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__pause = (1U & ((IData)(vlTOPp->inputs) 
                                     >> 0xbU));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset = 
        (1U & (~ (IData)(vlTOPp->top__DOT__uut__DOT__mpu_reset_n)));
    vlTOPp->top__DOT__uut__DOT__pause = vlTOPp->top__DOT__pause;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__rdy = (1U 
                                                   & (~ (IData)(vlTOPp->top__DOT__pause)));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__reset 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma_nxt 
        = (0xffffU & (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__reset) 
                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset)) 
                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset1)) 
                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi3))
                       ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__vec)
                       : ((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset2) 
                              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi4)) 
                             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jmpi1)) 
                            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix1)) 
                           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy1))
                           ? ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma))
                           : (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                                 & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int))) 
                                | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                   & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absxy) 
                                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jsr)) 
                                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__branch)))) 
                               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts3))
                               ? ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg))
                               : (((((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset3) 
                                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi5)) 
                                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti3)) 
                                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts2)) 
                                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ld_pch)) 
                                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2)) 
                                    | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2)) 
                                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1))
                                   ? (0xffffU & ((((IData)(vlTOPp->top__DOT__uut__DOT__db_in) 
                                                   << 8U) 
                                                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tmp)) 
                                                 + (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__xyz_reg)))
                                   : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                       & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpxy) 
                                           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ix)) 
                                          | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iy)))
                                       ? (0xffU & ((IData)(vlTOPp->top__DOT__uut__DOT__db_in) 
                                                   + (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__xyz_reg)))
                                       : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch) 
                                           & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__taken))
                                           ? (0xffffU 
                                              & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg) 
                                                 + 
                                                 ((0xff00U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tmp) 
                                                                     >> 7U)))) 
                                                      << 8U)) 
                                                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tmp))))
                                           : ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch) 
                                                | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update)) 
                                               & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2m))
                                               ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma)
                                               : ((
                                                   (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch) 
                                                       & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__taken))) 
                                                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_pul)) 
                                                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_afterWrite)) 
                                                    | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                                       & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__imm) 
                                                          | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__mop)))) 
                                                   | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_dataFetch) 
                                                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update)) 
                                                      & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp0) 
                                                          | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp1)) 
                                                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2x))))
                                                   ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg)
                                                   : 
                                                  ((((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                                         & ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__brk) 
                                                            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__psh))) 
                                                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1)) 
                                                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2)) 
                                                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1)) 
                                                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2)) 
                                                    | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                                                       & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int)))
                                                    ? 
                                                   (0x100U 
                                                    | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_reg))
                                                    : 
                                                   ((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                                        & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pul) 
                                                            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rts)) 
                                                           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rti))) 
                                                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts1)) 
                                                      | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti1)) 
                                                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti2))
                                                     ? 
                                                    (0x100U 
                                                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sp_addo))
                                                     : 0U)))))))))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rdy 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__rdy;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__reset 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__reset;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ma_nxt 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma_nxt;
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_nxt 
        = (0xffffU & ((((((((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts2) 
                              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rts3)) 
                             | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_rti3)) 
                            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi5)) 
                           | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_reset3) 
                               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ld_pch)) 
                              | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
                                 & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmp)))) 
                          | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                             & (~ (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int)))) 
                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_branch)) 
                        | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                           & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__branch))) 
                       | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                          & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jsr)))
                       ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__ma_nxt)
                       : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1)
                           ? (((IData)(vlTOPp->top__DOT__uut__DOT__db_in) 
                               << 8U) | (0xffU & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg)))
                           : ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2)
                               ? ((0xff00U & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg)) 
                                  | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__tmp))
                               : ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                    & (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__imm) 
                                          | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpxy)) 
                                         | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__ix)) 
                                        | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__iy)) 
                                       | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__absxy))) 
                                   | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1) 
                                      & (~ ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmp) 
                                            | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__jmpi)))))
                                   ? ((IData)(1U) + (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg))
                                   : (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg))))));
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__seq0__DOT__rdy 
        = vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__rdy;
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__55(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__55\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__dout_nxt 
        = (0xffU & (((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_sync) 
                       & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__any_int)) 
                      | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                         & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__brk))) 
                     | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr1))
                     ? ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg) 
                        >> 8U) : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi1) 
                                   | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_jsr2))
                                   ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pc_reg)
                                   : ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__staxy) 
                                        & (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                            & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__zpxy)) 
                                           | (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_ix2) 
                                               | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_iy2)) 
                                              | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_abs1)))) 
                                       | ((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                          & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__pha)))
                                       ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__axy_reg)
                                       : ((((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_exec) 
                                            & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__php)) 
                                           | (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_nmi2))
                                           ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__sr_reg)
                                           : (((IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__s_update) 
                                               & (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2m))
                                               ? (IData)(vlTOPp->top__DOT__uut__DOT__p6502__DOT__bc6502__DOT__grp2_o)
                                               : (IData)(vlTOPp->top__DOT__uut__DOT__db_out)))))));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__3(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hs_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__hs_clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_48) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_48)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hsync_reset) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__hsync_reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_8h) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_8h))))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz)) 
         & (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz))))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__s_1h) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_1h)))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_1h)) 
         & (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_1h))) {
        vlTOPp->_sequent__TOP__11(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_12mhz) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_12mhz))))) {
        vlTOPp->_sequent__TOP__12(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__s_12mhz) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_12mhz)))) {
        vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz_n) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz_n)))) {
        vlTOPp->_sequent__TOP__14(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__mpu_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__mpu_clk)))) {
        vlTOPp->_sequent__TOP__15(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__s_6_12) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6_12)))) {
        vlTOPp->_sequent__TOP__16(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__blank_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__blank_clk))))) {
        vlTOPp->_sequent__TOP__17(vlSymsp);
    }
    vlTOPp->_combo__TOP__18(vlSymsp);
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__tb_v_ck) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__tb_v_ck))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__tb_v_ctr_clr) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__tb_v_ctr_clr))))) {
        vlTOPp->_sequent__TOP__20(vlSymsp);
    }
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__tb_h_ck) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__tb_h_ck))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__tb_h_ctr_clr) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__tb_h_ctr_clr))))) {
        vlTOPp->_sequent__TOP__22(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0)))) {
        vlTOPp->_sequent__TOP__23(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__phi2) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi2)))) {
        vlTOPp->_sequent__TOP__24(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__mpu_reset) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__mpu_reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__phi2) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi2))))) {
        vlTOPp->_sequent__TOP__25(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz)))) {
        vlTOPp->_sequent__TOP__26(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__s_12mhz) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_12mhz)))) {
        vlTOPp->_sequent__TOP__27(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz)) 
         & (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz))) {
        vlTOPp->_sequent__TOP__28(vlSymsp);
    }
    if ((((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
           | ((IData)(vlTOPp->top__DOT__uut__DOT__blank_clk) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__blank_clk)))) 
          | ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz)) 
             & (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz_n) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz_n))))) {
        vlTOPp->_multiclk__TOP__29(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hs_set) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__hs_set))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_32h) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_32h))))) {
        vlTOPp->_sequent__TOP__30(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_256h_n))))) {
        vlTOPp->_sequent__TOP__31(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__tb_v_ck) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__tb_v_ck))))) {
        vlTOPp->_sequent__TOP__32(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__tb_h_ck) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__tb_h_ck))))) {
        vlTOPp->_sequent__TOP__33(vlSymsp);
    }
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0))) 
         | ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_1h)) 
            & (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_1h)))) {
        vlTOPp->_multiclk__TOP__34(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0)))) {
        vlTOPp->_sequent__TOP__35(vlSymsp);
    }
    vlTOPp->_combo__TOP__36(vlSymsp);
    if (((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz)))) {
        vlTOPp->_sequent__TOP__37(vlSymsp);
    }
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__s_6_12) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6_12))) 
         | ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz)) 
            & (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz)))) {
        vlTOPp->_multiclk__TOP__38(vlSymsp);
    }
    if ((((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
           | ((IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hsync_reset) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__hsync_reset)))) 
          | ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_256h_n)))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_8h) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_8h))))) {
        vlTOPp->_multiclk__TOP__39(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__irqres_n)) 
          & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__irqres_n)) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_16v) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_16v))))) {
        vlTOPp->_sequent__TOP__40(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz))))) {
        vlTOPp->_sequent__TOP__41(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__ea_addr_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__ea_addr_clk)))) {
        vlTOPp->_sequent__TOP__42(vlSymsp);
    }
    if ((((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
           | ((IData)(vlTOPp->top__DOT__uut__DOT__blank_clk) 
              & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__blank_clk)))) 
          | ((IData)(vlTOPp->top__DOT__uut__DOT__s_6_12) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6_12)))) 
         | ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz)) 
            & (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz)))) {
        vlTOPp->_multiclk__TOP__43(vlSymsp);
    }
    if ((((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_256h_n) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_256h_n))))) {
        vlTOPp->_sequent__TOP__44(vlSymsp);
    }
    if (((((~ (IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__irqres_n)) 
           & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__irqres_n)) 
          | ((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0)))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_16v) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_16v))))) {
        vlTOPp->_multiclk__TOP__45(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0)))) {
        vlTOPp->_sequent__TOP__46(vlSymsp);
    }
    vlTOPp->_combo__TOP__47(vlSymsp);
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__phi2) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi2))))) {
        vlTOPp->_multiclk__TOP__48(vlSymsp);
    }
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_6mhz) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz))))) {
        vlTOPp->_multiclk__TOP__49(vlSymsp);
    }
    if ((((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0))) 
         | ((~ (IData)(vlTOPp->top__DOT__uut__DOT__s_1h)) 
            & (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_1h)))) {
        vlTOPp->_multiclk__TOP__50(vlSymsp);
    }
    if (((IData)(vlTOPp->top__DOT__uut__DOT__ea_ctrl_clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__ea_ctrl_clk)))) {
        vlTOPp->_sequent__TOP__51(vlSymsp);
    }
    vlTOPp->_combo__TOP__52(vlSymsp);
    if (((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0)))) {
        vlTOPp->_sequent__TOP__53(vlSymsp);
    }
    vlTOPp->_combo__TOP__54(vlSymsp);
    if (((((~ (IData)(vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__irqres_n)) 
           & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__irqres_n)) 
          | ((IData)(vlTOPp->top__DOT__uut__DOT__phi0) 
             & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0)))) 
         | ((IData)(vlTOPp->top__DOT__uut__DOT__s_16v) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_16v))))) {
        vlTOPp->_multiclk__TOP__55(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__hs_clk 
        = vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hs_clk;
    vlTOPp->__Vclklast__TOP__clk_48 = vlTOPp->clk_48;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__hsync_reset 
        = vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hsync_reset;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_8h 
        = vlTOPp->top__DOT__uut__DOT__s_8h;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz 
        = vlTOPp->top__DOT__uut__DOT__s_6mhz;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_1h 
        = vlTOPp->top__DOT__uut__DOT__s_1h;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_12mhz 
        = vlTOPp->top__DOT__uut__DOT__s_12mhz;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6mhz_n 
        = vlTOPp->top__DOT__uut__DOT__s_6mhz_n;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__mpu_clk 
        = vlTOPp->top__DOT__uut__DOT__mpu_clk;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_6_12 
        = vlTOPp->top__DOT__uut__DOT__s_6_12;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__blank_clk 
        = vlTOPp->top__DOT__uut__DOT__blank_clk;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__tb_v_ck 
        = vlTOPp->top__DOT__uut__DOT__tb_v_ck;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__tb_v_ctr_clr 
        = vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__tb_v_ctr_clr;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__tb_h_ck 
        = vlTOPp->top__DOT__uut__DOT__tb_h_ck;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__tb_h_ctr_clr 
        = vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__tb_h_ctr_clr;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi0 
        = vlTOPp->top__DOT__uut__DOT__phi0;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__phi2 
        = vlTOPp->top__DOT__uut__DOT__phi2;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__mpu_reset 
        = vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__mpu_reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__hs_set 
        = vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hs_set;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_32h 
        = vlTOPp->top__DOT__uut__DOT__s_32h;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_256h_n 
        = vlTOPp->top__DOT__uut__DOT__s_256h_n;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__uut__DOT__irqres_n 
        = vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__irqres_n;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__s_16v 
        = vlTOPp->top__DOT__uut__DOT__s_16v;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__ea_addr_clk 
        = vlTOPp->top__DOT__uut__DOT__ea_addr_clk;
    vlTOPp->__Vclklast__TOP__top__DOT__uut__DOT__ea_ctrl_clk 
        = vlTOPp->top__DOT__uut__DOT__ea_ctrl_clk;
    vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hs_clk 
        = vlTOPp->top__DOT__uut__DOT__hs_clk;
    vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hsync_reset 
        = vlTOPp->top__DOT__uut__DOT__hsync_reset;
    vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__tb_v_ctr_clr 
        = vlTOPp->top__DOT__uut__DOT__tb_v_ctr_clr;
    vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__tb_h_ctr_clr 
        = vlTOPp->top__DOT__uut__DOT__tb_h_ctr_clr;
    vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__mpu_reset 
        = vlTOPp->top__DOT__uut__DOT__mpu_reset;
    vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__hs_set 
        = vlTOPp->top__DOT__uut__DOT__hs_set;
    vlTOPp->__VinpClk__TOP__top__DOT__uut__DOT__irqres_n 
        = vlTOPp->top__DOT__uut__DOT__irqres_n;
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
    __req |= ((vlTOPp->top__DOT__uut__DOT__irqres_n ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__irqres_n)
         | (vlTOPp->top__DOT__uut__DOT__ea_addr_n ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__ea_addr_n)
         | (vlTOPp->top__DOT__uut__DOT__mpu_reset ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__mpu_reset)
         | (vlTOPp->top__DOT__uut__DOT__hsync_reset ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hsync_reset)
         | (vlTOPp->top__DOT__uut__DOT__hs_clk ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hs_clk)
         | (vlTOPp->top__DOT__uut__DOT__hs_set ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hs_set)
         | (vlTOPp->top__DOT__uut__DOT__h_counter ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__h_counter)
         | (vlTOPp->top__DOT__uut__DOT__tb_h_ctr_clr ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__tb_h_ctr_clr)
         | (vlTOPp->top__DOT__uut__DOT__tb_v_ctr_clr ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__tb_v_ctr_clr));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__irqres_n ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__irqres_n))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:62: top.uut.irqres_n\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__ea_addr_n ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__ea_addr_n))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:64: top.uut.ea_addr_n\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__mpu_reset ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__mpu_reset))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:76: top.uut.mpu_reset\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__hsync_reset ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hsync_reset))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:97: top.uut.hsync_reset\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__hs_clk ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hs_clk))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:170: top.uut.hs_clk\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__hs_set ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hs_set))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:176: top.uut.hs_set\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__h_counter ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__h_counter))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:222: top.uut.h_counter\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__tb_h_ctr_clr ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__tb_h_ctr_clr))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:922: top.uut.tb_h_ctr_clr\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__uut__DOT__tb_v_ctr_clr ^ vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__tb_v_ctr_clr))) VL_DBG_MSGF("        CHANGE: ../rtl/centipede.v:922: top.uut.tb_v_ctr_clr\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__irqres_n 
        = vlTOPp->top__DOT__uut__DOT__irqres_n;
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__ea_addr_n 
        = vlTOPp->top__DOT__uut__DOT__ea_addr_n;
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__mpu_reset 
        = vlTOPp->top__DOT__uut__DOT__mpu_reset;
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hsync_reset 
        = vlTOPp->top__DOT__uut__DOT__hsync_reset;
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hs_clk 
        = vlTOPp->top__DOT__uut__DOT__hs_clk;
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__hs_set 
        = vlTOPp->top__DOT__uut__DOT__hs_set;
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__h_counter 
        = vlTOPp->top__DOT__uut__DOT__h_counter;
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__tb_h_ctr_clr 
        = vlTOPp->top__DOT__uut__DOT__tb_h_ctr_clr;
    vlTOPp->__Vchglast__TOP__top__DOT__uut__DOT__tb_v_ctr_clr 
        = vlTOPp->top__DOT__uut__DOT__tb_v_ctr_clr;
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
