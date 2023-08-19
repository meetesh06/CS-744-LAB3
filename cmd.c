#include "types.h"
#include "stat.h"
#include "user.h"

void printUsage() {
  printf(1,"USAGE: cmd <program-to-run>\n");
  exit();
}

int main(int argc, char *argv[]) {
  if (argc != 2) printUsage();
  int child = fork();
  if (child == 0) {
    // Child Process
    printf(1, "Child created\n");
    exec(argv[1], (argv + 1));
  } else {
    // Parent Process
    wait(); // Wait for the child to exit
    printf(1, "Parent: child created and waited for child to exit\n");
  }
  return 0;
}
