#pragma once

#include <string>

class Mail 
{
	private:
		std::string _address; 
 
	public:
		Mail(const std::string& address);
		//~Mail(void) {}
    
		std::string address() const { return _address; }
		void set_address(const std::string& address) { _address = address; }
 };
