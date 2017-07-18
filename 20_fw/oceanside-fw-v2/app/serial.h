#ifndef SERIAL_H_
#define SERIAL_H_

typedef struct{
	uint8_t preamble_0;
	uint8_t preamble_1;
	uint8_t command_0;
	uint8_t command_1;
	uint8_t len;
	uint8_t pl[32];
	uint8_t checksum;
}MESSAGE;

void serial_init(void);


#endif
