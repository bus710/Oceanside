// Standard headers
#include <stdbool.h>
#include <string.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"
#include "can.h"

struct can_instance {
	CANDriver *canp;
};

static const struct can_instance can1 = { &CAND1 };
static const struct can_instance can2 = { &CAND2 };

// Please refer to F446Rx's RM0390 section 30.9, "bxCAN"
// CAN_BTR_BRP (14)	: 250kHz
// CAN_BTR_BRP (6)	: 500kHz
static const CANConfig cancfg = {
		CAN_MCR_ABOM | CAN_MCR_AWUM | CAN_MCR_TXFP
		| CAN_MCR_NART, CAN_BTR_SJW(0)
		| CAN_BTR_TS2(1) | CAN_BTR_TS1(8)
		| CAN_BTR_BRP(14) };


static THD_WORKING_AREA(waThread_can2_rx, 128);
static THD_FUNCTION(Thread_can2_rx, p) {
	struct can_instance *cip = p;
	event_listener_t el;
	CANRxFrame rxmsg;

	(void)p;
	chRegSetThreadName("can2_receiver");
	chEvtRegister(&cip->canp->rxfull_event, &el, 0);

	while(true){
		if(chEvtWaitAnyTimeout(ALL_EVENTS, MS2ST(100)) == 0){
			continue;
		}
		while(canReceive(
				cip->canp,
				CAN_ANY_MAILBOX,
				&rxmsg,
				TIME_IMMEDIATE) == MSG_OK){
			chThdSleepMilliseconds(5);
			uint32_t a = rxmsg.data32[0];
			if(a){}
		}
	}
	chEvtUnregister(&CAND2.rxfull_event, &el);
}

static THD_WORKING_AREA(waThread_can2_tx, 128);
static THD_FUNCTION(Thread_can2_tx, p) {

	(void)p;

	// Message initial.
	CANTxFrame txmsg;
	txmsg.IDE = CAN_IDE_EXT;
	txmsg.EID = 0x00000005; // ID
	txmsg.RTR = CAN_RTR_DATA;
	txmsg.DLC = 8; // length
	txmsg.data32[0] = 0xaa55aa55;
	txmsg.data32[1] = 0xaa55aa55;

	while(true){
		canTransmit(&CAND2, CAN_ANY_MAILBOX, &txmsg, MS2ST(20));
		chThdSleepMilliseconds(500);
	}
}


void can_init(void)
{
	// Setup CAN ports
	palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(9) |
						PAL_STM32_OTYPE_PUSHPULL |
						PAL_STM32_OSPEED_MID1 ); // CAN2 RX
	palSetPadMode(GPIOB, 13, PAL_MODE_ALTERNATE(9) |
						PAL_STM32_OTYPE_PUSHPULL |
						PAL_STM32_OSPEED_MID1 ); // CAN2 TX

	// Setup filters
	//canSTM32SetFilters(0, 0, NULL, NULL);

	// Even if CAN1 is not used in the project, CAN1 should be activated.
	// Since CAN2 relies on the configuration of CAN1.
	canStart(&CAND1, &cancfg);
	canStart(&CAND2, &cancfg);

	// Creates the serial thread.
	chThdCreateStatic(
			waThread_can2_tx,
			sizeof(waThread_can2_tx),
			NORMALPRIO,
			Thread_can2_tx,
			(void *)&can2);
	chThdCreateStatic(
			waThread_can2_rx,
			sizeof(waThread_can2_rx),
			NORMALPRIO,
			Thread_can2_rx,
			(void *)&can2);
}

