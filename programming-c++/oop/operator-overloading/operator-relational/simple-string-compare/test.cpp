#include <gtest/gtest.h>
#include <cstring>

#include "simple_string.h"

using namespace std;

TEST(RelationalOperatorTests, EqualityOperator)
{
    SimpleString str1("Hello");
    SimpleString str2("Hello");
    SimpleString str3("World");

    EXPECT_TRUE(str1 == str2);
    EXPECT_FALSE(str1 == str3);
}

TEST(RelationalOperatorTests, InequalityOperator)
{
    SimpleString str1("Hello");
    SimpleString str2("World");

    EXPECT_TRUE(str1 != str2);
    EXPECT_FALSE(str1 != SimpleString("Hello"));
}

TEST(RelationalOperatorTests, LessThanOperator)
{
    SimpleString str1("Apple");
    SimpleString str2("Banana");

    EXPECT_TRUE(str1 < str2);
    EXPECT_FALSE(str2 < str1);
}

TEST(RelationalOperatorTests, LessThanOrEqualOperator)
{
    SimpleString str1("Apple");
    SimpleString str2("Apple");
    SimpleString str3("Banana");

    EXPECT_TRUE(str1 <= str2);
    EXPECT_TRUE(str1 <= str3);
    EXPECT_FALSE(str3 <= str1);
}

TEST(RelationalOperatorTests, GreaterThanOperator)
{
    SimpleString str1("Banana");
    SimpleString str2("Apple");

    EXPECT_TRUE(str1 > str2);
    EXPECT_FALSE(str2 > str1);
}

TEST(RelationalOperatorTests, GreaterThanOrEqualOperator)
{
    SimpleString str1("Banana");
    SimpleString str2("Banana");
    SimpleString str3("Apple");

    EXPECT_TRUE(str1 >= str2);
    EXPECT_TRUE(str1 >= str3);
    EXPECT_FALSE(str3 >= str1);
}

