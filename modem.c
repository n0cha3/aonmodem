#include "modem.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define TRUE_FSK 1200
#define FALSE_FSK 2200 

size_t fsk_mod(const uint8_t *input, uint8_t *output, const uint16_t length, uint16_t sample_rate, uint16_t baud_rate) {
	size_t sample_pos = 0;

	for (uint16_t i = 0; i < length; i++) {
		for (uint8_t y = 0; y < 8; y++) {
			uint8_t mask = 1 << y;
			bool bit = (input[i] & mask) >> y;
			uint16_t frequency = bit ? TRUE_FSK : FALSE_FSK;

			for (size_t x = 0; x < (size_t)(sample_rate / baud_rate); x++) {
				output[sample_pos++] = (255 * sinf(2 * M_PI * x / sample_rate * frequency));
			}
		}
	}
	return sample_pos;
}
//todo demod with Goertzel
