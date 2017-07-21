// Standard headers
#include <stdbool.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "uart.h"


static uint16_t packet_id;
volatile uint8_t tx_done;
volatile uint8_t rx_done;
volatile uint8_t rx_char;
volatile uint8_t rx_cnt;
static uint8_t tx_buf[UART_MESSAGE_LEN] = {0x00};
static uint8_t rx_buf[UART_MESSAGE_LEN] = {0x00};


static THD_WORKING_AREA(waThread_uart, 1024);

static void txend1(UARTDriver *uartp){
	// End of transmission buffer callback.
	(void)uartp;
	tx_done = true;
}

static void txend2(UARTDriver *uartp){
	// Physical end of transmission callback.
	(void)uartp;
}

static void rxend(UARTDriver *uartp){
	// Receive buffer filled callback.
	(void)uartp;
}

static void rxchar(UARTDriver *uartp, uint16_t c){
	// Character received while out if the UART_RECEIVE state.
	(void)uartp;

	if ((rx_cnt==0) && (c==0xaa)){
		// received the first preamble, I guess.
		rx_buf[rx_cnt] = c & 0x00ff;
		rx_cnt += 1;
	}
	else if ((rx_cnt==1) && (c==0xaa)){
		// received the second preamble, I guess.
		rx_buf[rx_cnt] = c & 0x00ff;
		rx_cnt += 1;
	}
	else if(rx_cnt > 1){
		// received command, id, len, and payload.
		rx_buf[rx_cnt] = c & 0x00ff;
		rx_cnt += 1;
	}
	else{

	}

	if (rx_cnt > UART_MESSAGE_LEN){
		rx_cnt = 0;
		rx_done = true;
	}
}

static void rxerr(UARTDriver *uartp, uartflags_t e){
	 // Receive error callback.
  (void)uartp;
  (void)e;
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

static void uart_tx_message_init(void){
	tx_buf[UART_PREAMBLE_0]	= 0xaa;
	tx_buf[UART_PREAMBLE_1]	= 0xaa;
	tx_buf[UART_PACKET_ID_0]	= (packet_id & 0xff00) >> 8;
	tx_buf[UART_PACKET_ID_1]	= (packet_id & 0x00ff);
	tx_buf[UART_COMMAND_0]		= 0xcc;
	tx_buf[UART_COMMAND_1]		= 0xcc;
	tx_buf[UART_LEN]						= 0xdd;

	for (int i=UART_PL_START; i<UART_PL_END+1; i++){
		tx_buf[i] = i;
	}

	packet_id += 1;
}

static void uart_tx_message_checksum_gen(void){
	tx_buf[UART_CHECKSUM] = tx_buf[UART_PREAMBLE_0];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PREAMBLE_1];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PACKET_ID_0];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PACKET_ID_1];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_COMMAND_0];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_COMMAND_1];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_LEN];

	for (int i=UART_PL_START; i<UART_PL_END; i++){
		tx_buf[UART_CHECKSUM] ^= tx_buf[i];
	}
}

static THD_FUNCTION(Thread_uart, arg) {
	(void)arg;
	chRegSetThreadName("uart");

	uint16_t heartbeat_timeout = 0;


	tx_done = true;
	rx_done = false;
	packet_id = 0;

	// Initial UART ports
	palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(7)); // UART1 TX
	palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7)); // UART1 RX
	uartStart(&UARTD1, &uart_cfg_1);


	while (true) {
		chThdSleepMilliseconds(1);

		uart_tx_message_init();
		uart_tx_message_checksum_gen();

		heartbeat_timeout += 1;
		if (heartbeat_timeout > 1000){
			heartbeat_timeout = 0;
			if(tx_done){
				tx_done = false;
				uartStartSend(&UARTD1, UART_MESSAGE_LEN, tx_buf);
			}
		}

		if(rx_done){
			rx_done = false;
			uint8_t message[UART_MESSAGE_LEN]={0};
			for(int i=0; i<UART_MESSAGE_LEN; i++){
				message[i] = rx_buf[i];
			}
			uartStartReceive(&UARTD1, UART_MESSAGE_LEN, rx_buf);
		}

//		chMtxLock(&mtx_uart_tx);
//		if (global_char > 250){
//			global_char = 0;
//		}
//		chMtxUnlock(&mtx_uart_tx);

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
