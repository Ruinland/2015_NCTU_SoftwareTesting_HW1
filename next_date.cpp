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

//Date next_date(unsigned int y, unsigned int m, unsigned int d) {
//	std::unordered_set<unsigned int> smallMonth {4,6,9,11};
//	std::unordered_set<unsigned int> bigMonth   {1,3,5,7,8,10,12};
//	enum monthType {SM,BM,Dec,Feb};
//	unsigned int monthCase = 4; // which is not in monthType
//
//	if ( (y > 2012) || ( y < 1812)) 
//		return Date();
//  if( m < 1 || m > 12 )
//    return DATE_INVALID;
//  if( d < 1 || d > 31 )
//    return DATE_INVALID;
//
//	if(m == 12) { monthCase = Dec; }
//	else if(m == 2) { monthCase = Feb; } 
//	else if(smallMonth.find(m) != smallMonth.end()) { monthCase = SM; }
//	else if(bigMonth.find(m) != bigMonth.end()) { monthCase = BM; }
//	else {
//		//Thou shalt not reach here.
//		return Date();
//		};
//	
//	switch (monthCase) {
//		case BM:
//			if(d < 31) { return Date(y,m,d+1); }
//			else { return Date(y,m+1,1); }
//			break;
//
//		case Dec:
//			if(d < 30) { return Date(y,m,d+1);}
//			else {
//				if(y == 2012) {
//					std::cout<<"2012 is over"<<std::endl;
//					return Date();
//					}
//				else { return Date(y+1,1,1); }
//				}
//			break;
//
//		case SM:
//			if(d < 30) { return Date(y,m,d+1); }
//			else { return Date(y,m+1,1); }
//			break;
//
//		case Feb:
//			if(d<28) {return Date(y,m,d+1); }
//			else if(d==28) {
//				if(is_leap_year(y)) {return Date(y,m,29); }
//				else {return Date(y,3,1); }
//				}
//			else if(d==29) {
//				if(is_leap_year(y)) {return Date(y,3,1); }
//				else {
//					std::cout<<"Cannot havbe Feb."<<d<<std::endl;
//					return Date();
//					}
//				}
//			break;
//
//		default :
//			std::cout<<"Thou shalt not enter here."<<std::endl;
//			exit(1);
//
//		}
//
//
//	}
