#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <set>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

int singleNumber(vector<int> nums) {
  int ans = 0;
  for (int num : nums) {
    ans ^= num;
  }
  return ans;
}

vector<int> singleNumber2(vector<int> nums) {
  int ab = 0;  // value of a^b
  for (int num : nums) {
    ab ^= num;
  }
  int group1_flag = ab & (~(ab & (ab - 1)));
  int a = 0;
  for (int num : nums) {
    if (num & group1_flag) {
      a ^= num;
    }
  }
  int b = ab ^ a;
  if (a > b) {
    return {b, a};
  } else {
    return {a, b};
  }
}

TEST(NumCountTestSuite, SingleNumberTestCase) {
  EXPECT_EQ(singleNumber({2, 2, 1}), 1);
  EXPECT_EQ(singleNumber({4, 1, 2, 1, 2}), 4);
}

TEST(NumCountTestSuite, SingleNumber2TestCase) {
  vector<int> s1{1, 3};
  EXPECT_EQ(singleNumber2({2, 2, 1, 3}), s1);
  vector<int> s2{3, 5};
  EXPECT_EQ(singleNumber2({1, 2, 1, 3, 2, 5}), s2);
}

int singleNumber3(vector<int> nums) {
  int ones = 0, twos = 0;
  for (int num : nums) {
    ones = (ones ^ num) & ~twos;
    twos = (twos ^ num) & ~ones;
  }
  return ones;
}

TEST(NumCountTestSuite, SingleNumber3TestCase) {
  EXPECT_EQ(singleNumber3({2, 2, 2, 1}), 1);
  EXPECT_EQ(singleNumber3({2, 2, 2, 3}), 3);
  EXPECT_EQ(singleNumber3({4, 1, 1, 2, 2, 1, 2}), 4);
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}