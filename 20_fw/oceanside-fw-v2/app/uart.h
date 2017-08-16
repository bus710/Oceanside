#ifndef UART_H_
#define UART_H_

#define UART_PAYLOAD_LEN				16

// Message structure for messages sent out of the device
#define UART_MESSAGE_LEN				22
#define UART_PREAMBLE_0					0
#define UART_PREAMBLE_1					1
#define UART_PACKET_ID					2
#define UART_ADDRESS					3
#define UART_LEN						4
#define UART_PL_START					5
#define UART_PL_END						UART_PL_START + 15
#define UART_CHECKSUM					UART_PL_END + 1

// Message structure for messages exchanged in shared memory
#define SM_UART_MESSAGE_LEN				17
#define SM_UART_LEN						1
#define SM_UART_PL_START				2
#define SM_UART_PL_END					SM_UART_PL_START + 15


typedef struct UART_COMMAND_BUFS {
	bool ready;
	bool tx_updated;
	bool rx_updated;
	uint8_t writer_loc;
	uint8_t buf[128][SM_UART_MESSAGE_LEN];
} UART_COMMAND_BUF;

extern UART_COMMAND_BUF uart_command_buf;

extern mutex_t mtx_uart;

void uart_init(void);

#endif
