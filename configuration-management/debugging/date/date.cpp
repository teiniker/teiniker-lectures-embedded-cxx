#include "date.h"

Date::Date(int day, int month, int year) : _day(day), _month(month), _year(year)   
{
}

Date::~Date() 
{
}

bool Date::isLeapYear()
{
    return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}
    