# Subscript Operators

Subscript operators are used to **access elements** within an object as if 
it were an array.
To enable array-style indexing (such as `obj[i]`) on class objects, the 
subscript operator must be **overloaded**.

```C++
    Type& operator[](size_t index);
    const Type& operator[](size_t index) const;
```

The subscript operator provides **direct access** to internal elements of an object.

* The **non-const version allows modification** of the accessed element.
* The **const version provides read-only access** for const objects.

Unlike arithmetic operators, the subscript operator **does not create a new object**.
Instead, it **returns a reference** to an element stored inside the current object.

Subscript operators must be overloaded as **member functions**, because 
the left-hand operand (the object being indexed) must be known.


### General Guidelines

* The operator should **validate the index** when possible (for safety).
* Return a **reference** so the element can be modified or used efficiently.
* Provide both **const** and **non-const** versions:
  * non-const for assignments (`obj[i] = value;`)
  * const for inspection (`value = obj[i];`)
* When necessary, use the **this pointer** to refer to the calling object's 
    internal storage.


## References
* Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
    * Chapter 18: Operator Overloading

* [Operator Overloading in C++](https://www.geeksforgeeks.org/operator-overloading-c/)


*Egon Teiniker, 2024-2025, GPL v3.0*