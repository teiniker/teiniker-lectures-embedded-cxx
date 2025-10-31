#include <gtest/gtest.h>
#include "stack.h"

class StackTest : public ::testing::Test 
{
protected:
    array_stack_t *stack = nullptr;

    void SetUp() override 
    {
        stack = stack_new(10);
        stack_print(stack);
        stack_push(stack, 1);
        stack_print(stack);
        stack_push(stack, 3);
        stack_print(stack);
        stack_push(stack, 5);
        stack_print(stack);
    }

    void TearDown() override 
    {
        stack_delete(stack);
        stack = nullptr;
    }
};

TEST_F(StackTest, IsNotEmpty) 
{
    EXPECT_FALSE(stack_is_empty(stack));
}

TEST_F(StackTest, IsEmpty) 
{
    stack_print(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_print(stack);

    EXPECT_TRUE(stack_is_empty(stack));
}

TEST_F(StackTest, Pop) 
{
    stack_print(stack);
    EXPECT_EQ(5, stack_pop(stack));
    stack_print(stack);
    EXPECT_EQ(3, stack_pop(stack));
    stack_print(stack);
    EXPECT_EQ(1, stack_pop(stack));
    stack_print(stack);
}

TEST_F(StackTest, Top) 
{
    EXPECT_EQ(5, stack_top(stack));
    EXPECT_EQ(5, stack_top(stack));
}

