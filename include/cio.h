#ifndef H_CIO_C
#define H_CIO_C
#include <drivers/framebuffer.h>

void clear(void);
void putChar(char, unsigned int);
void print(char*);
void prints(char*, unsigned int);

#endif
