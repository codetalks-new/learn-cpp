#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;

using ParamType = pair<string, vector<string>>;

class StrSplitParamsTests : public ::testing::TestWithParam<ParamType> {};

// TEST_P(StrSplitParamsTests, StrSplitWith_strtok) {
//   auto p = GetParam();
//   string str = p.first;
//   vector<string> results;
//   vector<char> chars(str.begin(), str.end());
//   chars.push_back('\0');
//   char *source = chars.data();
//   char *token = strtok(source, ",");
//   while (token != nullptr) {
//     results.push_back(token);
//     token = strtok(nullptr, ",");
//   }
//   EXPECT_EQ(results, p.second);
//   if (source) {
//     cout << "source:" << source << endl;
//   }
// }

TEST_P(StrSplitParamsTests, StrSplitWith_strsep) {
  auto p = GetParam();
  string str = p.first;
  vector<string> results;
  vector<char> chars(str.begin(), str.end());
  chars.push_back('\0');
  char *source = chars.data();
  char *token = nullptr;
  while ((token = strsep(&source, ",")) != nullptr) {
    results.push_back(token);
  }
  EXPECT_EQ(results, p.second);
}

// TEST_P(StrSplitParamsTests, StrSplitWith_getline) {
//   auto p = GetParam();
//   auto source = p.first;
//   vector<string> results;
//   std::stringstream ss(source);
//   string part;
//   while (std::getline(ss, part, ',')) {
//     results.push_back(part);
//   }
//   EXPECT_EQ(results, p.second);
// }

TEST_P(StrSplitParamsTests, StrSplitWith_find_substr) {
  auto p = GetParam();
  auto source = p.first;
  vector<string> results;
  auto pos = source.find_first_of(',');
  if (pos == string::npos) {
    results.push_back(source);
  } else {
    string::size_type prevPos = 0;
    do {
      results.emplace_back(source.substr(prevPos, pos - prevPos));
      prevPos = pos + 1;
      pos = source.find_first_of(',', prevPos);
    } while (pos != string::npos);
    results.emplace_back(source.substr(prevPos));
  }
  EXPECT_EQ(results, p.second);
}

TEST_P(StrSplitParamsTests, StrSplitWith_regex) {
  auto p = GetParam();
  auto source = p.first;
  std::regex delimRe(",");
  auto part_begin = std::sregex_token_iterator(source.begin(), source.end(), delimRe, -1);
  auto part_end = std::sregex_token_iterator();
  std::vector<std::string> results(part_begin, part_end);

  EXPECT_EQ(results, p.second);
}
vector<ParamType> strSplitParamPairs{
    make_pair<string, vector<string>>("", {""}),
    make_pair<string, vector<string>>("a", {"a"}),
    make_pair<string, vector<string>>("a,b", {"a", "b"}),
    make_pair<string, vector<string>>("a, b", {"a", " b"}),
    make_pair<string, vector<string>>("a, b,c", {"a", " b", "c"}),
    make_pair<string, vector<string>>("a, b,c,", {"a", " b", "c", ""}),
};

INSTANTIATE_TEST_SUITE_P(StrSplitTests, StrSplitParamsTests, ::testing::ValuesIn(strSplitParamPairs));

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}