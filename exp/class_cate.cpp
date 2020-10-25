#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Point {
  int x;
  int y;
};
struct Rect1 {
  int width;
  int height;

  int area() const noexcept {
    return width * height;
  }
};
struct Shape {
  virtual int area() const noexcept = 0;
};
struct Rect2 : public Shape {
  int width;
  int height;

  virtual int area() const noexcept override {
    return width * height;
  }
};

struct User {
  std::string name;
  int age;
};

struct Student {
  int id;
  char sno[20];
  int age;

  Student() = default;
};
struct IntOper {
  int& value;
};

struct BaseUser {
  char name[20];
  int age;
};

struct VipUser : public BaseUser {
  int vipId;
};
struct NormalUser : public BaseUser {};

TEST(ClassCateTestSuite, POD) {
  static_assert(sizeof(Rect1) == 8);
  static_assert(sizeof(Rect2) == 8 + 8);
  static_assert(std::is_pod<Point>::value);
  static_assert(std::is_pod<Rect1>::value);
  static_assert(std::is_pod<Rect2>::value == false);
  static_assert(std::is_pod<User>::value == false);
  static_assert(std::is_pod<Student>::value);
  static_assert(std::is_trivial<Student>::value);
  static_assert(std::is_trivial<Rect2>::value == false);
  static_assert(std::is_pod<IntOper>::value == false);
  static_assert(std::is_standard_layout<Student>::value);
  static_assert(std::is_trivial<IntOper>::value);
  static_assert(std::is_pod<NormalUser>::value);
  static_assert(std::is_standard_layout<NormalUser>::value);
  static_assert(std::is_standard_layout<VipUser>::value == false);
  int count = 3;
  IntOper countOper{count};
}
GTEST_API_ int main(int argc, char* argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}