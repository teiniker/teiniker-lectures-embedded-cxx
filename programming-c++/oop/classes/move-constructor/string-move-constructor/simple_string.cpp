#include <cstdio>
#include <simple_string.h>

using namespace std;

SimpleString::SimpleString(const char* data)
{
	_size = 0;
	while (data[_size] != '\0')
	{
		_size++;
	}

	_data = new char[_size + 1];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = data[i];
	}
	_data[_size] = '\0';
}

SimpleString::SimpleString(const SimpleString& old)
{
	printf(">> Called: Copy Constructor\n");

	_size = old._size;
	_data = new char[_size + 1];
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = old._data[i];
	}
	_data[_size] = '\0';
}

// Move Constructor
SimpleString::SimpleString(SimpleString&& other) noexcept
    : _size(other._size), _data(other._data)
{
    // Leave 'other' in a safe, empty state
    other._size = 0;
    other._data = nullptr;
}


SimpleString::~SimpleString()
{
	delete[] _data;
}

