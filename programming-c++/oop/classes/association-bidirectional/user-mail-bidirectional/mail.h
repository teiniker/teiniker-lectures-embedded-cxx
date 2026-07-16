#pragma once

#include <string>
#include "user.h"

class Mail 
{
	private:
		std::string _address; 
		User* _user;			// ---[1]-> User
 
	public:
		// Constructor
		Mail(const std::string& address);
    
		// Accessors
		std::string address() const { return _address; }

		// Association
		// ---[1]-> User
		User* user() const { return _user; }
		void set_user(User* user) { _user = user; }
 };
