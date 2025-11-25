# Example: Index Operator for Simple String Class 

This example demonstrates using the index operator (a.k.a. subscript operator) 
to retrieve characters from `SimpleString` instances.


## Index Operator

We extend the `SimpleString` class with two index operators.

The first implementation is the **non-const subscript operator**, which 
allows users to **access and modify a character** within a `SimpleString` 
object using array notation:

```C++
str[i] = 'X';   // modification is allowed
```

Because it **returns a reference to a character** `char&`, callers can 
change the internal data via this operator.

```C++
char& SimpleString::operator[](size_t index)
{
	return _data[index];
}
```

* Parameter: size_t index: The user supplies the position they want to 
access in the string.

* No bounds checking: 
    Like in standard containers (e.g., `std::vector`, `std::string`) we 
    do not do bounds checking in operator[].

* Return the indexed element:
    - `_data` is the internal C-style character array.
    - return `_data[index]` returns a reference to the character at 
        that position. Because the return type is char&, the caller 
        can modify the character.


This second version of operator[] is used when the `SimpleString` object 
itself is const or when you only want **read-only access** to its characters.

```C++
const char& SimpleString::operator[](size_t index) const
{
	return _data[index];
}
```


* Because the **operator ends with const**, the function does not modify 
    the object, and can be called on const instances.

* No bounds checking.

* Because the **operator returns a `const char&`**, the caller cannot change 
    the returned character.


_Example:_ Using the index operator to read and write single characters in 
    `SimpleString` objects.

```C++
TEST(StringIndexOperatorTests, TestReadIndexing)
{
    const SimpleString str("World");
    EXPECT_EQ(str[0], 'W');
    EXPECT_EQ(str[4], 'd');
}   
```

```C++

TEST(StringIndexOperatorTests, TestWriteIndexing)
{
    SimpleString str("Hello");
    str[0] = 'h';
    EXPECT_EQ(str[0], 'h');
    EXPECT_STREQ(str.c_str(), "hello");
}
```

*Egon Teiniker, 2024-2025, GPL v3.0*