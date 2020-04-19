#pragma once

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

namespace calculator {
using std::string;
using std::vector;

static int _calc_expr_without_paretheses(const string& input) {
  vector<string> parts;
  boost::split(parts, input, [](char c) { return c == ' '; });
  parts.erase(std::remove_if(parts.begin(), parts.end(),
                             [](const string& part) { return part.empty(); }),
              parts.end());
  vector<string> phase1;
  int i = 0;
  while (i < parts.size()) {
    const auto& op = parts[i];
    if (op == "*" || op == "/") {
      const auto& lhs = phase1.back();
      const auto& rhs = parts[i + 1];
      i += 2;
      const int lval = atoi(lhs.c_str());
      const int rval = atoi(rhs.c_str());
      const int val = op == "*" ? lval * rval : lval / rval;
      phase1.pop_back();
      phase1.push_back(std::to_string(val));
    } else {
      phase1.push_back(op);
      i += 1;
    }
  }
  int result = atoi(phase1[0].c_str());
  for (int i = 1; i < phase1.size() - 1; i++) {
    auto& op = phase1[i];
    int rhs = atoi(phase1[i + 1].c_str());
    if (op == "+") {
      result += rhs;
    } else {
      result -= rhs;
    }
  }
  return result;
}

int calc(const string input) {
  const string source(input);
  const int N = source.size();
  int pos = 0;
  vector<string> exprs;
  string expr;
  for (char ch : source) {
    if (ch == '(') {
      exprs.push_back(expr);
      expr.clear();
    } else if (ch == ')') {
      int result = _calc_expr_without_paretheses(expr);
      expr = exprs.back();
      exprs.pop_back();
      expr += " " + std::to_string(result) + " ";
    } else {
      expr += ch;
    }
  }
  int result = _calc_expr_without_paretheses(expr);
  return result;
}

struct Token {
  // // 字母 D 表示数值类型
  char kind;
  double value;
  Token() : kind('D'), value(0) {}
};

static inline bool is_operator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

static vector<Token> tokenize(string input) {
  std::stringstream cin(input);
  vector<Token> tokens;
  bool leading = true;
  while (cin) {
    Token token;
    char ch = cin.peek();
    if (isdigit(ch)) {
      cin >> token.value;
      leading = false;
    } else if (leading && (ch == '+' || ch == '-')) {
      cin >> token.value;
      leading = false;
    } else {
      cin >> ch;
      if (isspace(ch)) {  // skip
        continue;
      }
      token.kind = ch;
      leading = (ch == '(' || is_operator(ch));
    }
    tokens.push_back(token);
  }
  return tokens;
}

static inline int op_priority(char ch) {
  switch (ch) {
    case '*':
    case '/':
      return 30;
    case '+':
    case '-':
      return 20;
    default:
      return 0;
  }
}
static bool is_integer(double num) {
  return isfinite(num) && floor(num) == num;
}

static string fmt_double(double d) {
  if (is_integer(d)) {
    long num = static_cast<long>(d);
    return std::to_string(num);
  } else {
    string str = std::to_string(d);
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    return str;
  }
}

string infix_to_postfix(string input) {
  std::vector<string> output;
  std::stack<char> operators;

  vector<Token> tokens = tokenize(input);

  for (Token& token : tokens) {
    const char ch = token.kind;
    if (is_operator(ch)) {
      const int op_pri = op_priority(ch);
      while (!operators.empty()) {
        char prev_op = operators.top();
        const int pre_op_pri = op_priority(prev_op);
        if (pre_op_pri >= op_pri) {
          output.push_back(string(1, prev_op));
          operators.pop();
        } else {
          break;
        }
      }
      operators.push(ch);
    } else if (token.kind == 'D') {
      output.push_back(fmt_double(token.value));
    } else if (ch == '(') {
      operators.push(ch);
    } else if (ch == ')') {
      char prev_op = operators.top();
      while (prev_op != '(') {
        output.push_back(string(1, prev_op));
        operators.pop();
        prev_op = operators.top();
      }
      operators.pop();
    } else {
      // skip
    }
  }

  while (!operators.empty()) {
    char ch = operators.top();
    output.push_back(string(1, ch));
    operators.pop();
  }

  return boost::join(output, " ");
}

}  // namespace calculator