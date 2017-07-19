// Standard headers
#include <stdbool.h>
#include <string.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "can.h"


static THD_WORKING_AREA(waThread_can, 128);

static THD_FUNCTION(Thread_can, arg) {
	(void)arg;

	// Setup CAN ports
	palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(9) |
						PAL_STM32_OTYPE_PUSHPULL |
						PAL_STM32_OSPEED_MID1 ); // CAN2 RX
	palSetPadMode(GPIOB, 13, PAL_MODE_ALTERNATE(9) |
						PAL_STM32_OTYPE_PUSHPULL |
						PAL_STM32_OSPEED_MID1 ); // CAN2 TX

	// Please refer to F446Rx's RM0390 section 30.9, "bxCAN"
	// CAN_BTR_BRP (14)	: 250kHz
	// CAN_BTR_BRP (6)	: 500kHz
	static const CANConfig cancfg = {
		CAN_MCR_ABOM | CAN_MCR_AWUM | CAN_MCR_TXFP | CAN_MCR_NART,
		CAN_BTR_SJW(0) | CAN_BTR_TS2(1) |
		CAN_BTR_TS1(8) | CAN_BTR_BRP(14)
	};


	// Even if CAN1 is not used in the project, CAN1 should be activated.
	// Since CAN2 relies on the configuration of CAN1.
	canStart(&CAND1, &cancfg);
	canStart(&CAND2, &cancfg);

	// Message initial.
	uint8_t id = 0x05;
	uint8_t data[8] = {0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55};
	uint8_t len = 8;

	CANTxFrame txmsg;
	txmsg.IDE = CAN_IDE_EXT;
	txmsg.EID = id;
	txmsg.RTR = CAN_RTR_DATA;
	txmsg.DLC = len;
	memcpy(txmsg.data8, data, len);


	while(true){
		canTransmit(&CAND2, CAN_ANY_MAILBOX, &txmsg, MS2ST(20));
		chThdSleepMilliseconds(500);
	}
}


void can_init(void)
{
  // Creates the serial thread.
  chThdCreateStatic(waThread_can,
										  sizeof(waThread_can),
										  NORMALPRIO,
										  Thread_can,
										  NULL);
}

