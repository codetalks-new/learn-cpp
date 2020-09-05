#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Animal {
  virtual void makeSound() = 0;
  virtual ~Animal() = default;
};
struct Dog : public Animal {
  void makeSound() override {
    printf("旺旺\n");
  }
  void walk(){};
};
struct Bird : public Animal {
  void makeSound() override {
    printf("布谷\n");
  }
  void fly(){};
};

void animalsMakeSomeNoise(vector<Animal *> &animals) {
  for (Animal *animal : animals) {
    animal->makeSound();
  }
}

TEST(DemoTestSuite, DemoTestCase) {
  Bird b1;
  vector<Bird *> birds{&b1};
  vector<Animal *> *animals = reinterpret_cast<vector<Animal *> *>(&birds);
  animalsMakeSomeNoise(*animals);
}
GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}