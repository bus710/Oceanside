#ifndef UART_H_
#define UART_H_

// Message structure for messages sent out of the device
#define UART_MESSAGE_LEN		40
#define UART_PREAMBLE_0			0
#define UART_PREAMBLE_1			1
#define UART_PACKET_ID_0		2
#define UART_PACKET_ID_1		3
#define UART_COMMAND_0				4
#define UART_COMMAND_1				5
#define UART_LEN							6
#define UART_PL_START				7
#define UART_PL_END						UART_PL_START + 31
#define UART_CHECKSUM				UART_PL_END + 1

// Message structure for messages exchanged between threads
#define MAIL_NUM							1
#define MAIL_MESSAGE_LEN		35
#define MAIL_COMMAND_ID_0		0
#define MAIL_COMMAND_ID_1		1
#define MAIL_LEN							1
#define MAIL_PL_START				7
#define MAIL_PL_END						MAIL_PL_START + 31

extern mutex_t mtx_uart_tx;
extern mutex_t mtx_uart_rx;

void uart_init(void);

#endif
