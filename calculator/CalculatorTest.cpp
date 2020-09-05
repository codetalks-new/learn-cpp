#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <stdio.h>

#include "Calculator.hpp"

// using testing::Eq;
using calculator::calc;
using calculator::calc_v2;
using calculator::infix_to_postfix;

TEST(Calculator, BasicAdd) {
  EXPECT_EQ(calc("3 + 4"), 7);
  EXPECT_EQ(calc("3 + 4"), 7);
  EXPECT_EQ(calc("3 + 4"), 7);
  EXPECT_EQ(calc("-1 + 4"), 3);
  EXPECT_EQ(calc("-1 + -4"), -5);
}
TEST(Calculator, BasicAddMoreOperand) {
  EXPECT_EQ(calc("1 + 2 + 3"), 6);
  EXPECT_EQ(calc("-1 + 3 + 4"), 6);
  EXPECT_EQ(calc("1 + 2 + 3 + 4"), 10);
  EXPECT_EQ(calc("1 + 2 + 3 + 4 + 5 + 6"), 21);
}

TEST(Calculator, BasicSubtract) {
  EXPECT_EQ(calc("-1 - 3"), -4);
  EXPECT_EQ(calc("1 - 3"), -2);
  EXPECT_EQ(calc("11 - 3"), 8);
}
TEST(Calculator, BasicFourArithmeticOperation) {
  EXPECT_EQ(calc("-1 - 3 * 2 + 1"), -6);
  EXPECT_EQ(calc("1 + 3 * 4 / 2"), 7);
  EXPECT_EQ(calc("2 * 3 + 8 / 2"), 10);
}
TEST(Calculator, BasicFourArithmeticOperationWithParetheses) {
  EXPECT_EQ(calc("( -1 - 3 ) * ( 2 + 1 )"), -12);
  EXPECT_EQ(calc("( 1 + 3 ) * 4 / 2"), 8);
  EXPECT_EQ(calc("2 * ( 3 + 8 ) / 2"), 11);
}

TEST(Calculator, BasicFourArithmeticOperationWithNestedParetheses) {
  EXPECT_EQ(calc("( 2 * (3 - 1) + 1) * ( 2 + 1 )"), 15);
  EXPECT_EQ(calc("( 1 + 3 ) * ((1 + 4 / 2) * 2 - 1)"), 20);
  EXPECT_EQ(calc("2 * ( 3 + (6 - 2) * 2 ) / 2"), 11);
}

TEST(InfixToPostfix, BasicAddSub) {
  EXPECT_EQ(infix_to_postfix("3+4"), "3 4 +");
  EXPECT_EQ(infix_to_postfix("3+4-5"), "3 4 + 5 -");
  EXPECT_EQ(infix_to_postfix("3+4-2+5"), "3 4 + 2 - 5 +");
}

TEST(InfixToPostfix, BasicFourArithmeticOps) {
  EXPECT_EQ(infix_to_postfix("3+4*2"), "3 4 2 * +");
  EXPECT_EQ(infix_to_postfix("3+2*5-6"), "3 2 5 * + 6 -");
  EXPECT_EQ(infix_to_postfix("3*4-2*5"), "3 4 * 2 5 * -");
  EXPECT_EQ(infix_to_postfix("3*4-2*6/3"), "3 4 * 2 6 * 3 / -");
}

TEST(InfixToPostfix, BasicFourArithmeticOpsWithParenthese) {
  EXPECT_EQ(infix_to_postfix("(3+4)*2"), "3 4 + 2 *");
  EXPECT_EQ(infix_to_postfix("(3+2)*(5-6)"), "3 2 + 5 6 - *");
  EXPECT_EQ(infix_to_postfix("3*(4-2)*5"), "3 4 2 - * 5 *");
  EXPECT_EQ(infix_to_postfix("3*(4-2)*6/3"), "3 4 2 - * 6 * 3 /");
}

TEST(InfixToPostfix, BasicFourArithmeticOpsWithNestedParenthese) {
  EXPECT_EQ(infix_to_postfix("(2*(3-1)+1)*(2+1)"), "2 3 1 - * 1 + 2 1 + *");
  EXPECT_EQ(infix_to_postfix("(1+3)*((1+4/2)*2-1)"),
            "1 3 + 1 4 2 / + 2 * 1 - *");
  EXPECT_EQ(infix_to_postfix("2*(3+(6-2)*2)/2"), "2 3 6 2 - 2 * + * 2 /");
}

TEST(InfixToPostfix, DoubleAddSub) {
  EXPECT_EQ(infix_to_postfix("3.14+4.2"), "3.14 4.2 +");
  EXPECT_EQ(infix_to_postfix("32+40-50"), "32 40 + 50 -");
  EXPECT_EQ(infix_to_postfix("314+4.5-2.5+5.1"), "314 4.5 + 2.5 - 5.1 +");
}

TEST(InfixToPostfix, NegtiveNum) {
  EXPECT_EQ(infix_to_postfix("-3.14+4.2"), "-3.14 4.2 +");
  EXPECT_EQ(infix_to_postfix("-3.14+-4.2"), "-3.14 -4.2 +");
  EXPECT_EQ(infix_to_postfix("(3+2)*(-5.1-6)"), "3 2 + -5.1 6 - *");
}
#define _STR(s) #s
#define STR(s) _STR(s)
#define EXP_B1 -3.14 + 4.2

TEST(CalculatorV2, Basic) {
  EXPECT_EQ(calc_v2(STR(EXP_B1)), (EXP_B1));
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}