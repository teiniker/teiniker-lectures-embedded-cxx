# std::optional 

Many embedded developers use **explicit error handling** instead.

`std::optional` basically a tiny container that can hold:
* a **value of some type T**, or
* **no value** at all

`std::optional<T>` behaves like:
* A **boolean**: tells us whether a value exists
* A **box**: if it exists, we get the value inside

Before `std::optional`, we had to signal failure with:
* `nullptrs`
* sentinel values (`-1`, `0xFFFF`, etc.)
* output parameters + error codes
* exceptions (expensive, often disabled in embedded)

`std::optional` gives us a clean, type-safe alternative.

_Example:_ Check is a value exists
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
std::optional<int> n = std::nullopt;
```

_Example:_ Input validation 
```c++
std::optional<Temperature> makeTemperature(int16_t raw)
{
    if (raw < -40 || raw > 125)
        return std::nullopt;

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




## References

* [YouTube (The Cherno): How to Deal with OPTIONAL Data in C++](https://youtu.be/UAAiwObNhQ0?si=eFyXOsqWF-Bckxyy)

* [C++ References: std::optional](https://en.cppreference.com/w/cpp/utility/optional.html)

*Egon Teiniker, 2024-2025, GPL v3.0*