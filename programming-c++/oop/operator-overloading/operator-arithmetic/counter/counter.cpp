#include "counter.h"

Counter::Counter(int value, int min, int max) 
	: _value{value}, _min{min}, _max{max}
{
}

void Counter::operator ++(int)
{
	if(_value < _max)
		_value++;
}

void Counter::operator --(int)
{
	if(_value > _min)
		_value--;
}
