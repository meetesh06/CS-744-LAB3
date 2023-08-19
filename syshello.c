#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

#include "defs.h"

int sys_helloYou(void) {
  char *data;
  if (argstr(0, &data) < 0) {
    return -1;
  }
  cprintf(data);
  return 0;
}
