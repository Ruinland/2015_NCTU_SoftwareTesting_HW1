#include "next_date.h"
#include <unordered_set>
#include <iostream>

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

Date next_date(unsigned int y, unsigned int m, unsigned int d) {
	std::unordered_set<unsigned int> smallMonth {4,6,9,11};
	std::unordered_set<unsigned int> bigMonth   {1,3,5,7,8,10};
	enum monthType {SM,BM,Dec,Feb};
	unsigned int monthCase = 4; // which is not in monthType

	if ( (y > 2012) || ( y < 1812)) 
		return Date();

	if(m == 12) { monthCase = Dec; }
	else if(m == 2) { monthCase = Feb; } 
	else if(smallMonth.find(m) != smallMonth.end()) { monthCase = SM; }
	else if(bigMonth.find(m) != bigMonth.end()) { monthCase = BM; }
	else {
		//Thou shalt not reach here.
		return Date();
		};
	
	switch (monthCase) {
		case BM:
			if(d < 31) { return Date(y,m,d+1); }
			else { return Date(y,m+1,1); }
			break;

		case Dec:
			if(d < 30) { return Date(y,m,d+1);}
			else {
				if(y == 2012) {
					std::cout<<"2012 is over"<<std::endl;
					return Date();
					}
				else { return Date(y+1,1,1); }
				}
			break;

		case SM:
			if(d < 30) { return Date(y,m,d+1); }
			else { return Date(y,m+1,1); }
			break;

		case Feb:
			if(d<28) {return Date(y,m,d+1); }
			else if(d==28) {
				if(is_leap_year(y)) {return Date(y,m,29); }
				else {return Date(y,3,1); }
				}
			else if(d==29) {
				if(is_leap_year(y)) {return Date(y,3,1); }
				else {
					std::cout<<"Cannot havbe Feb."<<d<<std::endl;
					return Date();
					}
				}
			break;

		}


	}
