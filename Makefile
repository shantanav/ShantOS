OBJECTS = loader.o
CC = gcc
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	grub-mkrescue -o os.iso iso

run: os.iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $< -o $@

%.o: %.s
	$(AS) $< -o $@

clean:
	rm -rf *.o kernel.elf os.iso
