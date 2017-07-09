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

#include "ch.h"
#include "hal.h"
//#include "ch_test.h"

/*
 * Green LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palClearPad(GPIOC, GPIOC_PIN13);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOC, GPIOC_PIN13);
    chThdSleepMilliseconds(500);
  }
}


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

  /*
   * Activates the serial driver 2 using the driver default configuration.
   */
//  sdStart(&SD2, NULL);

  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(7)); // UART TX
  palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7)); // UART RX

	uartStart(&UARTD1, &uart_cfg_1);

	char message = 'a';


  /*
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (true) {
//    if (!palReadPad(GPIOC, GPIOC_BUTTON))
//      test_execute((BaseSequentialStream *)&SD2);
	  uartStartSend(&UARTD1, 1, &message);
    chThdSleepMilliseconds(500);
  }
}
