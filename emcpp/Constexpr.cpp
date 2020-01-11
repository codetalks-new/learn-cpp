
constexpr int pow(int base, int exp) noexcept {
  auto result = 1;
  for (int i = 0; i < exp; i++) result *= base;
  return result;
}

auto num1 = pow(2, 6);
int main(int argc, char const *argv[]) {
  constexpr auto num2 = pow(2, 5);
  auto num3 = pow(2, 4);
  return num1 - num2 - num3;
}