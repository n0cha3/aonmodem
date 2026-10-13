#pragma once

#include "main.h"

size_t fsk_mod(const uint8_t *input, uint8_t *output, const uint16_t length, uint16_t sample_rate, uint16_t baud_rate);
float goertzel(uint8_t *buffer, uint16_t targ_freq, uint16_t num_samples, uint16_t sample_rate);