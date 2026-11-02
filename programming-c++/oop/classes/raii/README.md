# Resource Acquisition Is Initialization (RAII)

Resource Acquisition Is Initialization (RAII) binds the lifecycle of a 
resource — such as heap memory, file handles, database connections, 
mutex locks, or network sockets — directly to the lifetime of a 
stack-allocated object.

* **Acquire in Constructor**: When an object is instantiated, its constructor 
    acquires the necessary resource (e.g., opens a file with `fopen`, locks 
    a `std::mutex`, or allocates memory with `new`). 
    If resource acquisition fails, the constructor throws an exception.

* **Use during Lifetime**: The resource remains valid and usable as long as 
    the object remains in scope.

* **Release in Destructor**: When the object goes out of scope — whether by 
    hitting a closing brace `}`, returning from a function, or unwinding 
    due to an uncaught exception — the C++ runtime automatically invokes 
    the object's destructor, which safely releases the resource (e.g., 
    calls `fclose`, unlocks the `mutex`, or executes `delete`).

In manual resource management (such as typical C programming), we must manually 
pair every resource allocation with an explicit deallocation. 
This approach is notoriously prone to bugs.

*Egon Teiniker, 2024-2026, GPL v3.0*