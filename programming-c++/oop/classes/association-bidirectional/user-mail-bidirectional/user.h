#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>

// Forward declaration
class Mail;

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
		Mail* _mail;			// ---[1]-> Mail
 
	public:                
		// Constructor
		User(const int id, const std::string& username, const std::string& password, Mail* mail);

		// Accessors
		int id() const { return _id; }
		std::string username(void) const { return _username; }
		std::string password() const { return _password; }
		
		// Association --[1]-> Mail
		Mail* mail() const { return _mail; }
		void set_mail(Mail* mail) { _mail = mail; }
 };

#endif /*_USER_H_ */
