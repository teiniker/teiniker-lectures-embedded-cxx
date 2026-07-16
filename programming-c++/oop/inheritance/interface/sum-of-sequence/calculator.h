#pragma once

class Calculator // Interface 
{
	public:  
		virtual ~Calculator(void) {}

		virtual int sumOfSequence(const int n) = 0;
 };
