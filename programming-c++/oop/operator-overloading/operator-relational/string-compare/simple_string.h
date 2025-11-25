#ifndef _SIMPLESTRING_H_
#define _SIMPLESTRING_H_

#include <cstddef>

class SimpleString 
{
private:
	size_t _size;
	char* _data;
	
public:             
	// Life Cycle Operations
	SimpleString(const char* data);
	SimpleString(const SimpleString& old);
	~SimpleString();
	SimpleString& operator=(const SimpleString& other);

	// Relational Operators
	bool operator==(const SimpleString& other) const;
	bool operator!=(const SimpleString& other) const;
	bool operator<(const SimpleString& other) const;
	bool operator<=(const SimpleString& other) const;
	bool operator>(const SimpleString& other) const;
	bool operator>=(const SimpleString& other) const;

 	size_t size() const
	{
		return _size;
	}

	const char* c_str() const
	{
		return _data;
	}
};

#endif //_SIMPLESTRING_H_