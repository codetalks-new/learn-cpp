#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cout;
using std::deque;
using std::endl;
using std::make_unique;
using std::string;
using std::unique_ptr;
using std::vector;
/*
8, 2, 5, 4, 3, 9, 7, 2, 5
0, 1, 2, 3, 4, 5, 6, 7, 8
unmatch_indexes:
[0,1]  [1] = 5
  [0,2]
  [0,2, 3]
  [0,2, 3, 4] [4] = 9, [3] = 9,[2]  =[9], [0] = 9
  [5,6,7] [7] = 5
  [5,6,8]






*/

vector<int> nextGreaterNums(vector<int> nums) {
  vector<int> result(nums.size(), -1);  // N -1
  vector<int> indexes{0};               // unmached indexes
  for (int i = 1; i < nums.size(); i++) {
    int num = nums[i];
    while (!indexes.empty() && nums[indexes.back()] < num) {
      int previ = indexes.back();
      result[previ] = num;
      indexes.pop_back();
    }
    indexes.push_back(i);
  }
  return result;
}

TEST(MonoStackTestSuite, GreaterNumTestCase) {
  vector<int> r1{5, 6, 6, 8, 8, 9, 10, -1};
  EXPECT_EQ(nextGreaterNums({1, 5, 3, 6, 4, 8, 9, 10}), r1);

  vector<int> r2{9, 5, 9, 9, 9, -1, -1, 5, -1};
  EXPECT_EQ(nextGreaterNums({8, 2, 5, 4, 3, 9, 7, 2, 5}), r2);

  vector<int> r3{13, 21, 12, 12, 21, -1, -1};
  EXPECT_EQ(nextGreaterNums({11, 13, 10, 5, 12, 21, 3}), r3);
}

class MinStack {
 private:
  struct Element {
    int value;
    int curMin;
  };
  vector<Element> stack;

 public:
  MinStack() {}

  void push(int x) {
    Element e{x, x};
    if (!stack.empty()) {
      int prevMin = stack.back().curMin;
      if (prevMin < x) {
        e.curMin = prevMin;
      }
    }
    stack.push_back(e);
  }

  void pop() {
    stack.pop_back();
  }

  int top() {
    return stack.back().value;
  }

  int getMin() {
    return stack.back().curMin;
  }
};

/**
 *
action      min        stack
--------  -------     -----------
push -2   -2          [-2]
push 0    -2          [-2,0]
push -3   -3          [-2,0, -3]
pop       -2          [-2,0]

 */

TEST(MonoStackTestSuite, MinStackTestCase) {
  MinStack obj;
  obj.push(-2);
  obj.push(0);
  obj.push(-3);
  EXPECT_EQ(obj.getMin(), -3);
  obj.pop();
  EXPECT_EQ(obj.top(), 0);
  EXPECT_EQ(obj.getMin(), -2);
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}