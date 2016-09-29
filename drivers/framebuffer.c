#include <drivers/framebuffer.h>

#define CPORT 0x3D4
#define DPORT 0x3D5
#define HBYTE 14
#define LBYTE 15

unsigned int FB_CURSOR_X = 0;
unsigned int FB_CURSOR_Y = 0;

unsigned short pos_to_cursor(int x, int y) {
  return (y * 80) + x;
}

void move_cursor_to (int x, int y) {
  unsigned short pos = pos_to_cursor(x, y);
  outb(CPORT, HBYTE);
  outb(DPORT, ((pos >> 8) & 0x00FF));
  outb(CPORT, LBYTE);
  outb(DPORT, pos & 0x00FF);
  FB_CURSOR_X = x;
  FB_CURSOR_Y = y;
}

void cursor_next(void) {
  FB_CURSOR_X++;
  if (FB_CURSOR_X > 79) {
    FB_CURSOR_Y++;
    FB_CURSOR_X = 0;
  }
  move_cursor_to(FB_CURSOR_X, FB_CURSOR_Y);
}

void cursor_next_line(void) {
  FB_CURSOR_Y++;
  FB_CURSOR_X = 0;
  move_cursor_to(FB_CURSOR_X, FB_CURSOR_Y);
}

unsigned short get_cursor(void) {
  return ((FB_CURSOR_Y * 80) + FB_CURSOR_X) * 2;
}
