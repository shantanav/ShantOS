# Variables
SRC := src
OBJ := exec
LOG := log

# C Stuff
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
     -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
CSRC := $(wildcard $(SRC)/*.c)

# Assembly Compiler Stuff
AS = nasm
ASFLAGS = -f elf
ASSRC := $(wildcard $(SRC)/*.s)

# Linker
COBJ := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CSRC))
ASOBJ := $(patsubst $(SRC)/%.s, $(OBJ)/%.o, $(ASSRC))
LDFLAGS = -T $(OBJ)/link.ld -melf_i386

all: $(OBJ)/kernel.elf $(COBJ) $(ASOBJ)

$(OBJ)/kernel.elf: $(COBJ) $(ASOBJ)
	ld $(LDFLAGS) $(COBJ) $(ASOBJ) -o $(OBJ)/kernel.elf

ShantOS.iso: $(OBJ)/kernel.elf
	cp $(OBJ)/kernel.elf iso/boot/kernel.elf
	grub-mkrescue -o ShantOS.iso iso

run: ShantOS.iso
	bochs -f $(OBJ)/bochsrc.txt -q

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -I$(SRC) $(CFLAGS)  $< -o $@

$(OBJ)/%.o: $(SRC)/%.s
	$(AS) -I$(SRC) $(ASFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)/*.o ShantOS.iso $(OBJ)/kernel.elf $(LOG)/bochslog.txt $(LOG)/com1.out

