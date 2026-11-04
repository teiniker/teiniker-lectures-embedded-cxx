#pragma once

#include <cstddef>

class SimpleString 
{
private:
	size_t _size;
	char* _data;
	
public:                
	SimpleString(const char* data);

	// Copy Constructor
	SimpleString(const SimpleString& old);
	
	~SimpleString();
		
 	size_t size() const
	{
		return _size;
	}

	const char* c_str() const
	{
		return _data;
	}
};
