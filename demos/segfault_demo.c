#include <malloc/malloc.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main(int argc, char const *argv[]) {
  char *p1 = malloc(1);
  char **p = environ;
  while (*p) {
    printf("%s\n", *p);
    p++;
  }
}
