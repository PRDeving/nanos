global loader
[bits 32]

extern kmain

MAGIC_NUMBER equ 0x1BADB002
FLAGS equ 0x0
CHECKSUM equ -MAGIC_NUMBER
KERNEL_STACK_SIZE equ 4096

section .bss
align  4
	resb KERNEL_STACK_SIZE

section .text:
align 4
	dd MAGIC_NUMBER
	dd FLAGS
	dd CHECKSUM

loader:
	mov esp, 0x9000 - KERNEL_STACK_SIZE
	call kmain
.loop:
		jmp .loop
