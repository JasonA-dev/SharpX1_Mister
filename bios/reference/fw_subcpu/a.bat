@echo off
echo off
..\aasm\aasm -MMR16.MAC -l -T10 x1sub.asm
..\aasm\hex_ut x1sub.hex -IB verilog\x1sub.bin
..\bin2ver\bin2ver verilog\x1sub.bin verilog\rom.v -nrom -s4096 -w16
copy /B verilog\head.v+verilog\rom.v+verilog\bottom.v ..\src\sub_rom.v >NUL
