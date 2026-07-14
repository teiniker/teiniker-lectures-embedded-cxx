#include <gtest/gtest.h>

#include "stack.h"

TEST(StackTest, EmptyStack)
{
    Stack stack(4);

    EXPECT_TRUE(stack.is_empty());
    EXPECT_FALSE(stack.is_full());
    EXPECT_EQ(0, stack.size());
    EXPECT_EQ(4, stack.capacity());
}

TEST(StackTest, PushAndPop)
{
    Stack stack(4);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(3, stack.size());

    // LIFO order
    EXPECT_EQ(3, stack.pop());
    EXPECT_EQ(2, stack.pop());
    EXPECT_EQ(1, stack.pop());
    EXPECT_TRUE(stack.is_empty());
}

TEST(StackTest, FullStack)
{
    Stack stack(4);

    for (size_t i = 0; i < stack.capacity(); i++)
    {
        stack.push(i);
    }

    EXPECT_TRUE(stack.is_full());
    EXPECT_EQ(4, stack.size());
}

TEST(StackTest, Top)
{
    Stack stack(4);

    stack.push(1);
    stack.push(2);

    // top() reads the last pushed element without removing it
    EXPECT_EQ(2, stack.top());
    EXPECT_EQ(2, stack.top());
    EXPECT_EQ(2, stack.size());
}

TEST(StackTest, TopAfterPop)
{
    Stack stack(4);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(3, stack.pop());
    EXPECT_EQ(2, stack.top());
    EXPECT_EQ(2, stack.size());
}
