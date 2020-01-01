#include <cassert>
// #include <iostream>
// using std::cout;
// using std::endl;

struct HasArea {
  virtual int getArea() const {};
};

struct Size : public HasArea {
  int width;
  int height;
  Size(int width, int height) : width(width), height(height) {}

  int getArea() const override {
    return this->width * this->height;
  }
};

int main(int argc, char const *argv[]) {
  Size s1(3, 4);
  HasArea ha1 = s1;
  return s1.getArea();
}
