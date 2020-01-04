#include <stdio.h>
#include <utility>
using std::move;

struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {
    printf("Point(x=%d,y=%d)\n", x, y);
  }
  Point(const Point &p) {
    x = p.x;
    y = p.y;
    printf("CopyFrom Point(x=%d,y=%d)\n", p.x, p.y);
  }
  const Point &operator=(const Point &p) {
    x = p.x;
    y = p.y;
    printf("operator=Point(x=%d,y=%d)\n", p.x, p.y);
    return *this;
  }
};

void swap(Point &p1, Point &p2) {
  Point tmp{move(p2)};
  p2 = move(p1);
  p1 = move(tmp);
}

int main(int argc, char const *argv[]) {
  Point p1(3, 4);
  Point p2(2, 5);
  swap(p1, p2);
  printf("After Swap:\n");
  printf("p1[x=%d,y=%d]\n", p1.x, p1.y);
  printf("p2[x=%d,y=%d]\n", p2.x, p2.y);
  return 0;
}
