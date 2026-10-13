#include "modem.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <complex.h>

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

float goertzel(uint8_t *buffer, uint16_t targ_freq, uint16_t num_samples, uint16_t sample_rate) {
	float scale_factor = num_samples / (float) 2.0;
    int k = (0.5 + (((float) num_samples * targ_freq) / sample_rate));

    float omega = (2.0 * M_PI * k) / (float) num_samples,
		sine = sin(omega),
		cosine = cos(omega),
		coeff = 2.0 * cosine;

    float q0=0, q1=0, q2=0;

    for (int i=0; i < num_samples; i++) {
        q2 = q1;
        q1 = q0;
        q0 = coeff * q1 - q2 + buffer[i];
    }

    float real = (q0 - q1 * cosine) / scale_factor,
		imaginary = (-q1 * sine) / scale_factor;

	float complex complex_result = real + imaginary * I;
	
	return cabsf(complex_result);
}
