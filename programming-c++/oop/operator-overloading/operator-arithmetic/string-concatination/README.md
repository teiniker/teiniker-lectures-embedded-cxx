# Example: Arithmetic Operator for Simple String Class 

In this example, arithmetic operators are used to concatenate SimpleString objects.


## Arithmetic Operators

We extend the simple string class with the following arithmetic operators.

The first overload defines how two `SimpleString` objects are combined 
using the addition operator `+`. It creates and returns a new `SimpleString` 
that contains the concatenation of both strings.

```C++
SimpleString SimpleString::operator+(const SimpleString& other) const
{
	size_t newSize = _size + other._size;
	char* newData = new char[newSize + 1];
	strcpy(newData, _data);
	strcat(newData, other._data);
	return SimpleString(newData);
}	
```

* **Compute the total size of the resulting string**:
	- `_size` refers to the length of the calling object’s string.
	- `other._size` is the length of the right-hand operand.
	- Their sum gives the size of the concatenated string (excluding the null terminator).	

* **Allocate memory for the new string**:
	- Allocates enough space for: All characters from both strings
		and the null terminator.
	- Memory is allocated dynamically because the result is a new independent object.

* **Copy the first string into newData**:
	Copies the contents of the calling object’s internal string `_data` 
	into the new buffer.	

* **Append the second string**:
	- Appends `other._data` to the end of `newData`.
	- At this point, `newData` contains the full concatenated string.

* **Return a new `SimpleString` object**:
	- Constructs a temporary SimpleString` using the concatenated data.
	- This object is **returned by value**.
	- The temporary object should make its own internal copy of `newData`.


The second overload defines the behavior of the addition-assignment 
operator `+=` for a SimpleString object.

Unlike `operator+` (which returns a new object), `operator+=` modifies 
the existing object in place and returns a reference to it.

```C++
SimpleString& SimpleString::operator+=(const SimpleString& other)
{
	size_t newSize = _size + other._size;
	char* newData = new char[newSize + 1];
	strcpy(newData, _data);
	strcat(newData, other._data);

	delete[] _data;		

	_size = newSize;
	_data = newData;

	return *this;
}
```

* **Calculate the new size**.

* **Allocate a new buffer** large enough to hold the result.

* **Copy the existing string into the new buffer**.

* **Append the additional string**.

* **Free the old memory**:
	- The old _data is no longer needed.
	- This avoids memory leaks.

* **Update object state** to reflect the new string:
	- The object now stores the newly allocated buffer.
	- `_size` now matches the total length of the concatenated string.

* **Return this**: 
	Returning a reference to the current object allows chaining:
	`a += b += c;`


Note that in this implementation, we rely on the **C string library  
functions** to manage the internal character array of the class.


_Example:_ Concatinate two `SimpleString` objects to a new object

```C++
TEST(StringArithmeticTest, TestConcatenationOperator)
{
    SimpleString str1("Hello, ");
    SimpleString str2("World!");
    SimpleString str3 = str1 + str2;

    EXPECT_EQ(str3.size(), str1.size() + str2.size());
    EXPECT_STREQ(str3.c_str(), "Hello, World!");
}
```

*Egon Teiniker, 2024-2025, GPL v3.0*