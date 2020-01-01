#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;

// 车轮
class Wheel {
 public:
  Wheel() {
    cout << "Wheel()" << endl;
  }
  ~Wheel() noexcept {
    cout << "~Wheel()" << endl;
  }
};
enum class VehicleType { car, bike, motorcycle };

// 载具
class Vehicle {
 public:
  Vehicle() {
    cout << "Vehicle()" << endl;
  }
  virtual ~Vehicle() noexcept {
    cout << "~Vehicle()" << endl;
  }
  virtual int wheelCount() const = 0;
  static shared_ptr<Vehicle> create(VehicleType type);
};

// 汽车
class Car : public Vehicle {
 public:
  Car() {
    cout << "Car()" << endl;
  }
  ~Car() noexcept {
    cout << "~Car()" << endl;
  }

  int wheelCount() const override {
    return 4;
  }

 private:
  Wheel wheels[4];
};
// 自行车
class Bike : public Vehicle {
 public:
  Bike() {
    cout << "Bike()" << endl;
  }
  ~Bike() noexcept {
    cout << "~Bike()" << endl;
  }
  int wheelCount() const override {
    return 2;
  }

 private:
  Wheel wheels[2];
};
// 摩托车
class Motorcycle : public Vehicle {
 public:
  Motorcycle() {
    cout << "Motorcycle()" << endl;
  }
  ~Motorcycle() noexcept {
    cout << "~Motorcycle()" << endl;
  }

  int wheelCount() const override {
    return 2;
  }

 private:
  Wheel wheels[2];
};

shared_ptr<Vehicle> Vehicle::create(VehicleType type) {
  shared_ptr<Vehicle> ptr(nullptr);
  switch (type) {
    case VehicleType::car:
      ptr.reset(new Car());
      break;
    case VehicleType::bike:
      ptr.reset(new Bike());
      break;
    case VehicleType::motorcycle:
      ptr.reset(new Motorcycle());
      break;
    default:
      break;
  }
  return ptr;
}
int main(int argc, char const* argv[]) {
  shared_ptr<Vehicle> bike = Vehicle::create(VehicleType::bike);
  cout << "Bike wheelCount=" << bike->wheelCount() << endl;
  return 0;
}
