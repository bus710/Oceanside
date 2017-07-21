// Standard headers
#include <stdbool.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "uart.h"


static THD_WORKING_AREA(waThread_app, 1024);

static THD_FUNCTION(Thread_app, arg) {
	(void)arg;
	chRegSetThreadName("app");

	while (true) {
		chThdSleepMilliseconds(20);

		chMtxLock(&mtx_uart_tx);
		if (tx_command_buf.ready == true){
			if ((tx_command_buf.writer_loc + 1) != (tx_command_buf.reader_loc)){
				tx_command_buf.updated = true;
				tx_command_buf.writer_loc += 1;
				tx_command_buf.buf[tx_command_buf.writer_loc][SM_UART_COMMAND_0] = 0xff;
				tx_command_buf.buf[tx_command_buf.writer_loc][SM_UART_COMMAND_1] = 0xff;
				tx_command_buf.buf[tx_command_buf.writer_loc][SM_UART_LEN] = 32;
				for (int i=0; i<UART_PAYLOAD_LEN; i++){
					tx_command_buf.buf[tx_command_buf.writer_loc][SM_UART_PL_START+i] = 0xff;
				}
			}

		}

		chMtxUnlock(&mtx_uart_tx);

	}
}


void app_init(void)
{
  // Creates the serial thread.
  chThdCreateStatic(waThread_app,
										  sizeof(waThread_app),
										  NORMALPRIO,
										  Thread_app,
										  NULL);
}
