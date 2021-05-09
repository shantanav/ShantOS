# Directories
SRC := src
OBJ := exec
ASM := $(SRC)/asm

# C Stuff
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
     -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
CSRC := $(wildcard $(SRC)/*.c)

# Assembly Compiler Stuff
AS = nasm
ASFLAGS = -f elf
ASSRC := $(wildcard $(ASM)/*.s)

# Linker
COBJ := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CSRC))
ASOBJ := $(patsubst $(ASM)/%.s, $(OBJ)/%.o, $(ASSRC))
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

$(OBJ)/%.o: $(ASM)/%.s
	$(AS) -I$(ASM) $(ASFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)/*.o ShantOS.iso $(OBJ)/kernel.elf \
		$(OBJ)/bochslog.txt $(OBJ)/com1.out

