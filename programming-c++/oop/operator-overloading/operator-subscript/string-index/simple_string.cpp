#include <cstdio>
#include <cstring>
#include <simple_string.h>

using namespace std;

SimpleString::SimpleString(const char* data)
{
	_size = std::strlen(data);
	_data = new char[_size + 1];
	std::strcpy(_data, data);
}

// Copy Constructor
SimpleString::SimpleString(const SimpleString& old)
{
	printf(">> Called: Copy Constructor\n");
	_size = old._size;
	_data = new char[_size + 1];
	std::strcpy(_data, old._data);
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
		std::strcpy(_data, other._data);
	}
	return *this;
}

// Indexing Operator
char& SimpleString::operator[](size_t index)
{
	if (index >= _size)
	{
		printf(">> Error: Index out of bounds in non-const operator[]\n");
		return _data[_size - 1]; // Return last character as a fallback
	}
	return _data[index];
}

const char& SimpleString::operator[](size_t index) const
{
	if (index >= _size)
	{
		printf(">> Error: Index out of bounds in const operator[]\n");
		return _data[_size - 1]; // Return last character as a fallback
	}
	return _data[index];
}
