// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk_48", false,-1);
        tracep->declBit(c+2,"clk_12", false,-1);
        tracep->declBit(c+3,"reset", false,-1);
        tracep->declBus(c+4,"inputs", false,-1, 11,0);
        tracep->declBus(c+5,"VGA_R", false,-1, 7,0);
        tracep->declBus(c+6,"VGA_G", false,-1, 7,0);
        tracep->declBus(c+7,"VGA_B", false,-1, 7,0);
        tracep->declBit(c+8,"VGA_HS", false,-1);
        tracep->declBit(c+9,"VGA_VS", false,-1);
        tracep->declBit(c+10,"VGA_HB", false,-1);
        tracep->declBit(c+11,"VGA_VB", false,-1);
        tracep->declBus(c+12,"AUDIO_L", false,-1, 15,0);
        tracep->declBus(c+13,"AUDIO_R", false,-1, 15,0);
        tracep->declBit(c+14,"ioctl_download", false,-1);
        tracep->declBit(c+15,"ioctl_upload", false,-1);
        tracep->declBit(c+16,"ioctl_wr", false,-1);
        tracep->declBus(c+17,"ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+18,"ioctl_dout", false,-1, 7,0);
        tracep->declBus(c+19,"ioctl_din", false,-1, 7,0);
        tracep->declBus(c+20,"ioctl_index", false,-1, 7,0);
        tracep->declBit(c+21,"ioctl_wait", false,-1);
        tracep->declBit(c+22,"top clk_48", false,-1);
        tracep->declBit(c+23,"top clk_12", false,-1);
        tracep->declBit(c+24,"top reset", false,-1);
        tracep->declBus(c+25,"top inputs", false,-1, 11,0);
        tracep->declBus(c+26,"top VGA_R", false,-1, 7,0);
        tracep->declBus(c+27,"top VGA_G", false,-1, 7,0);
        tracep->declBus(c+28,"top VGA_B", false,-1, 7,0);
        tracep->declBit(c+29,"top VGA_HS", false,-1);
        tracep->declBit(c+30,"top VGA_VS", false,-1);
        tracep->declBit(c+31,"top VGA_HB", false,-1);
        tracep->declBit(c+32,"top VGA_VB", false,-1);
        tracep->declBus(c+33,"top AUDIO_L", false,-1, 15,0);
        tracep->declBus(c+34,"top AUDIO_R", false,-1, 15,0);
        tracep->declBit(c+35,"top ioctl_download", false,-1);
        tracep->declBit(c+36,"top ioctl_upload", false,-1);
        tracep->declBit(c+37,"top ioctl_wr", false,-1);
        tracep->declBus(c+38,"top ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+39,"top ioctl_dout", false,-1, 7,0);
        tracep->declBus(c+40,"top ioctl_din", false,-1, 7,0);
        tracep->declBus(c+41,"top ioctl_index", false,-1, 7,0);
        tracep->declBit(c+42,"top ioctl_wait", false,-1);
        tracep->declBit(c+43,"top pause", false,-1);
        tracep->declBus(c+44,"top audio", false,-1, 7,0);
        tracep->declBus(c+45,"top rgb", false,-1, 8,0);
        tracep->declBus(c+46,"top led", false,-1, 3,0);
        tracep->declBus(c+47,"top trakball", false,-1, 7,0);
        tracep->declBus(c+48,"top joystick", false,-1, 7,0);
        tracep->declBus(c+49,"top playerinput", false,-1, 9,0);
        tracep->declBus(c+50,"top sw1", false,-1, 7,0);
        tracep->declBus(c+51,"top sw2", false,-1, 7,0);
        tracep->declBit(c+52,"top ce_pix", false,-1);
        tracep->declBit(c+53,"top ioctl_data", false,-1);
        tracep->declBit(c+54,"top unnamedblk1 old_clk", false,-1);
        tracep->declBit(c+55,"top sharpx1 clk_sys", false,-1);
        tracep->declBit(c+56,"top sharpx1 clk_28636", false,-1);
        tracep->declBit(c+57,"top sharpx1 reset", false,-1);
        tracep->declBit(c+58,"top sharpx1 pal", false,-1);
        tracep->declBit(c+59,"top sharpx1 scandouble", false,-1);
        tracep->declBit(c+60,"top sharpx1 ioctl_download", false,-1);
        tracep->declBus(c+61,"top sharpx1 ioctl_index", false,-1, 7,0);
        tracep->declBit(c+62,"top sharpx1 ioctl_wr", false,-1);
        tracep->declBus(c+63,"top sharpx1 ioctl_addr", false,-1, 24,0);
        tracep->declBus(c+64,"top sharpx1 ioctl_dout", false,-1, 7,0);
        tracep->declBit(c+65,"top sharpx1 ce_pix", false,-1);
        tracep->declBit(c+66,"top sharpx1 HBlank", false,-1);
        tracep->declBit(c+67,"top sharpx1 HSync", false,-1);
        tracep->declBit(c+68,"top sharpx1 VBlank", false,-1);
        tracep->declBit(c+69,"top sharpx1 VSync", false,-1);
        tracep->declBus(c+70,"top sharpx1 video", false,-1, 7,0);
        tracep->declBus(c+119,"top sharpx1 bios_fw_spi DW", false,-1, 31,0);
        tracep->declBus(c+120,"top sharpx1 bios_fw_spi AW", false,-1, 31,0);
        tracep->declArray(c+121,"top sharpx1 bios_fw_spi FN", false,-1, 223,0);
        tracep->declBit(c+71,"top sharpx1 bios_fw_spi clock", false,-1);
        tracep->declBit(c+72,"top sharpx1 bios_fw_spi ce", false,-1);
        tracep->declBus(c+73,"top sharpx1 bios_fw_spi data_out", false,-1, 7,0);
        tracep->declBus(c+74,"top sharpx1 bios_fw_spi a", false,-1, 12,0);
        tracep->declBus(c+119,"top sharpx1 RAM data_width_g", false,-1, 31,0);
        tracep->declBus(c+128,"top sharpx1 RAM addr_width_g", false,-1, 31,0);
        tracep->declBit(c+75,"top sharpx1 RAM clock", false,-1);
        tracep->declBit(c+76,"top sharpx1 RAM ram_cs", false,-1);
        tracep->declBit(c+77,"top sharpx1 RAM wren_a", false,-1);
        tracep->declBus(c+78,"top sharpx1 RAM address_a", false,-1, 15,0);
        tracep->declBus(c+79,"top sharpx1 RAM data_a", false,-1, 7,0);
        tracep->declBus(c+80,"top sharpx1 RAM q_a", false,-1, 7,0);
        tracep->declBit(c+81,"top sharpx1 RAM ram_cs_b", false,-1);
        tracep->declBit(c+82,"top sharpx1 RAM wren_b", false,-1);
        tracep->declBus(c+83,"top sharpx1 RAM address_b", false,-1, 15,0);
        tracep->declBus(c+84,"top sharpx1 RAM data_b", false,-1, 7,0);
        tracep->declBus(c+85,"top sharpx1 RAM q_b", false,-1, 7,0);
        tracep->declBus(c+119,"top sharpx1 VRAM data_width_g", false,-1, 31,0);
        tracep->declBus(c+129,"top sharpx1 VRAM addr_width_g", false,-1, 31,0);
        tracep->declBit(c+86,"top sharpx1 VRAM clock", false,-1);
        tracep->declBit(c+87,"top sharpx1 VRAM ram_cs", false,-1);
        tracep->declBit(c+88,"top sharpx1 VRAM wren_a", false,-1);
        tracep->declBus(c+89,"top sharpx1 VRAM address_a", false,-1, 11,0);
        tracep->declBus(c+90,"top sharpx1 VRAM data_a", false,-1, 7,0);
        tracep->declBus(c+91,"top sharpx1 VRAM q_a", false,-1, 7,0);
        tracep->declBit(c+92,"top sharpx1 VRAM ram_cs_b", false,-1);
        tracep->declBit(c+93,"top sharpx1 VRAM wren_b", false,-1);
        tracep->declBus(c+94,"top sharpx1 VRAM address_b", false,-1, 11,0);
        tracep->declBus(c+95,"top sharpx1 VRAM data_b", false,-1, 7,0);
        tracep->declBus(c+96,"top sharpx1 VRAM q_b", false,-1, 7,0);
        tracep->declBus(c+119,"top sharpx1 PCGRAM data_width_g", false,-1, 31,0);
        tracep->declBus(c+120,"top sharpx1 PCGRAM addr_width_g", false,-1, 31,0);
        tracep->declBit(c+97,"top sharpx1 PCGRAM clock", false,-1);
        tracep->declBit(c+98,"top sharpx1 PCGRAM ram_cs", false,-1);
        tracep->declBit(c+99,"top sharpx1 PCGRAM wren_a", false,-1);
        tracep->declBus(c+100,"top sharpx1 PCGRAM address_a", false,-1, 12,0);
        tracep->declBus(c+101,"top sharpx1 PCGRAM data_a", false,-1, 7,0);
        tracep->declBus(c+102,"top sharpx1 PCGRAM q_a", false,-1, 7,0);
        tracep->declBit(c+103,"top sharpx1 PCGRAM ram_cs_b", false,-1);
        tracep->declBit(c+104,"top sharpx1 PCGRAM wren_b", false,-1);
        tracep->declBus(c+105,"top sharpx1 PCGRAM address_b", false,-1, 12,0);
        tracep->declBus(c+106,"top sharpx1 PCGRAM data_b", false,-1, 7,0);
        tracep->declBus(c+107,"top sharpx1 PCGRAM q_b", false,-1, 7,0);
        tracep->declBus(c+119,"top sharpx1 GRAM data_width_g", false,-1, 31,0);
        tracep->declBus(c+128,"top sharpx1 GRAM addr_width_g", false,-1, 31,0);
        tracep->declBit(c+108,"top sharpx1 GRAM clock", false,-1);
        tracep->declBit(c+109,"top sharpx1 GRAM ram_cs", false,-1);
        tracep->declBit(c+110,"top sharpx1 GRAM wren_a", false,-1);
        tracep->declBus(c+111,"top sharpx1 GRAM address_a", false,-1, 15,0);
        tracep->declBus(c+112,"top sharpx1 GRAM data_a", false,-1, 7,0);
        tracep->declBus(c+113,"top sharpx1 GRAM q_a", false,-1, 7,0);
        tracep->declBit(c+114,"top sharpx1 GRAM ram_cs_b", false,-1);
        tracep->declBit(c+115,"top sharpx1 GRAM wren_b", false,-1);
        tracep->declBus(c+116,"top sharpx1 GRAM address_b", false,-1, 15,0);
        tracep->declBus(c+117,"top sharpx1 GRAM data_b", false,-1, 7,0);
        tracep->declBus(c+118,"top sharpx1 GRAM q_b", false,-1, 7,0);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Variables
    VlWide<7>/*223:0*/ __Vtemp2;
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk_48));
        tracep->fullBit(oldp+2,(vlTOPp->clk_12));
        tracep->fullBit(oldp+3,(vlTOPp->reset));
        tracep->fullSData(oldp+4,(vlTOPp->inputs),12);
        tracep->fullCData(oldp+5,(vlTOPp->VGA_R),8);
        tracep->fullCData(oldp+6,(vlTOPp->VGA_G),8);
        tracep->fullCData(oldp+7,(vlTOPp->VGA_B),8);
        tracep->fullBit(oldp+8,(vlTOPp->VGA_HS));
        tracep->fullBit(oldp+9,(vlTOPp->VGA_VS));
        tracep->fullBit(oldp+10,(vlTOPp->VGA_HB));
        tracep->fullBit(oldp+11,(vlTOPp->VGA_VB));
        tracep->fullSData(oldp+12,(vlTOPp->AUDIO_L),16);
        tracep->fullSData(oldp+13,(vlTOPp->AUDIO_R),16);
        tracep->fullBit(oldp+14,(vlTOPp->ioctl_download));
        tracep->fullBit(oldp+15,(vlTOPp->ioctl_upload));
        tracep->fullBit(oldp+16,(vlTOPp->ioctl_wr));
        tracep->fullIData(oldp+17,(vlTOPp->ioctl_addr),25);
        tracep->fullCData(oldp+18,(vlTOPp->ioctl_dout),8);
        tracep->fullCData(oldp+19,(vlTOPp->ioctl_din),8);
        tracep->fullCData(oldp+20,(vlTOPp->ioctl_index),8);
        tracep->fullBit(oldp+21,(vlTOPp->ioctl_wait));
        tracep->fullBit(oldp+22,(vlTOPp->top__DOT__clk_48));
        tracep->fullBit(oldp+23,(vlTOPp->top__DOT__clk_12));
        tracep->fullBit(oldp+24,(vlTOPp->top__DOT__reset));
        tracep->fullSData(oldp+25,(vlTOPp->top__DOT__inputs),12);
        tracep->fullCData(oldp+26,(vlTOPp->top__DOT__VGA_R),8);
        tracep->fullCData(oldp+27,(vlTOPp->top__DOT__VGA_G),8);
        tracep->fullCData(oldp+28,(vlTOPp->top__DOT__VGA_B),8);
        tracep->fullBit(oldp+29,(vlTOPp->top__DOT__VGA_HS));
        tracep->fullBit(oldp+30,(vlTOPp->top__DOT__VGA_VS));
        tracep->fullBit(oldp+31,(vlTOPp->top__DOT__VGA_HB));
        tracep->fullBit(oldp+32,(vlTOPp->top__DOT__VGA_VB));
        tracep->fullSData(oldp+33,(vlTOPp->top__DOT__AUDIO_L),16);
        tracep->fullSData(oldp+34,(vlTOPp->top__DOT__AUDIO_R),16);
        tracep->fullBit(oldp+35,(vlTOPp->top__DOT__ioctl_download));
        tracep->fullBit(oldp+36,(vlTOPp->top__DOT__ioctl_upload));
        tracep->fullBit(oldp+37,(vlTOPp->top__DOT__ioctl_wr));
        tracep->fullIData(oldp+38,(vlTOPp->top__DOT__ioctl_addr),25);
        tracep->fullCData(oldp+39,(vlTOPp->top__DOT__ioctl_dout),8);
        tracep->fullCData(oldp+40,(vlTOPp->top__DOT__ioctl_din),8);
        tracep->fullCData(oldp+41,(vlTOPp->top__DOT__ioctl_index),8);
        tracep->fullBit(oldp+42,(vlTOPp->top__DOT__ioctl_wait));
        tracep->fullBit(oldp+43,(vlTOPp->top__DOT__pause));
        tracep->fullCData(oldp+44,(vlTOPp->top__DOT__audio),8);
        tracep->fullSData(oldp+45,(vlTOPp->top__DOT__rgb),9);
        tracep->fullCData(oldp+46,(vlTOPp->top__DOT__led),4);
        tracep->fullCData(oldp+47,(vlTOPp->top__DOT__trakball),8);
        tracep->fullCData(oldp+48,(vlTOPp->top__DOT__joystick),8);
        tracep->fullSData(oldp+49,(vlTOPp->top__DOT__playerinput),10);
        tracep->fullCData(oldp+50,(vlTOPp->top__DOT__sw1),8);
        tracep->fullCData(oldp+51,(vlTOPp->top__DOT__sw2),8);
        tracep->fullBit(oldp+52,(vlTOPp->top__DOT__ce_pix));
        tracep->fullBit(oldp+53,(vlTOPp->top__DOT__ioctl_data));
        tracep->fullBit(oldp+54,(vlTOPp->top__DOT__unnamedblk1__DOT__old_clk));
        tracep->fullBit(oldp+55,(vlTOPp->top__DOT__sharpx1__DOT__clk_sys));
        tracep->fullBit(oldp+56,(vlTOPp->top__DOT__sharpx1__DOT__clk_28636));
        tracep->fullBit(oldp+57,(vlTOPp->top__DOT__sharpx1__DOT__reset));
        tracep->fullBit(oldp+58,(vlTOPp->top__DOT__sharpx1__DOT__pal));
        tracep->fullBit(oldp+59,(vlTOPp->top__DOT__sharpx1__DOT__scandouble));
        tracep->fullBit(oldp+60,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_download));
        tracep->fullCData(oldp+61,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_index),8);
        tracep->fullBit(oldp+62,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_wr));
        tracep->fullIData(oldp+63,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_addr),25);
        tracep->fullCData(oldp+64,(vlTOPp->top__DOT__sharpx1__DOT__ioctl_dout),8);
        tracep->fullBit(oldp+65,(vlTOPp->top__DOT__sharpx1__DOT__ce_pix));
        tracep->fullBit(oldp+66,(vlTOPp->top__DOT__sharpx1__DOT__HBlank));
        tracep->fullBit(oldp+67,(vlTOPp->top__DOT__sharpx1__DOT__HSync));
        tracep->fullBit(oldp+68,(vlTOPp->top__DOT__sharpx1__DOT__VBlank));
        tracep->fullBit(oldp+69,(vlTOPp->top__DOT__sharpx1__DOT__VSync));
        tracep->fullCData(oldp+70,(vlTOPp->top__DOT__sharpx1__DOT__video),8);
        tracep->fullBit(oldp+71,(vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__clock));
        tracep->fullBit(oldp+72,(vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__ce));
        tracep->fullCData(oldp+73,(vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__data_out),8);
        tracep->fullSData(oldp+74,(vlTOPp->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__a),13);
        tracep->fullBit(oldp+75,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__clock));
        tracep->fullBit(oldp+76,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__ram_cs));
        tracep->fullBit(oldp+77,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_a));
        tracep->fullSData(oldp+78,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_a),16);
        tracep->fullCData(oldp+79,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_a),8);
        tracep->fullCData(oldp+80,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_a),8);
        tracep->fullBit(oldp+81,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__ram_cs_b));
        tracep->fullBit(oldp+82,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__wren_b));
        tracep->fullSData(oldp+83,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__address_b),16);
        tracep->fullCData(oldp+84,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__data_b),8);
        tracep->fullCData(oldp+85,(vlTOPp->top__DOT__sharpx1__DOT__RAM__DOT__q_b),8);
        tracep->fullBit(oldp+86,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__clock));
        tracep->fullBit(oldp+87,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__ram_cs));
        tracep->fullBit(oldp+88,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__wren_a));
        tracep->fullSData(oldp+89,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_a),12);
        tracep->fullCData(oldp+90,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__data_a),8);
        tracep->fullCData(oldp+91,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_a),8);
        tracep->fullBit(oldp+92,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__ram_cs_b));
        tracep->fullBit(oldp+93,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__wren_b));
        tracep->fullSData(oldp+94,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__address_b),12);
        tracep->fullCData(oldp+95,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__data_b),8);
        tracep->fullCData(oldp+96,(vlTOPp->top__DOT__sharpx1__DOT__VRAM__DOT__q_b),8);
        tracep->fullBit(oldp+97,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__clock));
        tracep->fullBit(oldp+98,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__ram_cs));
        tracep->fullBit(oldp+99,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__wren_a));
        tracep->fullSData(oldp+100,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__address_a),13);
        tracep->fullCData(oldp+101,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__data_a),8);
        tracep->fullCData(oldp+102,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__q_a),8);
        tracep->fullBit(oldp+103,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__ram_cs_b));
        tracep->fullBit(oldp+104,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__wren_b));
        tracep->fullSData(oldp+105,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__address_b),13);
        tracep->fullCData(oldp+106,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__data_b),8);
        tracep->fullCData(oldp+107,(vlTOPp->top__DOT__sharpx1__DOT__PCGRAM__DOT__q_b),8);
        tracep->fullBit(oldp+108,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__clock));
        tracep->fullBit(oldp+109,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__ram_cs));
        tracep->fullBit(oldp+110,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_a));
        tracep->fullSData(oldp+111,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_a),16);
        tracep->fullCData(oldp+112,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_a),8);
        tracep->fullCData(oldp+113,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_a),8);
        tracep->fullBit(oldp+114,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__ram_cs_b));
        tracep->fullBit(oldp+115,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__wren_b));
        tracep->fullSData(oldp+116,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__address_b),16);
        tracep->fullCData(oldp+117,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__data_b),8);
        tracep->fullCData(oldp+118,(vlTOPp->top__DOT__sharpx1__DOT__GRAM__DOT__q_b),8);
        tracep->fullIData(oldp+119,(8U),32);
        tracep->fullIData(oldp+120,(0xdU),32);
        __Vtemp2[0U] = 0x2e726f6dU;
        __Vtemp2[1U] = 0x626f6f74U;
        __Vtemp2[2U] = 0x7370692fU;
        __Vtemp2[3U] = 0x696f735fU;
        __Vtemp2[4U] = 0x66775f62U;
        __Vtemp2[5U] = 0x696f732fU;
        __Vtemp2[6U] = 0x2e2e2f62U;
        tracep->fullWData(oldp+121,(__Vtemp2),224);
        tracep->fullIData(oldp+128,(0x10U),32);
        tracep->fullIData(oldp+129,(0xcU),32);
    }
}
