# Repository Instructions

## Repository Overview
This is an educational repository containing **examples, exercises, and model 
solutions** for teaching programming in C++.
These small examples are distributed in different folders.

### High-Level Organization

- `introduction/` - Motivation for C++ in embedded systems.
- `configuration-management/` - Build automation, testing, debugging,
    and generative AI, as part of the software engineering process.
- `software-modeling/` - UML diagrams (class, object, package,
    sequence, state machine) used to design the examples.
- `programming-c++/` - Core C++ language content: C basics,
    implementation aspects, OOP, templates, STL, and the C++ subset
    used for embedded systems.

## Build and Test Commands

Use cmake to build projects.
Every subdirectory contains a `CMakeLists.txt`.
Use `./build` directory to store build artifacts.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/test
```

### Testing Framework
Projects use the Google testing framework.

## Key Conventions

### Naming Conventions

- **Exercise directories**: Suffix with `-exercise` (e.g., `resistor-exercise`)
- **Model solution directories**: No suffix (e.g., `resistor`)
- **Test files**: Named `test.cpp`
- **Source organization**: Each logical unit (functions, structures,
    algorithms) has its own subdirectory
- **Accessors**: Getter matches the property name (e.g. `title()`);
    setter is prefixed with `set_` (e.g. `set_title()`)

### Coding Standard

- **Line width**: Maximum **80 characters** per line
- **Indentation**: **4 spaces** per level (not tabs)
- **Braces**: 
  - Always surround blocks with braces `{ }`, even for single statements
  - Left brace `{` goes on the next line after the statement
  - Right brace `}` aligns with the opening keyword
- **Spacing**:
  - Binary operators (`+`, `-`, `*`, `/`, `==`, etc.) surrounded by spaces
  - Unary operators (`++`, `--`, `!`, `~`) have no space on operand side
  - Pointer operators (`*`, `&`) have spaces in declarations but not
    on operand side
  - No spaces around member/arrow operators (`.`, `->`, `[`, `]`)
- **Variable declarations**: First characters aligned within a block
- **Blank lines**: Before and after natural blocks of code (loops,
    if/else, declarations)

#### Example

```c++
class Book 
{
private:
    std::string _title;
    std::string _author;
    std::string _isbn;

public:
    // Initializing Constructor
    Book(const std::string& title, const std::string& author,
        const std::string& isbn);

    // Copy Constructor
    Book(const Book &book) = default;

    // Default destructor
    ~Book() = default;  

    // Getter and Setter Methods
    std::string title() const { return _title; }
    void set_title(const std::string& title) { _title = title; }

    std::string author() const { return _author; }
    void set_author(const std::string& author) { _author = author; }

    std::string isbn() const { return _isbn; }
    void set_isbn(const std::string& isbn) { _isbn = isbn; }
};
```


### Documentation

- Use only 80 chars per line for documentation text.
- Don't use —, ---, and emojis in generated text.
- Use Mermaid to generate class diagrams.
    - Use direction LR
    - Add a : between an attribute name and type, e.g. id:int
    - Make the constructor static (add $ at the end)