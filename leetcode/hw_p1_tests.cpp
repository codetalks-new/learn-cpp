#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
#include <stdint.h>

uint64_t calc_step_comp(int N) {
  uint64_t steps[51] = {0};
  steps[1] = 1;
  steps[2] = 1;
  steps[3] = 2;  // 3| 1 + 1 + 1;
  steps[4] = 3;  // 3+1 | 1 +3 | 1 + 1 + 1+1;
  steps[5] = 4;  // 3+1+1| 1 +3 +1 | 1 + 1 + 3 | 1+1+1+1+1

  if (N < 6) {
    return steps[N];
  }
  for (int n = 5; n < N + 1; n++) {
    steps[n] = steps[n - 3] + steps[n - 1];
  }
  return steps[N];
}

TEST(DemoTestSuite, DemoTestCase) {
  EXPECT_EQ(calc_step_comp(50), 122106097);
}

constexpr const int MUM = -3;
constexpr const int BABY = -2;
constexpr const int STOP = -1;
using Grid = vector<vector<int>>;

struct Result {
  int minSteps{2600};
  int maxCandy{-1};
};
int find_basy_collect_candy(Grid& grid, Result& r, Result cur, int x, int y) {
  int N = grid.size();
  int val = grid[x][y];
  if (val == STOP) {
    return -1;  // path invalid
  }
  if (val == BABY) {
    if (cur.minSteps < r.minSteps) {
      r = cur;
    } else if (cur.minSteps == r.minSteps) {
      r.maxCandy = std::max(cur.maxCandy, r.maxCandy);
    }
    return 0;  // path valid
  }
  // up,down,left,right
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  grid[x][y] = STOP;
  for (int di = 0; di < 4; di++) {
    int nx = x + dx[di];
    int ny = y + dy[di];
    if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
      continue;
    }
    Result next = {cur.minSteps + 1, cur.maxCandy + std::max(0, val)};
    find_basy_collect_candy(grid, r, next, nx, ny);
  }
  grid[x][y] = val;
  return 0;
}
int max_candy(vector<vector<int>> grid) {
  int N = grid.size();
  // 1) find mum pos
  int mi = -1, mj = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == MUM) {
        mi = i;
        mj = j;
        break;
      }
    }
    if (mi != -1) {
      break;
    }
  }
  // 2) find baby collect_max_candy
  Result r;
  Result cur{0, 0};
  find_basy_collect_candy(grid, r, cur, mi, mj);
  return r.maxCandy;
}

TEST(GridTestSuite, MaxCandy) {
  int res = max_candy({
      {3, 2, 1, -3},
      {1, -1, 1, 1},
      {1, 1, -1, 2},
      {-2, 1, 2, 3},
  });
  EXPECT_EQ(res, 9);

  int res2 =
      max_candy({{3, 2, 1, -3}, {-1, -1, 1, 1}, {1, 1, -1, 2}, {-2, 1, -1, 3}});
  EXPECT_EQ(res2, -1);
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}