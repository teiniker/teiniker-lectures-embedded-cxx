#include <gtest/gtest.h>
#include <cstring>

#include "simple_string.h"

using namespace std;

SimpleString createSimpleString()
{
    SimpleString temp("Temporary SimpleString");
    return temp; // This will invoke the move constructor
}

TEST(MoveConstructorTests, CreateAndMove)
{
    SimpleString str = createSimpleString();
    
    EXPECT_EQ(str.size(), strlen("Temporary SimpleString"));
    EXPECT_STREQ(str.c_str(), "Temporary SimpleString");
}


TEST(MoveConstructorTests, MoveConstructorWorks)
{
    SimpleString original("Hello, World!");
    
    // Use the move constructor
    SimpleString other(std::move(original));
    
    // Check that the moved-to object has the correct data
    EXPECT_EQ(other.size(), strlen("Hello, World!"));
    EXPECT_STREQ(other.c_str(), "Hello, World!");
    
    // Check that the original object is in a valid but empty state
    EXPECT_EQ(original.size(), 0);
    EXPECT_EQ(original.c_str(), nullptr);
}
