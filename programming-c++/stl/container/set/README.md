# std::set

`std::set` is an associative container that stores **unique elements**
in **sorted order**.

It is usually implemented as a **balanced binary search tree**
(red-black tree), which gives it the following properties:
* each element appears only once (duplicates are ignored)
* elements are always sorted (by default using `std::less<T>`)
* insertion, removal, and lookup take **logarithmic time** O(log n)
* elements are read-only: changing a value would break the ordering
* supports iteration (`begin()`, `end()`) in sorted order
* elements are **not** stored contiguously in memory (each node is
    allocated separately on the heap)

## Operations

* **Construction**
    We can create and initialize a `std::set` in several ways:

    * **Default Initialization**: (empty set)
        ```C++
        std::set<int> s;
        ```

    * **List Initialization**: Duplicates are removed, elements are sorted.
        ```C++
        std::set<int> s = {7, 5, 7, 16, 8};   // {5, 7, 8, 16}
        ```

    * **Range Initialization**: From another container.
        ```C++
        std::vector<int> v = {3, 1, 3, 2};
        std::set<int> s(v.begin(), v.end());  // {1, 2, 3}
        ```

    * **Custom Ordering**: The comparator is a template parameter.
        ```C++
        std::set<int, std::greater<int>> s = {7, 5, 16, 8};
        // {16, 8, 7, 5}
        ```

    * **Copy Initialization**:
        ```C++
        std::set<int> a = {1, 2, 3};
        std::set<int> b = a;   // copies all values
        ```

* **Modifying Elements**

    * **insert()**: Inserts an element and returns a
        `std::pair<iterator, bool>`. The `bool` is `false` if the element
        already existed.
        ```C++
        std::pair<std::set<int>::iterator, bool> result = s.insert(7);
        // result.first:  iterator to the element
        // result.second: true if the element was inserted
        ```

    * **emplace()**: Constructs the element in place.
        ```C++
        std::set<std::string> names;
        names.emplace("Homer");
        ```

    * **erase()**: Removes an element by value (returns the number of
        removed elements, 0 or 1) or by iterator.
        ```C++
        s.erase(5);
        s.erase(s.find(16));
        ```

    * **clear()**: Removes all elements.

* **Lookup**

    * **find()**: Returns an iterator to the element, or `end()` if it
        was not found.
        ```C++
        if (s.find(16) != s.end())
        {
            std::cout << "found";
        }
        ```

    * **count()**: Returns the number of matching elements (0 or 1).

    * **contains()**: Returns `true` if the element exists (C++20).
        ```C++
        bool found = s.contains(8);
        ```

    * **lower_bound()** and **upper_bound()**: Return an iterator to the
        first element `>= key` and `> key`, respectively.
        ```C++
        auto it = s.lower_bound(9);   // first element >= 9
        ```

* **Capacity Management**

    * **size()**: Returns the number of elements in the set.
        ```C++
        size_t len = s.size();
        ```

    * **empty()**: Checks if the set is empty.
        ```C++
        if (s.empty())
        {
            std::cout << "Set is empty";
        }
        ```
    * **max_size()**: Returns the maximum number of elements the container
        is able to hold.

* **Iterating through Elements**

    Elements are always visited in sorted order:
    ```C++
    for (int i : s)
    {
        std::cout << i << " ";
    }
    ```

    ```C++
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        std::cout << *it << " ";
    }
    ```
    Note that `*it` is always `const`; `*it = 3;` does not compile.

## Custom Types

To store a user-defined type, the set needs a **strict weak ordering**.
We can either provide `operator<` for the type or pass a comparator
function object as the second template parameter:

```C++
struct Point
{
    int x;
    int y;
};

struct PointLess
{
    bool operator()(const Point& a, const Point& b) const
    {
        if (a.x != b.x)
        {
            return a.x < b.x;
        }

        return a.y < b.y;
    }
};

std::set<Point, PointLess> points = {{2, 1}, {1, 5}, {1, 2}};
```

Two elements `a` and `b` are considered **equal** if neither
`comp(a, b)` nor `comp(b, a)` is true.

## std::set vs std::unordered_set

| Feature           | `std::set`               | `std::unordered_set`     |
| ----------------- | ------------------------ | ------------------------ |
| **Impl.**         | Balanced binary tree     | Hash table               |
| **Ordering**      | Sorted                   | No defined order         |
| **Lookup**        | O(log n)                 | O(1) avg, O(n) worst     |
| **Requirements**  | `operator<` or comparator| Hash function and `==`   |
| **Range queries** | `lower_bound()`, etc.    | Not supported            |
| **Duplicates**    | No (see `multiset`)      | No (see `unordered_...`) |

## Embedded Systems

Because every element is a separately allocated tree node, `std::set`
uses **dynamic memory** and has a per-element memory overhead (pointers
and color bit). In systems where heap allocation is restricted, a
sorted `std::array` or `std::vector` combined with `std::binary_search`
is often a better choice.

## Examples and Exercises

* [set-test](set-test/): Google Test cases demonstrating the
    operations of `std::set`.

## References

* [C++ Reference: set](https://en.cppreference.com/w/cpp/container/set.html)

*Egon Teiniker, 2024-2026, GPL v3.0*
