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
	
 	size_t size() const
	{
		return _size;
	}

	const char* c_str() const
	{
		return _data;
	}
};
