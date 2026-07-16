#pragma once


class Counter 
{
	private:
		int _value;
		int _min;
		int _max;
	
	public:       
		// Constructor
		Counter(int value, int min, int max);
		
		// Getter 
		int value(void) const { return _value; }
		
		// Operator Overloading
		void operator ++(int);	// postfix increment operator
		void operator --(int);	// postfix decrement operator
 };
