#include "admin.h"

using namespace std;

Admin::Admin(const int id, const string& username, const string& password, Mail* mail)
	: User(id, username, mail), _password{password}
{	
}
		
