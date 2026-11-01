#include "main.h"
#include "modem.h"

int main(void) {

	FILE *input = fopen("untitled.raw", "wb");
	
	/*if (!input) puts("PCM not found");

	fseek(input, 0, SEEK_END);

	size_t fsize = ftell(input);

	fseek(input, 0, SEEK_SET);

	uint8_t *input_buf = calloc(fsize, sizeof(uint8_t));
	
	fread(input_buf, sizeof(uint8_t), fsize, input);

	printf("%f", goertzel(input_buf, 960, 400, 44100));*/

	uint8_t buf[44100];

	generate_mf(buf, 44100, 44100, 400, 0);

	fwrite(buf, sizeof(uint8_t), 44100, input);

	return EXIT_SUCCESS;
}
