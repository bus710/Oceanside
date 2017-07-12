#include "ch.h"
#include "hal.h"


static THD_WORKING_AREA(waThread_serial, 128);

static void txend1(UARTDriver *uartp){
  (void)uartp;
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


static THD_FUNCTION(Thread_serial, arg) {

	// Setup UART ports
  palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(7)); // UART1 TX
  palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7)); // UART1 RX
  uartStart(&UARTD1, &uart_cfg_1);

	(void)arg;
	chRegSetThreadName("serial");

  char message = 'a';

	while (true) {
		uartStartSend(&UARTD1, 1, &message);
		chThdSleepMilliseconds(500);
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
