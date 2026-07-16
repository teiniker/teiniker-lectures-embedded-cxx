#pragma once

#include <string>

#include "part.h"

class Capacitor : public Part
{
	public:                
		Capacitor(const int id, const double value, const std::string& username)
			: Part(id, value, username) 
		{
		}

		std::string to_csv(void) const override;
};
