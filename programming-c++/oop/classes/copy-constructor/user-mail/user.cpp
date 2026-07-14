#include "user.h"

using namespace std;

User::User(const int id, const string& username, const string& password, Mail* mail)
	: _id{id}, _username{username}, _password{password}, _mail{mail}
{
}

// Copy Constructor
User::User(const User& old)
{
	_id = old._id;
	_username = old._username;
	_password = old._password;
	_mail = new Mail(*old._mail);	// Deep Copy
	//_mail = old._mail;			// Shallow copy
}

// ---[1]-> Mail		
