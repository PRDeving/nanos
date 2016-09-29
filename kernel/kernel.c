#include <head.h>

#include <drivers/framebuffer.h>

#define FONT_DEFAULT 0x0f
#define FONT_RED_IN_BLACK 0x02

unsigned int CURSOR_X = 0;
unsigned int CURSOR_Y = 0;
unsigned char* video= (unsigned char*)0xb8000;

void clear(void);
void putChar(char, unsigned int);
void print(char*);

void clear(void) {
  CURSOR_X = 0;
  CURSOR_Y = 0;
  while (CURSOR_X < 80 && CURSOR_Y < 25) putChar(' ', FONT_DEFAULT);

  CURSOR_X = 0;
  CURSOR_Y = 0;
}
void putChar(char ch, unsigned int style) {
  if (ch == '\n') {
    CURSOR_Y++;
    CURSOR_X = 0;
  } else {
    unsigned int offset = (CURSOR_Y * 80 + CURSOR_X) * 2;
    video[offset] = ch;
    video[offset + 1] = style;
    CURSOR_X++;
    if (CURSOR_X > 79) {
      CURSOR_Y++;
      CURSOR_X = 0;
    }
  }
}
void print(char* msg) {
  int i = 0;
  while (msg[i]){
    putChar(msg[i], FONT_DEFAULT);
    i++;
  }
}
void prints(char* msg, unsigned int style) {
  int i = 0;
  while (msg[i]) {
    putChar(msg[i], style);
    i++;
  }
}

void kmain() {
  clear();
  print("nanOS v0.0.1 - kernel v0.0.1\n\n");
  print("Bootstraping system ["); prints("OK", 0x02); print("]");
}
