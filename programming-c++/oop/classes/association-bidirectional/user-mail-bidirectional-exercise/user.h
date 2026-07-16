#pragma once

#include <string>
#include <vector>

class User 
{
	private:
		int _id; 
		std::string _username;
		std::string _password;
 
	public:                
		// Constructor
		User(const int id, const std::string& username, const std::string& password);

		// Accessors
		int id() const { return _id; }
		std::string username(void) const { return _username; }
		std::string password() const { return _password; }
 };
