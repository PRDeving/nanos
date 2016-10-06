#include <libc/memory.h>

unsigned char* _libc_find_empty_block(size_t size) {
  unsigned char *mem = (unsigned char*)MEM_START;
  unsigned int i = 0;
  while (i++) {
    if(mem[i]) {
      continue;
    } else if(i == 0 || mem[i - 1] == (unsigned char)PADDING_BLOCK){
      unsigned int b = 0;
      while (b++ < size) {
        if (mem[i + b]) {
          i += b;
          break;
        }
      }
      if (b == size) return (unsigned char*)(MEM_START + i);
      else i += b;
    };
  }
  return (unsigned char*)MEM_ERROR;
}

unsigned int memlen(void* ptr) {
  unsigned int count = 1;
  unsigned char* p = (unsigned char*)ptr;
  if (p[0] == (unsigned char)FREE_BLOCK) return 0;
  while (p[count + 1] != (unsigned char)PADDING_BLOCK) count++;
  return count;
}

void* malloc(size_t size) {
  unsigned char* free_block = _libc_find_empty_block(size);
  size_t i = 0;
  while (i < size) {
    free_block[i] = (unsigned char)RESERVED_BLOCK;
    i++;
  }
  free_block[i + 1] = (unsigned char)PADDING_BLOCK;
  return free_block;
}

void* realloc(void* ptr, size_t size) {
  unsigned char* p = (unsigned char*)ptr;
  size_t l = memlen(ptr);
  p[size] = (unsigned char)PADDING_BLOCK;
  while (size++ < l) {
    p[size] = (unsigned char)FREE_BLOCK;
  }
  ptr = p;
  return (void*)p;
}

void free(void* ptr) {
  unsigned char* p = (unsigned char*)ptr;
  unsigned int len = memlen(ptr);
  unsigned int i = 0;
  while (i < len) {
    p[i] = (unsigned char)FREE_BLOCK;
    i++;
  }
  p[len] = (unsigned char)FREE_BLOCK;
}
