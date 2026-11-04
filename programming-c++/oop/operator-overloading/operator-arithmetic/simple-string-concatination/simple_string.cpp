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
		delete[] _data;		

		_size = other._size;
		_data = new char[_size + 1];

		std::strcpy(_data, other._data);
	}
	return *this;
}


// Arithmetic Operators
SimpleString SimpleString::operator+(const SimpleString& other) const
{
	size_t newSize = _size + other._size;
	char* newData = new char[newSize + 1];
	strcpy(newData, _data);
	strcat(newData, other._data);
	return SimpleString(newData);
}	

SimpleString& SimpleString::operator+=(const SimpleString& other)
{
	size_t newSize = _size + other._size;
	char* newData = new char[newSize + 1];
	strcpy(newData, _data);
	strcat(newData, other._data);

	delete[] _data;		

	_size = newSize;
	_data = newData;

	return *this;
}