[org 0x7c00]
KERNEL_OFFSET equ 0x1000

	mov [BOOT_DRIVE], dl

	; setup stack
	mov bp, 0x9000
	mov sp, bp

	mov bx, MSG_BOOTSTRAP_INIT
	call print16

	call loadKernel

	call switchProtected32

	jmp $

[bits 16]
; print16:
	

loadKernel:
	mov bx, MSG_KERNEL_INIT
	call print16

	mov bx, KERNEL_OFFSET
	mov dh, 15 ;15 sectors
	mov dl, [BOOT_DRIVE]
	call loadFromDisk
	ret

[bits 32]
switchProtected32:
	mov ebx, MSG_KERNEL_LOAD
	call print32
	call KERNEL_OFFSET


BOOT_DRIVE db 0
MSG_BOOTSTRAP_INIT db "Starting 16bit bootstrap", 0
MSG_KERNEL_INIT db "Starting kernel loading", 0
MSG_KERNEL_LOAD db "Launching kernel", 0

; Set as bootable
times 510-($-$$) db 0
dw 0xaa55
