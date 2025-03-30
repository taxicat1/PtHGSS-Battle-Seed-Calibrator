#include <stdio.h>

#include "searcher.h"
#include "target_time.h"
#include "metronome.h"
#include "move_list.h"

#define COL_GAP  "    "

int searchBattleSeed(targetTime target_time, int target_move, int seconds_pm, int delay_pm) {
	int min_delay = target_time.delay - delay_pm;
	int max_delay = target_time.delay + delay_pm;
	
	if (min_delay < 0) {
		min_delay = 0;
	}
	
	if (max_delay > 65535) {
		max_delay = 65535;
	}
	
	for (int i = 0; i < seconds_pm; i++) {
		targetTimeSubtractSecond(&target_time);
	}
	
	int printed_headers = 0;
	for (int i = 0; i <= seconds_pm*2; i++) {
		for (int delay = min_delay; delay <= max_delay; delay++) {
			target_time.delay = delay;
			
			uint32_t seed = targetTimeToSeed(&target_time);
			int move = metronomeMoveFromSeed(seed);
			
			if (move == target_move) {
				if (!printed_headers) {
					printf(
						"%-8s" COL_GAP "%-10s" COL_GAP "%-8s" COL_GAP "%-5s" COL_GAP "%s\n",
						"Seed", "Date", "Time", "Delay", "Metronome"
					);
					
					printed_headers = 1;
				}
				
				printf(
					"%08x" COL_GAP "%04i-%02i-%02i" COL_GAP "%02i:%02i:%02i" COL_GAP "%-5i" COL_GAP "%s\n",
					seed,
					target_time.year+2000, target_time.month, target_time.day,
					target_time.hour, target_time.minute, target_time.second,
					target_time.delay,
					moveNames[move]
				);
			}
		}
		
		targetTimeAddSecond(&target_time);
	}
	
	if (!printed_headers) {
		printf("No result found!\n");
	}
}
