#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

TEST(DemoTestSuite, DemoTestCase) {
  EXPECT_EQ(2020, 2020);
  string s1("abc");
  string s2("abc");
  // EXPECT_STREQ(string("abc"), StrE);
}
GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}