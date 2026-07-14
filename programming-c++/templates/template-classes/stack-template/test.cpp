#include <cstdint>
#include <string>

#include <gtest/gtest.h>

#include "stack.h"

TEST(StackTest, EmptyStack)
{
    Stack<int, 4> stack;

    EXPECT_TRUE(stack.is_empty());
    EXPECT_FALSE(stack.is_full());
    EXPECT_EQ(0, stack.size());
    EXPECT_EQ(4, stack.capacity());
}

TEST(StackTest, PushAndPop)
{
    Stack<int, 4> stack;

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
    Stack<uint8_t, 2> stack;

    stack.push(0xaa);
    stack.push(0xbb);

    EXPECT_TRUE(stack.is_full());
    EXPECT_EQ(2, stack.size());
    EXPECT_EQ(2, stack.capacity());
}

TEST(StackTest, Top)
{
    Stack<int, 4> stack;

    stack.push(1);
    stack.push(2);

    // top() reads the last pushed element without removing it
    EXPECT_EQ(2, stack.top());
    EXPECT_EQ(2, stack.top());
    EXPECT_EQ(2, stack.size());
}

TEST(StackTest, TopAfterPop)
{
    Stack<int, 4> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(3, stack.pop());
    EXPECT_EQ(2, stack.top());
    EXPECT_EQ(2, stack.size());
}

TEST(StackTest, DifferentTypeParameters)
{
    // Every combination of T and N is a distinct type
    Stack<float, 8> samples;
    Stack<std::string, 4> names;

    samples.push(3.14f);
    names.push("Homer");

    EXPECT_FLOAT_EQ(3.14f, samples.pop());
    EXPECT_EQ("Homer", names.pop());
}
