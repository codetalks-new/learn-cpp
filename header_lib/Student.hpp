#pragma once
#include <iostream>
#include "Hello.hpp"
using std::cout;

class Student {
 public:
  void sayHello() {
    cout << "I'm Student!\n";
    Hello h;
    h.sayHello();
  }
};