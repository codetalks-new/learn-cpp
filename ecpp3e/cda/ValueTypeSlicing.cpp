#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class BaseUser
{

public:
  BaseUser(const string name) : name(name) {}
  virtual ~BaseUser() {}
  virtual const string toString() const
  {
    return this->name;
  };
  const string getName() const
  {
    return this->name;
  }

private:
  const string name;
};

class Student : public BaseUser
{
public:
  Student(const string name, const string sno) : BaseUser(name), sno(sno) {}
  virtual ~Student() {}
  const string toString() const override
  {
    string str = "Student[name=";
    str += this->getName();
    str += ",sno=";
    str += this->sno;
    str += "]";
    return str;
  }

private:
  const string sno;
};

class Teacher : public BaseUser
{
public:
  Teacher(const string name, const string tno) : BaseUser(name), tno(tno) {}
  virtual ~Teacher() {}
  const string toString() const override
  {
    string str = "Teacher[name=";
    str += this->getName();
    str += ",tno=";
    str += this->tno;
    str += "]";
    return str;
  }

private:
  const string tno;
};

void printUser(const BaseUser &user)
{
  cout << "sizeof(user)=" << sizeof(user) << endl;
  cout << user.toString() << endl;
}

int main(int argc, char const *argv[])
{
  Student stu("codetalks", "2019");
  cout << "sizeof(stu)=" << sizeof(stu) << endl;
  printUser(stu);

  return 0;
}
