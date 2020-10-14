# 1 "exp/layout_demo.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 417 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "exp/layout_demo.cpp" 2
struct Shape {

  virtual double area() const noexcept = 0;

  virtual double perimeter() const noexcept = 0;
};

struct Square : public Shape {
  short len;
  double area() const noexcept override {
    return len * len;
  }
  double perimeter() const noexcept override {
    return len * 4;
  }
};
