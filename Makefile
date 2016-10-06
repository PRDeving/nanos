all: kernel.elf

CC=gcc
CC_FLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c

%.o: %.c
	$(CC) $(CC_FLAGS) -Iinclude $< -o $@

%.o: %.asm
	nasm $< -f elf32 -o $@

kernel.elf: boot/boot.o kernel/io.o kernel/libc/memory.o drivers/framebuffer.o kernel/cio.o kernel/kernel.o
	ld -T boot/link.ld -melf_i386 $^ -o $@

build: clean kernel.elf

clean:
	rm **/*.o *.elf

run: build
	qemu-system-i386 -kernel kernel.elf
