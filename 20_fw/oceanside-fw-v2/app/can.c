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

CAN_BUF can_buf;

//static const struct can_instance can1 = { &CAND1 };
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

            //chMtxLock(&mtx_can); // shouldn't use mutex here.

            can_buf.buf[can_buf.writer_loc][0] = 0xff; // type or time
            can_buf.buf[can_buf.writer_loc][1] = (rxmsg.EID & 0xff000000) >> 24;
            can_buf.buf[can_buf.writer_loc][2] = (rxmsg.EID & 0x00ff0000) >> 16;
            can_buf.buf[can_buf.writer_loc][3] = (rxmsg.EID & 0x0000ff00) >> 8;
            can_buf.buf[can_buf.writer_loc][4] = rxmsg.EID & 0x000000ff;

		    for(int i=0; i<8; i++){
              can_buf.buf[can_buf.writer_loc][i+5] = rxmsg.data8[i]; // 5, because of time and eid.
		    }

		    can_buf.writer_loc += 1;
		    if(can_buf.writer_loc > 0x255){ can_buf.writer_loc = 0; }

            //chMtxUnlock(&mtx_can); // shouldn't use mutex here.

			//chThdSleepMilliseconds(1);
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
		chThdSleepMilliseconds(1000);
	}
}


void can_init(void)
{

    can_buf.writer_loc = 0;

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
	CANFilter f[7] = {
	               {1, 0, 1, 0,
	               set_can_eid_data(0x00F00300), // target id
	               set_can_eid_mask(0x00F00F00)}, // bits interested
	               {2, 0, 1, 0,
	               set_can_eid_data(0x00000002), // target id
	               set_can_eid_mask(0x0000000f)}, // bits interested
	               {3, 0, 1, 0,
	               set_can_eid_data(0x00000003), // target id
	               set_can_eid_mask(0x0000000f)}, // bits interested
	               {4, 0, 1, 0,
	               set_can_eid_data(0x00000004), // target id
	               set_can_eid_mask(0x000000ff)}, // bits interested
	               {5, 0, 1, 0,
	               set_can_eid_data(0x00000005), // target id
	               set_can_eid_mask(0x0000000f)}, // bits interested
	               {6, 0, 1, 0,
	               set_can_eid_data(0x00000006), // target id
	               set_can_eid_mask(0x0000000f)}, // bits interested
	               {7, 1, 1, 0,
	               set_can_eid_data(0x00000007), // target id
	               set_can_eid_data(0x00000008)}, // target id
	               };

    /*
	canSTM32SetFilters(
	    CANDriver *canp,
	    uint32_t can2sb,
	    uint32_t num,
	    const CANFilter *cfp)*/
	canSTM32SetFilters(&CAND1, 0x0, 7, &f[0]);
	canSTM32SetFilters(&CAND2, 0x0, 7, &f[0]);


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

