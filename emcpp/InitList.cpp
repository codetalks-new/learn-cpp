#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include<initializer_list>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::initializer_list;
using std::vector;

class Widget1 {
 public:
  const string ctorName;
  Widget1(int i, bool b) : ctorName("Ctor(ib)") {}
  Widget1(int i, double d) : ctorName("Ctor(id)") {}
};

class Widget2 {
 public:
  const string ctorName;
  Widget2(int i, bool b) : ctorName("Ctor(ib)") {}
  Widget2(int i, double d) : ctorName("Ctor(id)") {}
  Widget2(const Widget2& w) : ctorName("Ctor(copy)") {}
  Widget2(initializer_list<long double> il) : ctorName("Ctor(init_list_ld)") {}
};



TEST(CtorTestSuite, CtorNoInitList) {
  Widget1 w1(10,true);
  Widget1 w2{10,true};
  Widget1 w3(10,5.0);
  Widget1 w4{10,5.0};
  EXPECT_STREQ(w1.ctorName.c_str(), "Ctor(ib)");
  EXPECT_STREQ(w2.ctorName.c_str(), "Ctor(ib)");
  EXPECT_STREQ(w3.ctorName.c_str(), "Ctor(id)");
  EXPECT_STREQ(w4.ctorName.c_str(), "Ctor(id)");
}

TEST(CtorTestSuite, CtorWithInitList) {
  Widget2 w1(10,true);
  Widget2 w2{10,true};
  Widget2 w3(10,5.0);
  Widget2 w4{10,5.0};
  Widget2 w5(w3);
  Widget2 w6{w3};
  EXPECT_STREQ(w1.ctorName.c_str(), "Ctor(ib)");
  EXPECT_STREQ(w2.ctorName.c_str(), "Ctor(init_list_ld)");
  EXPECT_STREQ(w3.ctorName.c_str(), "Ctor(id)");
  EXPECT_STREQ(w4.ctorName.c_str(), "Ctor(init_list_ld)");
  EXPECT_STREQ(w5.ctorName.c_str(), "Ctor(copy)");
  EXPECT_STREQ(w6.ctorName.c_str(), "Ctor(copy)");
}

class Widget3 {
 public:
  const string ctorName;
  Widget3():ctorName("Ctor(default)"){}
  Widget3(int i, bool b) : ctorName("Ctor(ib)") {}
  Widget3(int i, double d) : ctorName("Ctor(id)") {}
  Widget3(const Widget3& w) : ctorName("Ctor(copy)") {}
  Widget3(initializer_list<long double> il) : ctorName("Ctor(init_list_ld)") {}

  operator double() const{
    return 3.0;
  }
};

TEST(CtorTestSuite, CtorWithInitListFloatOperator) {
  Widget3 w1;
  Widget3 w2{};
  Widget3 w3(10,5.0);
  Widget3 w4{{}};
  Widget3 w5(w3);
  Widget3 w6{w3};
  EXPECT_STREQ(w1.ctorName.c_str(), "Ctor(default)");
  EXPECT_STREQ(w2.ctorName.c_str(), "Ctor(default)");
  EXPECT_STREQ(w4.ctorName.c_str(), "Ctor(init_list_ld)");
  EXPECT_STREQ(w5.ctorName.c_str(), "Ctor(copy)");
  EXPECT_STREQ(w6.ctorName.c_str(), "Ctor(copy)");
}

TEST(CtorTestSuite,VectorCtor){
  vector<int> v1(10,20);
  vector<int> v2{10,20};
  EXPECT_EQ(v1.size(),10);
  EXPECT_EQ(v1[0],20);
  EXPECT_EQ(v1[1],20);

  EXPECT_EQ(v2.size(),2);
  EXPECT_EQ(v2[0],10);
  EXPECT_EQ(v2[1],20);
}


GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}