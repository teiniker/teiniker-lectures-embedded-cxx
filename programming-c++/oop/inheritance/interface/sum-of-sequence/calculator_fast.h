#pragma once

#include "calculator.h"

class CalculatorFast : public Calculator 
{
	public: 
		CalculatorFast(void);
		~CalculatorFast(void);
		
		int sumOfSequence(const int n) override;
};
