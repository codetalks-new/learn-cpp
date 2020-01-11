#pragma once
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;

/**
 * Soundex 规则
 * 1) 保留第一个字母,丢掉所有出现的 a,e,i,o,u,y,h,w
 * 2) 以数字来代替辅音(第一个字母除外)
 *   - b,f,p,v: 1
 *   - c,g,j,k,q,s,x,z: 2
 *   - d,t: 3
 *   - l: 4
 *   - m,n: 5
 *   - r: 6
 * 3) 如果相邻字母编码相同,用一个数字表示它们即可.
 *    同样,如果出现两个编码相同的字母肯它们被h或w隔开,也这样处理
 *    但是如果被元音隔开,就要编码两次. 这条规则同样适用于第一个字母.
 * 4) 当得到一个字母和有一个数字时,停止处理.如果需要补零以对齐.
 *
 *
 *
 */
class Soundex {
 public:
  string encode(const string& word) const {
    return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
  }
  string encodedDigit(char ch) const {
    const unordered_map<char, string> ch2digit{
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"},
        {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
        {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"},
    };
    auto it = ch2digit.find(tolower(ch));
    return it == ch2digit.end() ? NotADigit : it->second;
  }

 private:
  static constexpr size_t MaxCodeLength{4};
  string head(const string& word) const {
    return word.substr(0, 1);
  }
  string tail(const string& word) const {
    return word.substr(1);
  }
  string upperFront(const string& word) const {
    return string(1, toupper(word.front()));
  }
  bool isComplete(const string& word) const {
    return word.length() == MaxCodeLength;
  }
  bool isVowel(char ch) const {
    return string("aeiouy").find(tolower(ch)) != string::npos;
  }
  const string NotADigit{"*"};

  void encodeHead(string& encoding, const string& word) const {
    encoding += encodedDigit(word.front());
  }
  void encodeTail(string& encoding, const string& word) const {
    for (auto i = 1; i < word.length(); i++) {
      if (!isComplete(encoding)) {
        encodeLetter(encoding, word[i], word[i - 1]);
      }
    }
  }

  void encodeLetter(string& encoding, char ch, char lastCh) const {
    auto digit = encodedDigit(ch);
    if (digit != NotADigit &&
        (digit != lastDigit(encoding) || isVowel(lastCh))) {
      encoding += digit;
    }
  }

  string encodedDigits(const string& word) const {
    string encoding;
    encodeHead(encoding, word);
    encodeTail(encoding, word);
    return encoding;
  }
  string lastDigit(const string& encoding) const {
    if (encoding.empty()) {
      return NotADigit;
    } else {
      return string(1, encoding.back());
    }
  }

  string zeroPad(const string& word) const {
    auto zerosNeeded = MaxCodeLength - word.length();
    return word + string(zerosNeeded, '0');
  }
};