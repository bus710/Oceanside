#include <stdbool.h>
#include "ch.h"
#include "hal.h"
#include "serial.h"


volatile int tx_done;

static THD_WORKING_AREA(waThread_serial, 128);

static void txend1(UARTDriver *uartp){
  (void)uartp;
	tx_done = true;
}

static void txend2(UARTDriver *uartp){
  (void)uartp;
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

static void message_init(MESSAGE* msg){
	msg->preamble_0 = 0xaa;
	msg->preamble_1 = 0xaa;
	msg->command_0 = 0x00;
	msg->command_1 = 0x00;
	msg->len = 0;
	for (int i=0; i<32; i++){
		msg->pl[i] = 0x00;
	}
}

static THD_FUNCTION(Thread_serial, arg) {

	// Setup UART ports
  palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(7)); // UART1 TX
  palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7)); // UART1 RX
  uartStart(&UARTD1, &uart_cfg_1);

	(void)arg;
	chRegSetThreadName("serial");

  char message = 'a';


	while (true) {
		MESSAGE msg;
		message_init(&msg);

		uartStartSend(&UARTD1, 1, &message);
		uartStartSend(&UARTD1, 38, &msg);
		if(tx_done == false){
			chThdSleepMilliseconds(10);
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
