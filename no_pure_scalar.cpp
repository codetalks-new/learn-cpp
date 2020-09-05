#include <stdint.h>

#include <cstdio>
#include <ostream>
#include <string>

namespace rmb {
using std::string;
using std::to_string;
struct Fen {
  int64_t value;
};
Fen halfPrice(Fen price) {
  return {.value = price.value / 2};
}
Fen yuan(int64_t yuan) {
  return {.value = yuan * 100};
}
Fen yuan(double yuan) {
  return {.value = static_cast<int64_t>(yuan * 100)};
}
Fen yuan(string yuan) {
  int doti = yuan.find_last_of('.');
  if (doti == string::npos) {
    return {.value = atoll(yuan.c_str())};
  }
  string yuan_part = yuan.substr(0, doti);
  string fen_part = yuan.substr(doti + 1);
  int64_t value = atoll(yuan_part.c_str()) * 100 + atoll(fen_part.c_str());
  return {.value = value};
}

string fmt_fen(Fen fen) {
  int64_t yuan = fen.value / 100;
  int64_t remain_fen = fen.value % 100;
  return to_string(yuan) + "." + to_string(remain_fen);
}

std::ostream &operator<<(std::ostream &os, Fen fen) {
  os << fmt_fen(fen);
}

Fen operator+(Fen lhs, Fen rhs) {
  return {.value = lhs.value + rhs.value};
}
Fen operator-(Fen lhs, Fen rhs) {
  return {.value = lhs.value - rhs.value};
}
Fen &operator+=(Fen &lhs, Fen rhs) {
  lhs.value = lhs.value + rhs.value;
  return lhs;
};
Fen &operator-=(Fen &lhs, Fen rhs) {
  lhs.value = lhs.value - rhs.value;
  return lhs;
};
bool operator<(Fen lhs, Fen rhs) {
  return lhs.value < rhs.value;
}
bool operator>(Fen lhs, Fen rhs) {
  return lhs.value > rhs.value;
}
bool operator==(Fen lhs, Fen rhs) {
  return lhs.value == rhs.value;
}
// 省略其他重载, c++11 以上可以再添加 constexpr 修饰.

}  // namespace rmb

int main(int argc, char const *argv[]) {
  rmb::Fen price = rmb::yuan("3.14");
  printf("fen=%lld\n", price.value);
}

// namespace rmb {

// }  // namespace rmb
