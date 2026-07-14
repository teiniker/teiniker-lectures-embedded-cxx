# Introduction to C++ Templates 

Templates are the C++ mechanism for **generic programming**: we write 
code once, parameterized over types (and constants), and the compiler 
generates a concrete implementation for every combination of parameters 
actually used.

* A template is **not code** - it is a **recipe for generating code**. 
    Only when a template is **instantiated** with concrete arguments 
    (`max<int>`, `Stack<uint8_t, 32>`) does the compiler produce a real 
    function or class.

* Instantiation happens **entirely at compile time**. There is no runtime 
    dispatch involved. Calling a template function is as fast as calling 
    a hand-written function for that exact type.

* Templates are the **type-safe alternative** to the C approaches for 
    generic code: preprocessor macros (no type checking, surprising 
    evaluation rules) and `void*` plus casts (no type checking, runtime 
    overhead).

The entire **Standard Template Library (STL)** (containers, algorithms,
iterators, smart pointers) is built out of templates, which is why 
`std::vector<int>` and `std::vector<std::string>` behave identically 
without sharing any runtime machinery.


## Template Functions

A **function template** defines a family of functions. The classic 
example is a `max()` function that works for any type that supports 
the `>` operator:

```C++
template <typename T>
T max_value(T a, T b)
{
    return (a > b) ? a : b;
}
```

At the call site, the compiler **deduces the template argument** from 
the parameter types:

```C++
int i = max_value(3, 7);            // T deduced as int
double d = max_value(2.5, 1.5);     // T deduced as double

std::string s = max_value(std::string("abc"), std::string("xyz"));
```

For every distinct `T`, the compiler generates a separate function 
(`max_value<int>`, `max_value<double>`, `max_value<std::string>`) each 
fully type-checked and independently optimized.

We can also specify the template argument **explicitly**, which is useful 
when deduction would fail or pick the wrong type:

```C++
double x = max_value<double>(3, 7.5);   // int argument converted to double
```

Since C++20, **constraints (concepts)** can document and enforce the 
requirements on `T` directly in the signature:

```C++
template <typename T>
    requires std::totally_ordered<T>
T max_value(T a, T b)
{
    return (a > b) ? a : b;
}
```

Without the constraint, using an unsupported type fails with a hard-to-read 
error deep inside the template body; with the constraint, the compiler 
reports the violated requirement at the call site.


## Template Classes

A **class template** defines a family of classes. In addition to type 
parameters, templates can take **non-type parameters** - compile-time 
constants such as a buffer size. This combination is particularly useful 
for embedded programming, because the size becomes part of the type and 
**no heap allocation is needed**.

_Example_: A fixed-capacity stack (`stack.h`)

```C++
#include <array>
#include <cstddef>

template <typename T, size_t N>
class Stack
{
    private:
        std::array<T, N> _data;
        size_t _index = 0;

    public:
        // Accessors
        size_t size() const { return _index; }
        size_t capacity() const { return N; }
        bool is_empty() const { return _index == 0; }
        bool is_full() const { return _index == N; }

        // Methods
        void push(const T& value) { _data[_index++] = value; }
        T pop() { return _data[--_index]; }
};
```

Every combination of `T` and `N` is a **distinct type**, created at 
compile time:

```C++
Stack<uint8_t, 32> rx_buffer;     // 32 bytes, lives on the stack/in .bss
Stack<float, 8> samples;          // a completely unrelated type

rx_buffer.push(0x42);
uint8_t byte = rx_buffer.pop();

samples.push(3.14f);              // type-safe: push(int) would not compile
```

Note that `Stack<uint8_t, 32>` and `Stack<uint8_t, 64>` are **different, 
incompatible types** - the capacity is checked by the type system, not 
at runtime.

Because the compiler must see the full definition to instantiate a 
template, **class templates are implemented completely in the header 
file** - there is no `stack.cpp` 
(see [Header File vs. Implementation File](../../implementation-aspects/header-vs-cpp/README.md)).


## Consequences

Advantages of templates:

* **Type safety without duplication**: One implementation serves all 
    types, and every instantiation is fully checked at compile time.

* **Zero runtime overhead**: No casts, no virtual dispatch, no boxing. 
    The generated code is as efficient as a hand-written version for 
    that specific type - abstractions compile away.

* **Compile-time configuration**: Non-type parameters (buffer sizes, 
    pin numbers, baud rates) are constants the optimizer can exploit.

Disadvantages of templates:

* **Code bloat**: Every instantiation generates its own copy of the 
    code. `Stack<uint8_t, 32>` and `Stack<uint8_t, 64>` duplicate all 
    methods, even though they only differ in one constant.

* **Everything lives in headers**: Implementation details are exposed, 
    every change triggers recompilation of all users, and compile times 
    grow.

* **Error messages**: Mistakes inside deeply nested template code can 
    produce notoriously long diagnostics (C++20 concepts improve this 
    considerably).

* **Harder debugging**: Stepping through instantiated template code and 
    reading mangled symbol names takes some getting used to.


### Templates in Embedded Programming

Templates fit embedded systems surprisingly well, if used deliberately:

* **Static allocation**: Non-type parameters replace dynamic memory. 
    A `Stack<uint8_t, 32>` needs no `new`, no heap, and its memory 
    footprint is known at link time - important for systems where the 
    heap is forbidden or unavailable.

* **Zero-cost hardware abstraction**: Register addresses or pin numbers 
    passed as template parameters are folded into constants; the generic 
    driver compiles to the same instructions as hard-coded code.

* **Compile-time computation**: Combined with `constexpr`, templates 
    move work (lookup tables, CRC tables, unit conversions) from runtime 
    to compile time.

But the disadvantages weigh heavier on small targets:

* **Flash is limited**: Careless instantiation with many type/size 
    combinations multiplies code size. Monitor the map file.

* The full **STL is often avoided** in deeply embedded code because 
    many containers allocate on the heap and exceptions may be disabled. 
    The [Embedded Template Library (ETL)](https://www.etlcpp.com/) 
    provides STL-like, fixed-capacity, heap-free containers - built 
    exactly on the `Stack<T, N>` pattern shown above.


## References

* Bjarne Stroustrup. **The C++ Programming Language**. Pearson 4th Edition 2017
    * Chapter 23: Templates
    * Chapter 24: Generic Programming
    * Chapter 25: Specialization

* [cppreference: Templates](https://en.cppreference.com/w/cpp/language/templates)


*Egon Teiniker, 2024-2026, GPL v3.0*
