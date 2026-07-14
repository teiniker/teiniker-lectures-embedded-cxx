#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
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

		int id() const { return _id; }
		void set_id(const int id) { _id = id; }
		
		std::string username(void) const { return _username; }
		void set_username(const std::string& username) { _username = username; }
		
		std::string password() const { return _password; }
		void set_password(const std::string& password) { _password = password; }
		
		// ---[1]-> Mail
		Mail* mail() const { return _mail; }
		void set_mail(Mail* mail) { _mail = mail; }
 };

#endif /*_USER_H_ */
