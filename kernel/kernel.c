#include <head.h>
#include <cio.h>
#include <libc/memory.h>

void kmain() {
  clear();
  print("nanOS v0.0.1 - kernel v0.0.1\n");
  print("============================\n\n");
  print("Bootstraping kernel ["); prints("OK", FB_GREEN_IN_BLACK); print("]\n");

  print("\nTesting memory management\n");
  print("...Allocation [");
  int *memtest = malloc(4 * sizeof(int));
  memtest[0] = 4;
  memtest[1] = 3;
  memtest[2] = 2;
  memtest[3] = 1;
  if (memtest[0] == 4 &&
      memtest[1] == 3 &&
      memtest[2] == 2 &&
      memtest[3] == 1) {
    prints("OK", FB_GREEN_IN_BLACK);
  } else {
    prints("FAIL", FB_RED_IN_BLACK);
  }
  print("]\n");

  print("...Data integrity [");
  if (memtest[1] + memtest[2] == 5 &&
      memtest[1] + memtest[3] == 4 &&
      memtest[0] + memtest[1] == 7) {
    prints("OK", FB_GREEN_IN_BLACK);
  } else {
    prints("FAIL", FB_RED_IN_BLACK);
  }
  print("]\n");

  print("...Range [");
  if (memlen(memtest) == (unsigned int)(4 * sizeof(int))) {
    prints("OK", FB_GREEN_IN_BLACK);
  } else {
    prints("FAIL", FB_RED_IN_BLACK);
  }
  print("]\n");

  print("...Resize [");
  realloc(memtest, 2 * sizeof(int));
  if (memlen(memtest) <= (unsigned int)(2 * sizeof(int)) &&
      memtest[0] == 4 &&
      memtest[2] != 2 &&
      !memtest[3] &&
      memtest[1] == 3) {
    prints("OK", FB_GREEN_IN_BLACK);
  } else {
    prints("FAIL", FB_RED_IN_BLACK);
  }
  print("]\n");

  print("...Freeing [");
  free(memtest);
  if (memtest[0] != 4 &&
      memtest[3] != 1 &&
      memtest[1] != 3 &&
      memlen(memtest) == 0) {
    prints("OK", FB_GREEN_IN_BLACK);
  } else {
    prints("FAIL", FB_RED_IN_BLACK);
  }
  print("]\n");
}
