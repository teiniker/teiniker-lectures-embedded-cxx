#include "user.h"
#include "mail.h"

using namespace std;

User::User(const int id, const string& username, const string& password, Mail* mail)
	: _id{id}, _username{username}, _password{password}, _mail{mail}
{
}

// ---[1]-> Mail		
Mail* User::mail() const
{
	return _mail;
}
void User::set_mail(Mail* mail)
{
	_mail = mail;
}		
