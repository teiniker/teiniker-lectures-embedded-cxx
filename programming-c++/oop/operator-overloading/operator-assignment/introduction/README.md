# Assignment Operator

The assignment `operator=` is used to copy values from one object 
to another already existing object.

```C++
    ClassName& operator =(const lassName& orig);
```

The purpose of the copy constructor and the assignment operator are almost 
equivalent - both copy one object to another: 

* The **copy constructor initializes new objects**

* The **assignment operator replaces the contents of existing objects**

The assignment operator must be **overloaded as a member function**.
	
The overloaded **operator=** returns ***this**, so that we can chain multiple 
assignments together.


## this Pointer

The **this pointer** is a special, implicit pointer available within all non-static 
member functions of a class. It **points to the instance of the class** for which 
the member function is currently being invoked.     


## Assignment Operator vs. Copy Constructor

Both copy the state of one object into another, but they are
called in different situations and have different responsibilities.

| Aspect           | Copy Constructor        | Assignment Operator        |
|------------------|-------------------------|----------------------------|
| Target object    | Does not exist yet      | Already exists             |
| Purpose          | Initialize a new object | Replace the existing state |
| Old resources    | None to release         | Must be released first     |
| Self-assignment  | Not possible            | Must be handled            |
| Return value     | None (constructor)      | `*this` as `ClassName&`    |
| Initializer list | Can be used             | Not available              |

The compiler decides which operation is called based on whether a **new
object is created** or an **existing object is overwritten**:

```C++
    SimpleString a("Hello");
    SimpleString b = a;     // Copy Constructor (b is created)
    SimpleString c(a);      // Copy Constructor (c is created)

    SimpleString d("World");
    d = a;                  // Assignment Operator (d already exists)
```

Note that `SimpleString b = a;` uses the `=` sign, but it is an
**initialization**, not an assignment. Therefore, the copy constructor
is called.

### Copy Constructor

The copy constructor works on a freshly created object, which does not
own any resources yet. It only has to allocate memory and copy the data:

```C++
SimpleString::SimpleString(const SimpleString& old)
{
    _size = old._size;
    _data = new char[_size + 1];
    strcpy(_data, old._data);
}
```

### Assignment Operator

The assignment operator works on an object that already owns resources.
It therefore has to do more work:

1. **Check for self-assignment** (`a = a;`). Without this check, the
    object would release its own data before copying it.

2. **Release the existing resources** to avoid memory leaks.

3. **Copy the data** from the other object (the same as in the copy
    constructor).

4. **Return `*this`** to allow chained assignments like `a = b = c;`.

```C++
SimpleString& SimpleString::operator=(const SimpleString& other)
{
    if (this != &other)     // 1. Self-assignment check
    {
        delete[] _data;     // 2. Release existing resource

        _size = other._size;    // 3. Copy data
        _data = new char[_size + 1];
        strcpy(_data, other._data);
    }

    return *this;           // 4. Enable chained assignments
}
```

### Rule of Three

If a class manages a resource (e.g. dynamically allocated memory), the
compiler generated versions only copy the pointer (**shallow copy**).
Two objects would then share the same memory, which leads to double
deletes in the destructor.

Therefore, if a class needs one of the following member functions, it
usually needs all three of them:

* Destructor
* Copy Constructor
* Assignment Operator

## References
* Josh Lospinoso. **C++ Crash Course**. No Starch Press. 2019
    - Chapter 4: The Object Life Cycle
    
* [Overloading the assignment operator](https://www.learncpp.com/cpp-tutorial/9-14-overloading-the-assignment-operator/)

*Egon Teiniker, 2024-2026, GPL v3.0*
