#include <stdint.h>

template <uint64_t base, uint64_t exp>
struct Pow {
  enum { Value = base * Pow<base, exp - 1>::Value };
};
template <uint64_t base>
struct Pow<base, 1> {
  enum { Value = base };
};

constexpr int pow(int base, int exp) noexcept {
  auto result = 1;
  for (int i = 0; i < exp; i++) result *= base;
  return result;
}

uint64_t num2_10 = Pow<2, 10>::Value;

auto num1 = pow(2, 6);
int main(int argc, char const *argv[]) {
  constexpr auto num2 = pow(2, 5);
  auto num3 = pow(2, 4);
  return num1 - num2 - num3;
}