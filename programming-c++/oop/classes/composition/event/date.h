#pragma once

class Date 
{
	private:
		int _dd; 
		int _mm;
		int _yyyy;
 
	public:
		Date(int dd, int mm, int yyyy);
				
		int day(void) const { return _dd; }
		int month(void) const { return _mm; }
		int year(void) const { return _yyyy; }
 };
