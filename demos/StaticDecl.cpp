
#include <gtest/gtest.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Demo
{
public:
  static int callMethod();
};

int Demo::callMethod()
{
  return 2020;
}
TEST(DemoTestSuite, DemoTestCase)
{
  EXPECT_EQ(2020, Demo::callMethod());
}

GTEST_API_ int main(int argc, char *argv[])
{
  printf("Running main() from %s ", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
