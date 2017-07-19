

// Standard headers
#include <stdbool.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "blinker.h"
#include "serial.h"
#include "can.h"


volatile int tx_done;
volatile int rx_done;

static THD_WORKING_AREA(waThread_serial, 128);

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

static void message_init(uint8_t* tx_buf){
	tx_buf[PREAMBLE_0]	= 0xaa;
	tx_buf[PREAMBLE_1]	= 0xaa;
	tx_buf[COMMAND_0]		= 0x00;
	tx_buf[COMMAND_1]		= 0x00;
	tx_buf[PACKET_ID_0]	= 0x00;
	tx_buf[PACKET_ID_1]	= 0x00;
	tx_buf[LEN]						= 0x00;

	for (int i=0; i<PL_END-PL_START; i++){
		tx_buf[PL_START+i] = 0x00;
	}
}

static void message_checksum_gen(uint8_t* tx_buf){
	tx_buf[CHECKSUM] = 0x00;
	tx_buf[CHECKSUM] ^= tx_buf[PREAMBLE_0];
	tx_buf[CHECKSUM] ^= tx_buf[PREAMBLE_1];
	tx_buf[CHECKSUM] ^= tx_buf[COMMAND_0];
	tx_buf[CHECKSUM] ^= tx_buf[COMMAND_1];
	tx_buf[CHECKSUM] ^= tx_buf[PACKET_ID_0];
	tx_buf[CHECKSUM] ^= tx_buf[PACKET_ID_1];
	tx_buf[CHECKSUM] ^= tx_buf[LEN];

	for (int i=0; i<PL_END-PL_START; i++){
		tx_buf[CHECKSUM] ^= tx_buf[PL_START+i];
	}
}

static THD_FUNCTION(Thread_serial, arg) {
	(void)arg;
	chRegSetThreadName("serial");

	uint8_t heartbeat_timeout = 0;
	uint8_t tx_buf[MESSAGE_LEN] = {0x00};
	uint8_t rx_buf[MESSAGE_LEN] = {0x00};

	// Initial UART ports
	palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(7)); // UART1 TX
	palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7)); // UART1 RX
	uartStart(&UARTD1, &uart_cfg_1);


	message_init(tx_buf);
	message_checksum_gen(tx_buf);



	while (true) {
//		char message = 'a';
//		uartStartSend(&UARTD1, 1, &message);

		tx_done = false;
		uartStartSend(&UARTD1, MESSAGE_LEN, tx_buf);
		uartStartReceive(&UARTD1, MESSAGE_LEN, rx_buf);

//		heartbeat_timeout = 0;
		while(tx_done == false){
			chThdSleepMilliseconds(10);
//			heartbeat_timeout += 1;
//			if (heartbeat_timeout > 100) break;
		}

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
}

void serial_init(void)
{
  // Creates the serial thread.
  chThdCreateStatic(waThread_serial,
										  sizeof(waThread_serial),
										  NORMALPRIO,
										  Thread_serial,
										  NULL);

}
