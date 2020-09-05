#include <new>

#include "Hello.hpp"
#include "Student.hpp"

int main(int argc, char const *argv[]) {
  Student s;
  Hello h;
  s.sayHello();
  h.sayHello();
  return 0;
}
