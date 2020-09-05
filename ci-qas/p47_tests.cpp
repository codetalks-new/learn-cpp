#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int maxGiftValue(vector<vector<int>> grid) {
  int N = grid.size();
  int M = grid[0].size();
  for (int c = 1; c < M; c++) {
    grid[0][c] += grid[0][c - 1];
  }
  for (int r = 1; r < N; r++) {
    grid[r][0] += grid[r - 1][0];
  }
  for (int r = 1; r < N; r++) {
    for (int c = 1; c < M; c++) {
      grid[r][c] += std::max(grid[r][c - 1], grid[r - 1][c]);
    }
  }
  return grid[N - 1][M - 1];
}
/**

[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

*/

TEST(DemoTestSuite, DemoTestCase) {
  int res = maxGiftValue({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
  EXPECT_EQ(res, 12);
}
GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}