#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>
using std::cout;
using std::deque;
using std::endl;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

int deque_max(deque<int> q) {
  int max = q.front();
  for (int num : q) {
    max = num > max ? num : max;
  }
  return max;
}

vector<int> maxSlidingWind(vector<int> nums, int k) {
  deque<int> wind{};
  for (int i = 0; i < k; i++) {
    int num = nums[i];
    while (!wind.empty() && wind.back() < num) {
      wind.pop_back();
    }
    wind.push_back(num);
  }
  vector<int> result{wind[0]};
  for (int i = k; i < nums.size(); i++) {
    int num = nums[i];
    int numi_k = nums[i - k];  // for debug
    if (wind[0] == numi_k) {
      wind.pop_front();
    }
    while (!wind.empty() && wind.back() < num) {
      wind.pop_back();
    }
    wind.push_back(num);
    result.push_back(wind[0]);
  }
  return result;
}

TEST(SlidingWinTestSuite, MaxSlidingWinTestCase) {
  vector<int> r1{3, 3, 5, 5, 6, 7};
  EXPECT_EQ(maxSlidingWind({1, 3, -1, -3, 5, 3, 6, 7}, 3), r1);

  vector<int> r2{3, 3, 2, 5};
  EXPECT_EQ(maxSlidingWind({1, 3, 1, 2, 0, 5}, 3), r2);

  vector<int> r3{7, 6, 5, 4, 3};
  EXPECT_EQ(maxSlidingWind({7, 6, 5, 4, 3, 2, 1}, 3), r3);

  vector<int> r4{3, 3, 3, 5, 5, 6, 7};
  EXPECT_EQ(maxSlidingWind({1, 2, 3, -1, -3, 5, 3, 6, 7}, 3), r4);
}

int lengthOfLongestSubstring(string s) {
  int maxLen = 0;
  unordered_set<char> chars;
  int left = 0;
  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    auto r = chars.find(ch);
    if (r == chars.end()) {
      chars.insert(ch);
    } else {
      while (s[left] != ch) {
        chars.erase(s[left]);
        left += 1;
      }
      left += 1;  // for duplicate ch itself
    }
    int curLen = i - left + 1;
    maxLen = curLen > maxLen ? curLen : maxLen;
  }
  return maxLen;
}

TEST(SlidingWinTestSuite, LongestSubstringWithoutDuplicate) {
  EXPECT_EQ(lengthOfLongestSubstring("abcabcbb"), 3);
  EXPECT_EQ(lengthOfLongestSubstring("aaaaa"), 1);
  EXPECT_EQ(lengthOfLongestSubstring("pwwkew"), 3);
}

int longestOnes(vector<int> A, int K) {
  int maxLen = 0;
  int zero_cnt = 0;
  int left = 0;
  for (int i = 0; i < A.size(); i++) {
    int num = A[i];
    if (num == 0) {
      zero_cnt += 1;
      while (zero_cnt > K) {
        if (A[left] == 0) {
          zero_cnt -= 1;
        }
        left += 1;
      }
    }
    int curMax = i - left + 1;
    maxLen = curMax > maxLen ? curMax : maxLen;
  }
  return maxLen;
}

int longestOnes_raw(vector<int> A, int K) {
  int maxLen = 0;
  int zero_cnt = 0;
  deque<int> wind;
  for (int num : A) {
    wind.push_back(num);
    if (num == 0) {
      zero_cnt += 1;
      while (zero_cnt > K) {
        int one = wind.front();
        wind.pop_front();
        if (one == 0) {
          zero_cnt -= 1;
        }
      }
    }
    int curMax = wind.size();
    maxLen = curMax > maxLen ? curMax : maxLen;
  }
  return maxLen;
}

TEST(SlidingWinTestSuite, LongestOnes) {
  EXPECT_EQ(longestOnes({1, 0, 1}, 0), 1);
  EXPECT_EQ(longestOnes({1, 0, 1}, 1), 3);
  EXPECT_EQ(longestOnes({1, 0, 1}, 2), 3);
  EXPECT_EQ(longestOnes({1, 0, 0, 1}, 2), 4);
  EXPECT_EQ(longestOnes({1, 0, 0, 1, 0, 1}, 2), 4);
  EXPECT_EQ(longestOnes({1, 0, 0, 0, 1, 0, 1}, 2), 4);
  EXPECT_EQ(longestOnes({1, 0, 0, 0, 1, 0, 0, 1}, 2), 4);
  EXPECT_EQ(longestOnes({1, 0, 0, 0, 1, 0, 0, 0, 1}, 2), 3);
  EXPECT_EQ(longestOnes({1, 0, 1, 0, 1}, 2), 5);
  EXPECT_EQ(longestOnes({0, 1, 1, 0, 1}, 2), 5);
  EXPECT_EQ(longestOnes({0, 0, 1, 1, 1}, 2), 5);
}

int strReplaceWithChar(string& s, char winchar, int k) {
  int maxLen = 0;
  int replace_cnt = 0;
  int left = 0;
  for (int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if (ch != winchar) {
      replace_cnt += 1;
      while (replace_cnt > k) {
        if (s[left] != winchar) {
          replace_cnt -= 1;
        }
        left += 1;
      }
    }
    int curLen = i - left + 1;
    maxLen = curLen > maxLen ? curLen : maxLen;
  }
  return maxLen;
}
int charReplacement(string s, int k) {
  unordered_set<char> chars(s.cbegin(), s.cend());
  int maxLen = 0;
  for (char winch : chars) {
    int curLen = strReplaceWithChar(s, winch, k);
    maxLen = curLen > maxLen ? curLen : maxLen;
  }

  return maxLen;
}

TEST(SlidingWinTestSuite, CharReplacement) {
  EXPECT_EQ(charReplacement("ABA", 0), 1);
  EXPECT_EQ(charReplacement("ABA", 1), 3);
  EXPECT_EQ(charReplacement("AAA", 1), 3);
  EXPECT_EQ(charReplacement("AAA", 0), 3);
  EXPECT_EQ(charReplacement("ABAB", 2), 4);
  EXPECT_EQ(charReplacement("AABABBA", 1), 4);
  EXPECT_EQ(charReplacement("AABABBBA", 1), 5);
}

string minWindow(string s, string t) {
  unordered_map<char, int> tcounter;
  for (char ch : t) {
    tcounter[ch] += 1;
  }
  const int tsize = t.size();
  int matchCount = 0;
  unordered_map<char, int> wind;
  int N = s.size();
  int left = 0;
  int right = 0;
  string ans;
  int minLen = N + 1;
  int minStart = -1;
  while (right < N) {
    char ch = s[right];
    int tcnt = tcounter[ch];
    if (tcnt > 0) {
      wind[ch] += 1;
      if (wind[ch] <= tcnt) {
        matchCount += 1;
      }
    }
    bool valid = false;
    while (matchCount == tsize && left <= right) {
      valid = true;
      char lch = s[left];
      int cnt = tcounter[lch];
      if (cnt > 0) {
        wind[lch] -= 1;
        if (wind[lch] < cnt) {
          matchCount -= 1;
        }
      }
      left += 1;
    }
    if (valid) {
      int start = left - 1;  //
      int curLen = right - start + 1;
      if (curLen < minLen) {
        minLen = curLen;
        minStart = start;
      }
    }
    right += 1;
  }

  return minLen > N ? string() : s.substr(minStart, minLen);
}

TEST(SlidingWinTestSuite, MinWindow) {
  EXPECT_EQ(minWindow("ADOBECODEBANC", "ABC"), "BANC");
}

vector<int> shortestSeq(vector<int> big, vector<int> small) {
  if (big.empty() || big.size() < small.size()) {
    return {};
  }
  unordered_map<int, int> small_stats(small.size());
  unordered_map<int, int> wind;
  for (int num : small) {
    small_stats[num] = 1;
  }
  const int smallSize = small.size();
  int left = 0;
  int right = 0;
  int N = big.size();
  int matchSize = 0;

  int minStart = N + 1;
  int minLength = N + 1;

  while (right < N) {
    int num = big[right];
    if (small_stats[num]) {
      wind[num] += 1;
      if (wind[num] == 1) {
        matchSize += 1;
      }
    }
    bool valid = false;
    while (smallSize == matchSize && left <= right) {
      valid = true;
      int leftNum = big[left];
      if (small_stats[leftNum]) {
        wind[leftNum] -= 1;
        if (wind[leftNum] == 0) {
          matchSize -= 1;
        }
      }
      left += 1;
    }
    if (valid) {
      int curStart = left - 1;
      int curLen = right - curStart + 1;
      if (curLen < minLength) {
        minLength = curLen;
        minStart = curStart;
      }
    }
    right += 1;
  }

  if (minLength < N + 1) {
    return {minStart, minStart + minLength - 1};
  } else {
    return {};
  }
}

TEST(SlidingWinTestSuite, ShortestSeq) {
  vector<int> r1{7, 10};
  EXPECT_EQ(shortestSeq({7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7},
                        {1, 5, 9}),
            r1);
  EXPECT_EQ(shortestSeq({1, 2, 3}, {4}).size(), 0);
}

bool checkInclusion(string s1, string s2) {
  if (s2.size() < s1.size()) {
    return false;
  }
  unordered_map<char, int> s1stat;
  unordered_map<char, int> wind;
  int wind_size = 0;

  for (char ch : s1) {
    s1stat[ch] += 1;
  }
  int match_cnt = 0;
  int left = 0;
  int right = 0;
  int N = s2.size();
  while (right < N) {
    char ch = s2[right];
    wind[ch] += 1;
    wind_size += 1;
    if (s1stat[ch] > 0 && wind[ch] <= s1stat[ch]) {
      match_cnt += 1;
    }
    while (match_cnt == s1.size() && left <= right) {
      if (wind_size == s1.size()) {
        return true;
      }
      char lch = s2[left];
      wind[lch] -= 1;
      wind_size -= 1;
      if (s1stat[lch] > 0 && wind[lch] < s1stat[lch]) {
        match_cnt -= 1;
      }
      left += 1;
    }
    right += 1;
  }

  return false;
}

TEST(SlidingWinTestSuite, CheckInclusion) {
  EXPECT_TRUE(checkInclusion("ab", "eidbaooo"));
  EXPECT_FALSE(checkInclusion("ab", "eidboaoo"));
  EXPECT_TRUE(checkInclusion("a", "ab"));
}

vector<int> findAnagrams(string s, string p) {
  const int N = s.size();
  const int psize = p.size();
  if (N < psize) {
    return {};
  }
  vector<int> ans;
  unordered_map<char, int> pstat;
  for (char ch : p) {
    pstat[ch] += 1;
  }
  unordered_map<char, int> wind;
  int match_cnt = 0;
  for (int i = 0; i < psize - 1; i++) {
    char ch = s[i];
    if (pstat[ch] && wind[ch] < pstat[ch]) {
      match_cnt += 1;
    }
    wind[ch] += 1;
  }
  int left = 0;
  int right = psize - 1;
  while (right < N) {
    char ch = s[right];
    if (pstat[ch] && wind[ch] < pstat[ch]) {
      match_cnt += 1;
    }
    wind[ch] += 1;
    if (match_cnt == psize) {
      ans.push_back(left);
    }
    char lch = s[left];
    if (pstat[lch] && wind[lch] <= pstat[lch]) {
      match_cnt -= 1;
    }
    wind[lch] -= 1;
    right += 1;
    left += 1;
  }
  return ans;
}

TEST(SlidingWinTestSuite, FindAnagrams) {
  vector<int> r1{0, 1, 2};
  EXPECT_EQ(findAnagrams("abab", "ab"), r1);
  vector<int> r2{0, 6};
  EXPECT_EQ(findAnagrams("cbaebabacd", "abc"), r2);
}

bool isValid(deque<int>& wind, int new_num, int limit) {
  for (int num : wind) {
    if (abs(num - new_num) > limit) {
      return false;
    }
  }
  return true;
}

int longestSubarray(vector<int> nums, int limit) {
  int maxLen = 0;
  int left = 0;
  int right = 0;
  const int N = nums.size();
  int min = 0;
  int max = 0;

  auto findNewLeft = [&nums, &min, &max, limit](int left, int right) {
    int new_max = 0;
    int new_min = INT_MAX;
    int new_left = right;
    for (int i = right; i >= left; i--) {
      int num = nums[i];
      if (num > new_max) {
        new_max = num;
      }
      if (num < new_min) {
        new_min = num;
      }
      if ((new_max - new_min) > limit) {
        break;
      } else {
        new_left = i;
      }
    }
    min = new_min;
    max = new_max;
    return new_left;
  };

  while (right < N) {
    int new_num = nums[right];
    if (new_num > max) {
      max = new_num;
    }
    if (new_num < min) {
      min = new_num;
    }
    if ((max - min) > limit) {
      left = findNewLeft(left, right);
    }
    int curLen = right - left + 1;
    maxLen = curLen > maxLen ? curLen : maxLen;
    right += 1;
  }
  return maxLen;
}

TEST(SlidingWinTestSuite, LongestSubarray) {
  EXPECT_EQ(longestSubarray({4, 8, 5, 1, 7, 9}, 6), 3);
  EXPECT_EQ(longestSubarray({8, 2, 4, 7}, 4), 2);
  EXPECT_EQ(longestSubarray({10, 1, 2, 4, 7, 2}, 5), 4);
  EXPECT_EQ(longestSubarray({4, 2, 2, 2, 4, 4, 2, 2}, 0), 3);

  int N = 100000;
  vector<int> nums(N, 1);
  EXPECT_EQ(nums.size(), N);
  EXPECT_EQ(longestSubarray(std::move(nums), 10), N);
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}