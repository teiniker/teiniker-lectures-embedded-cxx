#pragma once

#include <cstdint>

class Range 
{
	private:
		int32_t value_;
		int32_t min_;
		int32_t max_;
 
	public:
		// Constructor
		Range(const int32_t min, const int32_t max);

		// Accessor methods
		int32_t value() const { return value_; }
		void set_value(const int32_t value);

		// Operator overloading
		bool operator==(const Range& other) const;
		bool operator!=(const Range& other) const;
		bool operator<(const Range& other) const;
		bool operator>(const Range& other) const;
		bool operator<=(const Range& other) const;
		bool operator>=(const Range& other) const;
};
