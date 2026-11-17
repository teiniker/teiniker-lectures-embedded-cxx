#include <cstdio>
#include <cstring>
#include <iostream>
#include <simple_string.h>

using namespace std;

SimpleString::SimpleString(const char* data)
{
	_size = strlen(data);
	_data = new char[_size + 1];
	strcpy(_data, data);
}


// Move Constructor
SimpleString::SimpleString(SimpleString&& other) noexcept
    : _size(other._size), _data(other._data)
{
    printf(">> Called: Move Constructor\n");
    // Leave 'other' in a safe, empty state
    other._size = 0;
    other._data = nullptr;
}


SimpleString::~SimpleString()
{
	delete[] _data;
}

