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

TEST(StringIndexOperatorTests, TestOutOfBoundsIndexing)
{
    SimpleString str("Test");
    char ch = str[10];
    EXPECT_EQ(ch, 't'); // Should return last character as fallback

    const SimpleString constStr("Const");
    // Const out-of-bounds access
    const char constCh = constStr[10];
    EXPECT_EQ(constCh, 't'); // Should return last character as fallback
}

