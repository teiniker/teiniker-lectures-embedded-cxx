#include <simple_string.h>
#include <cstdio>

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

// Copy Constructor
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

SimpleString::~SimpleString()
{
	delete[] _data;
}

// Assignment Operator
SimpleString& SimpleString::operator=(const SimpleString& other)
{
	printf(">> Called: Assignment Operator\n");

	if (this != &other) // Self-assignment check
	{
		// Release existing resource
		delete[] _data;		
		_size = other._size;
		_data = new char[_size + 1];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = other._data[i];
		}
		_data[_size] = '\0';
	}
	return *this;
}
