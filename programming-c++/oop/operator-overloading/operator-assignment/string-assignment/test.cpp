#include <gtest/gtest.h>
#include <cstring>

#include "simple_string.h"

using namespace std;


TEST(StringTests, Constructor) 
{
    // Setup and exercise
    String str("hello");
    
    // Verify 
    EXPECT_EQ(5, str.size());
    EXPECT_STREQ("hello", str.c_str());
}

TEST(StringTests, CopyConstructor) 
{
    // Setup
    String original("world");
    
    // Exercise
    String copy = original;  // Calls copy constructor
    
    // Verify
    EXPECT_EQ(original.size(), copy.size());
    EXPECT_STREQ(original.c_str(), copy.c_str());    
}

TEST(StringTests, AssignmentOperator) 
{
    // Setup
    String str1("first");
    String str2("second");
    
    // Exercise
    str1 = str2;  // Calls assignment operator
    
    // Verify
    EXPECT_EQ(str2.size(), str1.size());
    EXPECT_STREQ(str2.c_str(), str1.c_str());    
}