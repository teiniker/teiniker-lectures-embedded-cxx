# Introduction 

C++ is widely used in embedded systems development due to its combination 
of high performance, low-level hardware access, and advanced features such 
as object-oriented programming.


## Features of C++ 

* **Performance and Efficiency**
   * C++ offers close-to-hardware performance similar to C.
   * Enables fine-grained control over memory and CPU usage—crucial for 
   resource-constrained embedded environments.

* **Object-Oriented Programming (OOP)**
   * Supports classes, inheritance, encapsulation, and polymorphism.
   * Encourages modular design and reusable code, which simplifies maintenance 
   and scaling of firmware.

* **Code Reusability and Maintainability**
   * Templates and STL (though used sparingly) allow for generic programming 
   and reusable components.

* **Better Type Safety and Abstraction**
   * C++ provides stronger type checking and support for abstract interfaces, 
   reducing bugs and improving software robustness.


## C++ in Embedded Systems

C++ is increasingly popular in embedded systems for its ability to balance 
high-level abstractions with low-level hardware control. 

Common applications and practices of C++ in embedded systems:

* **Microcontroller Programming**
    * C++ is used to write firmware for microcontrollers like ARM Cortex-M, 
    AVR, or ESP32.
    * Common toolchains: GCC for ARM (arm-none-eabi), AVR-GCC, etc.

* **Device Drivers and Hardware Abstraction Layers (HAL)**
   * C++ classes are often used to wrap low-level C functions for hardware 
   access, making APIs cleaner and more modular.

* **Real-Time Operating Systems (RTOS)**
   * C++ can be used with RTOSes (e.g., FreeRTOS, ThreadX) to structure tasks, 
   threads, and events.

* **State Machines and Control Systems**
   * Object-oriented design is well-suited for modeling state machines and 
   event-driven control logic.

* **Bare-Metal and Low-Level Access**
   * C++ still allows direct memory access using pointers, bit manipulation, 
   and inline assembly when needed.

Because some **embedded systems have strict constraints**, there are some
considerations to keep in mind when using C++ in these environments:

* **Avoid dynamic memory allocation** (e.g., `new`, `delete`, heap usage) 
    unless carefully managed, as it can cause fragmentation.

* **Limit STL usage** due to potential for dynamic memory usage and larger 
    code footprint.

* **Careful exception handling**: Often disabled in embedded compilers to 
    reduce code size and complexity.

* **RTTI (Run-Time Type Information)** is usually avoided for the same reasons.

In this repository, you will find a collection of C++ examples and projects
that demonstrate various aspects of C++ programming without restrictions.

Later, we will come back to restrictions and best practices for embedded 
systems development using C++.


## References
* [YouTube: Bjarne Stroustrup: Why I Created C++ ](https://youtu.be/JBjjnqG0BP8?si=ZFvZpu5uKGs23bGe)
* Jez Humble, Davis Farley. **Continuous Delivery**. Addison-Wesley, 2010


*Egon Teiniker, 2020-2025, GPL v3.0*

