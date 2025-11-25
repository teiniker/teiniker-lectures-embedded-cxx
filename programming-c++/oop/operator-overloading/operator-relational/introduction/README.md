# Relational Operators

Relational operators are used to **compare two objects** of a class 
to determine how they relate to each other.
These operators allow objects to be used in **conditional statements**, 
sorting algorithms, and any context where comparisons are required.

```C++
    bool operator==(const ClassName& other) const;
    bool operator!=(const ClassName& other) const;
    bool operator<(const ClassName& other) const;
    bool operator>(const ClassName& other) const;
    bool operator<=(const ClassName& other) const;
    bool operator>=(const ClassName& other) const;
```

The purpose of the relational operators is to let your objects behave 
like built-in types with respect to comparisons:

* **operator==** checks whether two objects are **equal**
* **operator!=** checks whether two objects are **not equal**
* **operator<, operator>, operator<=, operator>=** establish an 
    **ordering** between objects

Relational operators must typically be **overloaded either as member 
functions or as friend functions**, depending on whether they require 
direct access to private data.

Unlike the assignment operator, relational operators:

* **do not modify either object**
* **return a boolean value** indicating the result of the comparison

Because relational operators only inspect the internal state of the 
objects, they are almost always implemented as **const functions**.


## References
* Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
    * Chapter 18: Operator Overloading

* [Operator Overloading in C++](https://www.geeksforgeeks.org/operator-overloading-c/)


*Egon Teiniker, 2024-2025, GPL v3.0*