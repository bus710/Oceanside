// Standard headers
#include <stdbool.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "uart.h"


static THD_WORKING_AREA(waThread_app, 128);

static THD_FUNCTION(Thread_app, arg) {
	(void)arg;
	chRegSetThreadName("app");

	while (true) {

		bool sec_checker = true;

		systime_t start = chVTGetSystemTime();
		systime_t end = start + S2ST(1);

		while (chVTIsSystemTimeWithin(start, end)) {

			chThdSleepMilliseconds(20);

			if (sec_checker) {
				sec_checker = false;

				chMtxLock(&mtx_uart_tx);

				if ((tx_command_buf.ready == true)
						&& (tx_command_buf.updated == false)) {
					tx_command_buf.updated = true;
					tx_command_buf.writer_loc = 0;

					for (int j = 0; j < 128; j++) {
						tx_command_buf.buf[j][SM_UART_LEN] = 16;
						for (int i = 0; i < UART_PAYLOAD_LEN; i++) {
							tx_command_buf.buf[j][SM_UART_PL_START + i] = 0xff;
						}
					}

				}

				chMtxUnlock(&mtx_uart_tx);
			}
		}
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
