#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <string>

#include "user.h"
#include "mail.h"

class Admin : public User
{
	private:
		std::string _password;
 
	public:                
		Admin(int id, const std::string& username, const std::string& password, Mail* mail);

		std::string password() { return _password; }
		void set_password(const std::string& password) { _password = password; }
 };

#endif /*_USER_H_ */
