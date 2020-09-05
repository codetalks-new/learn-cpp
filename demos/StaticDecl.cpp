
#include <gtest/gtest.h>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Demo {
  static int counter = 0;

 public:
  Demo() {
    counter += 1;
  }
  int getCounter() {
    return counter;
  }
  static int resetCounter() {
    counter = 0;
    return counter;
  }
};

int nextId() {
  static int id = 0;
  id += 1;
  return id;
}

TEST(DemoTestSuite, DemoTestCase) {
  EXPECT_EQ(1, nextId());
  EXPECT_EQ(2, nextId());
  EXPECT_EQ(3, nextId());
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s ", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
