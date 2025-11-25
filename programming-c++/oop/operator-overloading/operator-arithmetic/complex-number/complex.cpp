#include "complex.h"

Complex::Complex(double re, double im) 
	: _re{re}, _im{im}
{
}	

Complex::Complex(const Complex& c)
	: _re{c._re}, _im{c._im}
{
	// No deep copy needed as no dynamic memory is used
}


Complex Complex::operator +(const Complex& c)
{
	Complex result(_re + c._re, _im + c._im);
	return result;
}

Complex Complex::operator -(const Complex& c)
{
	Complex result(_re - c._re, _im - c._im);
	return result;
}

