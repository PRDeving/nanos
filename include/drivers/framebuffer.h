#ifndef H_FRAMEBUFFER_C
#define H_FRAMEBUFFER_C

#include <asm/io.h>
#define FB_DEFAULT 0x0f
#define FB_GREEN_IN_BLACK 0x02
#define FB_RED_IN_BLACK 0x04

void move_cursor_to(int, int);
void cursor_next(void);
void cursor_next_line(void);
unsigned short get_cursor(void);
unsigned short pos_to_cursor(int, int);

#endif
