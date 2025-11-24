# Move Semantics 

Copying can be quite time-consuming at runtime when a large amount of data 
is involved. Often, we just want to **transfer ownership of resources** 
from one object to another. 

We could make a **copy and destroy the original**, but this is often **inefficient**. 

Instead, we can move. Move semantics is move’s corollary to copy semantics, 
and it requires that after an object `y` is moved into an object `x`, `x` 
is equivalent to the former value of `y`. 
After the move, `y` is in a special state called the **moved-from state**. 

We can perform only two operations on moved-from objects: 
* (re) assign them 
* destruct them 

Note that moving an object `y` into an object `x` isn’t just a renaming: 
these are separate objects with separate storage and potentially separate 
lifetimes. 

Similar to how we specify copying behavior, we specify how objects move 
with **move constructors** and **move assignment operators**.


## Move Constructor

> A **move constructor** is a special kind of constructor in C++ 
> whose job is to **transfer resources** from one object to another 
> without copying them.

We can think of it like this:

**A move constructor doesn’t copy an object — it steals its stuff**.

And after stealing, it **leaves the original object in a safe, empty state**.


### Use Cases for the Move Constructor

In the following common situations, the compiler will prefer the move 
constructor (if available) over the copy constructor:

* **Returning a value from a function**:

    ```C++
    String makeName() 
    {
        return String("Bob");
    } // temporary is moved into the caller
    ```

* **Moving explicitly**:

    ```C++
    String a("Hello");
    String b = std::move(a);  // move constructor kicks in
    ```

* **In STL containers**: When resizing, pushing, or rearranging elements.

    ```C++
    std::vector<String> v;
    v.push_back(String("hi")); // The temporary gets moved
    ```

* **Anytime we operate on a temporary object**:
    Temporaries are rvalues, and rvalues are perfect move targets.


## Move Assignment Operator 

The move assignment operator takes an **rvalue reference** rather than 
a const lvalue reference, and you usually mark it `noexcept`.






## References

* [YouTube (The Cherno): lvalues and rvalues in C++](https://youtu.be/fbYknr-HPYE?si=fgQjcpxUjO3Zxcfa)
* [YouTube (The Cherno): Move Semantics in C++](https://youtu.be/ehMg6zvXuMY?si=lenapTauyjAwLGHX)

* Josh Lospinoso. **C++ Crash Course**. No Starch Press. 2019
    - Chapter 4: The Object Life Cycle

* Bjarne Stroustrup. **The C++ Programming Language.** Pearson 4th Edition 2017
    - Chapter 3.3: Copy and Move


*Egon Teiniker, 2024-2025, GPL v3.0*
