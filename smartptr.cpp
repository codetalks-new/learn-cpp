#include <cassert>
#include <cstdint>
#include <cstdio>
#include <utility>

class Buffer {
  char* data;

 public:
  explicit Buffer(size_t len) {
    printf("Buffer()\n");
    data = new char[len];
    data[0] = 'c';
  }
  ~Buffer() {
    printf("~Buffer()\n");
    delete[] data;
  }
  Buffer(const Buffer& buf) {
    printf("Buffer(Buffer&)\n");
  }
  Buffer& operator=(Buffer& buf) {
    printf("Buffer operator=(Buffer&)\n");
    return *this;
  }
  char first() const {
    return data[0];
  }
};

template <typename T>
class unique_ptr {
 private:
  T* _ptr;
  int a;

 public:
  explicit unique_ptr(T* ptr = nullptr) noexcept : _ptr(ptr) {
    printf("unique_ptr()\n");
  }
  ~unique_ptr() noexcept {
    printf("~unique_ptr()\n");
    delete _ptr;
  }
  T* operator->() const noexcept {
    return _ptr;
  }
  T& operator*() const {
    return *_ptr;
  }

  explicit operator bool() const noexcept {
    return _ptr != nullptr;
  }

  T* get() const noexcept {
    return _ptr;
  }

  void reset(T* p = nullptr) {
    _ptr = p;
  }

  T* release() noexcept {
    T* tmp = _ptr;
    _ptr = nullptr;
    return tmp;
  }
  unique_ptr(unique_ptr&& up) noexcept : _ptr(up.release()) {}
  unique_ptr& operator=(unique_ptr&& up) noexcept {
    reset(up.release());
    return *this;
  }
};

unique_ptr<Buffer> readBuffer(size_t packet_size) {
  unique_ptr<Buffer> buf1(new Buffer(packet_size));
  unique_ptr<Buffer> buf2(new Buffer(packet_size * 2));
  if (packet_size < 1024) {
    return buf2;
  } else {
    return buf1;
  }
}

constexpr int arr_len(int nums[]) {
  return sizeof(nums) / sizeof(nums[0]);
}

void print(const char str[]) {
  printf("print %s\n", str);
}

int fun() {
  char hello[] = "abcdefg";
  char* world = "cdefghjk";
  hello = world;

  int arr[8] = {1, 2, 3, 4, 5, 6};
  constexpr int len = sizeof(arr) / sizeof(arr[0]);
  constexpr int len2 = arr_len(arr);
  std::move(hello);
  return len + len2;
}