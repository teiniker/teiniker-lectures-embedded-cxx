#include <gtest/gtest.h>

#include "max_value.h"

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
