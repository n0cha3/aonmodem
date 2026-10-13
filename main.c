#include "main.h"
#include "modem.h"

#define SAMPLE_RATE 8000
#define BAUD_RATE 39
#define BIT_DEPTH 8

int main(void) {
	/*uint8_t buffer[95] = "test test test test test test test test test test test test test test test test test test test";

	uint8_t *output_buffer = calloc(95 * SAMPLE_RATE * BIT_DEPTH, sizeof(uint8_t));

	size_t filesize = fsk_mod(buffer, output_buffer, 95, SAMPLE_RATE, BAUD_RATE);

	FILE *output_file = fopen("out.pcm", "wb+");
	fwrite(output_buffer, sizeof(uint8_t), filesize, output_file);*/


	FILE *input = fopen("untitled.raw", "rb");
	
	if (!input) puts("PCM not found");

	fseek(input, 0, SEEK_END);

	size_t fsize = ftell(input);

	fseek(input, 0, SEEK_SET);

	uint8_t *input_buf = calloc(fsize, sizeof(uint8_t));
	
	fread(input_buf, sizeof(uint8_t), fsize, input);

	printf("%f", goertzel(input_buf, 100, 200, 44100));

	return EXIT_SUCCESS;
}
