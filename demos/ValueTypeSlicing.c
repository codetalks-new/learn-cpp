#include <stdio.h>
#include <stdint.h>

typedef struct Point2D
{
  int32_t x;
  int32_t y;
} Point2D;

typedef struct Point3D
{
  int32_t x;
  int32_t y;
  int32_t z;
} Point3D;

void printPoint(Point2D p)
{
  printf("Point2D[x=%d,y=%d]\n", p.x, p.y);
}

int main(int argc, char const *argv[])
{
  Point3D p1 = {.x = 1, .y = 2, .z = 3};
  printPoint(*(Point2D *)&p1);
  return 0;
}
