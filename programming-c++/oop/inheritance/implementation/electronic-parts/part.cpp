#include "part.h"

using namespace std;

Part::Part(const int id, const double value, const string& unit)
	: _id(id), _value(value), _unit(unit)
{
}

string Part::to_csv(void) const
{
	char buffer[100];
    snprintf(buffer, sizeof(buffer), "%d,%.3E,%s", id(), value(), unit().c_str());
    return string(buffer);
}