#include <string>
#include <gtest/gtest.h>

#include "print.h"

using namespace std;

TEST(PrintTest, IntValue)
{
    print(3);
    print(7);
    print(-3);
}

TEST(PrintTest, DoubleValue)
{
    print(5.0);
    print(7.0);
    print(-3.0);
}

TEST(PrintTest, StringValue)
{
    print(string("abc"));
    print(string("xyz"));
}
