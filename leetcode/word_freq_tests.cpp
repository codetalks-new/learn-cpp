#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
using std::make_unique;
using std::move;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::unordered_map;
using std::vector;

struct WordInfo {
  int count;
};

/**
 *
  from 李海珍 18578921024

 h:[
    a: {
      v:{
        e:{
          is_word:true
        }
      }
      s:{
        is_word:true
        count
      }
    }
 ]
 have
 has
 O(K)  key char
 */

class WordFreq {
 private:
  /// TODO using unique_ptr
  unordered_map<char, unique_ptr<WordFreq>> ch_to_word_freq;
  char ch;
  bool is_word{false};
  int count{0};
  void build_tie_tree_from_words(const vector<string>& words) noexcept {
    for (const string& word : words) {
      build_tie_tree_from_word(word);
    }
  }

  void build_tie_tree_from_word(const string& word) noexcept {
    WordFreq* parent{this};
    for (char ch : word) {
      auto& map = parent->ch_to_word_freq;
      auto r = map.find(ch);
      if (r == map.end()) {
        auto child = make_unique<WordFreq>(ch);
        parent = child.get();
        map[ch] = std::move(child);
      } else {
        parent = r->second.get();
      }
    }
    parent->is_word = true;
    parent->count += 1;
  }

 public:
  WordFreq(char ch) : ch(ch) {}
  WordFreq(const vector<string> words) {
    build_tie_tree_from_words(words);
  }

  WordInfo search(const string word) noexcept {
    WordFreq* parent{this};
    for (char ch : word) {
      auto& map = parent->ch_to_word_freq;
      auto r = map.find(ch);
      if (r == map.end()) {
        return {-1};
      } else {
        parent = r->second.get();
      }
    }
    if (parent->is_word) {
      return {parent->count};
    } else {
      return {-1};
    }
  }

  int get(const string& word) noexcept {
    WordInfo wi = search(word);
    return wi.count;
  }
};

TEST(WordFreqTestSuite, WordFreqTestCase) {
  WordFreq wf({"i", "have", "en", "apple", "an", "orange"});
  EXPECT_EQ(wf.get("i"), 1);
  EXPECT_EQ(wf.get("hav"), -1);
  EXPECT_EQ(wf.get("have"), 1);
  EXPECT_EQ(wf.get("an"), 1);
  EXPECT_EQ(wf.get("en"), 1);
}
GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}