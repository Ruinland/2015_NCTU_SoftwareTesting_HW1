#include "next_date.h"

Date::Date(unsigned int y, unsigned int m, unsigned int d) :
	year(y), mon(m), day(d) {
	// do nothing;
	}

// 0/0/0 is a date for invalid date
Date::Date(): year(0), mon(0), day(0) {}

Date next_date(unsigned int y, unsigned int m, unsigned int d) {
	return Date();
	}
