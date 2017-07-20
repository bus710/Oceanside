// Standard headers
#include <stdbool.h>

// System headers
#include "ch.h"
#include "hal.h"

// Application headers
#include "app.h"



static THD_WORKING_AREA(waThread_app, 1024);

static THD_FUNCTION(Thread_app, arg) {
	(void)arg;
	chRegSetThreadName("app");

	while (true) {
		chThdSleepMilliseconds(500);
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
