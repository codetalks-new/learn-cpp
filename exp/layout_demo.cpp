struct Point {
  short x;
  short y;
};
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
  virtual int draw() const noexcept = 0;
  virtual int getStyle() const noexcept {
    return 1;
  }
};

struct Square : public Shape, public Drawable {
  short len;
  Square(short len, Point origin) : len(len), Shape(ShapeKind::POLYGON), Drawable(origin) {}
  double area() const noexcept override {
    return len * len;
  }
  double perimeter() const noexcept override {
    return len * 4;
  }
  int draw() const noexcept override {
    return 2;
  }
};

int main(int argc, char const *argv[]) {
  Square s1(8, Point{3, 4});
  return 0;
}
