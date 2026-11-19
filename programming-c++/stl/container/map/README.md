# std::map

`std::map` is an associative container that stores **key-value pairs**
with **unique keys** in **sorted order** (sorted by key).

Like `std::set`, it is usually implemented as a **balanced binary search
tree** (red-black tree), which gives it the following properties:
* each key appears only once
* elements are always sorted by key (by default using `std::less<Key>`)
* insertion, removal, and lookup take **logarithmic time** O(log n)
* each element is a `std::pair<const Key, Value>`: the key is read-only,
    the value can be modified
* supports iteration (`begin()`, `end()`) in key order
* elements are **not** stored contiguously in memory (each node is
    allocated separately on the heap)

## Operations

* **Construction**
    We can create and initialize a `std::map` in several ways:

    * **Default Initialization**: (empty map)
        ```C++
        std::map<std::string, int> m;
        ```

    * **List Initialization**: Each element is a `{key, value}` pair.
        ```C++
        std::map<std::string, int> m = {{"Homer", 39}, {"Marge", 36}};
        ```

    * **Custom Ordering**: The comparator is a template parameter.
        ```C++
        std::map<int, std::string, std::greater<int>> m =
            {{7, "seven"}, {5, "five"}, {16, "sixteen"}};
        // keys: 16, 7, 5
        ```

    * **Copy Initialization**:
        ```C++
        std::map<std::string, int> a = {{"Homer", 39}};
        std::map<std::string, int> b = a;   // copies all elements
        ```

* **Accessing Elements**

    * **Operator[]**: Returns a reference to the value of a key.
        If the key does not exist, a value-initialized element is
        **inserted** (0 for ints). Therefore it cannot be used on a
        `const` map.
        ```C++
        m["Bart"] = 10;     // inserts or overwrites
        int age = m["Lisa"]; // inserts {"Lisa", 0}
        ```

    * **at()**: Returns the value of a key, throws `std::out_of_range`
        if the key does not exist. Never inserts.
        ```C++
        int age = m.at("Homer");
        ```

* **Modifying Elements**

    * **insert()**: Inserts a pair and returns a
        `std::pair<iterator, bool>`. If the key already exists, nothing
        is changed and the `bool` is `false`.
        ```C++
        std::pair<std::map<std::string, int>::iterator, bool> result =
            m.insert(std::pair<std::string, int>("Homer", 39));
        // result.first:  iterator to the element (a key-value pair)
        // result.second: true if the element was inserted
        ```

    * **insert_or_assign()**: Inserts a new element or overwrites the
        value of an existing key (C++17).

    * **emplace()**: Constructs the element in place.
        ```C++
        m.emplace("Lisa", 8);
        ```

    * **erase()**: Removes an element by key (returns the number of
        removed elements, 0 or 1) or by iterator.
        ```C++
        m.erase("Bart");
        m.erase(m.find("Marge"));
        ```

    * **clear()**: Removes all elements.

* **Lookup**

    * **find()**: Returns an iterator to the element, or `end()` if the
        key was not found.
        ```C++
        std::map<std::string, int>::iterator it = m.find("Marge");

        if (it != m.end())
        {
            std::cout << it->first << ": " << it->second;
        }
        ```

    * **count()**: Returns the number of matching keys (0 or 1).

    * **contains()**: Returns `true` if the key exists (C++20).

    * **lower_bound()** and **upper_bound()**: Return an iterator to the
        first element with key `>= key` and `> key`, respectively.

* **Capacity Management**

    * **size()**: Returns the number of elements in the map.

    * **empty()**: Checks if the map is empty.

    * **max_size()**: Returns the maximum number of elements the container
        is able to hold.

* **Iterating through Elements**

    Elements are visited in key order. Each element is a
    `std::pair<const Key, Value>`:
    ```C++
    for (const std::pair<const std::string, int>& entry : m)
    {
        std::cout << entry.first << ": " << entry.second << "\n";
    }
    ```

    ```C++
    for (std::map<std::string, int>::iterator it = m.begin();
        it != m.end(); ++it)
    {
        it->second++;   // values can be modified, keys cannot
    }
    ```

## Custom Key Types

To use a user-defined type as key, the map needs a **strict weak
ordering** for the keys. We can either provide `operator<` for the type
or pass a comparator function object as the third template parameter:

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

std::map<Point, std::string, PointLess> labels;
labels[{1, 2}] = "A";
```

## std::map vs std::unordered_map

| Feature           | `std::map`               | `std::unordered_map`     |
| ----------------- | ------------------------ | ------------------------ |
| **Impl.**         | Balanced binary tree     | Hash table               |
| **Ordering**      | Sorted by key            | No defined order         |
| **Lookup**        | O(log n)                 | O(1) avg, O(n) worst     |
| **Requirements**  | `operator<` or comparator| Hash function and `==`   |
| **Range queries** | `lower_bound()`, etc.    | Not supported            |
| **Duplicates**    | No (see `multimap`)      | No (see `unordered_...`) |

## Embedded Systems

Because every element is a separately allocated tree node, `std::map`
uses **dynamic memory** and has a per-element memory overhead. In
systems where heap allocation is restricted, a fixed-size lookup table
(for example a sorted `std::array` of key-value structs searched with
`std::lower_bound`) is often a better choice.

## Examples and Exercises

* [map-test](map-test/): Google Test cases demonstrating the
    operations of `std::map`.

## References

* [C++ Reference: map](https://en.cppreference.com/w/cpp/container/map.html)

*Egon Teiniker, 2024-2026, GPL v3.0*
