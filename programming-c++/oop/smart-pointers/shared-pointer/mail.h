#pragma once

#include <string>

using namespace std;

class Mail 
{
	private:
		string address_; 
 
	public:
		Mail(const string& address);
		~Mail(void);
    
		string address() { return address_; }
		void set_address(const string& address) { address_ = address; }
 };
