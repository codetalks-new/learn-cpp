#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Widget {
 private:
  int a;
  vector<int> v1;

 public:
  int b, c, d;
  Widget(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
  const int getA() const {
    return a;
  }

  vector<int>& getV1() {
    return v1;
  }
  auto size() const {
    return v1.size();
  }
};

TEST(SwapSuite, DefaultCopyPrivateFields) {
  Widget w1(1, 2, 3, 4);
  auto v1 = w1.getV1();
  v1.push_back(5);
  v1.push_back(6);
  v1.push_back(7);
  EXPECT_EQ(w1.getV1().front(), 5);
  EXPECT_EQ(w1.size(), 3);

  Widget w2(w1);
  EXPECT_EQ(w2.getA(), 1);
  EXPECT_EQ(w2.b, 2);
  EXPECT_EQ(w2.c, 3);
  EXPECT_EQ(w2.d, 4);
  auto w2v1 = w2.getV1();
  EXPECT_EQ(w2v1.size(), 3);
  EXPECT_EQ(w2v1[0], 5);
}
GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}