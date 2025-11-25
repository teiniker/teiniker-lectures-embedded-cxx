# Example: Arithmetic Operator for Simple String Class 

In this example, an arithmetic operator is used to concatinate strings.


## Arithmetic Operator

We extend the simple string class with an assignment operator.

```C++
class String 
{
	private:
	size_t _size;
	char* _data;
	
public:                
	String(const char* data);
	String(const String& old);
	~String();

	// Assignment Operator:
	String& operator=(const String& other);
	
	size_t size() const { return _size; }
	const char* c_str() const { return _data; }
};
```

The assignment operator works similarly to the copy constructor,
but data that is already stored in the object before the assignment
is released first.

```C++
String& String::operator=(const String& other)
{
	if (this != &other) // Self-assignment check
	{
		// Release existing resource
		delete[] _data;		
		_size = other._size;
		_data = new char[_size + 1];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = other._data[i];
		}
		_data[_size] = '\0';
	}
	return *this;
}
```

* Self-assignment check: This one-line check prevents a self-destruct.

* Delete existing data: Since the object already owns a buffer, we must 
	clear it before replacing it.

* Copy size attribute.

* Allocate new buffer: We are creating a new chunk of memory.

* Copy characters: Manual copy again (like in the copy constructor).

* Add the null terminator: To keep it a valid C-string.

* Return this: This allows assignments to chain: `a = b = c;`


_Example:_ Assign a `String` object to an existing one using the assignment operator
```C++
TEST(StringTests, AssignmentOperator) 
{
    // Setup
    String str1("first");
    String str2("second");
    
    // Exercise
    str1 = str2;  // Calls assignment operator
    
    // Verify
    EXPECT_EQ(str2.size(), str1.size());
    EXPECT_STREQ(str2.c_str(), str1.c_str());    
}
```

*Egon Teiniker, 2024-2025, GPL v3.0*