#include <cio.h>

unsigned char* video = (unsigned char*)0xb8000;

void clear(void) {
  move_cursor_to(0, 0);
  while (get_cursor() < 79 * 24) putChar(' ', FB_DEFAULT);
  move_cursor_to(0, 0);
}
void putChar(char ch, unsigned int style) {
  if (ch == '\n') {
    cursor_next_line();
  } else {
    unsigned int offset = get_cursor();
    video[offset] = ch;
    video[offset + 1] = style;
    cursor_next();
  }
}
void print(char* msg) {
  int i = 0;
  while (msg[i]){
    putChar(msg[i], FB_DEFAULT);
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
