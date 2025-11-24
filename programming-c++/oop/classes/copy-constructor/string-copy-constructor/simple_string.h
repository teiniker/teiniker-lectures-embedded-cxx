#ifndef _STRING_H_
#define _STRING_H_

#include <cstddef>

class String 
{
private:
	size_t _size;
	char* _data;
	
public:                
	String(const char* data);
	String(const String& old); // Copy Constructor
	~String();
		
 	size_t size() const
	{
		return _size;
	}

	const char* c_str() const
	{
		return _data;
	}
};

#endif //_STRING_H_