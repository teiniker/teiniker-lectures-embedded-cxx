#include "user.h"
#include "mail.h"

using namespace std;

User::User(const int id, const string& username, const string& password)
	: _id{id}, _username{username}, _password{password}
{
}

// ---[*]-> Mail		
void User::addMail(Mail* mail)
{
	_mails.push_back(mail);
}

Mail* User::mail(int index) const
{
	return _mails[index];
}

size_t User::numberOfMails(void) const
{
	return _mails.size();
}	
