# std::optional 

`std::optional<T>` (C++17, header `<optional>`) represents a value which
**may or may not be present**. It is used whenever a result can be
missing in a normal, expected way, e.g. a search that finds nothing, a
sensor reading outside its valid range, or a configuration entry that
is not set.

The basic characteristics of `std::optional` are:
* **Explicit absence**: The type itself documents that a value can be
    missing. Unlike a sentinel value like `-1`, the caller cannot
    accidentally use "no value" as a normal number.
* **Value semantics**: The value is stored **inside** the optional
    object. Copying an optional copies the contained value.
* **No dynamic memory**: `std::optional` never allocates memory on the
    heap. It needs only the size of `T` plus a flag (typically
    `sizeof(std::optional<int>)` is `2 * sizeof(int)` due to alignment).
    This makes it well suited for **embedded systems**.
* **No exceptions required**: Absence is a normal state, not an error
    that has to be thrown.

`std::optional` is basically a tiny container that can hold:
* a **value of some type T**, or
* **no value** at all

`std::optional<T>` behaves like:
* A **boolean**: tells us whether a value exists
* A **box**: if it exists, we get the value inside

Before `std::optional`, we had to signal failure with:
* `nullptr`s
* sentinel values (`-1`, `0xFFFF`, etc.)
* output parameters + error codes
* exceptions (expensive, often disabled in embedded)

`std::optional` gives us a clean, type-safe alternative.

_Example:_ Check if a value exists

```c++
#include <optional>

std::optional<int> x;

if (x) 
{
    // x contains a value
    int v = x.value();
} 
else 
{
    // nothing there
}
```

_Example:_ Constructing optionals

```c++
// With value
std::optional<int> n = 42;

// Empty
std::optional<int> m = std::nullopt;
std::optional<int> k;               // Also empty
```

_Example:_ Input validation 

```c++
std::optional<Temperature> makeTemperature(int16_t raw)
{
    if (raw < -40 || raw > 125)
    {
        return std::nullopt;
    }

    return Temperature{raw};
}

// Usage:
auto temp = makeTemperature(raw);

if (!temp) 
{
    // Error handling here
} 
else 
{
    process(*temp);
}
```

## Accessing the Value

There are several ways to access the contained value:

| Operation       | Empty optional                      |
|-----------------|-------------------------------------|
| `has_value()`   | Returns `false` (same as `if (x)`)  |
| `*x`, `x->m`    | **Undefined behavior**, no check    |
| `x.value()`     | Throws `std::bad_optional_access`   |
| `x.value_or(d)` | Returns the default value `d`       |

_Example:_ Access with a default value

```c++
std::optional<int> timeout = readTimeout();

int t = timeout.value_or(1000);    // 1000 ms if not configured
```

In embedded systems with exceptions disabled, `value()` should be
avoided. Instead, check the optional first and then use `*x`, or use
`value_or()`.

_Example:_ Changing the content

```c++
std::optional<int> n;

n = 7;          // Assign a value
n.emplace(8);   // Construct a new value in place
n.reset();      // Make it empty again
n = std::nullopt;
```


## References

* [YouTube (The Cherno): How to Deal with OPTIONAL Data in C++](https://youtu.be/UAAiwObNhQ0?si=eFyXOsqWF-Bckxyy)

* [C++ References: std::optional](https://en.cppreference.com/w/cpp/utility/optional.html)

*Egon Teiniker, 2024-2026, GPL v3.0*