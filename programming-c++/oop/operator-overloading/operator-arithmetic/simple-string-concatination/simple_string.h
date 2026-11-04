#pragma once

#include <cstddef>

class SimpleString 
{
private:
	size_t _size;
	char* _data;
	
public:                
	SimpleString(const char* data);
	SimpleString(const SimpleString& old);
	~SimpleString();
		
	// Assignment Operator
	SimpleString& operator=(const SimpleString& other);
	
	// Arithmetic Operators
	SimpleString operator+(const SimpleString& other) const;
	SimpleString& operator+=(const SimpleString& other);

	// Accessor Methods
 	size_t size() const { return _size; }
	const char* c_str() const { return _data; }
};
