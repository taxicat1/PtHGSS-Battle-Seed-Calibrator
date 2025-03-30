#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "input_tool.h"
#include "move_list.h"
#include "metronome.h"

static void clearRemainingLine() {
	int end;
	do {
		end = fgetc(stdin);
	} while (end != EOF && end != '\n');
}

int inputReadInt(const char* prompt, int min, int max) {
	char intbuf[16];
	char* intbufptr;
	int result;
	do {
		printf("%s ", prompt);
		errno = 0;
		
		if (fgets(intbuf, 16, stdin) == NULL) {
			fprintf(stderr, "Input error!\n");
			exit(1);
		}
		
		int len = strlen(intbuf);
		if (len > 0 && intbuf[len-1] != '\n') {
			clearRemainingLine();
		}
		
		result = strtol(intbuf, &intbufptr, 10);
	} while (result < min || result > max || errno != 0 || intbufptr == &intbuf[0]);
	
	return result;
}

int inputReadMetronomeMove(const char* prompt) {
	char move_name_buf[16];
	
	int move_id;
	do {
		printf("%s ", prompt);
		
		if (fgets(move_name_buf, 16, stdin) == NULL) {
			fprintf(stderr, "Input error!\n");
			exit(1);
		}
		
		int len = strlen(move_name_buf);
		if (len > 0 && move_name_buf[len-1] != '\n') {
			clearRemainingLine();
		}
		
		// Remove line feed for strcmp later
		if (move_name_buf[len-1] == '\n') {
			move_name_buf[len-1] = '\0';
		}
		
		move_id = moveGetByName(move_name_buf);
	} while (move_id == -1 || metronomeMoveIsExcluded(move_id));
	
	return move_id;
}

int inputReadYN(const char* prompt) {
	char yn_buf[3];
	
	while (1) {
		printf("%s ", prompt);
		
		if (fgets(yn_buf, 3, stdin) == NULL) {
			fprintf(stderr, "Input error!\n");
			exit(1);
		}
		
		int len = strlen(yn_buf);
		if (len > 0 && yn_buf[len-1] != '\n') {
			clearRemainingLine();
		}
		
		if (len > 0) {
			switch (yn_buf[0]) {
				case 'y':
				case 'Y':
					return 1;
				
				case 'n':
				case 'N':
					return 0;
				
				default:
					break;
			}
		}
	}
}
