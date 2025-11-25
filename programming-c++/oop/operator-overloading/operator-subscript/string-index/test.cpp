#include <gtest/gtest.h>
#include <cstring>

#include "simple_string.h"

using namespace std;


TEST(StringIndexOperatorTests, TestReadIndexing)
{
    const SimpleString str("World");
    EXPECT_EQ(str[0], 'W');
    EXPECT_EQ(str[4], 'd');
}   

TEST(StringIndexOperatorTests, TestWriteIndexing)
{
    SimpleString str("Hello");
    str[0] = 'h';
    EXPECT_EQ(str[0], 'h');
    EXPECT_STREQ(str.c_str(), "hello");
}


