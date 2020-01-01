#include <string>
using std::string;

struct Header {
  string &name;
  string &value;

  Header(string &name, string &value) : name(name), value(value) {}

  int size() const {
    return this->name.size() + this->value.size();
  }
};

int main(int argc, char const *argv[]) {
  string name("Content-Type");
  string value("text/json");
  Header h1(name, value);

  Header h2(h1);
  Header h3 = h1;

  h3 = h1;

  return h3.size();
}
