#include "next_date.h"
#include <unordered_set>
#include <iostream>

#ifdef __KLEE__
#include "klee/klee.h"
#endif

Date::Date(unsigned int y, unsigned int m, unsigned int d) :
	year(y), mon(m), day(d) {
	// do nothing;
	}

// 0/0/0 is a date for invalid date
Date::Date(): year(0), mon(0), day(0) {}

static bool is_leap_year(unsigned int y) {
	if ( ( (y % 400) == 0) || ( (y%4 == 0) && (y%100 != 0) ) ) {return true ;}
	else {return false;}
	}
// 1812 <= year <= 2012
// 1 <= month <= 12
// 1 <= day <= 31
Date next_date(unsigned int year, unsigned int month, unsigned int day){
		if( year < 1812 || year > 2012 )
        return DATE_INVALID;
    if( month < 1 || month > 12 )
        return DATE_INVALID;
    if( day < 1 || day > 31 )
        return DATE_INVALID;

    unsigned int days_per_month = 0;
    switch( month ){
        case 1: case 3: case 5: case 7: 
        case 8: case 10: case 12:
            days_per_month = 31;
            break;
        case 4: case 6: case 9: case 11: 
            days_per_month = 30;
            break;
        // 28 or 29 days
        case 2:
            if( year%4 != 0 )
                days_per_month = 28;
            else if( year%100 != 0 )
                days_per_month = 29;
            else if( year%400 != 0 )
                days_per_month = 28;
            else
                // year%400 == 0
                days_per_month = 29;
            break;
    }

    if( day <= days_per_month-1 ){
        return Date(year, month, day+1);
    }
    else if( day == days_per_month ){
        if( month != 12 )
            return Date(year, month+1, 1);
        return Date(year+1, 1, 1);
    }
    else{
        return DATE_INVALID;
    }
}

#ifdef __KLEE__
int main(int argc, char *argv[]) {
	unsigned int year, month, day;
	klee_make_symbolic(&year, sizeof(year), "year");
	klee_make_symbolic(&month, sizeof(month), "month");
	klee_make_symbolic(&day, sizeof(day), "day");
	next_date(year, month, day);
	return 0;
	}
#endif
