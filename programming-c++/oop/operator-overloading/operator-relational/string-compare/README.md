# Example: Relational Operators for Simple String Class 

In this example, various relational operators are implemented 
to enable comparisons between SimpleString instances.

## Relational Operators

These implementations uses the C string functions from `string.h`:

```C++
bool SimpleString::operator==(const SimpleString& other) const
{
	return std::strcmp(_data, other._data) == 0;
}

bool SimpleString::operator!=(const SimpleString& other) const
{
	return !(*this == other);
}

bool SimpleString::operator<(const SimpleString& other) const
{
	return std::strcmp(_data, other._data) < 0;
}

bool SimpleString::operator<=(const SimpleString& other) const
{
	return (*this < other) || (*this == other);
}

bool SimpleString::operator>(const SimpleString& other) const
{
	return !(*this <= other);
}

bool SimpleString::operator>=(const SimpleString& other) const
{
	return !(*this < other);
}
```

* `operator==`: Checks if the two strings contain exactly the same characters.

* `operator!=`: This is simply “not equal.” Instead of re-implementing the logic, 
	it reuses `operator==` and negates it.

* `operator<`: Compares strings lexicographically (“dictionary order”).

* `operator<=`: This means “less than OR equal.”
	It reuses the already-defined `operator<` and `operator==` to avoid duplicate logic.

* `operator>`: This is the logical opposite of `<=`.

* `operator>=`: This is the opposite of `<`.


**Note that we cannot use `=default` for these operators**:
The default (`=default`) relational operators don’t work for custom string 
classes because the compiler only compares member variables, not the content 
those members point to.

Therefore, **implementing them manually is required**!


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
```

*Egon Teiniker, 2024-2025, GPL v3.0*