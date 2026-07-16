#pragma once

class Complex 
{
private:
	double _re;
	double _im;

public:       
	// Constructor
	Complex(double re, double im);
	// Copy Constructor
	Complex(const Complex& c);
	// Destructor
	~Complex(void) = default;
	
	// Accessor Methods 
	double real(void) const { return _re; }
	double imag(void) const { return _im; }
	
	// Operator Overloading
	Complex operator +(const Complex& c);
	Complex operator -(const Complex& c);
 };
