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
	if (this != &other) // Self-assignment check
	{
		delete[] _data;
		_size = other._size;
		_data = new char[_size + 1];
		std::strcpy(_data, other._data);
	}
	return *this;
}

bool SimpleString::operator==(const SimpleString& other) const
{
	return std::strcmp(_data, other._data) == 0;
}

bool SimpleString::operator!=(const SimpleString& other) const
{
	return !(*this == other);
}

bool SimpleString::operator<(const SimpleString& other) const
{
	return std::strcmp(_data, other._data) < 0;
}

bool SimpleString::operator<=(const SimpleString& other) const
{
	return (*this < other) || (*this == other);
}

bool SimpleString::operator>(const SimpleString& other) const
{
	return !(*this <= other);
}

bool SimpleString::operator>=(const SimpleString& other) const
{
	return !(*this < other);
}
