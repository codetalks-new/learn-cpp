#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int maxSubArraySum(vector<int> nums) {
  int maxSum = nums[0];
  // int N = nums.size();
  // vector<int> sums(N + 1, 0);
  // for (int i = 1; i < N + 1; i++) {
  //   int num = nums[i - 1];
  //   sums[i] = sums[i - 1] + num;
  // }
  // // O(N*N)
  // //
  // for (int i = 0; i < N + 1; i++) {
  //   for (int j = i + 1; j < N + 1; j++) {
  //     int subArraySum = sums[j] - sums[i];
  //     maxSum = subArraySum > maxSum ? subArraySum : maxSum;
  //   }
  // }
  int curSum = 0;
  for (int num : nums) {
    if (curSum < 0) {
      curSum = num;
    } else {
      curSum += num;
    }
    maxSum = curSum > maxSum ? curSum : maxSum;
  }

  return maxSum;
}
//-2, 1, -3, 4, 2, 2, -1, -5, 4
//-2, -1,-4, 0, 2, 4,3, -2, 2

TEST(DemoTestSuite, DemoTestCase) {
  EXPECT_EQ(maxSubArraySum({-1}), -1);
  EXPECT_EQ(maxSubArraySum({-1, 0, -2}), 0);
  EXPECT_EQ(maxSubArraySum({-2, 1}), 1);
  EXPECT_EQ(maxSubArraySum({-2, 1, -3, 4, 2, 2, -1, -5, 4}), 8);
  EXPECT_EQ(maxSubArraySum({-2, 9, -6, 4, 2, 2, -1, -5, 4}), 11);
}
GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}