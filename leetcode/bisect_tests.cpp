#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

/// 在 从小到大排序 好的 nums 中搜索适合插入 x 的位置.
int search_ints(vector<int> nums, int x) {
  int lo = 0;
  int hi = nums.size();  // 1) 细节 1: hi 取的是 nums.size()
  while (lo < hi) {      //  2) 细节 2: 循环条件变成了 lo < hi
    int mid = lo + (hi - lo) / 2;
    if (x > nums[mid]) {
      lo = mid + 1;
    } else {
      // 3) 细节 3: hi 不再变成 mid -1, 而只是 mid
      // 为了在相等的时候再尝试继续向左走.
      hi = mid;
    }
  }
  return hi;  // lo == hi
}

TEST(BinarySearchTestSuite, SearchInts) {
  EXPECT_EQ(search_ints({}, 1), 0);
  EXPECT_EQ(search_ints({0}, 1), 1);
  EXPECT_EQ(search_ints({1}, 0), 0);
  EXPECT_EQ(search_ints({0, 1}, 2), 2);
  EXPECT_EQ(search_ints({0, 1, 2}, 3), 3);

  EXPECT_EQ(search_ints({2, 2}, 2), 0);
  EXPECT_EQ(search_ints({1, 2, 2}, 2), 1);
  EXPECT_EQ(search_ints({1, 2, 2, 3}, 2), 1);
}

/// 在 从小到大排序 好的 nums 中搜索适合插入 x 的位置.
int search_ints_right(vector<int> nums, int x) {
  int lo = 0;
  int hi = nums.size();  // 1) 细节 1: hi 取的是 nums.size()
  while (lo < hi) {      //  2) 细节 2: 循环条件变成了 lo < hi
    int mid = lo + (hi - lo) / 2;
    if (x >= nums[mid]) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return hi;  // lo == hi
}

TEST(BinarySearchTestSuite, SearchIntsRight) {
  EXPECT_EQ(search_ints_right({}, 1), 0);
  EXPECT_EQ(search_ints_right({0}, 1), 1);
  EXPECT_EQ(search_ints_right({1}, 0), 0);
  EXPECT_EQ(search_ints_right({0, 1}, 2), 2);
  EXPECT_EQ(search_ints_right({0, 1, 2}, 3), 3);

  EXPECT_EQ(search_ints_right({2, 2}, 2), 2);
  EXPECT_EQ(search_ints_right({1, 2, 2}, 2), 3);
  EXPECT_EQ(search_ints_right({1, 2, 2, 3}, 2), 3);
}

/// 使用二分查找,在 nums 中查找目标值 target 所在的位置索引.
/// 如果找不到返回 -1
int bsearch(vector<int> nums, int target) {
  int lo = search_ints(nums, target);
  if (lo != nums.size() && nums[lo] == target) {
    return lo;
  }
  return -1;
}

TEST(BinarySearchTestSuite, bsearch_base) {
  EXPECT_EQ(bsearch({0, 1, 2, 3, 4, 5}, 6), -1);
  EXPECT_EQ(bsearch({0, 1, 2, 3, 4, 5}, 7), -1);
  EXPECT_EQ(bsearch({0, 1, 2, 3, 4, 5}, 0), 0);
  EXPECT_EQ(bsearch({0, 1, 2, 3, 4, 5}, 1), 1);
  EXPECT_EQ(bsearch({0, 1, 2, 3, 4, 5}, 2), 2);
  EXPECT_EQ(bsearch({0, 1, 2, 3, 4, 5}, 3), 3);
  EXPECT_EQ(bsearch({0, 1, 2, 3, 4, 5}, 4), 4);
  EXPECT_EQ(bsearch({0, 1, 2, 3, 4, 5}, 5), 5);

  EXPECT_EQ(bsearch({}, 1), -1);
  EXPECT_EQ(bsearch({0}, 1), -1);
  EXPECT_EQ(bsearch({1}, 1), 0);
  EXPECT_EQ(bsearch({1, 2}, 1), 0);
  EXPECT_EQ(bsearch({1, 2}, 2), 1);
  EXPECT_EQ(bsearch({1, 2}, 3), -1);
}

bool find_lt(vector<int> nums, int x, int& out) {
  int i = search_ints(nums, x);
  if (i > 0) {
    out = nums[i - 1];
    return true;
  }
  return false;
}
bool find_le(vector<int> nums, int x, int& out) {
  int i = search_ints_right(nums, x);
  if (i > 0) {
    out = nums[i - 1];
    return true;
  }
  return false;
}

bool find_gt(vector<int> nums, int x, int& out) {
  int i = search_ints_right(nums, x);
  if (i != nums.size()) {
    out = nums[i];
    return true;
  }
  return false;
}
bool find_ge(vector<int> nums, int x, int& out) {
  int i = search_ints(nums, x);
  if (i != nums.size()) {
    out = nums[i];
    return true;
  }
  return false;
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}