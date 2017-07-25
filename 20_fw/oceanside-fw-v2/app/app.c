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

		bool app_tick = true;

		systime_t start = chVTGetSystemTime();
		systime_t end = start + S2ST(1);

		while (chVTIsSystemTimeWithin(start, end)) {

			chThdSleepMilliseconds(20);

			if (app_tick) {
				app_tick = false;

				chMtxLock(&mtx_uart);

				if (uart_command_buf.ready == true) {
					if (uart_command_buf.tx_updated == false) {
						uart_command_buf.tx_updated = true;
						uart_command_buf.writer_loc = 0;

						for (int j = 0; j < 100; j++) {
							uart_command_buf.buf[j][SM_UART_LEN] = 16;
							for (int i = 0; i < UART_PAYLOAD_LEN; i++) {
								// copy operation for sensors should be executed here.
								uart_command_buf.buf[j][SM_UART_PL_START + i] =
										0xff;
							}
						}
						if (uart_command_buf.rx_updated == true) {
							uart_command_buf.rx_updated = false;
							// copy operation for parameter from odroid should be executed here.
							// refer the buffer and copy to each local buffers for threads.
						}
					}

				}

				chMtxUnlock(&mtx_uart);
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
