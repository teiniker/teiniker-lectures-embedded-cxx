#pragma once

#include <string>

class Mail 
{
	private:
		std::string _address; 
 
	public:
		// Constructor
		Mail(const std::string& address);
    
		// Accessors
		std::string address() const { return _address; }
};
