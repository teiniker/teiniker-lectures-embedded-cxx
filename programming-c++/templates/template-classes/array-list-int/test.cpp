#include <gtest/gtest.h>

#include "array_list.h"

class ArrayListTest : public ::testing::Test
{
protected:
    ArrayList list{16};

    void SetUp() override
    {
        list.append(1);
        list.append(3);
        list.append(5);
    }
};

TEST_F(ArrayListTest, Size)
{
    EXPECT_EQ(3, list.size());
}

TEST_F(ArrayListTest, Get)
{
    list.print();

    EXPECT_EQ(1, list.get(0));
    EXPECT_EQ(3, list.get(1));
    EXPECT_EQ(5, list.get(2));
}

TEST_F(ArrayListTest, Find)
{
    EXPECT_EQ(2, list.find(5));
}

TEST_F(ArrayListTest, InsertFirst)
{
    list.insert(0, 10);

    EXPECT_EQ(10, list.get(0));
    EXPECT_EQ(1,  list.get(1));
    EXPECT_EQ(3,  list.get(2));
    EXPECT_EQ(5,  list.get(3));
}

TEST_F(ArrayListTest, Insert)
{
    list.insert(3, 33);

    EXPECT_EQ(1,  list.get(0));
    EXPECT_EQ(3,  list.get(1));
    EXPECT_EQ(5,  list.get(2));
    EXPECT_EQ(33, list.get(3));
}

TEST_F(ArrayListTest, RemoveFirst)
{
    list.remove(0);

    EXPECT_EQ(3, list.get(0));
    EXPECT_EQ(5, list.get(1));
}

TEST_F(ArrayListTest, Remove)
{
    list.remove(2);

    EXPECT_EQ(1, list.get(0));
    EXPECT_EQ(3, list.get(1));
}
