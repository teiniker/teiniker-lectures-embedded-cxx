#pragma once

#include <GPIO.h>
#include <iostream>

class ControllerException : public std::exception 
{
	private:
		std::string _cause;
		
	public:
		ControllerException(const std::string& cause) 
		: _cause{cause} 
		{
		}
		
		const char* what() const noexcept
		{
			return _cause.c_str();
		}
};


class Controller 
{
	private:
		GPIO* _io = nullptr;
		
	public:                
		Controller();		
		~Controller();
		
		// ...		
 };
