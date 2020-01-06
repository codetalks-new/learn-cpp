#include <atomic>
#include <iostream>
#include <string>
using std::atomic;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  atomic<int> ai1{3};
  atomic<int> ai2(2);
  atomic<int> ai3 = 5;

  double x = 3, y = 4;
  int z{x + y};
  return z;
}