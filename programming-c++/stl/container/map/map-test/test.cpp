#include <gtest/gtest.h>
#include <map>
#include <string>
#include <vector>
#include <functional>
#include <stdexcept>

using namespace std;

TEST(MapTest, MapSize)
{
    map<string, int> ages = {{"Homer", 39}, {"Marge", 36}, {"Bart", 10}};
    size_t           len  = ages.size();

    EXPECT_EQ(3, len);
    EXPECT_FALSE(ages.empty());
}

TEST(MapTest, UniqueKeys)
{
    // Duplicate keys are ignored, the first value wins
    map<string, int> ages = {{"Bart", 10}, {"Lisa", 8}, {"Bart", 11}};

    EXPECT_EQ(2, ages.size());
    EXPECT_EQ(10, ages["Bart"]);
}

TEST(MapTest, SortedOrder)
{
    // Elements are sorted by key
    map<int, string> numbers  = {{7, "seven"}, {5, "five"}, {16, "sixteen"}};
    vector<int>      expected = {5, 7, 16};

    vector<int> keys;

    for (const pair<const int, string>& entry : numbers)
    {
        keys.push_back(entry.first);
    }

    EXPECT_EQ(expected, keys);
}

TEST(MapTest, IndexOperator)
{
    map<string, int> ages;

    // operator[] inserts a new element if the key does not exist
    ages["Homer"] = 39;
    ages["Marge"] = 36;

    // operator[] overwrites the value of an existing key
    ages["Homer"] = 40;

    EXPECT_EQ(40, ages["Homer"]);
    EXPECT_EQ(36, ages["Marge"]);

    // Reading a missing key inserts a value-initialized element (0)
    EXPECT_EQ(0, ages["Bart"]);
    EXPECT_EQ(3, ages.size());
}

TEST(MapTest, Access)
{
    map<string, int> ages = {{"Homer", 39}, {"Marge", 36}};

    EXPECT_EQ(39, ages.at("Homer"));
    EXPECT_EQ(36, ages.at("Marge"));

    // at() performs bounds checking and does not insert
    EXPECT_THROW(ages.at("Bart"), out_of_range);
    EXPECT_EQ(2, ages.size());
}

TEST(MapTest, Insert)
{
    map<string, int> ages;

    // insert() returns a pair: iterator to the element and a success flag
    pair<map<string, int>::iterator, bool> result1 =
        ages.insert(pair<string, int>("Homer", 39));
    EXPECT_TRUE(result1.second);
    EXPECT_EQ("Homer", result1.first->first);
    EXPECT_EQ(39, result1.first->second);

    // Inserting an existing key fails, the value is not changed
    pair<map<string, int>::iterator, bool> result2 =
        ages.insert(pair<string, int>("Homer", 40));
    EXPECT_FALSE(result2.second);
    EXPECT_EQ(39, result2.first->second);

    EXPECT_EQ(1, ages.size());
}

TEST(MapTest, InsertOrAssign)
{
    map<string, int> ages = {{"Homer", 39}};

    // insert_or_assign() overwrites an existing value (C++17)
    pair<map<string, int>::iterator, bool> result =
        ages.insert_or_assign("Homer", 40);
    EXPECT_FALSE(result.second);
    EXPECT_EQ(40, ages.at("Homer"));
}

TEST(MapTest, Emplace)
{
    map<string, int> ages;

    ages.emplace("Bart", 10);
    ages.emplace("Lisa", 8);
    ages.emplace("Bart", 11);

    EXPECT_EQ(2, ages.size());
    EXPECT_EQ(10, ages.at("Bart"));
}

TEST(MapTest, Find)
{
    map<string, int> ages = {{"Homer", 39}, {"Marge", 36}};

    map<string, int>::iterator it = ages.find("Marge");
    EXPECT_NE(ages.end(), it);
    EXPECT_EQ("Marge", it->first);
    EXPECT_EQ(36, it->second);

    EXPECT_EQ(ages.end(), ages.find("Bart"));
}

TEST(MapTest, CountAndContains)
{
    map<string, int> ages = {{"Homer", 39}, {"Marge", 36}};

    // count() returns 0 or 1 for a std::map
    EXPECT_EQ(1, ages.count("Homer"));
    EXPECT_EQ(0, ages.count("Bart"));

    // contains() is available since C++20
    EXPECT_TRUE(ages.contains("Marge"));
    EXPECT_FALSE(ages.contains("Bart"));
}

TEST(MapTest, Erase)
{
    map<string, int> ages = {{"Homer", 39}, {"Marge", 36}, {"Bart", 10}};

    // Erase by key returns the number of removed elements
    EXPECT_EQ(1, ages.erase("Bart"));
    EXPECT_EQ(0, ages.erase("Lisa"));

    // Erase by iterator
    ages.erase(ages.find("Marge"));

    map<string, int> expected = {{"Homer", 39}};
    EXPECT_EQ(expected, ages);
}

TEST(MapTest, Clear)
{
    map<string, int> ages = {{"Homer", 39}, {"Marge", 36}};
    ages.clear();

    EXPECT_TRUE(ages.empty());
    EXPECT_EQ(0, ages.size());
}

TEST(MapTest, Equals)
{
    // Insertion order does not matter
    map<string, int> ages     = {{"Marge", 36}, {"Homer", 39}};
    map<string, int> expected = {{"Homer", 39}, {"Marge", 36}};

    EXPECT_EQ(expected, ages);
}

TEST(MapTest, MapForEach)
{
    map<string, int> ages = {{"Homer", 39}, {"Marge", 36}, {"Bart", 10}};

    // Each element is a pair<const Key, Value>
    for (const pair<const string, int>& entry : ages)
    {
        printf("%-6s %3d\n", entry.first.c_str(), entry.second);
    }
}

TEST(MapTest, Iterator)
{
    map<string, int> ages = {{"Homer", 39}, {"Marge", 36}, {"Bart", 10}};

    // Values can be modified through an iterator, keys cannot
    for (map<string, int>::iterator it = ages.begin(); it != ages.end();
        ++it)
    {
        it->second++;
    }

    for (map<string, int>::const_iterator it = ages.cbegin();
        it != ages.cend(); ++it)
    {
        printf("%-6s %3d\n", it->first.c_str(), it->second);
    }

    EXPECT_EQ(11, ages.at("Bart"));
}

TEST(MapTest, LowerAndUpperBound)
{
    map<int, string> numbers = {{5, "five"}, {7, "seven"}, {16, "sixteen"}};

    // lower_bound: first element with key >= given key
    EXPECT_EQ(7, numbers.lower_bound(7)->first);
    EXPECT_EQ(16, numbers.lower_bound(9)->first);

    // upper_bound: first element with key > given key
    EXPECT_EQ(16, numbers.upper_bound(7)->first);
    EXPECT_EQ(numbers.end(), numbers.upper_bound(16));
}

TEST(MapTest, MapSortDescending)
{
    // The comparator is a template parameter
    map<int, string, greater<int>> numbers =
        {{7, "seven"}, {5, "five"}, {16, "sixteen"}};
    vector<int> expected = {16, 7, 5};

    vector<int> keys;

    for (const pair<const int, string>& entry : numbers)
    {
        keys.push_back(entry.first);
    }

    EXPECT_EQ(expected, keys);
}

TEST(MapTest, WordCount)
{
    vector<string>   words = {"red", "green", "red", "blue", "red", "green"};
    map<string, int> counts;

    for (const string& word : words)
    {
        counts[word]++;
    }

    EXPECT_EQ(3, counts.at("red"));
    EXPECT_EQ(2, counts.at("green"));
    EXPECT_EQ(1, counts.at("blue"));
}

// Comparator function object for a user-defined key type
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

TEST(MapTest, CustomComparator)
{
    map<Point, string, PointLess> labels;

    labels[{2, 1}] = "B";
    labels[{1, 5}] = "A2";
    labels[{1, 2}] = "A1";
    labels[{2, 1}] = "B*";

    EXPECT_EQ(3, labels.size());

    map<Point, string, PointLess>::iterator it = labels.begin();
    EXPECT_EQ(1, it->first.x);
    EXPECT_EQ(2, it->first.y);
    EXPECT_EQ("A1", it->second);

    EXPECT_EQ("B*", labels.at({2, 1}));
}
