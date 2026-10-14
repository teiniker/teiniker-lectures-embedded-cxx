#pragma once

#include <array>
#include <cstddef>
#include <cstdio>
#include <cstdlib>

template <typename T, size_t N>
class ArrayList
{
    private:
        std::array<T, N> _data{};
        size_t _size = 0;

        static void check_index(size_t index, size_t limit)
        {
            if (index >= limit)
            {
                fprintf(stderr, "Index out of bounds\n");
                exit(EXIT_FAILURE);
            }
        }

    public:
        // Accessors
        size_t size() const { return _size; }
        size_t capacity() const { return N; }
        bool is_empty() const { return _size == 0; }
        bool is_full() const { return _size == N; }

        // Methods
        T get(size_t index) const
        {
            check_index(index, _size);
            return _data[index];
        }

        int find(const T& value) const
        {
            for (size_t i = 0; i < _size; i++)
            {
                if (_data[i] == value)
                {
                    return static_cast<int>(i);
                }
            }
            return -1;
        }

        void append(const T& value) { _data[_size++] = value; }

        void insert(size_t index, const T& value)
        {
            check_index(index, _size + 1);

            for (size_t i = _size; i > index; i--)
            {
                _data[i] = _data[i - 1];
            }
            _data[index] = value;
            _size++;
        }

        void remove(size_t index)
        {
            check_index(index, _size);

            _size--;
            for (size_t i = index; i < _size; i++)
            {
                _data[i] = _data[i + 1];
            }
        }
};
