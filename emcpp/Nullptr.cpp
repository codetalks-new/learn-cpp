#include <gtest/gtest.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

const char* fun(int){
  return "int";
}
const char* fun(bool){
  return "bool";
}
const char* fun(void *){
  return "void*";
}


TEST(DemoTestSuite,DemoTestCase){
  EXPECT_STREQ(fun(0), "int");
  EXPECT_STREQ(fun(true), "bool");
  // error: call to 'fun' is ambiguous EXPECT_STREQ(fun(NULL), "int");
  EXPECT_STREQ(fun(nullptr), "void*");
}
GTEST_API_ int main(int argc, char  *argv[]){
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}