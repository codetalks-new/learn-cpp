#include <gtest/gtest.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Widget {
 private:
  int a, b, c;

 public:
  int d;
  Widget(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
  const int getA() const {
    return a;
  }
  const int getB() const {
    return b;
  }
  const int getC() const {
    return c;
  }
};

TEST(SwapSuite, DefaultCopyPrivateFields) {
  Widget w1(1, 2, 3, 4);
  Widget w2(w1);
  EXPECT_EQ(w2.getA(), 1);
  EXPECT_EQ(w2.getB(), 2);
  EXPECT_EQ(w2.getC(), 3);
  EXPECT_EQ(w2.d, 4);
}
GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}