# nanOS
nanOS is a light Operating System written in NASM assembly and C

Every single routine in the nanOS kernel has been written from scratch, from the asm entry point to the kernel drivers, learning is 
the main reason to not using external libraries or resources

## What can it do
Right now, nanOS kernel is bootable using GRUB (or qemu) and launches the C kernel entry point (kmain), after that, it'll take control of
the machine.

io.asm library has been written to interact with hardware level I/O signals

Framebuffer is avaiable to interact with the screen, over this, a simple console I/O controler has been written, implementing the
well known stdio print function and a custom prints function to print text with styles


## Compilation and testing

to compile, you will need make, nasm and gcc.
`$ make`

to run the test you will need qemu
`$ make run`
or load the kernel from grub

## next steps
- file system
- memory management
- memory pagination
- console input
- basic shell (bash-style)
