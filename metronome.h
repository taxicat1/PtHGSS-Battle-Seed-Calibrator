#ifndef METRONOME_H
#define METRONOME_H

#include <stdint.h>

int metronomeMoveIsExcluded(int move_id);
int metronomeMoveFromSeed(uint32_t seed);

#endif
