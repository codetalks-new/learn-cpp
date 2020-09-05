#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int max(vector<int> nums) {
  int max = INT_MIN;
  for (int num : nums) {
    if (num > max) {
      max = num;
    }
  }
  return max;
}

int the_2st(vector<int> nums) {
  int max = INT_MIN;
  int second = INT_MIN;
  for (int num : nums) {
    if (num > max) {
      second = max;
      max = num;
    } else if (num > second && num < max) {
      second = num;
    }
  }
  return second;
}

TEST(KthNumTestSuite, the2st) {
  EXPECT_EQ(the_2st({1, 2, 3}), 2);
  EXPECT_EQ(the_2st({1, 2, 3, 3}), 2);
  EXPECT_EQ(the_2st({4, 4, 3, 2, 1}), 3);
  EXPECT_EQ(the_2st({4, 5, 6, 7, 3, 2}), 6);
}

int the_3st(vector<int> nums) {
  int max = INT_MIN;
  int second = INT_MIN;
  int third = INT_MIN;
  for (int num : nums) {
    if (num > max) {
      third = second;
      second = max;
      max = num;
    } else if (num > second && num < max) {
      third = second;
      second = num;
    } else if (num > third && num < second) {
      third = num;
    }
  }
  return third;
}

TEST(KthNumTestSuite, the3st) {
  EXPECT_EQ(the_3st({1, 2, 3}), 1);
  EXPECT_EQ(the_3st({1, 2, 3, 3}), 1);
  EXPECT_EQ(the_3st({4, 4, 3, 2, 1}), 2);
  EXPECT_EQ(the_3st({4, 5, 6, 7, 3, 2}), 5);
  EXPECT_EQ(the_3st({1, 2, -2147483648}), -2147483648);
}

int kth_pq(vector<int> nums, int k) {
  assert(nums.size() >= k);
  std::priority_queue<int, vector<int>, std::greater<int>> pq;
  for (int num : nums) {
    pq.push(num);
    if (pq.size() > k) {
      pq.pop();
    }
  }
  return pq.top();
}

// `8 1 10 5 4 2 3 7 6 9 `
// 1  8 10 5 4 2 3 7 6 9
//
inline void swap(vector<int>& nums, int i, int j) {
  int tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

int partition(vector<int>& nums, int lo, int hi, int pivot_value_index) {
  int pivot = nums[pivot_value_index];
  // 先把 pivot 放最右边,以勉后面换来换去
  swap(nums, pivot_value_index, hi);
  int next_lo = lo;

  for (int i = lo; i <= hi; i++) {
    if (nums[i] < pivot) {
      swap(nums, next_lo, i);
      next_lo++;
    }
  }
  swap(nums, next_lo, hi);
  int real_pivot_index = next_lo;
  return real_pivot_index;
}
// 0 1,2,3
//  0,1
int quick_select(vector<int>& nums, int lo, int hi, int k) {
  if (lo == hi) {
    return nums[lo];
  }
  srand(time(NULL));
  int rand_pivot_index = rand() % (hi - lo + 1) + lo;
  int real_pivot_index = partition(nums, lo, hi, rand_pivot_index);
  if (real_pivot_index == k) {
    return nums[k];
  } else if (real_pivot_index > k) {
    // 说明在 左边
    return quick_select(nums, lo, real_pivot_index - 1, k);
  } else {
    // 说明在右边
    return quick_select(nums, real_pivot_index + 1, hi, k);
  }
}

int kth(vector<int> nums, int k) {
  int N = nums.size();
  return quick_select(nums, 0, N - 1, N - k);
}

TEST(KthNumTestSuite, kthNum) {
  EXPECT_EQ(kth({1, 3, 2, 8, 7, 2, 5}, 3), 5);
  EXPECT_EQ(kth({1, 2, 3, 4, 5, 6, 7, 8, 9}, 3), 7);
  EXPECT_EQ(kth({1, 2, 3, 4, 6, 6, 7, 8, 9}, 7), 3);
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}