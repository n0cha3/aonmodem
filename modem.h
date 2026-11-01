#pragma once

#include "main.h"

size_t fsk_mod(const uint8_t *input, uint8_t *output, const uint16_t length, uint16_t sample_rate, uint16_t baud_rate);
void generate_mf(uint8_t *output, const uint16_t out_bufsize, const uint16_t sample_rate, const uint16_t prim_freq, const uint16_t sec_freq);
float goertzel(uint8_t *buffer, uint16_t targ_freq, uint16_t num_samples, uint16_t sample_rate);