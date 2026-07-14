#ifndef _DATE_H_
#define _DATE_H_

#include <cstdint>

class Date 
{
    private:
        int _day;
        int _month;
        int _year;

    public:
        Date(int d, int m, int y);  // Constructor   
        ~Date();                    // Destructor

        int day() const { return _day; }
        void set_day(const int day) { _day = day; }
        
        int month() const { return _month; }
        void set_month(const int month) { _month = month; }
        
        int year() const { return _year; }
        void set_year(const int year) { _year = year; }

        bool isLeapYear();
};

#endif // _DATE_H_