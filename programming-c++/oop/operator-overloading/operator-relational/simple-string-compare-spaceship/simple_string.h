#pragma once

#include <cstddef>
#include <compare>

class SimpleString
{
private:
    std::size_t _size;
    char*       _data;

public:
    // Life Cycle Operations
    SimpleString(const char* data);
    SimpleString(const SimpleString& old);
    ~SimpleString();
    SimpleString& operator=(const SimpleString& other);

    // Relational Operators
    // The compiler rewrites != using ==, and <, <=, >, >= using <=>
    bool operator==(const SimpleString& other) const;
    std::strong_ordering operator<=>(const SimpleString& other) const;

    std::size_t size() const { return _size; }
    const char* c_str() const { return _data; }
};
