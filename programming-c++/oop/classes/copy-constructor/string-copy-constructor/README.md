# Example: Simple String 

Let’s build a minimal String class that manages its own heap-allocated C-style character buffer.

```C++
class String 
{
    private:
	size_t _size;
	char* _data;
	
public:                
	String(const char* data);
	~String();
		
    // Accessors     
 	size_t size() const { return _size; }
	const char* c_str() const { return _data; }
};
```

The **constructor** takes a C-style string (`const char*`) and turns it into our 
own `String` object.

```C++
String::String(const char* data)
{
	_size = 0;
	while (data[_size] != '\0')
	{
		_size++;
	}

	_data = new char[_size + 1];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = data[i];
	}

    _data[_size] = '\0';
}
```

* Figure out how long the input C-string is:
    It just walks through the characters until it hits the null terminator 
    (`'\0'`), counting how many characters there are.
    So `_size` becomes the length of the string without the null terminator.

* Allocate memory for your internal buffer:
    We need space for the characters plus one extra byte for that `'\0'` 
    terminator at the end.

* Copy each character manually: Straight-up for-loop copy.     

* Add a null terminator:
    Since `_size` counts just the characters, position `_size` is where 
    the terminator goes.


Our custom `String` class uses `new[]` in the constructor to allocate 
a dynamic character buffer, so the **destructor**’s whole job is basically 
to clean up after that allocation.

```C++
String::~String()
{
	delete[] _data;
}
```

* Releases the memory that was allocated for the string’s internal character array.

## Copy Constructor

_Example:_ Create a copy of the String object 

```C++
TEST(StringTests, CopyConstructor) 
{
    // Setup
    String original("world");
    
    // Exercise
    String copy = original;  // Calls copy constructor
    
    // Verify
    EXPECT_EQ(original.size(), copy.size());
    EXPECT_STREQ(original.c_str(), copy.c_str());    
}
```

In this test case, a copy of the original String is made.
The compiler will generate a default copy constructor for us, which makes 
a shallow copy of the String object's data (also the `char* _data`).

```C++
String(const String& old) = default;    // Use default copy constructor
```

Wenn both instances go out of scope, the application will crash because 
both destructors will delete the `_data` on the heap. 

So, we have to implement our own **copy constructor**.
We want a **deep copy** of the original String, not just another pointer 
to the same memory.

```C++
String::String(const String& old)
{
	_size = old._size;

	_data = new char[_size + 1];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = old._data[i];
	}
	_data[_size] = '\0';
}
```

* Copy the `_size` attribute value.

* Allocate new memory: `String` creates its own fresh buffer.

* Copy the actual characters: One-by-one copying.

* Null-terminate the new string


*Egon Teiniker, 2024-2025, GPL v3.0*