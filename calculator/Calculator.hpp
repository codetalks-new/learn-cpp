#pragma once
#include <algorithm>
#include <boost/algorithm/string.hpp>
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
}  // namespace calculator