#include "target_time.h"
#include "calendar_util.h"


targetTime targetTimeMake(int year, int month, int day, int hour, int minute, int second, int delay) {
	targetTime ret;
	
	ret.year   = year - 2000;
	ret.month  = month;
	ret.day    = day;
	ret.hour   = hour;
	ret.minute = minute;
	ret.second = second;
	ret.delay  = delay;
	
	return ret;
}

int targetTimeInBounds(const targetTime* target) {
	if (target->year < 0 || target->year > 99) {
		return 0;
	}
	
	return 1;
}

void targetTimeSubtractSecond(targetTime* target) {
	target->second--;
	if (target->second == -1) {
		target->second = 59;
		target->minute--;
		if (target->minute == -1) {
			target->minute = 59;
			target->hour--;
			if (target->hour == -1) {
				target->hour = 23;
				target->day--;
				if (target->day == 0) {
					target->month--;
					if (target->month == 0) {
						target->month = 12;
						target->year--;
					}
					target->day = calendarMonthLengths[target->month];
					if (target->month == 2 && calendarIsLeapYear(target->year)) {
						target->day++;
					}
				}
			}
		}
	}
}

void targetTimeAddSecond(targetTime* target) {
	target->second++;
	if (target->second == 60) {
		target->second = 0;
		target->minute++;
		if (target->minute == 60) {
			target->minute = 0;
			target->hour++;
			if (target->hour == 24) {
				target->hour = 0;
				target->day++;
				int month_length = calendarMonthLengths[target->month];
				if (target->month == 2 && calendarIsLeapYear(target->year)) {
					month_length++;
				}
				if (target->day > month_length) {
					target->day = 1;
					target->month++;
					if (target->month == 13) {
						target->month = 1;
						target->year++;
					}
				}
			}
		}
	}
}

uint32_t targetTimeToSeed(const targetTime* target) {
	return target->delay +
	       target->year + 
	       (target->month * target->day * 0x01000000) + 
	       (target->hour * 0x00010000) + 
	       ((target->minute + target->second) * 0x01000000);
}
