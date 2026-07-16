#pragma once

#include <string>
#include "mail.h"

class User 
{
	private:
		int _id; 
		std::string _username;
		Mail* _mail;
 
	public:                
		User(const int id, const std::string& username, Mail* mail);

		int id() const { return _id; }
		void set_id(const int id) { _id = id; }
		
		std::string username(void) const { return _username; }
		void set_username(const std::string& username) { _username = username; }

		Mail* mail() const { return _mail; }
		void set_mail(Mail* mail) { _mail = mail; }
 };
