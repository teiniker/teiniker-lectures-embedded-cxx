#include <gtest/gtest.h>
#include "range.h"


TEST(RangeTests, ValidValueTest) 
{
    // Setup
    Range range(0, 100);

    // Exercise
    range.set_value(50);
    
    // Verify
    EXPECT_EQ(50, range.value());
}

TEST(RangeTests, ValueTooSmallTest) 
{
    // Setup
    Range range(0, 100);

    // Exercise
    range.set_value(-1);
    
    // Verify
    EXPECT_EQ(0, range.value());
}


TEST(RangeTests, ValueTooBigTest) 
{
    // Setup
    Range range(0, 100);

    // Exercise
    range.set_value(101);
    
    // Verify
    EXPECT_EQ(100, range.value());
}


TEST(RangeTests, ValueToooooooBigTest) 
{
    // Setup
    Range range(0, 100);

    // Exercise
    range.set_value(100000000);
    
    // Verify
    EXPECT_EQ(100, range.value());
}


TEST(RangeTests, CompareEqualTest) 
{
    // Setup
    Range range1(0, 100);
    range1.set_value(50);
    Range range2(0, 100);
    range2.set_value(50);
    
    // Exercise + Verify
    EXPECT_EQ(true, range1 == range2);
}

TEST(RangeTests, CompareNotEqualTest) 
{
    // Setup
    Range range1(0, 100);
    range1.set_value(50);
    Range range2(0, 100);
    range2.set_value(70);
    
    // Exercise + Verify
    EXPECT_EQ(true, range1 != range2);
}

TEST(RangeTests, CompareLessTest) 
{
    // Setup
    Range range1(0, 100);
    range1.set_value(50);
    Range range2(0, 100);
    range2.set_value(70);
    
    // Exercise + Verify
    EXPECT_EQ(true, range1 < range2);
}

TEST(RangeTests, CompareGraterTest) 
{
    // Setup
    Range range1(0, 100);
    range1.set_value(50);
    Range range2(0, 100);
    range2.set_value(70);
    
    // Exercise + Verify
    EXPECT_EQ(true, range2 > range1);
}

