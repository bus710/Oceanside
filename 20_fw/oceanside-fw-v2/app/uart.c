// Standard headers
#include <stdbool.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "uart.h"

mutex_t mtx_uart;

static uint16_t packet_id;
volatile uint8_t tx_done;
volatile uint8_t rx_done;
volatile uint8_t rx_char;
volatile uint8_t rx_cnt;
static uint8_t tx_buf[UART_MESSAGE_LEN] = {0x00};
static uint8_t rx_buf[UART_MESSAGE_LEN] = {0x00};

UART_COMMAND_BUF uart_command_buf;

static THD_WORKING_AREA(waThread_uart, 128);

// =========================================
// UART Callback Declarations.
// An UART requires 5 callbacks in general.
//
// txend1:	End of transmission buffer callback.
// txend2:	Physical end of transmission callback.
// rxend:		Receive buffer filled callback.
// rxchar: Character received while out if the UART_RECEIVE state.
// rxerr:		Receive error callback.
// =========================================

static void txend1(UARTDriver *uartp){
	// When a sending for a command is done, this would be called.
	// tx_done should be set to indicate UART1 is ready for the next commands.
	(void)uartp;
	tx_done = true;
}

static void txend2(UARTDriver *uartp){
	// This won't be used.
	(void)uartp;
}

static void rxend(UARTDriver *uartp){
	// This won't be used.
	(void)uartp;
}

static void rxchar(UARTDriver *uartp, uint16_t c){
	// The received byte would be checked and saved as our protocol.
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
		// No preamble was received so that there is no relative action.
	}

	if (rx_cnt > UART_MESSAGE_LEN){
		// Seems received enough bytes as a command.
		// Checksum maybe checked here.
		rx_cnt = 0;
		rx_done = true;
	}

	// Future work.
	// - Timeout feature maybe required.
}

static void rxerr(UARTDriver *uartp, uartflags_t e){
	// If there is an error, rx_cnt should be reset.
  (void)uartp;
  (void)e;
  rx_cnt = 0;

  // Future work.
  // - Command recovery feature maybe required.
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
	// USART_CR1, CR2, and CR3 should be referred from DS and RM.
};

static void uart_tx_message_init(void){
	// Takes data from the shared memory from the app thread.
	// And adds packet IDs
	tx_buf[UART_PREAMBLE_0]	= 0xaa;
	tx_buf[UART_PREAMBLE_1]	= 0xaa;
	tx_buf[UART_PACKET_ID] = (packet_id & 0x00ff);
	tx_buf[UART_ADDRESS] = 0x00;
	tx_buf[UART_LEN]			= 0x00;

	for (int i=UART_PL_START; i<UART_PL_END+1; i++){
		tx_buf[i] = 0x00;
	}

	packet_id += 1;
}

static void uart_tx_message_checksum_gen(void){
	// Generates the checksum.
	tx_buf[UART_CHECKSUM] = tx_buf[UART_PREAMBLE_0];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PREAMBLE_1];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_PACKET_ID];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_ADDRESS];
	tx_buf[UART_CHECKSUM] ^= tx_buf[UART_LEN];

	for (int i=UART_PL_START; i<UART_PL_END+1; i++){
		tx_buf[UART_CHECKSUM] ^= tx_buf[i];
	}
}

static void buf_initialization(UART_COMMAND_BUF* buf_handler){
	// Initializes a buffer in the shared space.
	buf_handler->tx_updated = false;
	buf_handler->rx_updated = false;
	buf_handler->writer_loc = 0;
	for (int i = 0; i < 128; i++) {
		for (int j=0; j<SM_UART_MESSAGE_LEN; j++){
			buf_handler->buf[i][j] = 0x00;
		}
	}
	buf_handler->ready = true;
}

static THD_FUNCTION(Thread_uart, arg) {
	(void)arg;
	chRegSetThreadName("uart");

	// Local variable declaration

	// Thread variable declaration
	tx_done = true;
	rx_done = false;
	packet_id = 0;

	// Command buffer initialization
	// Please lock the mutexes while editing the buffers.
	chMtxObjectInit(&mtx_uart);

	chMtxLock(&mtx_uart);
	buf_initialization(&uart_command_buf);
	chMtxUnlock(&mtx_uart);

	// UART ports and object initialization
	palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(7)); // UART1 TX
	palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7)); // UART1 RX
	uartStart(&UARTD1, &uart_cfg_1);

	// Thread loop
	while (true) {
		chThdSleepMilliseconds(1);


		// =========================================
		// Tx part
		// =========================================


//		// In order to have minimum communication with the host.
//		heartbeat_timeout += 1;
//		if (heartbeat_timeout > 1000){
//			heartbeat_timeout = 0;
//			if(tx_done){
//				// Tx command packing
//				uart_tx_message_init();
//				uart_tx_message_checksum_gen();
//				tx_done = false;
//				uartStartSend(&UARTD1, UART_MESSAGE_LEN, tx_buf);
//			}
//		}

		// In order to check if the app thread requested sending packet out.
		chMtxLock(&mtx_uart);
		if ((uart_command_buf.tx_updated) && (tx_done)) {

			if (uart_command_buf.writer_loc < 128) {

				// Tx command packing
				uart_tx_message_init();

				tx_buf[UART_ADDRESS] = uart_command_buf.writer_loc;
				tx_buf[UART_LEN] =
						uart_command_buf.buf[uart_command_buf.writer_loc][SM_UART_LEN];

				for (int i = 0; i < UART_PAYLOAD_LEN; i++) {
					tx_buf[UART_PL_START + i] =
							uart_command_buf.buf[uart_command_buf.writer_loc][SM_UART_PL_START + i];
				}
				uart_tx_message_checksum_gen();

				tx_done = false;
				uartStartSend(&UARTD1, UART_MESSAGE_LEN, tx_buf);

				uart_command_buf.writer_loc += 1;

			}
			else {
				// sent all already.
				uart_command_buf.ready = true;
				uart_command_buf.tx_updated = false;
			}

		}


		// =========================================
		// Rx part
		// =========================================

		// In order to receive a command.
		if(rx_done){
			rx_done = false;

			// In order to store the received data to the shared memory space.
			uint8_t addr = rx_buf[UART_ADDRESS];

			if(addr < 128){
				uart_command_buf.buf[addr][SM_UART_LEN] = rx_buf[UART_LEN];

				for (int i = 0; i < UART_MESSAGE_LEN; i++) {
					uart_command_buf.buf[addr][SM_UART_PL_START + i] = rx_buf[UART_PL_START + i];
				}
			}

			uart_command_buf.rx_updated = true;

			uartStartReceive(&UARTD1, UART_MESSAGE_LEN, rx_buf);
		}

		chMtxUnlock(&mtx_uart);
	}
}

void uart_init(void)
{
	// Creates the uart thread.
  chThdCreateStatic(
	waThread_uart,
	sizeof(waThread_uart),
	NORMALPRIO, Thread_uart,
	NULL);
}
