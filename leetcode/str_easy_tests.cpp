#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

string restoreString(string s, vector<int> indices) {
  const int N = indices.size();
  char chars[N + 1];
  for (int i = 0; i < indices.size(); i++) {
    chars[indices[i]] = s[i];
  }
  chars[N] = '\0';
  string ans(chars);
  return ans;
}

TEST(LeetCodeTestSuite, restoreStringTestCase) {
  EXPECT_EQ(restoreString("codeleet", {4, 5, 6, 7, 0, 2, 1, 3}), "leetcode");
}

int minFlips(string target) {}
TEST(LeetCodeTestSuite, minFlipsTestCase) {
  EXPECT_EQ(minFlips("10111"), 3);
  EXPECT_EQ(minFlips("101"), 3);
  EXPECT_EQ(minFlips("00000"), 0);
  EXPECT_EQ(minFlips("001011101"), 5);
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}