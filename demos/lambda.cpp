#include <stdio.h>

#include <functional>
auto nextIdMaker(unsigned seed) {
  unsigned init_id = seed;
  auto nextId = [&init_id](unsigned inc) {
    init_id += inc;
    return init_id;
  };
  return nextId;
}
using NextIdFn = std::function<unsigned(unsigned)>;

int f2(NextIdFn nextId) {
  int arr[] = {1, 2, 3, 4, 5};
  unsigned arr_len = sizeof(arr) / sizeof(int);
  int sum = 0;
  for (int i = 0; i < arr_len; i++) {
    sum += i;
  }
  printf("21=%d\n", nextId(4));
  return sum;
}

int main() {
  auto nextId = nextIdMaker(17);
  return f2(nextId);
}