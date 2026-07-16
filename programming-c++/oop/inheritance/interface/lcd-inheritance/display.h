#pragma once

class Display 
{
	public:
		virtual ~Display(void) {}; 	// Destructor

		// Pure virtual Methods
		virtual void clear(void) = 0;
		virtual void print(char c) = 0;
		virtual void print(const char * c_ptr) = 0;
};
