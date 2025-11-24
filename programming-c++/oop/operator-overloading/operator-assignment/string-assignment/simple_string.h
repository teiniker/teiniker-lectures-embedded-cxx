#ifndef _STRING_H_
#define _STRING_H_

#include <cstddef>

class String 
{
private:
	size_t _size;
	char* _data;
	
public:                
	// Initializer Constructor
	String(const char* data);
	// Copy Constructor
	String(const String& old);
	// Destructor 
	~String();
		
	// Assignment Operator
	String& operator=(const String& other);
	
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