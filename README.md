# Messing around with OS Development
## Build Instructions
 - Install the following dependencies: `sudo apt-get install build-essential nasm xorriso grub-pc-bin bochs bochs-sdl`
 - Run `make run` in the top level of your repository
 - At this point, Bochs may `\>PANIC<<` at you. If it does, complaining about a display module or not having a GUI module, add the following line to `bochsrc.txt`: `display_library: sdl2`
 - When the Bochs instance opens, press `c` in the terminal and Enter. This will compile and run the OS in Bochs
 - Select Bochs and hit enter in the GRUB menu that opens in Bochs to launch ShantOS
## Disclaimers / Known Issues:
 - This OS has only been tested on Ubuntu 20.10, and Manjaro 20.2.1 Your mileage may vary when using other OSes. 
 If you manage to get this running on a distro that isn't Ubuntu or Manjaro, open a PR that edits this README
 with instructions!
