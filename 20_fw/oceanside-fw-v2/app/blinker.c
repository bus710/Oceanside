#include "ch.h"
#include "hal.h"

/*
 * Green LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread_blinker, 128);

static THD_FUNCTION(Thread_blinker, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palClearPad(GPIOC, GPIOC_PIN13);
    chThdSleepMilliseconds(500);
    palSetPad(GPIOC, GPIOC_PIN13);
    chThdSleepMilliseconds(500);
  }
}


void blinker_init(void)
{
  // Creates the blinker thread.
  chThdCreateStatic(
	  waThread_blinker,
	  sizeof(waThread_blinker),
	  NORMALPRIO,
	  Thread_blinker,
	  NULL);
}
