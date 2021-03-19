# ShantOS - The Shantanav OS

## Why ShantOS?
On a whim, I decided to get into operating system development for nothing more than curiosity's sake. ShantOS is the 
result of that curiosity. ShantOS boots using GRUB, and its primary running environment is Bochs, an x86\_64 emulator.

## Current Features
 - Text output to the screen
 - Logging output through serial port to a log file

## Build Instructions
 - Install the following dependencies using your favorite package manager: 
 `mtools build-essential nasm xorriso grub-pc-bin bochs bochs-sdl`
 - Run `make run` in the top level of your repository
 - At this point, Bochs may `>>PANIC<<` at you. If it does, and it's complaining about a display module or not having a 
 GUI module, add the following line to `exec/bochsrc.txt`: `display_library: sdl2` (or substitute `sdl2` with whatever
 display library your machine/distro happens to use)
 - When the Bochs instance opens, press `c` in the terminal and Enter. This will compile and run the OS in Bochs
 - Select Bochs and hit enter in the GRUB menu that opens in Bochs to launch ShantOS

## Disclaimers / Known Issues:
 - This OS has only been run on Ubuntu 20.10, and Manjaro 20.2.1 Your mileage may vary when using other OSes. 
 If you manage to get this running on anything that isn't Ubuntu or Manjaro, open a PR that edits this README
 with instructions.
 - Occasionally, the screen-output driver exhibits some *interesting* behavior - specifically it will occasionally
 ignore newline and tab characters. I have no idea what might be causing that, contributions to fix that are more
 than welcome.
 - Identify an issue with the OS? Have suggestions for a change that makes things cleaner or more efficient or 
 anything of the sort? Open a PR or an issue!
