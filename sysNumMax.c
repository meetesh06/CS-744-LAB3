#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

#include "defs.h"

int sys_getNumProc(void) {
  struct proc * ptabproc = getPtableProc();
  int numProcesses = 0;
  for(struct proc *p = ptabproc; p < (ptabproc+NPROC); ++p){
    if(p->state > UNUSED) ++numProcesses; 
  }
  return numProcesses;
}

int sys_getMaxPid(void) {
  struct proc * ptabproc = getPtableProc();
  int maxpid = 0;
  for(struct proc *p = ptabproc; p < (ptabproc+NPROC); ++p){
    if(p->pid > maxpid) maxpid = p->pid; 
  }
  return maxpid;
}
