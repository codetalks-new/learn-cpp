struct Point {
  int x;
  int y;
};

int calcXY(Point *p) {
  return p->x + p->y;
}

int main(int argc, char const *argv[]) {
  Point *p = new Point{3, 4};
  return calcXY(p);
}
