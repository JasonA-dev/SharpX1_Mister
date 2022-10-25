verilator \
-cc -exe --public --trace --savable \
--compiler msvc +define+SIMULATION=1 \
-O3 --x-assign fast --x-initial fast --noassert \
--converge-limit 6000 \
-Wno-fatal \
--top-module top sim.v \
../rtl/sharpx1_legacy.v \
../rtl/legacy/noicez80.v \
../rtl/legacy/bootrom.v \
../rtl/legacy/x1_mode.v \
../rtl/legacy/x1t_mode.v \
../rtl/legacy/x1_vid.v \
../rtl/legacy/crtc/crtc6845s.v \
../rtl/legacy/pcg_wait.v \
../rtl/legacy/z80/z80ctc.v \
../rtl/legacy/dpram2k.v \
../rtl/legacy/x1_cg8.v \
../rtl/legacy/video/dbl_scan.v \
../rtl/legacy/uart_rx.v \
../rtl/legacy/uart_tx.v \
../rtl/legacy/fz80/fz80c.v \
../rtl/legacy/fz80/fz80_110.v \
../rtl/legacy/z80/z80reti.v \
../rtl/legacy/PIA8255.v \
../rtl/legacy/sound/ay8910.v \
../rtl/sharpx1.v \
../rtl/cpu.v \
../rtl/tv80/tv80e.v \
../rtl/tv80/tv80_core.v \
../rtl/tv80/tv80_mcode.v \
../rtl/tv80/tv80_alu.v \
../rtl/tv80/tv80_reg.v \
../rtl/dpram.sv \
../rtl/rom.v \
../rtl/sub_cpu.v \
../rtl/sub_rom.v \
../rtl/mr16_x1.v \
../rtl/mr16core.v \
../rtl/x1_adec.v