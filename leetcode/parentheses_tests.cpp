#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool isValid(const string s) {
  vector<char> expect_parens;
  for (char ch : s) {
    switch (ch) {
      case '(':
        expect_parens.push_back(')');
        break;
      case '{':
        expect_parens.push_back('}');
        break;
      case '[':
        expect_parens.push_back(']');
        break;
      default:
        if (expect_parens.empty()) {
          return false;
        }
        char expect_paren = expect_parens.back();
        expect_parens.pop_back();
        if (expect_paren != ch) {
          return false;
        }
        break;
    }
  }
  return expect_parens.empty();
}

bool checkValidR(vector<char>& chars, char* s) {
  for (; *s; s++) {
    char ch = *s;
    if (ch == '*') {
      bool valid = false;
      // 1) * as (
      *s = '(';
      vector<char> opt1{chars};
      valid = checkValidR(opt1, s);
      if (valid) {
        return true;
      }
      // 2) * as )
      *s = ')';
      vector<char> opt2{chars};
      valid = checkValidR(opt2, s);
      if (valid) {
        return true;
      }
      // 3) * as ''
      s++;
      valid = checkValidR(chars, s);
      return valid;
    } else if (ch == '(') {
      chars.push_back(ch);
    } else {
      if (chars.empty()) {
        return false;
      }
      chars.pop_back();
    }
  }
  return chars.empty();
}

bool checkValid1(char* s) {
  vector<char> chars;
  return checkValidR(chars, s);
}

bool checkValid2(char* s) {
  vector<int> left_parens;
  vector<int> stars;
  for (int i = 0; *s; s++, i++) {
    char ch = *s;
    if (ch == '*') {
      stars.push_back(i);
    } else if (ch == '(') {
      left_parens.push_back(i);
    } else {
      if (left_parens.size()) {
        left_parens.pop_back();
      } else if (stars.size()) {
        stars.pop_back();
      } else {
        return false;
      }
    }
  }
  if (left_parens.empty()) {
    return true;
  }
  if (stars.size() < left_parens.size()) {
    return false;
  }
  for (int i = left_parens.size() - 1, j = stars.size() - 1; i > -1; i--, j--) {
    int paren_index = left_parens[i];
    int star_index = stars[j];
    if (paren_index > star_index) {
      return false;
    }
  }
  return true;
}

TEST(ParensTestSuite, isValid) {
  // valid
  EXPECT_TRUE(isValid(""));
  EXPECT_TRUE(isValid("{}"));
  EXPECT_TRUE(isValid("({})"));
  EXPECT_TRUE(isValid("[]({})"));
  EXPECT_TRUE(isValid("[]{}()"));
  // invalid
  EXPECT_FALSE(isValid("[]{(})"));
  EXPECT_FALSE(isValid("[]{}(()"));
}

bool checkValid(const char* str) {
  int left_paren_min = 0;
  int left_paren_max = 0;
  for (; *str; str++) {
    char ch = *str;
    switch (ch) {
      case '(':
        left_paren_min++;
        left_paren_max++;
        break;
      case ')':
        if (left_paren_min > 0) left_paren_min--;
        left_paren_max--;
        break;
      case '*':
        if (left_paren_min > 0) left_paren_min--;
        left_paren_max++;
        break;
      default:
        break;
    }
    if (left_paren_max < 0) {
      return false;
    }
  }
  return left_paren_min == 0;
}

TEST(ParensTestSuite, CheckValid) {
  // valid
  char s1[] = "()";
  EXPECT_TRUE(checkValid(s1));
  char s2[] = "(*)";
  EXPECT_TRUE(checkValid(s2));
  char s3[] = "((*)";
  EXPECT_TRUE(checkValid(s3));
  char s4[] = "(*))";
  EXPECT_TRUE(checkValid(s4));
  char s5[] = "(**)))";
  EXPECT_TRUE(checkValid(s5));
  char s5_2[] = "(((**)";
  EXPECT_TRUE(checkValid(s5_2));
  char s6[] = "(*)*))";
  EXPECT_TRUE(checkValid(s6));

  // invalid
  char s7[] = "())";
  EXPECT_FALSE(checkValid(s7));
  char s8[] = "(*)))";
  EXPECT_FALSE(checkValid(s8));
  char s9[] = "(()";
  EXPECT_FALSE(checkValid(s9));
  char s10[] = "*(";
  EXPECT_FALSE(checkValid(s10));

  char s11[] = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
  EXPECT_FALSE(checkValid(s11));

  char s12[] = "((()))()(())(*()()())**(())()()()()((*()*))((*()*)";
  EXPECT_TRUE(checkValid(s12));
}

GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}