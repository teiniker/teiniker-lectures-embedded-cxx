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
	_size = strlen(data);
	_data = new char[_size + 1];
	strcpy(_data, data);
}
```

* Figure out how long the input C-string is:
    `strlen()` walks through the characters until it hits the null
    terminator (`'\0'`), counting how many characters there are.
    So `_size` becomes the length of the string without the null terminator.

* Allocate memory for your internal buffer:
    We need space for the characters plus one extra byte for that `'\0'` 
    terminator at the end.

* Copy the characters using `strcpy()`, which also copies the
    terminating `'\0'`, so no manual null termination is needed.

Both functions are declared in the `<cstring>` header.


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
	_size = strlen(old._data);
	_data = new char[_size + 1];
	strcpy(_data, old._data);
}
```

* Determine the length of the original string using `strlen()`, which
    counts the characters up to (but not including) the `'\0'` terminator.

* Allocate new memory: `SimpleString` creates its own fresh buffer with
    one extra byte for the null terminator.

* Copy the characters using `strcpy()`, which also copies the
    terminating `'\0'`, so no manual null termination is needed.

Now that we have a proper copy constructor, the test will pass successfully.


*Egon Teiniker, 2024-2026, GPL v3.0*