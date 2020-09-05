#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int gcd(int a, int b) {
  int tmp = 0;
  while (b) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

int lcm(int a, int b) {
  return (a * b) / (gcd(a, b));
}

TEST(MathTestSuite, GCD) {
  EXPECT_EQ(gcd(2, 4), 2);
  EXPECT_EQ(gcd(4, 8), 4);
  EXPECT_EQ(gcd(6, 9), 3);
  EXPECT_EQ(gcd(-6, 9), 3);
}

double nt_sqrt(double a) {
  if (a == 0) {
    return 0;
  }
  double x1 = a;
  while (true) {
    double x2 = 0.5 * (x1 + a / x1);
    if (fabs(x1 - x2) < 1e-7) {
      break;
    }
    x1 = x2;
  }
  return x1;
}

TEST(MathTestSuite, NtSqrt) {
  EXPECT_NEAR(nt_sqrt(9), 3.0, 1e-6);
  EXPECT_NEAR(nt_sqrt(4), 2.0, 1e-6);
  EXPECT_NEAR(nt_sqrt(2), 1.414, 1e-2);
}

double nt_cubrt(double a) {
  if (abs(a) < 1e-6) {
    return a;
  }
  double x1 = a;
  while (true) {
    double x2 = ((2 * x1 * x1 * x1 + a) / (3 * x1 * x1));
    if (fabs(x1 - x2) < 1e-7) {
      break;
    }
    x1 = x2;
  }
  return x1;
}

TEST(MathTestSuite, NtCubrt) {
  EXPECT_NEAR(nt_cubrt(27), 3.0, 1e-6);
  EXPECT_NEAR(nt_cubrt(8), 2.0, 1e-6);
  EXPECT_NEAR(nt_cubrt(216), 6.0, 1e-6);
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}