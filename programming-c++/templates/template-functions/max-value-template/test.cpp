#include <string>
#include <gtest/gtest.h>

#include "max_value.h"

// T is deduced as int
TEST(MaxValueTest, IntValues)
{
    EXPECT_EQ(7, max_value(3, 7));
    EXPECT_EQ(7, max_value(7, 3));
    EXPECT_EQ(-3, max_value(-3, -7));
}

TEST(MaxValueTest, EqualValues)
{
    EXPECT_EQ(5, max_value(5, 5));
}

// T is deduced as double
TEST(MaxValueTest, DoubleValues)
{
    EXPECT_DOUBLE_EQ(2.5, max_value(2.5, 1.5));
    EXPECT_DOUBLE_EQ(2.5, max_value(1.5, 2.5));
}

// T is deduced as std::string (lexicographical comparison)
TEST(MaxValueTest, StringValues)
{
    std::string s = max_value(std::string("abc"), std::string("xyz"));

    EXPECT_EQ("xyz", s);
}

// Mixed argument types: deduction would fail, so we specify T explicitly
TEST(MaxValueTest, ExplicitTemplateArgument)
{
    EXPECT_DOUBLE_EQ(7.5, max_value<double>(3, 7.5));
}

