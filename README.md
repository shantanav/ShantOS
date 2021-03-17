# Messing around with OS Development
## Build Instructions
 - Install the following dependencies: `sudo apt-get install build-essential nasm xorriso grub-pc-bin bochs bochs-sdl`
 - Run `make run` in the top level of your repository
 - At this point, Bochs may \>\>PANIC\<\< at you. If it does, complaining about a display module or not having a GUI module, add the following line to `bochsrc.txt`: `display_library: sdl2`
 - In the Bochs instance that opens, press `c` and Enter to compile and run the instance
 - Hit enter in the GRUB menu that opens in Bochs to launch ShantOS
