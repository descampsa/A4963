#include "A4963.h"

void setup()
{
	A4963.begin();
	A4963.write(REG_RUN, RUN_ENABLE | RESTART_ENABLE | STOP_ON_FAIL | CONTROL_CLOSED_SPEED);
	A4963.setPWM(128);
}

void loop(){}
