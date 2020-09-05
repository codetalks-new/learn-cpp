#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
/// 一个简单的固定长度的自定义字符串类型
template <int N = 32>
class TinyStr {
 private:
  size_t _size;
  char _chars[N + 1];

 public:
  size_t length() const {
    return this->_size;
  }
  TinyStr() {
    printf("TinyStr default Ctor called\n");
    memset(_chars, '\0', N + 1);
    _size = 0;
  }

  TinyStr(const char* str) {
    printf("TinyStr char* Ctor called\n");
    const size_t new_size = strnlen(str, N);
    memcpy(_chars, str, new_size);
    _chars[new_size] = '\0';
    _size = new_size;
  }
  template <int K>
  TinyStr(TinyStr<K>& str) {
    printf("TinyStr Copy Ctor called\n");
    *this = str;
  }
  template <int K>
  TinyStr<N>& operator=(TinyStr<K>& str) {
    printf("TinyStr Assign operator called\n");
    if ((void*)this != (void*)&str) {
      const size_t new_size = (N < K ? N : K);
      memcpy(_chars, str.c_str(), new_size);
      _size = new_size;
      _chars[new_size] = '\0';
    }
    return *this;
  }

  const char* const c_str() const {
    return _chars;
  }
};

struct Str {
  char chars[32];

  Str() {
    printf("[执行] Str 默认构造函数\n");
  }
  Str(const char* str) {
    printf("[执行] Str char* 构造函数\n");
  }
  Str(const Str& str) {
    printf("[执行] Str 拷贝构造函数\n");
  }
  Str(Str&& str) : chars(std::move(str.chars)) {
    printf("[执行] Str 拷贝构造函数\n");
  }
  Str& operator=(const Str& str) {
    printf("[执行] Str 赋值运行符重载函数\n");
    return *this;
  }
};

struct Student {
  int age;
  Str name;

  Student(const char* name, int age) : age(age), name(name) {}
};

int main(int argc, char const* argv[]) {
  Student lilei("Li Lei", 18);
}
