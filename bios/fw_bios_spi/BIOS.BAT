rem echo off
del bios.hex
del bios.lst
del work\bios.bin
del work\boot.v
..\aasm\aasm -t10 -MZ80.MAC -l bios.s >err
..\aasm\hex_ut bios.hex -IB work\bios.bin
bin2ver work\bios.bin work\boot.v -nboot_rom -s2048
if EXIST work\boot.v goto ok
echo ERROR !!!!!
goto end

:ok
copy /B work\head.v+work\boot.v+work\bottom.v ..\src\bootrom.v
:end
