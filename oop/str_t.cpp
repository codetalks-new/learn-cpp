#include <cstdint>
#include <iostream>

using namespace std;

class str_t {
 private:
  size_t _len{0};
  u_char *_data{nullptr};

 public:
  str_t(const u_char *data, size_t len) : _data(data), _len(len) {}
  operator bool() {
    return this->_len > 0 && this->_data != nullptr;
  }
  size_t len() const noexcept {
    return this->_len;
  }
  const u_char *data() const noexcept {
    return this->_data;
  }
};
template <size_t N>
constexpr str_t make_str_t(char(&) text[N]) {
  str_t str((u_char *)text, N - 1);
  return str;
}

int main(int argc, char const *argv[]) {
  str_t abc = make_str_t("abc");
  cout << abc.len();
  return 0;
}
