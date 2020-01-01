#include <iostream>
class Uncopyable {
 protected:
  constexpr Uncopyable() = default;
  ~Uncopyable() = default;

  Uncopyable(const Uncopyable &) = delete;
  Uncopyable &operator=(const Uncopyable) = delete;
};

struct Big : private Uncopyable {
  Big() {}

  void someMemberFun() {
    Big tmp;
    Big tmp2(tmp);
  }
};

int main(int argc, char const *argv[]) {
  Big b1;

  return 0;
}
