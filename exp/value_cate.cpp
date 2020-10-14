#include <iostream>
#include <string>
#include <utility>
using namespace std;
void swapName(string& firstName, string& lastName) {
  string tmp(move(firstName));
  cout << "tmp before move:" << tmp << endl;
  firstName = move(lastName);
  lastName = move(tmp);
  cout << "tmp after  move:" << tmp << endl;
}

string getFirstName() {
  return "code";
}
string getLastName() {
  return "talks";
}

string makeName(string&& firstName, string&& lastName) {
  return firstName + lastName;
}

int main() {
  string firstName("code");
  string lastName("talks");
  makeName(getFirstName(), getLastName());
  makeName(move(firstName), move(lastName));

  swapName(firstName, lastName);
  cout << "firstName:" << firstName << endl;
  cout << "lastName:" << lastName << endl;
}