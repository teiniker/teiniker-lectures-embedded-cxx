# Classes and Objects 

Classes are the central feature of an **object oriented language**. 

* A class is a **user-defined type**.

* A class consists of a **set of members**. The most common kinds of members are data members and member functions.

* A **class is a namespace** containing its members.

* The **public members provide the class’s interface** and the **private members provide implementation details**.

* A **struct** is a class where **members are by default public**.

* Members are accessed using **. (dot) for objects** and **–> (arrow) for pointers**.

* Member functions can define the meaning of **initialization (creation)**, **copy**, **move**, and **cleanup (destruction)**.

* **Operators**, such as `+`, `!`, and `[]`, can be defined for a class.


## Class Declaration

In C++ a **class** is a user-defined type that has **attributes** 
(data members) and **methods** (member functions). 

_Example_: C++ class declaration (`book.h`)
```C++
class Book 
{
private:
    // Private fields
    std::string _title;
    std::string _author;
    std::string _isbn;

public:
    // Initializing Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn);

    // Copy Constructor
    Book(const Book &book) = default;

    // Default destructor
    ~Book() = default;  

    // Getter and Setter Methods
    std::string title() const { return _title; }                // inline method
    void title(const std::string& title) { _title = title; }    // inline method
    
    std::string author() const; 
    void author(const std::string& author);

    std::string isbn() const;
    void isbn(const std::string& isbn);

    // Methods
};
``` 

Note that the operations marked as `=default`could be skipped - in both 
cases the compiler will generate the operations for us.

An explicit use of `=default` has the benefits:
* **Explicit control** over whether the function exists
* Ability to change **visibility** (public/private/protected)
* Clear **documentation** to readers that this special member exists intentionally


### Access Control

The **public** keyword is an access specifier. It specifies the access
level of the members of the class. The public members of a class are 
**accessible from outside** the class.

The **private** keyword is also an access specifier. The private members 
of a class are **only accessible within the class**. They are not accessible 
from outside the class.

All **members of a class** (attributes and methods) are **private per default**.


### Constructor

**Constructors** are special class members which are called by the compiler 
every time an object of that class is instantiated. Constructors have the 
**same name as the class**.
 
There are three different types of constructurs in C++:

* **Default Constructors:** 
    The default constructor is the constructor which doesn’t take any 
    argument (it has no parameters).
    If we do not define any constructor explicitly, the compiler will 
    automatically provide a default constructor implicitly.    

    _Example_: `Book(void)`
    
* **Parameterized Constrcutors:**
    It is possible to pass arguments to constructors. These arguments 
    help initialize an object when it is created. Note that constructors 
    also can be overloaded.        

    _Example_: `Book(const std::string& title, const std::string& author, const std::string& isbn)`

* **Copy Constructors:**
    A copy constructor is a member function which initializes an object 
    using another object of the same class. 
    If we don’t define our own copy constructor, the C++ compiler 
    creates a default copy constructor for each class which does a 
    member-wise copy between objects (**shallow copy**) . 
    We need to define our own copy constructor only if an object has 
    pointers or any runtime allocation of the resource like file handle, 
    a network connection etc. (**deep copy**).        
    
    _Example_: `Book(const Book &book)`
    
Like functions, **constructors can be overloaded** if they differ in their 
parameter lists.    

**Default arguments** are also allowed for constructors.


### Destructor
Destructor is another special member function that is called when the 
**scope of the object ends** or the **delete operator** is called.

Destructors have same name as the class preceded by a tilde `~`, 
**don’t take any argument, and don’t return anything**.
Note that there can only be one destructor in a class.

```C++
    ~Book() = default; 
```     

If we do not write our own destructor in class, compiler creates a 
**default destructor** for us. The default destructor works fine unless 
we have dynamically allocated memory or pointer in class. 
When a class contains a pointer to memory allocated in class, we should 
write a destructor to release memory before the class instance is destroyed. 
This must be done to avoid memory leak.


### Getter and Setter Methods

Getter and setter methods are fundamental components in object-oriented 
programming (OOP). They provide controlled access to an object's internal 
data (its attributes or member variables) while maintaining the principles 
of **encapsulation** and **data hiding**.

The **const keyword** can be used in various contexts in C++, but in the 
context of member functions, it serves a specific purpose related to
const-correctness. 

**Const-correctness** ensures that functions that are not supposed to modify 
the state of an object are explicitly marked, enhancing code safety and 
readability.

* `std::string title() const`: Indicates that the `title()` member function is 
    a **constant member function**. Specifically, it promises not to modify 
    any member variables of the `Book` object (unless those members are marked 
    as mutable).

* `void title(const std::string& title)`: This marks the parameter `title` 
    as a constant reference, meaning that within the function body, **we cannot 
    modify the value of `title`**.

All the member functions defined inside the class declaration are 
by default **inline**, but we can also make any non-class function 
inline by using keyword `inline` with them. 

Inline functions are actual functions, which are copied everywhere 
during compilation, like pre-processor macro, so the overhead of 
function calling is reduced.


## Class Implementation

### Header vs. Source Files

We **separate the declaration and the implementation of methods** (header 
and source file).

_Example_: C++ class implementation (`book.cpp`)
```C++
Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : _title{title}, _author{author}, _isbn{isbn}
{
}

std::string Book::author() const 
{ 
    return _author; 
}                
void Book::author(const std::string& author) 
{ 
    _author = author; 
}  

std::string Book::isbn() const 
{ 
    return _isbn; 
}                  
void Book::isbn(const std::string& isbn) 
{ 
    _isbn = isbn; 
}        
```

When we implement methods outside a class declaration we use the 
**scope resolution :: operator**.


## Objects (Class Instances)

At runtime, programs consist of instances of classes, the so-called 
objects. The functionality of an application is created through the 
interaction of these objects.

### Objects on the Stack

To create **Objects** (instances of a class), we define variables of this 
type. Note that the methods can be called directly on these instances using 
the **dot notation**.

```C++
TEST(BookTest, Constructor) 
{
    Book book("1984", "George Orwell", "978-3730614389");

    EXPECT_EQ("1984", book.title());
    EXPECT_EQ("George Orwell", book.author());
    EXPECT_EQ("978-3730614389", book.isbn());
}
``` 
Such a `Book` object is **created on the stack** and go out of scope 
at the end of a method or function.


### Objects on the Heap

To create objects on the heap we use the **new** operator. 
To delete objects from the heap, we use the **delete operator**. 

Note that **all objects on the heap must be deleted manually** using delete.

```C++
TEST(BookTest, ConstructorWithNew) 
{
    Book* book = new Book("1984", "George Orwell", "978-3730614389");

    EXPECT_EQ("1984", book->title());
    EXPECT_EQ("George Orwell", book->author());
    EXPECT_EQ("978-3730614389", book->isbn());

    delete book;
}
``` 

The `new` operator returns a pointer to the created object, thus, 
the members of an object are accessed with the **arrow operator**.

Remember to **delete** any objects you allocate with new to avoid memory leaks 
(use delete for single objects, delete[] for arrays). 


## References
Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
* Chapter 16: Classes
* Chapter 17: Construction, Cleanup, Copy, and Move 

[C++ Classes and Objects](https://www.geeksforgeeks.org/c-classes-and-objects/)

[Constructors in C++](https://www.geeksforgeeks.org/constructors-c/)

[Copy Constructor in C++](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)

[Destructors in C++](https://www.geeksforgeeks.org/destructors-c/)

*Egon Teiniker, 2024-2025, GPL v3.0*
