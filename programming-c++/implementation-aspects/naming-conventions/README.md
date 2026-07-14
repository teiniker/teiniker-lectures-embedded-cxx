# C++ Naming Conventions

Unlike many younger languages, **C++ has no single official naming convention**.
There are several historical and technical reasons for this:

* **C heritage**: C++ inherited a large body of code and habits from C,
    where short lowercase names and `snake_case` dominate.

* **The standard library uses `snake_case`** (`push_back()`, `size()`,
    `unique_ptr`), but it never became binding for user code.

* **Competing ecosystems**: Influential frameworks and style guides each
    established their own rules - Qt uses `camelCase` methods, the Windows
    API used Hungarian notation, the Google C++ Style Guide uses
    `UpperCamelCase` methods, and Java/C# habits (`getX()`/`setX()`)
    migrated into many C++ projects.

* **Decades of legacy code**: C++ has been in industrial use since the
    1980s. No committee could retroactively rename existing code bases,
    so the standard deliberately stays silent on naming.

The consequence: **consistency within a project matters more than the
particular style chosen**. The following sections describe the conventions
used throughout this repository.


## Types (Classes, Enums)

Type names start with an **uppercase character** and use
**UpperCamelCase** (also called PascalCase) for compound names:

```C++
class Book { /* ... */ };
class CanMsg { /* ... */ };
class IntegerSequence { /* ... */ };

enum class PinMode { INPUT, OUTPUT };
```

This makes types immediately distinguishable from variables, functions,
and objects, which start with a lowercase character:

```C++
Book book("1984", "George Orwell", "978-3730614389");
```


## Accessor Methods

For getter and setter methods we follow the **modern C++ style** used by
the standard library (and, in the same form, by Rust):

* **Getters omit the word `get` entirely** and use the **raw property
    name**. This is exactly how the standard library reads properties:
    `string.length()`, `vector.size()`, `thread.joinable()`.

* **Setters use the `set_` prefix** in front of the property name.

```C++
class File
{
    private:
        std::string _name;

    public:
        std::string name() const { return _name; }                   // getter
        void set_name(const std::string& name) { _name = name; }     // setter
};
```

A call site then reads naturally, like accessing a property:

```C++
file.set_name("main.cpp");
std::cout << file.name() << std::endl;
```

Boolean queries use an `is_` or `has_` prefix instead of the raw name:
`is_empty()`, `has_next()`.

Note that trivial accessors are **defined directly in the class
declaration** (implicitly inline) - see
[Header File vs. Implementation File](../header-vs-cpp/README.md).


## Private Members

Private member variables are written with a **single leading underscore**:
`_name`, `_buffer`, `_index`. This is the same idiom Python uses to mark
attributes as internal - the underscore signals *"implementation detail,
do not touch from outside"* at a glance.

```C++
class File
{
    private:
        std::string _name;   // member variable
    
    public:
        std::string name() const { return _name; }
        void set_name(const std::string& name) { _name = name; }
};
```

The notation solves two practical problems:

* **No collision with getters**: Since getters use the raw property name
    (`name()`), the member itself needs a different identifier - `_name`.

* **Readability inside methods**: In a method body, `_name = name;`
    makes immediately clear which identifier is the member and which is
    the parameter or local variable, without `this->` qualification.

A word on the **language rules**: C++ reserves identifiers that begin with
an underscore followed by an **uppercase letter** (`_Name`) and all
identifiers containing a **double underscore** (`my__name`) for the
compiler and standard library. A leading underscore followed by a
lowercase letter is only reserved in the **global namespace** - as a class
member, `_name` is perfectly legal.

Other conventions you will encounter in the wild are the trailing
underscore `name_` (Google C++ Style Guide) and the `m_name` prefix
(common in older Windows/MFC code). All serve the same purpose; this
repository consistently uses the leading underscore.


## Other Methods

Regular methods (operations that do real work, not just field access) are
named in **snake_case**, similar to the STL:

```C++
lcd.clear();
stack.push(42);
table.insert_user(user);
order.number_of_lines();
```

This keeps user-defined classes visually consistent with standard library
calls like `push_back()`, `pop_front()`, or `get_allocator()` that appear
in the same code.


## Example

The class `LCD` (see
[constructor-destructor/lcd](../../oop/classes/constructor-destructor/lcd/))
shows these rules in combination:

```C++
class LCD
{
    private:
        size_t _cols;       // private members: leading underscore
        size_t _rows;
        size_t _index;
        char* _buffer;

    public:
        LCD(size_t cols, size_t rows);  // Constructor
        ~LCD(void);                     // Destructor

        // Accessors
        char* buffer(void) const { return _buffer; }

        // Methods
        void clear(void);
        void print(char c);
        void print(const char* c_ptr);
};
```

* `LCD` - the **type name** starts with an uppercase character.
* `_cols`, `_rows`, `_index`, `_buffer` - **private members** with a
    leading underscore.
* `buffer()` - a **getter** using the raw property name, defined inline
    in the class declaration. There is deliberately no setter: the buffer
    is allocated by the constructor and released by the destructor, so
    no `set_buffer()` is offered.
* `clear()`, `print()` - **regular methods** in snake_case; they contain
    real logic and are therefore implemented in `lcd.cpp`:

```C++
void LCD::clear(void)
{
    _index = 0;
    for(unsigned int i = 0; i < _rows * _cols; i++)
        _buffer[i] = '\0';
}
```

*Egon Teiniker, 2024-2026, GPL v3.0*
