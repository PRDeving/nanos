all: boot/boot.bin

%.o: %.c
	gcc -std=c86 -ffreestanding -c $< -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm **/*.o **/*.bin

run:
	qemu-system-i386 boot/boot.bin
