#include <asm/io.h>

#define CPORT 0x3D4
#define DPORT 0x3D5
#define HBYTE 14
#define LBYTE 15

void move_cursor(unsigned short pos) {
  outb(CPORT, HBYTE);
  outb(DPORT, ((pos >> 8) & 0x00FF));
  outb(CPORT, LBYTE);
  outb(DPORT, pos & 0x00FF);
}

/* unsigned short get_cursor(void) { */
/* } */
