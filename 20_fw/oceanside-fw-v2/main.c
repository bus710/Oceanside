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
#include "string.h"
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


  // Creates the blinker thread.
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

	// Setup UART ports
  palSetPadMode(GPIOA, 9, PAL_MODE_ALTERNATE(7)); // UART1 TX
  palSetPadMode(GPIOA, 10, PAL_MODE_ALTERNATE(7)); // UART1 RX
  uartStart(&UARTD1, &uart_cfg_1);

  char message = 'a';

	// Setup CAN ports
	palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(9) |
						PAL_STM32_OTYPE_PUSHPULL |
						PAL_STM32_OSPEED_MID1 ); // CAN2 RX
	palSetPadMode(GPIOB, 13, PAL_MODE_ALTERNATE(9) |
						PAL_STM32_OTYPE_PUSHPULL |
						PAL_STM32_OSPEED_MID1 ); // CAN2 TX

	// Please refer to F446Rx's RM0390 section 30.9, "bxCAN"
	static const CANConfig cancfg = {
		CAN_MCR_ABOM | CAN_MCR_AWUM | CAN_MCR_TXFP | CAN_MCR_NART,
		CAN_BTR_SJW(0) | CAN_BTR_TS2(1) |
		CAN_BTR_TS1(8) | CAN_BTR_BRP(6)
	};


	// Even if CAN1 is not used in the project, CAN1 should be activated.
	canStart(&CAND1, &cancfg);
	canStart(&CAND2, &cancfg);

	uint8_t id = 0x05;
	uint8_t data[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
	uint8_t len = 8;

	CANTxFrame txmsg;
	txmsg.IDE = CAN_IDE_EXT;
	txmsg.EID = id;
	txmsg.RTR = CAN_RTR_DATA;
	txmsg.DLC = len;
	memcpy(txmsg.data8, data, len);




  // Normal main() thread activity, in this demo it does nothing except
  // sleeping in a loop and check the button state.
	while (true) {
		uartStartSend(&UARTD1, 1, &message);

//		canStart(&CAND2, &cancfg);
		msg_t rc = canTransmit(&CAND2, CAN_ANY_MAILBOX, &txmsg, MS2ST(20));
//		canStop(&CAND2);

		if (rc){

		}

		chThdSleepMilliseconds(500);
	}
}
