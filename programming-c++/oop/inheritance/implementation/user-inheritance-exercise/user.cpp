#include "user.h"
#include "mail.h"

using namespace std;

User::User(const int id, const string& username, Mail* mail)
	: _id{id}, _username{username}, _mail{mail}
{
}
