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


static THD_WORKING_AREA(waThread_can2_rx, 256);
static THD_FUNCTION(Thread_can2_rx, p) {
	struct can_instance *cip = p;
	event_listener_t el;
	CANRxFrame rxmsg;

	(void)p;
	chRegSetThreadName("can2_rx");
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
		    uint32_t e = rxmsg.EID;
		    uint32_t a = rxmsg.data32[0];
		    uint32_t b = rxmsg.data32[1];

			chThdSleepMilliseconds(5);
		}
	}
	chEvtUnregister(&CAND2.rxfull_event, &el);
}

static THD_WORKING_AREA(waThread_can2_tx, 128);
static THD_FUNCTION(Thread_can2_tx, p) {
	//struct can_instance *cip = p;

	(void)p;
	chRegSetThreadName("can2_tx");

	// Message initial.
	CANTxFrame txmsg;
	txmsg.IDE = CAN_IDE_EXT;
	//txmsg.EID = 0x00000005; // ID
	txmsg.EID = 0x00FEAA01; // ID
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
	// http://www.chibios.com/forum/viewtopic.php?f=16&t=4079
	/*
    CANFilter = {
        uint32_t filters,   (Number of filters)
        uint32_t mode,      (0=mask, 1=list)
        uint32_t scale,     (0=16bit, 1=32bit)
        uint32_t assignment,(CAN_FFA1R register bit)
        uint32_t register1, (Identifier)
        uint32_t register2  (Mask/Identifier)
    }*/
	CANFilter f[2] = {
	               {1, 1, 1, 0,
	               set_can_eid_data(0x00000000),
	               set_can_eid_data(0x00000000)},
	               {2, 1, 1, 1,
	               set_can_eid_data(0x00000004),
	               set_can_eid_data(0x00000004)}
	               };

    /*
	canSTM32SetFilters(
	    CANDriver *canp,
	    uint32_t can2sb,
	    uint32_t num,
	    const CANFilter *cfp)*/
	canSTM32SetFilters(&CAND1, 0x0, 2, &f[0]);
	canSTM32SetFilters(&CAND2, 0x0, 2, &f[0]);


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

