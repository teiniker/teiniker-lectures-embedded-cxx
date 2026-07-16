#pragma once

#include "calculator.h"

class CalculatorSlow : public Calculator 
{
	public:
		CalculatorSlow(void);
		~CalculatorSlow(void);
		
		int sumOfSequence(const int n) override;				
};
