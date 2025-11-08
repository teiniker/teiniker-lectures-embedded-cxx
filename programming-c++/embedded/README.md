# C++ on Embedded Systems

This is a list of all the C++ features that we should use in most 
embedded firmware:

* **Namespaces** (no overhead)

* **auto**

* **References** (they are just safer pointers that can’t be null!)

* **Function overloading** and **default parameters** makes it easy to extend functions 
    without massive refactors! And provides more flexibility to an API.

* **Operator overloading** (when done sensibly!)

* **Classes**

* **Enum classes**, typesafe typedefs

* **Inheritance**

* **RAII**

* **Smart pointers** (std::unique_ptr, std::shared_ptr)

* **Templates** (no overhead, can be thought of as a more powerful version of a macro). 
    However, incorrect/careless use of templates can cause a huge increase in code 
    size. Also be careful of overusing them, too much templating makes code very 
    unreadable.

* **std::array**

* **Embedded Template Library (ETL)**






## References

* [C++ On Embedded Systems](https://blog.mbedded.ninja/programming/languages/c-plus-plus/cpp-on-embedded-systems/)

* [Embedded Template Library](https://www.etlcpp.com/)

*Egon Teiniker, 2020-2025, GPL v3.0*