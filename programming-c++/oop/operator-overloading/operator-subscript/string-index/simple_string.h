#ifndef _SIMPLESTRING_H_
#define _SIMPLESTRING_H_

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
	
	// Indexing Operator
	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	// Accessor Methods
 	size_t size() const { return _size; }
	const char* c_str() const { return _data; }
};

#endif //_SIMPLESTRING_H_