// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk_48));
        tracep->chgBit(oldp+1,(vlTOPp->clk_12));
        tracep->chgBit(oldp+2,(vlTOPp->reset));
        tracep->chgSData(oldp+3,(vlTOPp->inputs),12);
        tracep->chgCData(oldp+4,(vlTOPp->VGA_R),8);
        tracep->chgCData(oldp+5,(vlTOPp->VGA_G),8);
        tracep->chgCData(oldp+6,(vlTOPp->VGA_B),8);
        tracep->chgBit(oldp+7,(vlTOPp->VGA_HS));
        tracep->chgBit(oldp+8,(vlTOPp->VGA_VS));
        tracep->chgBit(oldp+9,(vlTOPp->VGA_HB));
        tracep->chgBit(oldp+10,(vlTOPp->VGA_VB));
        tracep->chgSData(oldp+11,(vlTOPp->AUDIO_L),16);
        tracep->chgSData(oldp+12,(vlTOPp->AUDIO_R),16);
        tracep->chgBit(oldp+13,(vlTOPp->ioctl_download));
        tracep->chgBit(oldp+14,(vlTOPp->ioctl_upload));
        tracep->chgBit(oldp+15,(vlTOPp->ioctl_wr));
        tracep->chgIData(oldp+16,(vlTOPp->ioctl_addr),25);
        tracep->chgCData(oldp+17,(vlTOPp->ioctl_dout),8);
        tracep->chgCData(oldp+18,(vlTOPp->ioctl_din),8);
        tracep->chgCData(oldp+19,(vlTOPp->ioctl_index),8);
        tracep->chgBit(oldp+20,(vlTOPp->ioctl_wait));
        tracep->chgBit(oldp+21,(vlTOPp->top__DOT__clk_48));
        tracep->chgBit(oldp+22,(vlTOPp->top__DOT__clk_12));
        tracep->chgBit(oldp+23,(vlTOPp->top__DOT__reset));
        tracep->chgSData(oldp+24,(vlTOPp->top__DOT__inputs),12);
        tracep->chgCData(oldp+25,(vlTOPp->top__DOT__VGA_R),8);
        tracep->chgCData(oldp+26,(vlTOPp->top__DOT__VGA_G),8);
        tracep->chgCData(oldp+27,(vlTOPp->top__DOT__VGA_B),8);
        tracep->chgBit(oldp+28,(vlTOPp->top__DOT__VGA_HS));
        tracep->chgBit(oldp+29,(vlTOPp->top__DOT__VGA_VS));
        tracep->chgBit(oldp+30,(vlTOPp->top__DOT__VGA_HB));
        tracep->chgBit(oldp+31,(vlTOPp->top__DOT__VGA_VB));
        tracep->chgSData(oldp+32,(vlTOPp->top__DOT__AUDIO_L),16);
        tracep->chgSData(oldp+33,(vlTOPp->top__DOT__AUDIO_R),16);
        tracep->chgBit(oldp+34,(vlTOPp->top__DOT__ioctl_download));
        tracep->chgBit(oldp+35,(vlTOPp->top__DOT__ioctl_upload));
        tracep->chgBit(oldp+36,(vlTOPp->top__DOT__ioctl_wr));
        tracep->chgIData(oldp+37,(vlTOPp->top__DOT__ioctl_addr),25);
        tracep->chgCData(oldp+38,(vlTOPp->top__DOT__ioctl_dout),8);
        tracep->chgCData(oldp+39,(vlTOPp->top__DOT__ioctl_din),8);
        tracep->chgCData(oldp+40,(vlTOPp->top__DOT__ioctl_index),8);
        tracep->chgBit(oldp+41,(vlTOPp->top__DOT__ioctl_wait));
        tracep->chgBit(oldp+42,(vlTOPp->top__DOT__pause));
        tracep->chgCData(oldp+43,(vlTOPp->top__DOT__audio),8);
        tracep->chgSData(oldp+44,(vlTOPp->top__DOT__rgb),9);
        tracep->chgCData(oldp+45,(vlTOPp->top__DOT__led),4);
        tracep->chgCData(oldp+46,(vlTOPp->top__DOT__trakball),8);
        tracep->chgCData(oldp+47,(vlTOPp->top__DOT__joystick),8);
        tracep->chgSData(oldp+48,(vlTOPp->top__DOT__playerinput),10);
        tracep->chgCData(oldp+49,(vlTOPp->top__DOT__sw1),8);
        tracep->chgCData(oldp+50,(vlTOPp->top__DOT__sw2),8);
        tracep->chgBit(oldp+51,(vlTOPp->top__DOT__ce_pix));
        tracep->chgBit(oldp+52,(vlTOPp->top__DOT__ioctl_data));
        tracep->chgBit(oldp+53,(vlTOPp->top__DOT__unnamedblk1__DOT__old_clk));
        tracep->chgBit(oldp+54,(vlTOPp->top__DOT__sharpx1__DOT__clk_sys));
        tracep->chgBit(oldp+55,(vlTOPp->top__DOT__sharpx1__DOT__clk_28636));
        tracep->chgBit(oldp+56,(vlTOPp->top__DOT__sharpx1__DOT__reset));
        tracep->chgBit(oldp+57,(vlTOPp->top__DOT__sharpx1__DOT__pal));
        tracep->chgBit(oldp+58,(vlTOPp->top__DOT__sharpx1__DOT__scandouble));
        tracep->chgBit(oldp+59,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_download));
        tracep->chgCData(oldp+60,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_index),8);
        tracep->chgBit(oldp+61,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_wr));
        tracep->chgIData(oldp+62,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_addr),25);
        tracep->chgCData(oldp+63,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_dout),8);
        tracep->chgBit(oldp+64,(vlTOPp->top__DOT__sharpx1__DOT__ce_pix));
        tracep->chgBit(oldp+65,(vlTOPp->top__DOT__sharpx1__DOT__HBlank));
        tracep->chgBit(oldp+66,(vlTOPp->top__DOT__sharpx1__DOT__HSync));
        tracep->chgBit(oldp+67,(vlTOPp->top__DOT__sharpx1__DOT__VBlank));
        tracep->chgBit(oldp+68,(vlTOPp->top__DOT__sharpx1__DOT__VSync));
        tracep->chgCData(oldp+69,(vlTOPp->top__DOT__sharpx1__DOT__video),8);
        tracep->chgBit(oldp+70,(vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__clock));
        tracep->chgBit(oldp+71,(vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__ce));
        tracep->chgCData(oldp+72,(vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__data_out),8);
        tracep->chgSData(oldp+73,(vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__a),13);
        tracep->chgBit(oldp+74,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__clock));
        tracep->chgBit(oldp+75,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__ram_cs));
        tracep->chgBit(oldp+76,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_a));
        tracep->chgSData(oldp+77,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_a),16);
        tracep->chgCData(oldp+78,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_a),8);
        tracep->chgCData(oldp+79,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_a),8);
        tracep->chgBit(oldp+80,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__ram_cs_b));
        tracep->chgBit(oldp+81,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_b));
        tracep->chgSData(oldp+82,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_b),16);
        tracep->chgCData(oldp+83,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_b),8);
        tracep->chgCData(oldp+84,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_b),8);
        tracep->chgBit(oldp+85,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__clock));
        tracep->chgBit(oldp+86,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__ram_cs));
        tracep->chgBit(oldp+87,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__wren_a));
        tracep->chgSData(oldp+88,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_a),12);
        tracep->chgCData(oldp+89,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__data_a),8);
        tracep->chgCData(oldp+90,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_a),8);
        tracep->chgBit(oldp+91,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__ram_cs_b));
        tracep->chgBit(oldp+92,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__wren_b));
        tracep->chgSData(oldp+93,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_b),12);
        tracep->chgCData(oldp+94,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__data_b),8);
        tracep->chgCData(oldp+95,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_b),8);
        tracep->chgBit(oldp+96,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__clock));
        tracep->chgBit(oldp+97,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__ram_cs));
        tracep->chgBit(oldp+98,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__wren_a));
        tracep->chgSData(oldp+99,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__address_a),13);
        tracep->chgCData(oldp+100,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__data_a),8);
        tracep->chgCData(oldp+101,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__q_a),8);
        tracep->chgBit(oldp+102,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__ram_cs_b));
        tracep->chgBit(oldp+103,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__wren_b));
        tracep->chgSData(oldp+104,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__address_b),13);
        tracep->chgCData(oldp+105,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__data_b),8);
        tracep->chgCData(oldp+106,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__q_b),8);
        tracep->chgBit(oldp+107,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__clock));
        tracep->chgBit(oldp+108,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__ram_cs));
        tracep->chgBit(oldp+109,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_a));
        tracep->chgSData(oldp+110,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_a),16);
        tracep->chgCData(oldp+111,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_a),8);
        tracep->chgCData(oldp+112,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_a),8);
        tracep->chgBit(oldp+113,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__ram_cs_b));
        tracep->chgBit(oldp+114,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_b));
        tracep->chgSData(oldp+115,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_b),16);
        tracep->chgCData(oldp+116,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_b),8);
        tracep->chgCData(oldp+117,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_b),8);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
