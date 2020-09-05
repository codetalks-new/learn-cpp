#include <stdio.h>

struct Base {
  int a;
  void f1() {
    printf("Base,%d\n", a);
  }
};

struct Demo : Base {
  Demo() {
    this->a = 3;
  }
  virtual void f1() {
    printf("Demo, %d\n", a);
  }
};

int main(int argc, char const *argv[]) {
  Base *b = new Demo();
  b->f1();
  return 0;
}
