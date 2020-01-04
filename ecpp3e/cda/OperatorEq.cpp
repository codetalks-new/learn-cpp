#include <gtest/gtest.h>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class NumValue{
  public:
    int value;
  NumValue():value(0){}
  NumValue(int value):value(value){}
  NumValue(const NumValue& nv){
    value = nv.value;
  }
  
  NumValue & operator=(const NumValue &rhs){
    value = rhs.value;
    return *this;
  }
};


TEST(OperatorEqual,ReturnRefToThis){
  NumValue v1,v2,v3;
  v1=v2=v3 = NumValue(3);
  EXPECT_EQ(3, v1.value);
  EXPECT_EQ(3, v2.value);
  EXPECT_EQ(3, v3.value);
}


GTEST_API_ int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
// build and run: 
// c++ -std=gnu++11 -lgtest -o bin/demo OperatorEq.cpp && bin/demo