#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::unique_ptr;
using std::unordered_map;

// 1) typedef vs using
typedef unique_ptr<unordered_map<string, string>> UniPtrStrMap;
using UniPtrStrDict = unique_ptr<unordered_map<string, string>>;
// 2) typedef vs using
typedef void (*FnPtr)(int, const string &);
using FunPtr = void (*)(int, const string &);
// 3) typedef vs using

template <typename T>
struct MyAlloc {
  typedef T value_type;
  MyAlloc() = default;
  T *allocate(size_t n) {
    return nullptr;
  }
  void deallocate(T *p, size_t) {
    free(p);
  }
};

template <typename T>
struct MyList {
  typedef list<T, MyAlloc<T>> type;
};

template <typename T>
struct Widget {
  typename MyList<T>::type list;
};

template <typename T>
using MyList2 = list<T, MyAlloc<T>>;
template <typename T>
struct Widget2 {
  MyList2<T> list;
};

int main(int argc, char const *argv[]) {
  return 0;
}