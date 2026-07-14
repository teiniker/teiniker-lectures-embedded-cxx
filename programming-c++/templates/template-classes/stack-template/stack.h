#ifndef _STACK_H_
#define _STACK_H_

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
        T top() const { return _data[_index - 1]; }
};

#endif 