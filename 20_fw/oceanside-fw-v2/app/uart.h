#ifndef UART_H_
#define UART_H_


// Message structure for messages sent out of the device

#define UART_MESSAGE_LEN			17
#define UART_PREAMBLE_0				0
#define UART_PREAMBLE_1				1
#define UART_ADDRESS				2
#define UART_PL_START				3
#define UART_PAYLOAD_LEN			13
#define UART_PL_END					UART_PL_START + UART_PAYLOAD_LEN - 1
#define UART_CHECKSUM				UART_PL_END + 1

// Message structure for messages exchanged in shared memory

#define SM_UART_MESSAGE_LEN			13
#define SM_UART_PL_START			0
#define SM_PAYLOAD_LEN			    13  // time/type (1) + eid (4) + data (8)
#define SM_UART_PL_END				SM_UART_PL_START + SM_PAYLOAD_LEN - 1


typedef struct UART_BUFS {
	bool ready;
	bool tx_updated;
	bool rx_updated;
	uint16_t writer_loc;
	uint8_t buf[256][SM_UART_MESSAGE_LEN];
} UART_BUF;

extern UART_BUF uart_buf;

extern mutex_t mtx_uart;

void uart_init(void);

#endif
