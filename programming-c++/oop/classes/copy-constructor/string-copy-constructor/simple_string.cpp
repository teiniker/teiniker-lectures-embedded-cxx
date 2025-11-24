#include <simple_string.h>
#include <cstdio>

using namespace std;

String::String(const char* data)
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
String::String(const String& old)
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

String::~String()
{
	delete[] _data;
}

