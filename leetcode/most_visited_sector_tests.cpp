#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<int> mostVisited(int n, vector<int> rounds) {
  int R = rounds.size();
  vector<int> counts(n + 1, 0);
  counts[rounds[0]] += 1;
  for (int i = 0; i < R - 1; i++) {
    int start = rounds[i];
    int end = rounds[i + 1];
    if (start <= end) {
      for (int r = start + 1; r <= end; r++) {
        counts[r] += 1;
      }
    } else {
      for (int r = start + 1; r <= n; r++) {
        counts[r] += 1;
      }
      for (int r = 1; r <= end; r++) {
        counts[r] += 1;
      }
    }
  }
  // std::sort(counts.begin(), counts.end(), std::greater<int>());
  int MAX = *std::max_element(counts.begin(), counts.end());
  printf("MAX = %d\n", MAX);
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (counts[i] == MAX) {
      ans.push_back(i);
    }
  }
  return ans;
}

TEST(DemoTestSuite, MostVisitedTestCase) {
  vector<int> r1{1, 2};
  EXPECT_EQ(mostVisited(4, {1, 3, 1, 2}), r1);
  vector<int> r2{2};
  EXPECT_EQ(mostVisited(2, {2, 1, 2, 1, 2, 1, 2, 1, 2}), r2);
  vector<int> r3{1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(mostVisited(7, {1, 3, 5, 7}), r3);
}

int maxCoins(vector<int> piles) {
  int N3 = piles.size();
  int N = N3 / 3;
  int max = 0;
  int index = 1;
  std::sort(piles.begin(), piles.end(), std::greater<int>());
  for (int i = 0; i < N; i++) {
    max += piles[index];
    index += 2;
  }
  return max;
}

TEST(DemoTestSuite, MaxCoinsTestCase) {
  EXPECT_EQ(maxCoins({2, 4, 1, 2, 7, 8}), 9);
  EXPECT_EQ(maxCoins({2, 4, 5}), 4);
  EXPECT_EQ(maxCoins({9, 8, 7, 6, 5, 1, 2, 3, 4}), 18);
}

int findLatestStep(vector<int> arr, int m) {}

TEST(DemoTestSuite, FindLatestStepTestCase) {
  EXPECT_EQ(findLatestStep({3, 5, 1, 2, 4}, 1), 4);
  EXPECT_EQ(findLatestStep({3, 5, 1, 2, 4}, 2), -1);
  EXPECT_EQ(findLatestStep({1}, 1), 1);
  EXPECT_EQ(findLatestStep({2, 1}, 2), 2);
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}