# Arithmetic Operators

Arithmetic operators are used to **perform mathematical operations** on 
objects of a class.
To enable arithmetic expressions (such as addition or subtraction) between 
class objects, these operators must be **overloaded**.

```C++
    ClassName operator +(const ClassName& rhs) const;
    ClassName operator -(const ClassName& rhs) const;
    ClassName operator *(const ClassName& rhs) const;
    ClassName operator /(const ClassName& rhs) const;
```

Arithmetic operators **create and return new objects** based on the values 
of the operands.

* The **left-hand side object is not modified**
* The operator **returns a new instance** containing the result 
    of the operation

Arithmetic operators are usually overloaded as **const member functions** 
or **friend functions**, depending on whether access to private data is 
required and whether implicit conversions are desired.


### General Guidelines

* Arithmetic operators should **not** modify the operands.
* They should return a **new object** constructed from the computed result.
* Use `const` correctness to ensure the objects being operated on remain unchanged.
* When necessary, leverage the **this pointer** to access the calling object's data.


## References
* Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
    * Chapter 18: Operator Overloading

* [Operator Overloading in C++](https://www.geeksforgeeks.org/operator-overloading-c/)


*Egon Teiniker, 2024-2025, GPL v3.0*