#include <stdio.h>

class Demo
{
public:
  static void *callMethod(void *arg);
};

void *Demo::callMethod(void *arg)
{
  printf("CallMethod \n");
  return NULL;
}

int main(int argc, char const *argv[])
{
  Demo::callMethod(NULL);
  return 0;
}
