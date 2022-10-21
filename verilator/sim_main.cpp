#include <verilated.h>
#include "Vtop.h"

#include "imgui.h"
#include "implot.h"
#ifndef _MSC_VER
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#else
#define WIN32
#include <dinput.h>
#endif

#include "sim_console.h"
#include "sim_bus.h"
#include "sim_video.h"
#include "sim_audio.h"
#include "sim_input.h"
#include "sim_clock.h"

#include "../imgui/imgui_memory_editor.h"
#include <verilated_vcd_c.h> //VCD Trace
#include "../imgui/ImGuiFileDialog.h"

#include <iostream>
#include <fstream>
using namespace std;

// Simulation control
// ------------------
int initialReset = 48;
bool run_enable = 0;
int batchSize = 150000;
bool single_step = 0;
bool multi_step = 0;
int multi_step_amount = 1024;

// Debug GUI 
// ---------
const char* windowTitle = "Verilator Sim: Sharp X1";
const char* windowTitle_Control = "Simulation control";
const char* windowTitle_DebugLog = "Debug log";
const char* windowTitle_Video = "VGA output";
const char* windowTitle_Trace = "Trace/VCD control";
const char* windowTitle_Audio = "Audio output";
bool showDebugLog = true;
DebugConsole console;
MemoryEditor mem_edit;

// HPS emulator
// ------------
SimBus bus(console);

// Input handling
// --------------
SimInput input(12, console);
const int input_right = 0;
const int input_left = 1;
const int input_down = 2;
const int input_up = 3;
const int input_fire1 = 4;
const int input_fire2 = 5;
const int input_start_1 = 6;
const int input_start_2 = 7;
const int input_coin_1 = 8;
const int input_coin_2 = 9;
const int input_coin_3 = 10;
const int input_pause = 11;

// Video
// -----
#define VGA_WIDTH 320
#define VGA_HEIGHT 240
#define VGA_ROTATE -1  // 90 degrees anti-clockwise
#define VGA_SCALE_X vga_scale
#define VGA_SCALE_Y vga_scale
SimVideo video(VGA_WIDTH, VGA_HEIGHT, VGA_ROTATE);
float vga_scale = 2.5;

// Verilog module
// --------------
Vtop* top = NULL;

vluint64_t main_time = 0;	// Current simulation time.
double sc_time_stamp() {	// Called by $time in Verilog.
	return main_time;
}

int clk_sys_freq = 48000000;
SimClock clk_48(1); // 48mhz
SimClock clk_12(4); // 12mhz

// VCD trace logging
// -----------------
VerilatedVcdC* tfp = new VerilatedVcdC; //Trace
bool Trace = 0;
char Trace_Deep[3] = "99";
char Trace_File[30] = "sim.vcd";
char Trace_Deep_tmp[3] = "99";
char Trace_File_tmp[30] = "sim.vcd";
int  iTrace_Deep_tmp = 99;
char SaveModel_File_tmp[20] = "test", SaveModel_File[20] = "test";

//Trace Save/Restore
void save_model(const char* filenamep) {
	VerilatedSave os;
	os.open(filenamep);
	os << main_time; // user code must save the timestamp, etc
	os << *top;
}
void restore_model(const char* filenamep) {
	VerilatedRestore os;
	os.open(filenamep);
	os >> main_time;
	os >> *top;
}

// Audio
// -----
#define DISABLE_AUDIO
#ifndef DISABLE_AUDIO
SimAudio audio(clk_sys_freq, true);
#endif

// Reset simulation variables and clocks
void resetSim() {
	main_time = 0;
	clk_48.Reset();
	clk_12.Reset();
}

int verilate() {

	if (!Verilated::gotFinish()) {

		// Assert reset during startup
		//if (main_time < initialReset) { top->reset = 1; }
		// Deassert reset after startup
		//if (main_time == initialReset) { top->reset = 0; }

		// Clock dividers
		clk_48.Tick();
		clk_12.Tick();

		// Set clocks in core
		top->clk_48 = clk_48.clk;
		top->clk_12 = clk_12.clk;

		// Simulate both edges of fastest clock
		if (clk_48.clk != clk_48.old) {

			// System clock simulates HPS functions
			if (clk_12.clk) {
				input.BeforeEval();
				bus.BeforeEval();
			}
			top->eval();
			if (Trace) {
				if (!tfp->isOpen()) tfp->open(Trace_File);
				tfp->dump(main_time); //Trace
			}

			// System clock simulates HPS functions
			if (clk_12.clk) { bus.AfterEval(); }
		}

#ifndef DISABLE_AUDIO
		if (clk_48.IsRising())
		{
			audio.Clock(top->AUDIO_L, top->AUDIO_R);
		}
#endif

		// Output pixels on rising edge of pixel clock
		if (clk_48.IsRising() && top->top__DOT__ce_pix) {
			uint32_t colour = 0xFF000000 | top->VGA_B << 16 | top->VGA_G << 8 | top->VGA_R;
			video.Clock(top->VGA_HB, top->VGA_VB, top->VGA_HS, top->VGA_VS, colour);
		}

		if (clk_48.IsRising()) {
			main_time++;
		}
		return 1;
	}

	// Stop verilating and cleanup
	top->final();
	delete top;
	exit(0);
	return 0;
}

int main(int argc, char** argv, char** env) {

	// Create core and initialise
	top = new Vtop();
	Verilated::commandArgs(argc, argv);

	//Prepare for Dump Signals
	Verilated::traceEverOn(true); //Trace
	top->trace(tfp, 1);// atoi(Trace_Deep) );  // Trace 99 levels of hierarchy
	if (Trace) tfp->open(Trace_File);//"simx.vcd"); //Trace

#ifdef WIN32
	// Attach debug console to the verilated code
	Verilated::setDebug(console);
#endif

	// Attach bus
	bus.ioctl_addr = &top->ioctl_addr;
	bus.ioctl_index = &top->ioctl_index;
	bus.ioctl_wait = &top->ioctl_wait;
	bus.ioctl_download = &top->ioctl_download;
	bus.ioctl_upload = &top->ioctl_upload;
	bus.ioctl_wr = &top->ioctl_wr;
	bus.ioctl_dout = &top->ioctl_dout;
	bus.ioctl_din = &top->ioctl_din;

#ifndef DISABLE_AUDIO
	audio.Initialise();
#endif

	// Set up input module
	input.Initialise();
#ifdef WIN32
	input.SetMapping(input_up, DIK_UP);
	input.SetMapping(input_right, DIK_RIGHT);
	input.SetMapping(input_down, DIK_DOWN);
	input.SetMapping(input_left, DIK_LEFT);
	input.SetMapping(input_fire1, DIK_SPACE);
	input.SetMapping(input_start_1, DIK_1);
	input.SetMapping(input_start_2, DIK_2);
	input.SetMapping(input_coin_1, DIK_5);
	input.SetMapping(input_coin_2, DIK_6);
	input.SetMapping(input_coin_3, DIK_7);
	input.SetMapping(input_pause, DIK_P);
#else
	input.SetMapping(input_up, SDL_SCANCODE_UP);
	input.SetMapping(input_right, SDL_SCANCODE_RIGHT);
	input.SetMapping(input_down, SDL_SCANCODE_DOWN);
	input.SetMapping(input_left, SDL_SCANCODE_LEFT);
	input.SetMapping(input_fire1, SDL_SCANCODE_SPACE);
	input.SetMapping(input_start_1, SDL_SCANCODE_1);
	input.SetMapping(input_start_2, SDL_SCANCODE_2);
	input.SetMapping(input_coin_1, SDL_SCANCODE_3);
	input.SetMapping(input_coin_2, SDL_SCANCODE_4);
	input.SetMapping(input_coin_3, SDL_SCANCODE_5);
	input.SetMapping(input_pause, SDL_SCANCODE_P);
#endif
	// Setup video output
	if (video.Initialise(windowTitle) == 1) { return 1; }

	bus.QueueDownload("./ipl_x1.rom", 0, true);
	//bus.QueueDownload("./boot.hex", 0, true);

#ifdef WIN32
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}
#else
	bool done = false;
	while (!done)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT)
				done = true;
		}
#endif
		video.StartFrame();

		input.Read();


		// Draw GUI
		// --------
		ImGui::NewFrame();

		// Simulation control window
		ImGui::Begin(windowTitle_Control);
		ImGui::SetWindowPos(windowTitle_Control, ImVec2(0, 0), ImGuiCond_Once);
		ImGui::SetWindowSize(windowTitle_Control, ImVec2(500, 150), ImGuiCond_Once);
		if (ImGui::Button("Reset simulation")) { resetSim(); } ImGui::SameLine();
		if (ImGui::Button("Start running")) { run_enable = 1; } ImGui::SameLine();
		if (ImGui::Button("Stop running")) { run_enable = 0; } ImGui::SameLine();
		ImGui::Checkbox("RUN", &run_enable);
		//ImGui::PopItemWidth();
		ImGui::SliderInt("Run batch size", &batchSize, 1, 250000);
		if (single_step == 1) { single_step = 0; }
		if (ImGui::Button("Single Step")) { run_enable = 0; single_step = 1; }
		ImGui::SameLine();
		if (multi_step == 1) { multi_step = 0; }
		if (ImGui::Button("Multi Step")) { run_enable = 0; multi_step = 1; }
		//ImGui::SameLine();
		ImGui::SliderInt("Multi step amount", &multi_step_amount, 8, 1024);

		ImGui::End();

		// Debug log window
		console.Draw(windowTitle_DebugLog, &showDebugLog, ImVec2(500, 700));
		ImGui::SetWindowPos(windowTitle_DebugLog, ImVec2(0, 160), ImGuiCond_Once);

		// Memory debug
		ImGui::Begin("BOOTROM IPL");
		mem_edit.DrawContents(&top->top__DOT__sharpx1__DOT__IPL__DOT__mem, 8192, 0);
		ImGui::End();		
		//ImGui::Begin("BOOTROM CHARGEN");
		//mem_edit.DrawContents(&top->top__DOT__sharpx1__DOT__bios_fw_spi__DOT__d, 8192, 0);
		//ImGui::End();		
		ImGui::Begin("RAM");
		mem_edit.DrawContents(&top->top__DOT__sharpx1__DOT__RAM__DOT__mem, 65536, 0);
		ImGui::End();	
		ImGui::Begin("VRAM");
		mem_edit.DrawContents(&top->top__DOT__sharpx1__DOT__VRAM__DOT__mem, 4096, 0);
		ImGui::End();
		ImGui::Begin("PSG RAM");
		mem_edit.DrawContents(&top->top__DOT__sharpx1__DOT__PSGRAM__DOT__mem, 8192, 0);
		ImGui::End();
		ImGui::Begin("GRAM");
		mem_edit.DrawContents(&top->top__DOT__sharpx1__DOT__GRAM__DOT__mem, 65536, 0);
		ImGui::End();

		// Debug CPU
		ImGui::Begin("Cpu");
		ImGui::Text("I reset_n:   0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__reset_n);	
		ImGui::Text("I cep:       0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__cep);
		ImGui::Text("I cen:       0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__cen);
		ImGui::Text("I int_n:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__int_n);
		ImGui::Text("I di:        0x%04X", top->top__DOT__sharpx1__DOT__Cpu__DOT__di);
		ImGui::Text("I dir:       0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__dir);
		ImGui::Text("I dirset:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__dirset);
		ImGui::Spacing();
		ImGui::Text("O halt_n:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__halt_n);		
		ImGui::Text("O mreq:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__mreq);		
		ImGui::Text("O iorq:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__iorq);		
		ImGui::Text("O wr:        0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__wr);	
		ImGui::Text("O rd:        0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__rd);	
		ImGui::Text("O m1:        0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__m1);						
		ImGui::Text("O data_out:  0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__data_out);		
		ImGui::Text("O a:         0x%04X", top->top__DOT__sharpx1__DOT__Cpu__DOT__a);		
		ImGui::Spacing();					
		ImGui::End();

		// tv80_core Registers
		ImGui::Begin("tv80_core Registers");
		ImGui::Text("reset_n:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__reset_n);		
		ImGui::Spacing();			
		ImGui::Text("ACC:         0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC);	
		ImGui::Text("F:           0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F);
		ImGui::Text("Ap:          0x%04X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Ap);
		ImGui::Text("Fp:          0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Fp);		
		ImGui::Text("I:           0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I);	
		ImGui::Spacing();
		ImGui::Text("SP:          0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP);	
		ImGui::Text("PC:          0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC);	
		ImGui::Text("RegDIH:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIH);	
		ImGui::Text("RegDIL:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIL);	
		ImGui::Text("RegBusA:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA);	
		ImGui::Text("RegBusB:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusB);	
		ImGui::Text("RegBusC:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC);	
		ImGui::Text("RegAddrA_r:  0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA_r);	
		ImGui::Text("RegAddrA:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA);
		ImGui::Text("RegAddrB_r:  0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB_r);
		ImGui::Text("RegAddrB:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB);
		ImGui::Text("RegAddrC:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC);
		ImGui::Text("RegWEH:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEH);
		ImGui::Text("RegWEL:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEL);
		ImGui::Text("Alternate:   0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate);												
		ImGui::Spacing();														
		ImGui::End();

		// Debug Sub CPU
		ImGui::Begin("Sub CPU 80C49");
		ImGui::Text("I reset:     0x%02X", top->top__DOT__sharpx1__DOT__subCPU__DOT__I_reset);	
		ImGui::Text("I cs:        0x%02X", top->top__DOT__sharpx1__DOT__subCPU__DOT__I_cs);
		ImGui::Text("I rd:        0x%04X", top->top__DOT__sharpx1__DOT__subCPU__DOT__I_rd);
		ImGui::Text("I wr:        0x%04X", top->top__DOT__sharpx1__DOT__subCPU__DOT__I_wr);
		ImGui::Text("I M1_n:      0x%04X", top->top__DOT__sharpx1__DOT__subCPU__DOT__I_M1_n);
		ImGui::Text("I D:         0x%04X", top->top__DOT__sharpx1__DOT__subCPU__DOT__I_D);
		ImGui::Text("O D:         0x%04X", top->top__DOT__sharpx1__DOT__subCPU__DOT__O_D);
		ImGui::Spacing();
		ImGui::End();

		// Debug Address Decoder
		ImGui::Begin("Address Decoder");
		ImGui::Text("I reset:      0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__I_RESET);	
		ImGui::Text("I A:          0x%04X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__I_A);
		ImGui::Text("I MREQ_n:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__I_MREQ_n);
		ImGui::Spacing();	
		ImGui::Text("O IPL_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_CS);
		ImGui::Text("O RAM_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_RAM_CS);
		ImGui::Text("O MIOCS:      0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_MIOCS);
		ImGui::Text("O EMM_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_EMM_CS);
		ImGui::Text("O EXTROM_CS:  0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_EXTROM_CS);
		ImGui::Text("O KANROM_CS:  0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_KANROM_CS);
		ImGui::Text("O FD5_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_FD5_CS);
		ImGui::Text("O PAL_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_PAL_CS);
		ImGui::Text("O CG_CS:      0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_CG_CS);
		ImGui::Text("O CRTC_CS:    0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_CRTC_CS);																		
		ImGui::Text("O SUB_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_SUB_CS);
		ImGui::Text("O PIA_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_PIA_CS);
		ImGui::Text("O PSG_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_PSG_CS);
		ImGui::Text("O IPL_SET_CS: 0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_SET_CS);
		ImGui::Text("O IPL_RES_CS: 0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_IPL_RES_CS);
		ImGui::Text("O ATTR_CS:    0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_ATTR_CS);
		ImGui::Text("O TEXT_CS:    0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_TEXT_CS);
		ImGui::Text("O GRB_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRB_CS);
		ImGui::Text("O GRR_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRR_CS);
		ImGui::Text("O GRG_CS:     0x%02X", top->top__DOT__sharpx1__DOT__x1_adec__DOT__O_GRG_CS);
		ImGui::Spacing();
		ImGui::End();

/*
		// Debug CPU
		ImGui::Begin("Cpu");
		ImGui::Text("I cep:   0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__cep);	
		ImGui::Text("I cen:   0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__cen);
		ImGui::Text("I reset: 0x%04X", top->top__DOT__sharpx1__DOT__Cpu__DOT__reset);
		ImGui::Text("O rfsh:  0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__rfsh);		
		ImGui::Text("O mreq:  0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__mreq);	
		ImGui::Text("O iorq:  0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__iorq);	
		ImGui::Text("I nmi:   0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__nmi);	
		ImGui::Text("O wr:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__wr);	
		ImGui::Text("O rd:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__rd);	
		ImGui::Text("O m1:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__m1);	
		ImGui::Text("I d:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__d);	
		ImGui::Text("O q:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__q);	
		ImGui::Text("O a:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__a);																			
		ImGui::Spacing();														
		ImGui::End();

		// tv80_core Registers
		ImGui::Begin("tv80_core Registers");
		ImGui::Text("ACC:         0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__ACC);	
		ImGui::Text("F:           0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__F);
		ImGui::Text("Ap:          0x%04X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Ap);
		ImGui::Text("Fp:          0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Fp);		
		ImGui::Text("I:           0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__I);	
		ImGui::Spacing();
		ImGui::Text("SP:          0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__SP);	
		ImGui::Text("PC:          0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__PC);	
		ImGui::Text("RegDIH:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIH);	
		ImGui::Text("RegDIL:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegDIL);	
		ImGui::Text("RegBusA:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusA);	
		ImGui::Text("RegBusB:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusB);	
		ImGui::Text("RegBusC:     0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegBusC);	
		ImGui::Text("RegAddrA_r:  0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA_r);	
		ImGui::Text("RegAddrA:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrA);
		ImGui::Text("RegAddrB_r:  0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB_r);
		ImGui::Text("RegAddrB:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrB);
		ImGui::Text("RegAddrC:    0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegAddrC);
		ImGui::Text("RegWEH:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEH);
		ImGui::Text("RegWEL:      0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__RegWEL);
		ImGui::Text("Alternate:   0x%02X", top->top__DOT__sharpx1__DOT__Cpu__DOT__Z80CPU__DOT__i_tv80_core__DOT__Alternate);												
		ImGui::Spacing();														
		ImGui::End();
*/

		// Debug top
		ImGui::Begin("top");
		ImGui::Text("romA:    0x%04X", top->top__DOT__sharpx1__DOT__romA);
		ImGui::Text("ramWe:   0x%04X", top->top__DOT__sharpx1__DOT__ramWe);	
		ImGui::Text("ramDi:   0x%04X", top->top__DOT__sharpx1__DOT__ramDi);	
		ImGui::Text("ramA:    0x%04X", top->top__DOT__sharpx1__DOT__ramA);
		ImGui::Text("di:      0x%04X", top->top__DOT__sharpx1__DOT__di);
		ImGui::Spacing();			
		ImGui::Text("ce:      0x%02X", top->top__DOT__sharpx1__DOT__ce);
		ImGui::Text("pe4M4:   0x%02X", top->top__DOT__sharpx1__DOT__pe4M4);
		ImGui::Text("ne4M4:   0x%02X", top->top__DOT__sharpx1__DOT__ne4M4);	
		ImGui::Spacing();	
		ImGui::Text("rd:      0x%02X", top->top__DOT__sharpx1__DOT__rd);	
		ImGui::Text("wr:      0x%02X", top->top__DOT__sharpx1__DOT__wr);		
		ImGui::Text("m1:      0x%02X", top->top__DOT__sharpx1__DOT__m1);	
		//ImGui::Text("ior:     0x%02X", top->top__DOT__sharpx1__DOT__ior);	
		//ImGui::Text("iow:     0x%02X", top->top__DOT__sharpx1__DOT__iow);																														
		ImGui::End();

		// Debug top
		ImGui::Begin("DMA");
		ImGui::Text("dma_bank:    0x%04X", top->top__DOT__sharpx1__DOT__dma_bank);
		ImGui::Text("dma_a:       0x%04X", top->top__DOT__sharpx1__DOT__dma_a);	
		ImGui::Text("dma_do:      0x%04X", top->top__DOT__sharpx1__DOT__dma_do);	
		ImGui::Text("dma_di:      0x%04X", top->top__DOT__sharpx1__DOT__dma_di);
		ImGui::Text("di:          0x%04X", top->top__DOT__sharpx1__DOT__di);
		ImGui::Text("dma_mreq_n:  0x%04X", top->top__DOT__sharpx1__DOT__dma_mreq_n);
		ImGui::Text("dma_iorq_n:  0x%04X", top->top__DOT__sharpx1__DOT__dma_iorq_n);	
		ImGui::Text("dma_rd_n:    0x%04X", top->top__DOT__sharpx1__DOT__dma_rd_n);	
		ImGui::Text("dma_wr_n:    0x%04X", top->top__DOT__sharpx1__DOT__dma_wr_n);
		ImGui::Text("dma_sel:     0x%04X", top->top__DOT__sharpx1__DOT__dma_sel);
		ImGui::Spacing();			
		ImGui::Text("sdo:         0x%04X", top->top__DOT__sharpx1__DOT__sdo);
		ImGui::Text("sbank:       0x%04X", top->top__DOT__sharpx1__DOT__sbank);
		ImGui::Text("sa:          0x%04X", top->top__DOT__sharpx1__DOT__sa);	
		ImGui::Text("sm1_n:       0x%04X", top->top__DOT__sharpx1__DOT__sm1_n);	
		ImGui::Text("smreq_n:     0x%04X", top->top__DOT__sharpx1__DOT__smreq_n);		
		ImGui::Text("sireq_n:     0x%04X", top->top__DOT__sharpx1__DOT__sireq_n);	
		ImGui::Text("sireq_n:     0x%04X", top->top__DOT__sharpx1__DOT__sireq_n);	
		ImGui::Text("srd_n:       0x%04X", top->top__DOT__sharpx1__DOT__srd_n);			
		ImGui::Text("swr_n:       0x%04X", top->top__DOT__sharpx1__DOT__swr_n);	
		ImGui::Text("sdi:         0x%04X", top->top__DOT__sharpx1__DOT__sdi);																																
		ImGui::End();

		// Debug RAM
		ImGui::Begin("RAM ports");
		ImGui::Text("I address_a: 0x%04X", top->top__DOT__sharpx1__DOT__RAM__DOT__address_a);	
		ImGui::Text("I wren_a:    0x%04X", top->top__DOT__sharpx1__DOT__RAM__DOT__wren_a);
		ImGui::Text("I data_a:    0x%04X", top->top__DOT__sharpx1__DOT__RAM__DOT__data_a);
		ImGui::Text("O q_a:       0x%04X", top->top__DOT__sharpx1__DOT__RAM__DOT__q_a);	
		ImGui::Spacing();														
		ImGui::End();
		
		// Debug ROM
		ImGui::Begin("ROM ports");
		ImGui::Text("I address_b: 0x%04X", top->top__DOT__sharpx1__DOT__IPL__DOT__address_b);	
		ImGui::Text("I wren_b:    0x%04X", top->top__DOT__sharpx1__DOT__IPL__DOT__wren_b);
		ImGui::Text("I data_b:    0x%04X", top->top__DOT__sharpx1__DOT__IPL__DOT__data_b);
		ImGui::Text("O q_b:       0x%04X", top->top__DOT__sharpx1__DOT__IPL__DOT__q_b);	
		ImGui::Spacing();														
		ImGui::End();
		/*
		// Debug ROM
		ImGui::Begin("ROM ports");
		ImGui::Text("I a:        0x%04X", top->top__DOT__sharpx1__DOT__IPL__DOT__a);	
		ImGui::Text("I ce:       0x%04X", top->top__DOT__sharpx1__DOT__IPL__DOT__ce);
		ImGui::Text("O data_out: 0x%04X", top->top__DOT__sharpx1__DOT__IPL__DOT__data_out);	
		ImGui::Spacing();														
		ImGui::End();
		*/
		// Debug ioctl
		ImGui::Begin("ioctl");
		ImGui::Text("ioctl_download: 0x%02X", top->top__DOT__sharpx1__DOT__ioctl_download);	
		ImGui::Text("ioctl_wr:       0x%02X", top->top__DOT__sharpx1__DOT__ioctl_wr);
		ImGui::Text("ioctl_addr:     0x%04X", top->top__DOT__sharpx1__DOT__ioctl_addr);
		ImGui::Text("ioctl_dout:     0x%02X", top->top__DOT__sharpx1__DOT__ioctl_dout);		
		ImGui::Spacing();														
		ImGui::End();

		// Trace/VCD window
		ImGui::Begin(windowTitle_Trace);
		ImGui::SetWindowPos(windowTitle_Trace, ImVec2(0, 870), ImGuiCond_Once);
		ImGui::SetWindowSize(windowTitle_Trace, ImVec2(500, 150), ImGuiCond_Once);

		if (ImGui::Button("Start VCD Export")) { Trace = 1; } ImGui::SameLine();
		if (ImGui::Button("Stop VCD Export")) { Trace = 0; } ImGui::SameLine();
		if (ImGui::Button("Flush VCD Export")) { tfp->flush(); } ImGui::SameLine();
		ImGui::Checkbox("Export VCD", &Trace);

		ImGui::PushItemWidth(120);
		if (ImGui::InputInt("Deep Level", &iTrace_Deep_tmp, 1, 100, ImGuiInputTextFlags_EnterReturnsTrue))
		{
			top->trace(tfp, iTrace_Deep_tmp);
		}

		if (ImGui::InputText("TraceFilename", Trace_File_tmp, IM_ARRAYSIZE(Trace_File), ImGuiInputTextFlags_EnterReturnsTrue))
		{
			strcpy(Trace_File, Trace_File_tmp); //TODO onChange Close and open new trace file
			tfp->close();
			if (Trace) tfp->open(Trace_File);
		};
		ImGui::Separator();
		if (ImGui::Button("Save Model")) { save_model(SaveModel_File); } ImGui::SameLine();
		if (ImGui::Button("Load Model")) {
			restore_model(SaveModel_File);
		} ImGui::SameLine();
		if (ImGui::InputText("SaveFilename", SaveModel_File_tmp, IM_ARRAYSIZE(SaveModel_File), ImGuiInputTextFlags_EnterReturnsTrue))
		{
			strcpy(SaveModel_File, SaveModel_File_tmp); //TODO onChange Close and open new trace file
		}
		ImGui::End();
		int windowX = 550;
		int windowWidth = (VGA_WIDTH * VGA_SCALE_X) + 24;
		int windowHeight = (VGA_HEIGHT * VGA_SCALE_Y) + 90;

		// Video window
		ImGui::Begin(windowTitle_Video);
		ImGui::SetWindowPos(windowTitle_Video, ImVec2(windowX, 0), ImGuiCond_Once);
		ImGui::SetWindowSize(windowTitle_Video, ImVec2(windowWidth, windowHeight), ImGuiCond_Once);

		ImGui::SetNextItemWidth(400);
		ImGui::SliderFloat("Zoom", &vga_scale, 1, 8); ImGui::SameLine();
		ImGui::SetNextItemWidth(200);
		ImGui::SliderInt("Rotate", &video.output_rotate, -1, 1); ImGui::SameLine();
		ImGui::Checkbox("Flip V", &video.output_vflip);
		ImGui::Text("main_time: %d frame_count: %d sim FPS: %f", main_time, video.count_frame, video.stats_fps);
		//ImGui::Text("pixel: %06d line: %03d", video.count_pixel, video.count_line);

		// Draw VGA output
		ImGui::Image(video.texture_id, ImVec2(video.output_width * VGA_SCALE_X, video.output_height * VGA_SCALE_Y));
		ImGui::End();


#ifndef DISABLE_AUDIO

		ImGui::Begin(windowTitle_Audio);
		ImGui::SetWindowPos(windowTitle_Audio, ImVec2(windowX, windowHeight), ImGuiCond_Once);
		ImGui::SetWindowSize(windowTitle_Audio, ImVec2(windowWidth, 250), ImGuiCond_Once);


		//float vol_l = ((signed short)(top->AUDIO_L) / 256.0f) / 256.0f;
		//float vol_r = ((signed short)(top->AUDIO_R) / 256.0f) / 256.0f;
		//ImGui::ProgressBar(vol_l + 0.5f, ImVec2(200, 16), 0); ImGui::SameLine();
		//ImGui::ProgressBar(vol_r + 0.5f, ImVec2(200, 16), 0);

		int ticksPerSec = (24000000 / 60);
		if (run_enable) {
			audio.CollectDebug((signed short)top->AUDIO_L, (signed short)top->AUDIO_R);
		}
		int channelWidth = (windowWidth / 2) - 16;
		ImPlot::CreateContext();
		if (ImPlot::BeginPlot("Audio - L", ImVec2(channelWidth, 220), ImPlotFlags_NoLegend | ImPlotFlags_NoMenus | ImPlotFlags_NoTitle)) {
			ImPlot::SetupAxes("T", "A", ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickMarks, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickMarks);
			ImPlot::SetupAxesLimits(0, 1, -1, 1, ImPlotCond_Once);
			ImPlot::PlotStairs("", audio.debug_positions, audio.debug_wave_l, audio.debug_max_samples, audio.debug_pos);
			ImPlot::EndPlot();
		}
		ImGui::SameLine();
		if (ImPlot::BeginPlot("Audio - R", ImVec2(channelWidth, 220), ImPlotFlags_NoLegend | ImPlotFlags_NoMenus | ImPlotFlags_NoTitle)) {
			ImPlot::SetupAxes("T", "A", ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickMarks, ImPlotAxisFlags_AutoFit | ImPlotAxisFlags_NoLabel | ImPlotAxisFlags_NoTickMarks);
			ImPlot::SetupAxesLimits(0, 1, -1, 1, ImPlotCond_Once);
			ImPlot::PlotStairs("", audio.debug_positions, audio.debug_wave_r, audio.debug_max_samples, audio.debug_pos);
			ImPlot::EndPlot();
		}
		ImPlot::DestroyContext();
		ImGui::End();
#endif

		video.UpdateTexture();


		// Pass inputs to sim
		top->inputs = 0;
		for (int i = 0; i < input.inputCount; i++)
		{
			if (input.inputs[i]) { top->inputs |= (1 << i); }
		}

		// Run simulation
		if (run_enable) {
			for (int step = 0; step < batchSize; step++) { verilate(); }
		}
		else {
			if (single_step) { verilate(); }
			if (multi_step) {
				for (int step = 0; step < multi_step_amount; step++) { verilate(); }
			}
		}
	}

	// Clean up before exit
	// --------------------

#ifndef DISABLE_AUDIO
	audio.CleanUp();
#endif 
	video.CleanUp();
	input.CleanUp();

	return 0;
}
