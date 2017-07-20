/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

// Standard headers
#include <stdbool.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "blinker.h"
#include "can.h"
#include "uart.h"

mutex_t mtx_uart_tx;
mutex_t mtx_uart_rx;
char global_char = 0;

msg_t buffer[8];
msg_t queue[1];
mailbox_t mb_buffer;


/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
*/
	halInit();
	chSysInit();

	chMtxObjectInit(&mtx_uart_tx);

  blinker_init();
  uart_init();
  can_init();
  app_init();



  // Normal main() thread activity, in this demo it does nothing except
  // sleeping in a loop and check the button state.
	while (true) {

		chMtxLock(&mtx_uart_tx);
		global_char += 1;
		chMtxUnlock(&mtx_uart_tx);

		chThdSleepMilliseconds(500);
	}
}
