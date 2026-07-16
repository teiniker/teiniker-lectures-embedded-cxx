#pragma once

class IntegerSequence 
{
	private:
		static int _value;	// Static class variable
		int _id;

	public:
		// Constructor
		IntegerSequence(void); 

		// Static class methods
		static void init(int value);
		static int next(void); 
		
		int id(void) { return _id; }
 };
