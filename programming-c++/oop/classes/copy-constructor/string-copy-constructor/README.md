# Example: Copy Constructor for Simple String Class 

Let’s build a minimal String class that manages its own heap-allocated C-style character buffer.

```C++
class SimpleString 
{
    private:
	size_t _size;
	char* _data;
	
public:    
	// Constrcutor
	SimpleString(const char* data);
	// Destructor
	~SimpleString();
		
    // Accessors     
 	size_t size() const { return _size; }
	const char* c_str() const { return _data; }
};
```

The **constructor** takes a C-style string (`const char*`) and turns it into our 
own `String` object.

```C++
SimpleString::SimpleString(const char* data)
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


Our custom `SimpleString` class uses `new[]` in the constructor to allocate 
a dynamic character buffer, so the **destructor**’s whole job is basically 
to clean up after that allocation.

```C++
String::~String()
{
	delete[] _data;
}
```

* Releases the memory that was allocated for the string’s internal character array.

The `SimpleString` class owns a resource (the memory pointed to by buffer) which must 
be released when it’s no longer needed. The destructor contains a single line that 
deallocates buffer. Because we have **paired the allocation and deallocation** of buffer 
with the constructor and destructor of `SimpleString`, we will **never leak the storage**.

This pattern is called **Resource Acquisition is Initialization (RAII)**.


## Copy Constructor

_Example:_ Create a copy of the SimpleString object 

```C++
TEST(SimpleStringTests, CopyConstructor) 
{
    // Setup
    SimpleString original("world");
    
    // Exercise
    SimpleString copy = original;  // Calls copy constructor
    
    // Verify
    EXPECT_EQ(original.size(), copy.size());
    EXPECT_STREQ(original.c_str(), copy.c_str());    
}
```

In this test case, a **copy of the original String is made**.

The compiler will generate a **default copy constructor** for us, which makes 
a **shallow copy** of the `SimpleString` object's data (also the `char* _data`).

```C++
SimpleString(const SimpleString& old) = default;    // Use default copy constructor
```

**When both instances go out of scope, the application will crash** because 
both destructors will delete the `_data` on the heap. 

Therefore, we have to implement our own **copy constructor**, because
we want a **deep copy** of the original `SimpleString`, not just another 
pointer to the same memory.

```C++
SimpleString::SimpleString(const SimpleString& old)
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

Now that we have a proper copy constructor, the test will pass successfully.


*Egon Teiniker, 2024-2025, GPL v3.0*