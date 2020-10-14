#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Box1 {
  int8_t val;
};
struct Box2 {
  int16_t val;
};
struct Box3 {
  int32_t val;
};
struct Box4 {
  int64_t val;
};

TEST(LayoutTests, BoxSize) {
  static_assert(sizeof(Box1) == 1);
  static_assert(sizeof(Box2) == 2);
  static_assert(sizeof(Box3) == 4);
  static_assert(sizeof(Box4) == 8);
}

struct Box21 {
  int8_t val;
  int8_t val2;
};
struct Box22 {
  int16_t val;
  int8_t val2;
};
struct Box23 {
  int32_t val;
  int8_t val2;
};
struct Box24 {
  int64_t val;
  int8_t val2;
};
TEST(LayoutTests, Box2Size) {
  static_assert(sizeof(Box21) == 2);
  static_assert(sizeof(Box22) == 4);
  static_assert(sizeof(Box23) == 8);
  static_assert(sizeof(Box24) == 16);
}

struct Box31 {
  int8_t val;
  int8_t val2;
  int8_t val3;
};
struct Box32 {
  int16_t val;
  int8_t val2;
  int16_t val3;
};
struct Box33 {
  int32_t val;
  int8_t val2;
  int16_t val3;
};
struct Box34 {
  int64_t val;
  int8_t val2;
  int16_t val3;
};

TEST(LayoutTests, Box3Size) {
  static_assert(sizeof(Box31) == 3);
  static_assert(sizeof(Box32) == 6);
  static_assert(sizeof(Box33) == 8);
  static_assert(sizeof(Box34) == 16);
}

struct Empty {};
TEST(LayoutTests, EmptyStruct) {
  EXPECT_EQ(sizeof(Empty), 1);
}

struct Point {
  int16_t x;
  int16_t y;
};

TEST(LayoutTests, BasicStruct) {
  static_assert(sizeof(Point) == 4, "Point size should be 4 bytes");
  Point p1{3, 4};
  uint8_t *buf = reinterpret_cast<uint8_t *>(&p1);
  EXPECT_EQ(buf[0], 0x3);
  EXPECT_EQ(buf[1], 0x0);
  EXPECT_EQ(buf[2], 0x4);
  EXPECT_EQ(buf[3], 0x0);
}
struct Circle {
  Point center;
  uint16_t radius;

  double area() const noexcept {
    return M_PI * radius * radius;
  }
};
TEST(LayoutTests, BasicCircle) {
  EXPECT_EQ(sizeof(Circle), 6);
  Circle c1{Point{3, 4}, 5};
  uint8_t *buf = reinterpret_cast<uint8_t *>(&c1);
  EXPECT_EQ(buf[0], 0x3);
  EXPECT_EQ(buf[1], 0x0);
  EXPECT_EQ(buf[2], 0x4);
  EXPECT_EQ(buf[3], 0x0);
  EXPECT_EQ(buf[4], 0x5);
  EXPECT_EQ(buf[5], 0x0);
  EXPECT_DOUBLE_EQ(c1.area(), M_PI * c1.radius * c1.radius);
}

struct DrawableCircle : public Circle {
  uint8_t borderWidth;
  uint8_t color;
};

TEST(LayoutTests, DrawableCircle) {
  EXPECT_EQ(sizeof(DrawableCircle), 8);
  DrawableCircle c1;
  c1.center = Point{3, 4};
  c1.radius = 5;
  c1.borderWidth = 2;
  c1.color = 96;
  uint8_t *buf = reinterpret_cast<uint8_t *>(&c1);
  EXPECT_EQ(buf[0], 0x3);
  EXPECT_EQ(buf[1], 0x0);
  EXPECT_EQ(buf[2], 0x4);
  EXPECT_EQ(buf[3], 0x0);
  EXPECT_EQ(buf[4], 0x5);
  EXPECT_EQ(buf[5], 0x0);
  EXPECT_EQ(buf[6], 0x2);
  EXPECT_EQ(buf[7], 96);
}

enum class ShapeKind { POLYGON, ECLIPSE, CIRCLE, CIRCULAR_SECTOR };

struct Shape {
  const ShapeKind kind;
  Shape(ShapeKind kind) : kind(kind) {}
  // 面积
  virtual double area() const noexcept = 0;
  // 周长
  virtual double perimeter() const noexcept = 0;
};
struct Drawable {
  Point origin;
  Drawable(Point origin) : origin(origin) {}
  // 绘制
  virtual string draw() const noexcept = 0;
  virtual int getStyle() const noexcept {
    return 1;
  }
};

struct Square : public Shape, public Drawable {
  uint16_t len;
  Square(uint16_t len, Point origin) : len(len), Shape(ShapeKind::POLYGON), Drawable(origin) {}
  double area() const noexcept override {
    return len * len;
  }
  double perimeter() const noexcept override {
    return len * 4;
  }
  string draw() const noexcept override {
    return "Square";
  }
};
TEST(LayoutTests, ShapeSquareSize) {
  EXPECT_EQ(sizeof(Point), 4);
  EXPECT_EQ(sizeof(Shape), 8);
  EXPECT_EQ(sizeof(Square), 24);
}
TEST(LayoutTests, ShapeDrawableSquare) {
  Square s1(8, Point{3, 4});
  uint8_t *buf = reinterpret_cast<uint8_t *>(&s1);
  EXPECT_EQ(buf[16], 0x03);
  EXPECT_EQ(buf[17], 0x00);
  EXPECT_EQ(buf[18], 0x04);
  EXPECT_EQ(buf[19], 0x00);
  EXPECT_EQ(buf[20], 0x08);
  EXPECT_EQ(buf[21], 0x00);
  Shape *shape1 = &s1;
  uintptr_t *p = reinterpret_cast<uintptr_t *>(&s1);
  uintptr_t *vtable = (uintptr_t *)*p;
  using Fn = double(uintptr_t *);
  Fn *areaFn = (Fn *)(vtable[0]);
  EXPECT_EQ(areaFn(p), s1.area());
  Fn *perimeterFn = (Fn *)(vtable[1]);
  EXPECT_EQ(perimeterFn(p), s1.perimeter());
  using DrawFn = string(uintptr_t *);
  DrawFn *drawFn = (DrawFn *)(vtable[2]);
  EXPECT_EQ(drawFn(p), s1.draw());

  uintptr_t *vtable2 = (uintptr_t *)*(p + 1);
  using GetStyleFn = int(uintptr_t *);
  GetStyleFn *getStyleFn = (GetStyleFn *)(vtable[3]);
  EXPECT_EQ(getStyleFn(p), s1.getStyle());
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}