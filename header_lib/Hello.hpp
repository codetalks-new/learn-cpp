#pragma once
#include <iostream>
using std::cout;

const char* log_buffer;
class Hello {
 public:
  void sayHello() {
    cout << "Hello Header Lib!\n";
  }
};