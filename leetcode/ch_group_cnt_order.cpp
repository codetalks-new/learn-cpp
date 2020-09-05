#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
  char ch;
  unordered_map<char, int> ch_cnt{};
  constexpr char space = ' ';

  while (ch = getchar()) {
    if (isspace(ch)) {
      ch_cnt[space] += 1;
    } else if (isalnum(ch)) {
      ch_cnt[ch] += 1;
    }
  }
  return 0;
}