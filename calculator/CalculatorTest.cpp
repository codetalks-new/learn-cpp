#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <stdio.h>

#include "Calculator.hpp"

// using testing::Eq;
using calculator::calc;

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

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}