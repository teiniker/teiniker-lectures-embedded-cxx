#pragma once

#include <string>
#include "mail.h"

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
		Mail* _mail = NULL;			// ---[1]-> Mail
 
	public:                
		User(const int id, const std::string& username, const std::string& password, Mail* mail);
		User(const User& old);				// Copy Constructor
		User& operator =(const User& orig); // Assignment Operator

		int id(void) const { return _id; }
		std::string username(void) const { return _username; }
		std::string password(void) const { return _password; }
		
		// ---[1]-> Mail
		Mail* mail(void) { return _mail; }
		void set_mail(Mail* mail) { _mail = mail; }
 };
