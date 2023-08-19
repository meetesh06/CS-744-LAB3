#include "types.h"
#include "stat.h"
#include "user.h"

char buf;

void head(int fd, int numLines) {

  int linesPrinted = 0;
  int n;
  while((n = read(fd, &buf, sizeof(buf))) > 0) {
    if (buf == '\n') linesPrinted++;
    if (write(1, &buf, n) != n) {
      printf(1, "head: write error\n");
      exit();
    }
    if (linesPrinted == numLines) break;
  }
  if(n < 0){
    printf(1, "head: read error\n");
    exit();
  }
}

void printUsage() {
  printf(1,"USAGE: head <num-lines> [file1] [file2] ...\n");
  exit();
}

int checkPositiveInt(char num[]) {
  if (num[0] == '-') return 0;
  for (int i = 1; num[i] != 0; i++) {
    if (num[i] > '9' || num[i] < '0')
      return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int fd, i;
  if(argc <= 2) {
    printUsage();
  }

  if (!checkPositiveInt(argv[1])) {
    printUsage();
  }

  int numLines = atoi(argv[1]);

  for(i = 2; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "head: cannot open %s\n", argv[i]);
      exit();
    }
    printf(1, "-----%s-----\n", argv[i]);
    head(fd, numLines);
    close(fd);
  }
  exit();
}
