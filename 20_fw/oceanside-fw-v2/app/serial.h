#ifndef SERIAL_H_
#define SERIAL_H_

#define MESSAGE_LEN		39
#define PREAMBLE_0		0
#define PREAMBLE_1		1
#define PACKET_ID_0		2
#define PACKET_ID_1		3
#define COMMAND_0			4
#define COMMAND_1			5
#define LEN							6
#define PL_START			7
#define PL_END					PL_START + 31
#define CHECKSUM			PL_END + 1

typedef struct {
	uint8_t buf[MESSAGE_LEN];
} MESSAGE;

//typedef MESSAGE uint8_t message[MESSAGE_LEN];

void serial_init(void);


#endif
