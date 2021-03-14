CC = gcc
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: loader.o
	ld -T link.ld -melf_i386 loader.o -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	grub-mkrescue -o os.iso iso

run: os.iso
	bochs -f bochsrc.txt -q

loader.o: loader.s
	nasm -f elf32 loader.s 

clean:
	rm -rf *.o kernel.elf os.iso
