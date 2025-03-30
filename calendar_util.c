#include "calendar_util.h"

const int calendarMonthLengths[] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int calendarIsLeapYear(int year) {
	year += 2000;
	
	if (year % 400 == 0) {
		return 1;
	}
	
	if (year % 100 == 0) {
		return 0;
	}
	
	if (year % 4 == 0) {
		return 1;
	}
	
	return 0;
}
