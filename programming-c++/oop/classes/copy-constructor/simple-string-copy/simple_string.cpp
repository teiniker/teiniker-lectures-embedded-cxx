#include <cstdio>
#include <cstring>

#include <simple_string.h>

using namespace std;

SimpleString::SimpleString(const char* data)
{	
	_size = strlen(data);
	_data = new char[_size + 1];
	strcpy(_data, data);
}


// Copy Constructor
SimpleString::SimpleString(const SimpleString& old)
{
	printf(">> Called: Copy Constructor\n");
	
	_size = strlen(old._data);
	_data = new char[_size + 1];
	strcpy(_data, old._data);
}


SimpleString::~SimpleString()
{
	delete[] _data;
}

