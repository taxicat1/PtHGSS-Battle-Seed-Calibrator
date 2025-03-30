#ifndef TARGET_TIME_H
#define TARGET_TIME_H

#include <stdint.h>

typedef struct {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int delay;
} targetTime;

targetTime targetTimeMake(int year, int month, int day, int hour, int minute, int second, int delay);
void targetTimeSubtractSecond(targetTime* target);
void targetTimeAddSecond(targetTime* target);
uint32_t targetTimeToSeed(const targetTime* target);

#endif
