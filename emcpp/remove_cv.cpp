#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <type_traits>
using std::cout;
using std::endl;
using std::is_same;
using std::string;

template <typename T>
struct remove_const {
  typedef T type;
};
template <typename T>
struct remove_const<const T> {
  typedef T type;
};

template <typename T>
using remove_const_t = typename remove_const<T>::type;

TEST(DemoTestSuite, DemoTestCase) {
  auto v = is_same<int, remove_const_t<const int>>::value;
  EXPECT_TRUE(v);
}
GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}