#include "user.h"
#include "mail.h"

using namespace std;

User::User(const int id, const string& username, const string& password)
	: _id{id}, _username{username}, _password{password}
{
}

// ---[*]-> Mail		
void User::add_mail(Mail* mail)
{
	_mails.push_back(mail);
}

Mail* User::mail(int index) const
{
	return _mails[index];
}

size_t User::number_of_mails(void) const
{
	return _mails.size();
}	
