#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>

class Stack
{
    private:
        size_t _capacity;
        size_t _index = 0;
        int* _data;

    public:
        // Constructor
        Stack(size_t capacity)
            : _capacity{capacity}
        {
            _data = new int[_capacity];
        }

        // Destructor
        ~Stack()
        {
            delete[] _data;
        }

        // Accessors
        size_t size() const { return _index; }
        size_t capacity() const { return _capacity; }
        bool is_empty() const { return _index == 0; }
        bool is_full() const { return _index == _capacity; }

        // Methods
        void push(int value) { _data[_index++] = value; }
        int pop() { return _data[--_index]; }
        int top() const { return _data[_index - 1]; }
};

#endif
