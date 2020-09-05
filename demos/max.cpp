#include <concepts>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

template <integral T, integral U>
auto max(T a, U b) __attribute__((noinline)) {
  return a < b ? b : a;
}

int main() {
  using std::rand;
  std::srand(std::time(nullptr));
  uint8_t a1 = rand(), b1 = rand();
  int8_t a2 = rand(), b2 = rand();

  auto m1 = max(a1, b1);
  auto m2 = max(a2, b2);
  auto m3 = max(a1, a2);
  auto m4 = max(a2, a1);

  return m1 + m2 + m3 + m4;
}