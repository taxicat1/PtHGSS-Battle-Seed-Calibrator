#include <stdio.h>
#include <stdint.h>

#include "input_tool.h"
#include "searcher.h"
#include "calendar_util.h"
#include "move_list.h"
#include "metronome.h"

int main(void) {
	printf("Enter the target date, time, and delay for your seed:\n");
	int year  = inputReadInt("Year (2000-2099):", 2000, 2099);
	int month = inputReadInt("Month (1-12):", 1, 12);
	
	int month_len = calendarMonthLengths[month];
	if (month == 2 && calendarIsLeapYear(year)) {
		month_len++;
	}
	char day_str[24];
	snprintf(day_str, 24, "Day: (1-%i):", month_len);
	int day = inputReadInt(day_str, 1, month_len);
	
	printf("\n");
	
	int hour   = inputReadInt("Hour (0-23):", 0, 23);
	int minute = inputReadInt("Minute (0-59):", 0, 59);
	int second = inputReadInt("Second (0-59):", 0, 59);
	
	printf("\n");
	
	int delay  = inputReadInt("Delay (up to 65535):", 0, 65535);
	
	printf("\n");
	
	targetTime target = targetTimeMake(year, month, day, hour, minute, second, delay);
	uint32_t seed = targetTimeToSeed(&target);
	int move_id = metronomeMoveFromSeed(seed);
	
	while (1) {
		printf("Using target seed: %08x\n", seed);
		printf("Target Metronome: %s\n", moveNames[move_id]);
		
		printf("\n");
		
		printf("Enter the number of seconds +/- to search from the target time (up to 10):\n");
		int seconds_pm = inputReadInt("Seconds:", 0, 10);
		
		printf("\n");
		
		printf("Enter the number of frames +/- to search from the target delay (up to 2000):\n");
		int delay_pm = inputReadInt("Frames:", 0, 2000);
		
		printf("\n");
		
		printf("Enter the move that Metronome rolled (case sensitive!):\n");
		int metronome_move = inputReadMetronomeMove("Move:");
		
		printf("\n");
		
		searchBattleSeed(target, metronome_move, seconds_pm, delay_pm);
		
		printf("\n");
		
		printf("Continue?\n");
		int cont = inputReadYN("(Y/N):");
		if (!cont) {
			break;
		}
		
		printf("\n");
	}
	
	return 0;
}
