#include <ctime>  // time and localtime
#include "date.h"
//#include <iostream>
#include <iomanip>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	this->year = y;
	this->month = m;
	this->day = d;
}

int Date::getYear() const {return year;}
int Date::getMonth() const {return month;}
int Date::getDay() const {return day;}

void Date::next() {
	int daysInMonth = daysPerMonth[month-1];
    if (++day > daysInMonth) {
        day = 1; //ny månad
        if (++month > 12) { //om december
            month = 1; //januari, nytt år
            year++;
        }
    }
}

std::istream& operator>>(std::istream& is, Date& date) {
    int y, m, d;
    char dash1, dash2;

    is >> y >> dash1 >> m >> dash2 >> d;
    if (y < 0 || dash1 != '-' ||  m > 12 || dash2 != '-' || d > Date::daysPerMonth[m-1] || d < 0 || !is) { // Check format
        is.setstate(std::ios_base::failbit); // Set failbit if format is wrong
    } else {
		date.year = y;
		date.month = m;
		date.day = d;		
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.getYear() << '-' 
       << std::setw(2) << std::setfill('0') << date.getMonth() << '-' 
       << std::setw(2) << std::setfill('0') << date.getDay();
    return os;
}

