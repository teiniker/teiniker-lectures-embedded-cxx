# Example: Assignment Operator for Simple String Class 

In this example, the assignment operator turns our object into a deep 
copy of the other String, safely and correctly, avoiding:
* Memory leaks
* Double-deletes
* Self-assignment disasters

It pairs with the destructor and copy constructor to form a well-behaved 
string class using raw heap memory.

## Assignment Operator

The assignment operator works similarly to the copy constructor,
but **data that is already stored in the object before the assignment
is released first**.

```C++
SimpleString& SimpleString::operator=(const SimpleString& other)
{
	// Self-assignment check
	if (this != &other) 
	{
		// Release existing resource
		delete[] _data;		
		_size = other._size;
		_data = new char[_size + 1];
		strcpy(_data, other._data);
	}
	return *this;
}
```

* **Self-assignment check**: This one-line check prevents a self-destruct.

* **Delete existing data**: Since the object already owns a buffer, we must 
	clear it before replacing it.

* **Copy size attribute**.

* **Allocate new buffer**: We are creating a new chunk of memory.

* **Copy characters**: Copy the characters using `strcpy()` (like in the
	copy constructor), which also copies the null terminator `'\0'`.

* **Return this**: This allows assignments to chain: `a = b = c;`


_Example:_ Assign a `SimpleString` object to an existing one using 
	the assignment operator

```C++
TEST(SimpleStringTests, AssignmentOperator) 
{
    // Setup
    SimpleString str1("first");
    SimpleString str2("second");
    
    // Exercise
    str1 = str2;  // Calls assignment operator
    
    // Verify
    EXPECT_EQ(str2.size(), str1.size());
    EXPECT_STREQ(str2.c_str(), str1.c_str());    
}
```

*Egon Teiniker, 2024-2026, GPL v3.0*
