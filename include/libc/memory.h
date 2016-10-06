# ifndef H_MEMORY_C
# define H_MEMORY_C

#include <nanos/types.h>

#define MEM_START 0x9001
#define MEM_ERROR 0xE00E

#define FREE_BLOCK 0x00000000
#define RESERVED_BLOCK 0x1337BABA
#define PADDING_BLOCK 0xABAB1337

void* malloc(size_t);
void* realloc(void*, size_t);
void free(void*);
unsigned int memlen(void*);

unsigned char* _libc_find_empty_block(size_t);

# endif
