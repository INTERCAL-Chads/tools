#include <stdio.h>
#include <string.h>

int reverse_byte(int c) {
	c = (c & 0x55) << 1 | (c & 0xaa) >> 1;
	c = (c & 0x33) << 2 | (c & 0xcc) >> 2;
	c = (c & 0x0f) << 4 | (c & 0xf0) >> 4;
	return c;
} 

int main(int argc, char** argv) {
	const char* message = argv[1];
	const int len = strlen(message);

	printf("DO ,1 <- #%d\n", len);

	for (int i = 0, last_char = 0; i < len; i++) {
		int c = message[i];
		c = reverse_byte(c);
		c = last_char - c;
		c = c & 0xff;
		if (i % 5 == 0) {
			printf("PLEASE ");
		}
		printf("DO ,1 SUB #%d <- #%u\n", i+1, c);
		last_char -= c;
	}
	printf("DO READ OUT ,1\nPLEASE GIVE UP\n");
}
