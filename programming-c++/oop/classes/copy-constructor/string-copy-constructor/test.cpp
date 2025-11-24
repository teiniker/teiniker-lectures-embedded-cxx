#include <gtest/gtest.h>
#include <cstring>

#include "simple_string.h"

using namespace std;

void print_string_by_reference(const String& str)
{
	printf("String data: %s, size: %zu\n", str.c_str(), str.size());
}

void print_string_by_value(String str)
{
	printf("String data: %s, size: %zu\n", str.c_str(), str.size());
}

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

TEST(StringTests, IndependentCopies) 
{
    // Setup
    String original("independent");
    
    // Exercise
    String copy = original;  // Calls copy constructor
    
    // Modify original's data directly (not recommended in practice)
    char* modifiableData = const_cast<char*>(original.c_str());
    modifiableData[0] = 'X';
    
    // Verify that copy remains unchanged
    EXPECT_STREQ("independent", copy.c_str());
    EXPECT_STREQ("Xndependent", original.c_str());
}

TEST(StringTests, PassByReference) 
{
    // Setup
    String str("reference");
    
    // Exercise & Verify
    print_string_by_reference(str);
}

TEST(StringTests, PassByValue) 
{
    // Setup
    String str("value");
    
    // Exercise & Verify
    print_string_by_value(str);
}