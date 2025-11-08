# std::array 

`std::array` is a fixed-size sequence container introduced in C++11.

It behaves like a built-in C array in that its **size is known at 
compile time**, but it also behaves like a C++ container:
* knows its size (`.size()`)
* supports iteration (`begin()`, `end()`)
* can be copied/assigned
* works with standard algorithms (`sort`, `find`, etc.)
* stores elements contiguously in memory (like a normal array)

## Operations

* **Construction**
    We can create and initialize a `std::array` in several ways:

    * **Default Initialization**: (uninitialized values)
        ```C++
        std::array<int, 5> a;   // Elements are uninitialized (like built-in array)
        ```

    * **Zero-initialize**: Using Empty Braces
        ```C++
        std::array<int, 5> a{};   // {0, 0, 0, 0, 0}
        ```

    * **List Initialization**:
        ```C++
        std::array<int, 5> a = {1, 2, 3, 4, 5};
        // or uniform initialization
        std::array<int, 5> a{1, 2, 3, 4, 5};
        ```

    * **Partial Initialization**: Missing elements are value-initialized (0 for ints):
        ```C++
        std::array<int, 5> a = {1, 2};  // becomes {1, 2, 0, 0, 0}
        ```

    * **Initialize All to Same Value**: Unsing `a.fill()`
        ```C++
        std::array<int, 5> a;
        a.fill(7); // {7, 7, 7, 7, 7}
        ```

    * **Copy Initialization**: 
        ```C++
        std::array<int, 5> a = {1, 2, 3, 4, 5};
        std::array<int, 5> b = a;   // copies all values
        ```


* **Accessing Elements**

    * **Operator[]**: Provides direct access to an element by index (no bounds checking).
        ```C++
        int value = a[2];  // Accesses the element at index 2
        ```

    * **at()**: Similar to `[]`, but performs bounds checking and throws an exception if 
        the index is out of range.
        ```C++
        int value = a.at(2);  // Throws an exception if index is invalid
        ```

    * **front()** and **back()**: Access the first and last elements, respectively.
        ```C++
        int first = a.front();
        int last = a.back();
        ```
    * **data()**: Returns a pointer to the underlying array serving as element storage.

* **Capacity Management**

    * **size()**: Returns the number of elements in the vector
        ```C++
        site_t len = a.size();
        ```

    * **empty()**: Checks if the vector is empty.
        ```C++
        if (a.empty()) 
        {
            std::cout << "Array is empty";
        }
        ```
    * **max_size()**: Returns the maximum number of elements the container is able to hold.

* **Iterating through Elements**

    We can use iterators or range-based for loops to iterate through a `std::vector`:
    ```C++
    for (int i : arr) 
    {
        std::cout << i << " ";
    }
    ```

    ```C++
    for (auto it = a.begin(); it != a.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    ```

## std::array vs std::vector

| Feature                | `std::array`                      | `std::vector`                           |
| ---------------------- | --------------------------------- | --------------------------------------- |
| **Size**               | Fixed at compile time             | Dynamic (can grow or shrink at runtime) |
| **Memory**             | Stored on the **stack** (usually) | Elements stored on the **heap**         |
| **Initialization**     | Must know size at compile time    | Size can be chosen at runtime           |
| **Performance**        | Slightly faster, no reallocations | May reallocate when growing             |
| **Interfaces**         | STL-friendly container            | STL-friendly container                  |
| **Bounds Safety**      | `at()` throws on out-of-range     | Same                                    |
| **Contiguous storage** | Yes                               | Yes                                     |



## Examples and Exercises


## References

* [C++ Reference: array](https://en.cppreference.com/w/cpp/container/array.html)

*Egon Teiniker, 2020-2024, GPL v3.0*