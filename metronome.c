#include "metronome.h"
#include "move_list.h"

#define NUM_METRONOME_EXCLUDED_MOVES  26

static const int metronomeExcludedMoves[] = {
	0,    // ---
	118,  // Metronome
	165,  // Struggle
	166,  // Sketch
	102,  // Mimic
	448,  // Chatter
	214,  // Sleep Talk
	274,  // Assist
	119,  // Mirror Move
	68,   // Counter
	243,  // Mirror Coat
	182,  // Protect
	197,  // Detect
	203,  // Endure
	194,  // Destiny Bond
	168,  // Thief
	266,  // Follow Me
	289,  // Snatch
	270,  // Helping Hand
	343,  // Covet
	271,  // Trick
	264,  // Focus Punch
	364,  // Feint
	383,  // Copycat
	382,  // Me First
	415   // Switcheroo
};

int metronomeMoveIsExcluded(int move_id) {
	for (int i = 0; i < NUM_METRONOME_EXCLUDED_MOVES; i++) {
		if (move_id == metronomeExcludedMoves[i]) {
			return 1;
		}
	}
	
	return 0;
}

static uint32_t battleRngAdvance(uint32_t x) {
	return x * 1103515245 + 24691;
}

int metronomeMoveFromSeed(uint32_t seed) {
	int pre_advances = 11;
	// If at fight screen: pre_advances = 4
	
	for (int i = 0; i < pre_advances; i++) {
		seed = battleRngAdvance(seed);
	}
	
	// Metronome move selection
	int move_id;
	do {
		seed = battleRngAdvance(seed);
		move_id = ((seed >> 16) % NUM_MOVES) + 1;
	} while (metronomeMoveIsExcluded(move_id));
	
	return move_id;
}
