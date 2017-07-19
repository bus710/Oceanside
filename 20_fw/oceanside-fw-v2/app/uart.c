

// Standard headers
#include <stdbool.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "uart.h"


volatile int tx_done;
volatile int rx_done;


static THD_WORKING_AREA(waThread_uart, 1024);

static void txend1(UARTDriver *uartp){
	(void)uartp;
	tx_done = true;
}

static void txend2(UARTDriver *uartp){
	(void)uartp;
	rx_done = true;
}

static void rxerr(UARTDriver *uartp, uartflags_t e){
  (void)uartp;
  (void)e;
}

static void rxchar(UARTDriver *uartp, uint16_t c){
  (void)uartp;
  (void)c;
}

static void rxend(UARTDriver *uartp){
  (void)uartp;
}

static UARTConfig uart_cfg_1 = {
	txend1,
	txend2,
	rxend,
	rxchar,
	rxerr,
	115200,
	0,
	USART_CR2_LINEN,
	0
};

static void uart_message_init(uint8_t* tx_buf){
	tx_buf[UART_PREAMBLE_0]	= 0xaa;
	tx_buf[UART_PREAMBLE_1]	= 0xaa;
	tx_buf[UART_COMMAND_0]		= 0x00;
	tx_buf[UART_COMMAND_1]		= 0x00;
	tx_buf[UART_PACKET_ID_0]	= 0x00;
	tx_buf[UART_PACKET_ID_1]	= 0x00;
	tx_buf[UART_LEN]						= 0x00;

	for (int i=0; i<UART_PL_END-UART_PL_START; i++){
		tx_buf[UART_PL_START+i] = 0x00;
	}
}

static void uart_message_checksum_gen(uint8_t* tx_buf){
	tx_buf[UART_CHECKSUM] = 0x00;
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PREAMBLE_0];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PREAMBLE_1];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_COMMAND_0];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_COMMAND_1];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PACKET_ID_0];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PACKET_ID_1];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_LEN];

	for (int i=0; i<UART_PL_END-UART_PL_START; i++){
		tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PL_START+i];
	}
}

static THD_FUNCTION(Thread_uart, arg) {
	(void)arg;
	chRegSetThreadName("uart");

	uint8_t heartbeat_timeout = 0;
	uint8_t tx_buf[UART_MESSAGE_LEN] = {0x00};
	uint8_t rx_buf[UART_MESSAGE_LEN] = {0x00};

	// Initial UART ports
	palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(7)); // UART1 TX
	palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7)); // UART1 RX
	uartStart(&UARTD1, &uart_cfg_1);


	uart_message_init(tx_buf);
	uart_message_checksum_gen(tx_buf);


//	char message = 'a';

	while (true) {
//		uartStartSend(&UARTD1, 1, &message);

		heartbeat_timeout = 0;
		while(true){
			heartbeat_timeout += 1;
			if (heartbeat_timeout > 100) break;
			chThdSleepMilliseconds(10);


			if(rx_done){
				rx_done = false;

				// Preamble checking
				if ((rx_buf[0] != 0xaa) || (rx_buf[1] != 0xaa)){
					// Invalid packet
				}
				else{
					// Preambles are fine.
					// Still need to see checksum

				}
			}
		}

		chMtxLock(&mtx_app_uart);
		if (global_char > 250){
			global_char = 0;
		}
		tx_buf[0] = global_char;
		chMtxUnlock(&mtx_app_uart);


		tx_done = false;
		uartStartSend(&UARTD1, UART_MESSAGE_LEN, tx_buf);
		uartStartReceive(&UARTD1, UART_MESSAGE_LEN, rx_buf);

		while(tx_done == false){
			chThdSleepMilliseconds(10);
		}

	}
}

void uart_init(void)
{
  // Creates the serial thread.
  chThdCreateStatic(waThread_uart,
										  sizeof(waThread_uart),
										  NORMALPRIO,
										  Thread_uart,
										  NULL);

}
