# Resource Acquisition Is Initialization (RAII)

Resource Acquisition Is Initialization (RAII) binds the lifecycle of a
resource (such as heap memory, file handles, database connections,
mutex locks, or network sockets) directly to the lifetime of a
stack-allocated object.

* **Acquire in Constructor**: When an object is instantiated, its
    constructor acquires the necessary resource (e.g., opens a file with
    `fopen`, locks a `std::mutex`, or allocates memory with `new`).
    If resource acquisition fails, the constructor throws an exception.

* **Use during Lifetime**: The resource remains valid and usable as
    long as the object remains in scope.

* **Release in Destructor**: When the object goes out of scope (whether
    by hitting a closing brace `}`, returning from a function, or
    unwinding due to an uncaught exception), the C++ runtime
    automatically invokes the object's destructor, which safely releases
    the resource (e.g., calls `fclose`, unlocks the `mutex`, or executes
    `delete`).

In manual resource management (such as typical C programming), we must
manually pair every resource allocation with an explicit deallocation.
This approach is notoriously prone to bugs.


## Use Cases for RAII

### Dynamic Memory

Heap memory is the classic RAII resource. Instead of writing our own
classes, we often use the classes of the standard library:

* `std::vector`, `std::string`: dynamic arrays and strings.

* `std::unique_ptr`: exclusive ownership of a single heap object.

* `std::shared_ptr`: shared ownership with reference counting.

```C++
{
    auto lcd = std::make_unique<LCD>(40, 2);   // new LCD(40, 2)
    lcd->print("Hallo!");
}   // delete is called automatically
```


### Files

`std::ifstream` and `std::ofstream` open a file in the constructor and
close it in the destructor.

```C++
{
    std::ofstream log("log.txt");
    log << "Sensor value: " << value << std::endl;
}   // File is closed automatically
```


### Locks and Mutexes

A mutex that is never unlocked (e.g. because of an early `return`)
leads to a **deadlock**. `std::lock_guard` locks the mutex in its
constructor and unlocks it in its destructor.

```C++
std::mutex mtx;
int counter = 0;

void increment()
{
    std::lock_guard<std::mutex> lock(mtx);  // lock()
    counter++;
}   // unlock()
```


## Pitfalls

* **Copying**: If a class owns a raw pointer, the compiler-generated
    copy constructor only copies the pointer. Two objects then delete
    the same memory (**double free**). Follow the **Rule of Three/Five**:
    either implement or `delete` the copy (and move) operations.

* **Destructors must not throw**: A destructor is also called during
    stack unwinding. An exception thrown in a destructor at that point
    terminates the program.

* **Heap objects**: RAII only works automatically for objects with
    **automatic storage** (stack). An object created with `new` is only
    destroyed when `delete` is called. Use `std::unique_ptr` instead.

* **Exceptions in embedded systems**: Many embedded projects disable
    exceptions. RAII still works for releasing resources, but errors in
    the constructor must be reported differently (e.g. via a status
    method or a static creation method).


*Egon Teiniker, 2024-2026, GPL v3.0*
