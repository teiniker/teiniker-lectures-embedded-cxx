#ifndef _SimpleString_H_
#define _SimpleString_H_

#include <cstddef>

class SimpleString 
{
private:
	size_t _size;
	char* _data;
	
public:                
	SimpleString(const char* data);
	SimpleString(const SimpleString& old);

	// Move Constructor
	SimpleString(SimpleString&& other) noexcept; 
	
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

#endif //_SimpleString_H_