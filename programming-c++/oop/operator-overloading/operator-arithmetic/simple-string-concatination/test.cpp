#include <gtest/gtest.h>
#include <cstring>

#include "simple_string.h"

using namespace std;


TEST(StringArithmeticTest, TestConcatenationOperator)
{
    SimpleString str1("Hello, ");
    SimpleString str2("World!");
    SimpleString str3 = str1 + str2;

    EXPECT_EQ(str3.size(), str1.size() + str2.size());
    EXPECT_STREQ(str3.c_str(), "Hello, World!");
}

TEST(StringArithmeticTest, TestConcatenationAssignmentOperator)
{
    SimpleString str1("Hello, ");
    SimpleString str2("World!");
    str1 += str2;

    EXPECT_EQ(str1.size(), strlen("Hello, World!"));
    EXPECT_STREQ(str1.c_str(), "Hello, World!");
}
