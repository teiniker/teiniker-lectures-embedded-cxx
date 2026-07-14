#ifndef _MAIL_H_
#define _MAIL_H_

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

#endif /*_MAIL_H_ */
