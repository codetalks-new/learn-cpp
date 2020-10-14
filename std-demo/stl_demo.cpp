#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int arr[6] = {27, 210, 12, 27, 109, 83};
  vector<int, allocator<int>> vi{arr, arr + 6};
  cout << vi.size() << endl;
  int gt40 = count_if(vi.begin(), vi.end(), [](int v) { return v >= 40; });
  cout << gt40 << endl;
  vector<int> scores{42, 39, 71, 56, 48, 78, 65, 68, 31, 90, 78, 60, 88};
  using namespace placeholders;
  // int count = count_if(scores.begin(), scores.end(), bind(greater_equal<int>(), _1, 60));
  int count = count_if(scores.begin(), scores.end(), [](int score) { return score >= 60; });
  // int count = 0;
  // for (int score : scores) {
  //   if (score >= 60) {
  //     count += 1;
  //   }
  // }
  count = 0;
  for (auto it = scores.cbegin(); it != scores.cend(); ++it) {
    if (*it >= 60) {
      count += 1;
    }
  }

  cout << count << endl;
  return 0;
}
