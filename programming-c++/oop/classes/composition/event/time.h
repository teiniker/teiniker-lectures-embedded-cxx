#ifndef _TIME_H_
#define _TIME_H_

class Time 
{
	private:
		int _hh; 
		int _min;
		int _sec;
 
	public:
		Time(int hh, int min, int sec);
    
		int hours(void) const { return _hh; }
		int minutes(void) const { return _min; }
		int seconds(void) const { return _sec; }
 };

#endif /*_TIME_H_ */
