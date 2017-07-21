#ifndef UART_H_
#define UART_H_

#define UART_PAYLOAD_LEN					32

// Message structure for messages sent out of the device
#define UART_MESSAGE_LEN					40
#define UART_PREAMBLE_0						0
#define UART_PREAMBLE_1						1
#define UART_PACKET_ID_0					2
#define UART_PACKET_ID_1					3
#define UART_COMMAND_0							4
#define UART_COMMAND_1							5
#define UART_LEN										6
#define UART_PL_START							7
#define UART_PL_END									UART_PL_START + 31
#define UART_CHECKSUM							UART_PL_END + 1

// Message structure for messages exchanged in shared memory
#define SM_UART_MESSAGE_LEN				35
#define SM_UART_COMMAND_0					0
#define SM_UART_COMMAND_1					1
#define SM_UART_LEN									2
#define SM_UART_PL_START					3
#define SM_UART_PL_END							MAIL_PL_START + 31


typedef struct UART_COMMAND_BUFS {
	bool ready;
	bool updated;
	uint8_t reader_loc;
	uint8_t writer_loc;
	uint8_t buf[256][SM_UART_MESSAGE_LEN];
} UART_COMMAND_BUF;

extern UART_COMMAND_BUF tx_command_buf, rx_command_buf;

extern mutex_t mtx_uart_tx;
extern mutex_t mtx_uart_rx;

void uart_init(void);

#endif
