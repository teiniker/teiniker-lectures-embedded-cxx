#include <gtest/gtest.h>
#include <cstring>

#include "simple_string.h"

using namespace std;


TEST(StringTests, Constructor) 
{
    // Setup and exercise
    SimpleString str("hello");
    
    // Verify 
    EXPECT_EQ(5, str.size());
    EXPECT_STREQ("hello", str.c_str());
}

TEST(StringTests, CopyConstructor) 
{
    // Setup
    SimpleString original("world");
    
    // Exercise
    SimpleString copy = original;  // Calls copy constructor
    
    // Verify
    EXPECT_EQ(original.size(), copy.size());
    EXPECT_STREQ(original.c_str(), copy.c_str());    
}

TEST(StringTests, AssignmentOperator) 
{
    // Setup
    SimpleString str1("first");
    SimpleString str2("second");
    
    // Exercise
    str1 = str2;  // Calls assignment operator
    
    // Verify
    EXPECT_EQ(str2.size(), str1.size());
    EXPECT_STREQ(str2.c_str(), str1.c_str());    
}

TEST(StringTests, SelfAssignment) 
{
    // Setup
    SimpleString str("self");
    
    // Exercise
    str = str;  // Self-assignment
    
    // Verify
    EXPECT_EQ(4, str.size());
    EXPECT_STREQ("self", str.c_str());    
}
