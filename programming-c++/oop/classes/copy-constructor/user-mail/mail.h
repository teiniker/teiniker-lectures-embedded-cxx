#pragma once

#include <string>

class Mail 
{
	private:
		std::string _address; 
 
	public:
		Mail(const std::string& address);
		Mail(const Mail& old);	// Copy Constructor
    
		std::string address(void) const { return _address; }
		void set_address(const std::string& address) { _address = address; }
 };
