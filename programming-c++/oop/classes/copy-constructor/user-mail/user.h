#pragma once

#include <string>
#include "mail.h"

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
		Mail* _mail;			// ---[1]-> Mail
 
	public:                
		User(const int id, const std::string& username, const std::string& password, Mail* mail);
		User(const User& old);	// Copy Constructor

		int id() const { return _id; }
		std::string username(void) const { return _username; }
		std::string password() const { return _password; }
		
		// ---[1]-> Mail
		Mail* mail() { return _mail; }
		void set_mail(Mail* mail) { _mail = mail; }
 };
