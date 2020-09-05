#include <stdio.h>

int main(int argc, char const *argv[]) {
  int cnt = 0;
  int var;
  while (1) {
    int res = scanf("%d", &var);
    printf("%d %d\n", cnt, var);
    cnt++;
  }

  return 0;
}