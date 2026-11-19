#include <gtest/gtest.h>
#include <set>
#include <string>
#include <vector>
#include <functional>

using namespace std;

TEST(SetTest, SetSize)
{
    set<int> numbers = {7, 5, 16, 8};
    size_t   len     = numbers.size();

    EXPECT_EQ(4, len);
    EXPECT_FALSE(numbers.empty());
}

TEST(SetTest, UniqueElements)
{
    // Duplicates are ignored
    set<int> numbers = {7, 5, 7, 16, 5, 8};

    EXPECT_EQ(4, numbers.size());
}

TEST(SetTest, SortedOrder)
{
    set<int>    numbers  = {7, 5, 16, 8};
    vector<int> expected = {5, 7, 8, 16};

    vector<int> result(numbers.begin(), numbers.end());

    EXPECT_EQ(expected, result);
}

TEST(SetTest, Insert)
{
    set<int> numbers;

    // insert() returns a pair: iterator to the element and a success flag
    pair<set<int>::iterator, bool> result1 = numbers.insert(7);
    EXPECT_TRUE(result1.second);
    EXPECT_EQ(7, *result1.first);

    // Inserting an existing element fails
    pair<set<int>::iterator, bool> result2 = numbers.insert(7);
    EXPECT_FALSE(result2.second);
    EXPECT_EQ(7, *result2.first);

    EXPECT_EQ(1, numbers.size());
}

TEST(SetTest, Emplace)
{
    set<string> names;

    names.emplace("Bart");
    names.emplace("Homer");
    names.emplace("Bart");

    EXPECT_EQ(2, names.size());
}

TEST(SetTest, Find)
{
    set<int> numbers = {7, 5, 16, 8};

    auto it = numbers.find(16);
    EXPECT_NE(numbers.end(), it);
    EXPECT_EQ(16, *it);

    EXPECT_EQ(numbers.end(), numbers.find(42));
}

TEST(SetTest, CountAndContains)
{
    set<int> numbers = {7, 5, 16, 8};

    // count() returns 0 or 1 for a std::set
    EXPECT_EQ(1, numbers.count(5));
    EXPECT_EQ(0, numbers.count(42));

    // contains() is available since C++20
    EXPECT_TRUE(numbers.contains(8));
    EXPECT_FALSE(numbers.contains(42));
}

TEST(SetTest, Erase)
{
    set<int> numbers = {7, 5, 16, 8};

    // Erase by value returns the number of removed elements
    EXPECT_EQ(1, numbers.erase(5));
    EXPECT_EQ(0, numbers.erase(42));

    // Erase by iterator
    numbers.erase(numbers.find(16));

    set<int> expected = {7, 8};
    EXPECT_EQ(expected, numbers);
}

TEST(SetTest, Clear)
{
    set<int> numbers = {7, 5, 16, 8};
    numbers.clear();

    EXPECT_TRUE(numbers.empty());
    EXPECT_EQ(0, numbers.size());
}

TEST(SetTest, Equals)
{
    // Insertion order does not matter
    set<int> numbers  = {7, 5, 16, 8};
    set<int> expected = {5, 7, 8, 16};

    EXPECT_EQ(expected, numbers);
}

TEST(SetTest, SetForEach)
{
    set<int> numbers = {7, 5, 16, 8};

    for (int n : numbers)
    {
        printf("%3d\n", n);
    }
}

TEST(SetTest, Iterator)
{
    set<int> numbers = {7, 5, 16, 8};

    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        printf("%3d\n", *it);
    }

    // Elements of a set are read-only: *it = 3; does not compile
    for (set<int>::const_iterator it = numbers.cbegin();
        it != numbers.cend(); ++it)
    {
        printf("%3d\n", *it);
    }
}

TEST(SetTest, LowerAndUpperBound)
{
    set<int> numbers = {5, 7, 8, 16};

    // lower_bound: first element >= key
    EXPECT_EQ(7, *numbers.lower_bound(7));
    EXPECT_EQ(16, *numbers.lower_bound(9));

    // upper_bound: first element > key
    EXPECT_EQ(8, *numbers.upper_bound(7));
    EXPECT_EQ(numbers.end(), numbers.upper_bound(16));
}

TEST(SetTest, SetSortDescending)
{
    // The comparator is a template parameter
    set<int, greater<int>> numbers  = {7, 5, 16, 8};
    vector<int>            expected = {16, 8, 7, 5};

    vector<int> result(numbers.begin(), numbers.end());

    EXPECT_EQ(expected, result);
}

// Comparator function object for a user-defined type
struct Point
{
    int x;
    int y;
};

struct PointLess
{
    bool operator()(const Point& a, const Point& b) const
    {
        if (a.x != b.x)
        {
            return a.x < b.x;
        }

        return a.y < b.y;
    }
};

TEST(SetTest, CustomComparator)
{
    set<Point, PointLess> points = {{2, 1}, {1, 5}, {1, 2}, {2, 1}};

    EXPECT_EQ(3, points.size());

    auto it = points.begin();
    EXPECT_EQ(1, it->x);
    EXPECT_EQ(2, it->y);
}
