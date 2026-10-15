#include <cstdint>
#include <gtest/gtest.h>

#include "clamping.h"

// T is deduced as int
TEST(ClampingTest, IntValues)
{
    EXPECT_EQ(3, clamp(1, 3, 7));
    EXPECT_EQ(7, clamp(16, 3, 7));
    EXPECT_EQ(3, clamp(-3, 3, 7));
    EXPECT_EQ(5, clamp(5, 3, 7));
}

// Boundary values are returned unchanged
TEST(ClampingTest, BoundaryValues)
{
    EXPECT_EQ(3, clamp(3, 3, 7));
    EXPECT_EQ(7, clamp(7, 3, 7));
}

// T is deduced as char (comparison of character codes)
TEST(ClampingTest, CharValues)
{
    EXPECT_EQ('a', clamp('A', 'a', 'z'));
    EXPECT_EQ('z', clamp('~', 'a', 'z'));
    EXPECT_EQ('m', clamp('m', 'a', 'z'));
}

// Integer literals are of type int, so we specify T explicitly
TEST(ClampingTest, Uint8Values)
{
    EXPECT_EQ(10, clamp<uint8_t>(0, 10, 200));
    EXPECT_EQ(200, clamp<uint8_t>(255, 10, 200));
    EXPECT_EQ(100, clamp<uint8_t>(100, 10, 200));
}

// T is deduced as uint8_t from typed variables
TEST(ClampingTest, Uint8Variables)
{
    uint8_t value = 250;
    uint8_t min   = 0;
    uint8_t max   = 127;

    EXPECT_EQ(127, clamp(value, min, max));
}

// T is deduced as double
TEST(ClampingTest, DoubleValues)
{
    EXPECT_DOUBLE_EQ(-1.0, clamp(-1.5, -1.0, 1.0));
    EXPECT_DOUBLE_EQ(1.0, clamp(3.14, -1.0, 1.0));
    EXPECT_DOUBLE_EQ(0.5, clamp(0.5, -1.0, 1.0));
}

// Mixed argument types: deduction would fail, so we specify T explicitly
TEST(ClampingTest, ExplicitTemplateArgument)
{
    EXPECT_DOUBLE_EQ(7.0, clamp<double>(9.5, 3, 7));
}
