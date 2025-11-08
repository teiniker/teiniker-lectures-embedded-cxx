#include <gtest/gtest.h>
#include <array>
#include <algorithm>

using namespace std;

TEST(ArrayTest, ArrayLength) 
{
   array<int, 4> numbers = {7, 5, 16, 8};
   size_t len = numbers.size();

   EXPECT_EQ(4, len);
}

TEST(ArrayTest, IndexOperator) 
{
   array<int, 4> numbers = {7, 5, 16, 8};

   EXPECT_EQ(7, numbers[0]);
   EXPECT_EQ(5, numbers[1]);
   EXPECT_EQ(16, numbers[2]);
   EXPECT_EQ(8, numbers[3]);
}

TEST(ArrayTest, Access) 
{
   array<int, 4> numbers = {7, 5, 16, 8};

   EXPECT_EQ(7, numbers.at(0));
   EXPECT_EQ(5, numbers.at(1));
   EXPECT_EQ(16, numbers.at(2));
   EXPECT_EQ(8, numbers.at(3));
}

TEST(ArrayTest, Equals) 
{
   array<int, 4> numbers = {7, 5, 16, 8};
   array<int, 4> expected = {7, 5, 16, 8};
   
   EXPECT_EQ(expected, numbers);
}

TEST(ArrayTest, ArrayForEach) 
{
   array<int, 4> numbers = {7, 5, 16, 8};
   
   for(int n : numbers) 
   {
      printf("%3d\n", n);
   }
}


TEST(ArrayTest, Iterator) 
{
   array<int, 4> numbers = {7, 5, 16, 8};
   
   for(auto it = numbers.begin(); it != numbers.end(); ++it) 
   {
      printf("%3d\n", *it);
   }  

   for(array<int, 4>::iterator it = numbers.begin(); it != numbers.end(); ++it) 
   {
      printf("%3d\n", *it);
   }  
}

TEST(ArrayTest, ArraySort) 
{
   array<int, 4> numbers = {7, 5, 16, 8};
   sort(numbers.begin(), numbers.end());

   array<int, 4> expected = {5, 7, 8, 16};
   EXPECT_EQ(expected, numbers);
}

// Comparator function to sort in descending order
bool compareDesc(int a, int b) 
{
   return a > b;
}

TEST(ArrayTest, ArraySortDescending) 
{
   array<int, 4> numbers = {7, 5, 16, 8};
   sort(numbers.begin(), numbers.end(), compareDesc);
   
   array<int, 4> expected = {16, 8, 7, 5};
   EXPECT_EQ(expected, numbers);
}
