#include <cstdint>
#include <string>

#include <gtest/gtest.h>

#include "array_list.h"

class ArrayListTest : public ::testing::Test
{
protected:
    ArrayList<int, 16> list;

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
    EXPECT_EQ(16, list.capacity());
}

TEST_F(ArrayListTest, Get)
{
    EXPECT_EQ(1, list.get(0));
    EXPECT_EQ(3, list.get(1));
    EXPECT_EQ(5, list.get(2));
}

TEST_F(ArrayListTest, Find)
{
    EXPECT_EQ(2, list.find(5));
    EXPECT_EQ(-1, list.find(7));
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

TEST(ArrayListTemplateTest, FullList)
{
    ArrayList<uint8_t, 2> list;

    list.append(0xaa);
    list.append(0xbb);

    EXPECT_TRUE(list.is_full());
    EXPECT_EQ(2, list.size());
    EXPECT_EQ(2, list.capacity());
}

TEST(ArrayListTemplateTest, DifferentTypeParameters)
{
    // Every combination of T and N is a distinct type
    ArrayList<float, 8> samples;
    ArrayList<std::string, 4> names;

    samples.append(3.14f);
    names.append("Homer");
    names.append("Bart");

    EXPECT_FLOAT_EQ(3.14f, samples.get(0));
    EXPECT_EQ(1, names.find("Bart"));
}
