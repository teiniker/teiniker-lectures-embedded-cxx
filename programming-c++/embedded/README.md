# C++ on Embedded Systems

C++ is guided by the **zero-overhead principle** which is based on 
two concepts:

* We don't pay for what we don't use.
* What we do use is just as effective as what we could readonably 
    write by hand.

The only two language features that do not follow the zero-overhead 
principle are RTTI and Exceptions. 
Therefore, compilers support a switch for turning them off.

## Commonly Used Features 

The following C++ features are safe and practical to use even on small,
resource‑constrained embedded systems:

* **Namespaces**: Namespaces group related code under a named scope 
    to prevent naming conflicts.

* **auto**: `auto` lets the compiler deduce a variable’s type from its 
    initializer, reducing verbosity and errors.

* **References**: A reference is an alias to an existing object, 
    allowing indirect access without copying or pointer syntax.

* **Function overloading**: Function overloading lets multiple 
    functions share the same name as long as their parameter 
    types or counts differ. 

* **Default parameters**: Default parameters give function arguments 
    predefined values so callers can omit them.

* **Operator overloading**: Operator overloading lets classes define 
    how built-in operators (like `+` or `==`) behave for their objects.

* **Classes**: : A class defines a new user-defined type by bundling 
    data and behavior into a single blueprint.

* **Enum classes**: Enum classes create strongly typed enumerations 
    that avoid implicit conversions and name collisions.

* **Inheritance**: Inheritance lets a class extend another class 
    to reuse and customize its behavior.

* **Smart pointers**: Smart pointers (`std::unique_ptr`, `std::shared_ptr`)
    manage object lifetimes automatically using RAII to prevent memory 
    leaks and dangling pointers.

* **std::array**: This is a fixed-size, stack-allocated array that behaves 
    like a safe, STL-friendly alternative to C arrays.


### Resource Acquisition Is Initialization (RAII)

RAII is a C++ design principle where an **object acquires a resource 
in its constructor** and **releases it in its destructor**, guaranteeing 
that the resource is always cleaned up automatically when the object 
goes out of scope.

> Tie the lifetime of a resource to the lifetime of an object.

By resource we mean basically anything we must clean up manually:
* Heap memory
* File handles
* Temporary buffers
* Mutex locks
* Network sockets
* Hardware peripherals
* GPIO pins / drivers in embedded systems

Since cleanup is automatic, it’s extremely hard to leak memory or forget to release something.


### Templates

Templates have no overhead and can be thought of as a more powerful version of 
a pre.processor macro. 
However, incorrect/careless use of templates can cause a huge increase in code 
size. Also be careful of overusing them, too much templating makes code very 
unreadable.


### Embedded Template Library (ETL)

> The Embedded Template Library is a lightweight, deterministic, 
> STL-like library built specifically for embedded systems that can’t 
> afford dynamic allocation, exceptions, or unpredictable behavior.

The ETL is basically a *diet STL* designed for microcontrollers — it gives us 
many of the nice C++ standard library containers and utilities, but 
**without dynamic allocation**, **without exceptions**, and 
**without the unpredictable behavior** that small embedded systems can’t afford.


The ETL provides fixed-capacity, deterministic, RAM-safe versions of 
common STL types like:

* `etl::string`
* `etl::optional`
* `etl::array` (mostly identical to std::array)
* `etl::vector` (fixed max size, no heap)
* `etl::map`, `etl::unordered_map`, `etl::set`, etc. (all with compile-time capacity)
* `etl::function` (small-function optimized, no heap)

All designed to behave consistently even when exceptions and RTTI are disabled.



## Less Commonly Used Features 

The following C++ features are used less frequently or not at all, especially 
in **small (in terms of computing power and memory) embedded systems**.


### Exceptions 

In small embedded systems, exceptions tend to be more trouble than they're 
worth. They add **significant code size** because the compiler has to pull 
in stack unwinding machinery, type info, and runtime handlers. 

They also make **timing unpredictable**, since throwing and catching an 
exception isn’t constant-time — a big no-go in real-time code. 

And when RAM and flash are tight, the extra metadata and runtime support 
can eat up resources fast. 

Because of all that, **most embedded teams just turn them off**:

* `-fno-exceptions`: Turn off exceptions

_Example:_ Global configuration in CMake 

```cmake
add_compile_options(-fno-exceptions)
```

Once you build with these flags:

* `throw` and `catch` are forbidden


### Run-Time Type Information

Runtime type information (RTTI) in C++ is a mechanism that allows the **type 
of an object to be determined at runtime**. Most compilers implement RTTI 
using the **virtual tables**. 

Each polymorphic class (a class with at least one virtual function) has a 
virtual table that, among other things, includes type information for 
runtime type identification. RTTI imposes both time and space costs. 
It increases binary size and affects the runtime performance if type 
identification is used.

We can just **turn it off**:

* `-fno-rtti`: Turn off RTTI (Run-Time Type Information)

_Example:_ Global configuration in CMake 

```cmake
add_compile_options(-fno-rtti)
```
Once you build with these flags:

* `typeid()` and `dynamic_cast` stop working for polymorphic types
* The compiler no longer links in the big RTTI runtime baggage


## References

* Amar Mahmutbegović. **C++ in Embedded Systems: A practical transition from C to modern C++**. Packt Publishing, 2025

* [C++ On Embedded Systems](https://blog.mbedded.ninja/programming/languages/c-plus-plus/cpp-on-embedded-systems/)

* [Embedded Template Library](https://www.etlcpp.com/)

*Egon Teiniker, 2024-2025, GPL v3.0*
