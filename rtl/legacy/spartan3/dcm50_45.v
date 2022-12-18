////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2003 Xilinx, Inc.
// All Right Reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____ 
//  /   /\/   / 
// /___/  \  /    Vendor: Xilinx 
// \   \   \/     Version : 6.3.02i
//  \   \         Application : 
//  /   /         Filename : dcm50_45.v
// /___/   /\     Timestamp : 11/25/2004 14:36:12
// \   \  /  \ 
//  \___\/\___\ 
//
//Command: 
//Design Name: mydcm
//
// Module dcm50_45
// Generated by Xilinx Architecture Wizard
// Written for synthesis tool: XST
`timescale 1ns / 1ps

module dcm50_45(CLKIN_IN, 
             RST_IN, 
             CLKFX_OUT, 
             CLKIN_IBUFG_OUT, 
             CLK0_OUT, 
             LOCKED_OUT);

    input CLKIN_IN;
    input RST_IN;
   output CLKFX_OUT;
   output CLKIN_IBUFG_OUT;
   output CLK0_OUT;
   output LOCKED_OUT;
   
   wire CLKFB_IN;
   wire CLKFX_BUF;
   wire CLKIN_IBUFG;
   wire CLK0_BUF;
   wire GND;
   
   assign GND = 0;
   assign CLKIN_IBUFG_OUT = CLKIN_IBUFG;
   assign CLK0_OUT = CLKFB_IN;
   BUFG CLKFX_BUFG_INST (.I(CLKFX_BUF), 
                         .O(CLKFX_OUT));
   IBUFG CLKIN_IBUFG_INST (.I(CLKIN_IN), 
                           .O(CLKIN_IBUFG));
   BUFG CLK0_BUFG_INST (.I(CLK0_BUF), 
                        .O(CLKFB_IN));
   // Period Jitter (unit interval) for block DCM_INST = 0.05 UI
   // Period Jitter (Peak-to-Peak) for block DCM_INST = 1.02 ns
   DCM DCM_INST (.CLKFB(CLKFB_IN), 
                 .CLKIN(CLKIN_IBUFG), 
                 .DSSEN(GND), 
                 .PSCLK(GND), 
                 .PSEN(GND), 
                 .PSINCDEC(GND), 
                 .RST(RST_IN), 
                 .CLKDV(), 
                 .CLKFX(CLKFX_BUF), 
                 .CLKFX180(), 
                 .CLK0(CLK0_BUF), 
                 .CLK2X(), 
                 .CLK2X180(), 
                 .CLK90(), 
                 .CLK180(), 
                 .CLK270(), 
                 .LOCKED(LOCKED_OUT), 
                 .PSDONE(), 
                 .STATUS());
   // synthesis attribute CLK_FEEDBACK of DCM_INST is "1X"
   // synthesis attribute CLKDV_DIVIDE of DCM_INST is "2.000000"
   // synthesis attribute CLKFX_DIVIDE of DCM_INST is "10"
   // synthesis attribute CLKFX_MULTIPLY of DCM_INST is "9"
   // synthesis attribute CLKIN_DIVIDE_BY_2 of DCM_INST is "FALSE"
   // synthesis attribute CLKIN_PERIOD of DCM_INST is "20.000000"
   // synthesis attribute CLKOUT_PHASE_SHIFT of DCM_INST is "NONE"
   // synthesis attribute DESKEW_ADJUST of DCM_INST is "SYSTEM_SYNCHRONOUS"
   // synthesis attribute DFS_FREQUENCY_MODE of DCM_INST is "LOW"
   // synthesis attribute DLL_FREQUENCY_MODE of DCM_INST is "LOW"
   // synthesis attribute DUTY_CYCLE_CORRECTION of DCM_INST is "TRUE"
   // synthesis attribute FACTORY_JF of DCM_INST is "C080"
   // synthesis attribute PHASE_SHIFT of DCM_INST is "0"
   // synthesis attribute STARTUP_WAIT of DCM_INST is "FALSE"
   // synopsys translate_off
   defparam DCM_INST.CLK_FEEDBACK = "1X";
   defparam DCM_INST.CLKDV_DIVIDE = 2.000000;
   defparam DCM_INST.CLKFX_DIVIDE = 10;
   defparam DCM_INST.CLKFX_MULTIPLY = 9;
   defparam DCM_INST.CLKIN_DIVIDE_BY_2 = "FALSE";
   defparam DCM_INST.CLKIN_PERIOD = 20.000000;
   defparam DCM_INST.CLKOUT_PHASE_SHIFT = "NONE";
   defparam DCM_INST.DESKEW_ADJUST = "SYSTEM_SYNCHRONOUS";
   defparam DCM_INST.DFS_FREQUENCY_MODE = "LOW";
   defparam DCM_INST.DLL_FREQUENCY_MODE = "LOW";
   defparam DCM_INST.DUTY_CYCLE_CORRECTION = "TRUE";
   defparam DCM_INST.FACTORY_JF = 16'hC080;
   defparam DCM_INST.PHASE_SHIFT = 0;
   defparam DCM_INST.STARTUP_WAIT = "FALSE";
   // synopsys translate_on
endmodule