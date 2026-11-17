# Example: Spaceship Operator for Simple String Class 

In this example, the relational operators of the `SimpleString` class
are implemented using the C++20 **three-way comparison operator**
`<=>` (also called **spaceship operator**).

## Spaceship Operator

Instead of implementing six relational operators, we only implement
two of them:

```C++
#include <compare>

bool SimpleString::operator==(const SimpleString& other) const
{
    return std::strcmp(_data, other._data) == 0;
}

std::strong_ordering SimpleString::operator<=>(
    const SimpleString& other) const
{
    return std::strcmp(_data, other._data) <=> 0;
}
```

* `operator==`: Checks if the two strings contain exactly the same
    characters.

* `operator<=>`: Compares strings lexicographically ("dictionary
    order") and returns a `std::strong_ordering` value:
    `less`, `equal`, or `greater`.
    `strcmp()` returns an `int`, and `int <=> 0` converts this result
    into a `std::strong_ordering`.

The compiler **rewrites the remaining operators** using these two:

| Expression | Rewritten as      |
|------------|-------------------|
| `a != b`   | `!(a == b)`       |
| `a < b`    | `(a <=> b) < 0`   |
| `a <= b`   | `(a <=> b) <= 0`  |
| `a > b`    | `(a <=> b) > 0`   |
| `a >= b`   | `(a <=> b) >= 0`  |

We use `std::strong_ordering` because two strings which compare equal
are fully interchangeable.

**Note that we cannot use `=default` for these operators**:
A defaulted `operator<=>` compares the member variables one by one.
For `char* _data` this would compare the **pointer addresses**, not
the characters they point to.

Also note that a user-defined `operator<=>` does **not** generate
`operator==`. Only a defaulted `operator<=>` implicitly declares a
defaulted `operator==`. Therefore, **`operator==` must be implemented
manually** as well.

_Example:_ Perform comparisons between `SimpleString` objects

```C++
TEST(RelationalOperatorTests, EqualityOperator)
{
    SimpleString str1("Hello");
    SimpleString str2("Hello");
    SimpleString str3("World");

    EXPECT_TRUE(str1 == str2);
    EXPECT_FALSE(str1 == str3);
}

TEST(RelationalOperatorTests, InequalityOperator)
{
    SimpleString str1("Hello");
    SimpleString str2("World");

    EXPECT_TRUE(str1 != str2);
    EXPECT_FALSE(str1 != SimpleString("Hello"));
}

TEST(RelationalOperatorTests, LessThanOperator)
{
    SimpleString str1("Apple");
    SimpleString str2("Banana");

    EXPECT_TRUE(str1 < str2);
    EXPECT_FALSE(str2 < str1);
}
//...

TEST(RelationalOperatorTests, SpaceshipOperator)
{
    SimpleString str1("Apple");
    SimpleString str2("Apple");
    SimpleString str3("Banana");

    EXPECT_EQ(str1 <=> str2, std::strong_ordering::equal);
    EXPECT_EQ(str1 <=> str3, std::strong_ordering::less);
    EXPECT_EQ(str3 <=> str1, std::strong_ordering::greater);
}
```

*Egon Teiniker, 2024-2026, GPL v3.0*