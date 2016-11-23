#include "A4963_config.h"
#include "A4963_def.h"

//default values for registers
//same as power on reset values
static const uint16_t default_config0 = RECIRCULATION_AUTO | BLANK_TIME(8) | DEAD_TIME(20);
static const uint16_t default_config1 = PERCENT_FAST_DECAY_12_5 | CURRENT_LIMIT(15) | VDS_DEBOUNCE_MODE | VDS_THRESHOLD(31);
static const uint16_t default_config2 = POSITION_P_GAIN(7) | OVERSPEED_150 | INDIRECT_PWM_PERIOD(19);
static const uint16_t default_config3 = POSITION_I_GAIN(7) | HOLD_DUTY_CYCLE(5) | HOLD_TIME(2);
static const uint16_t default_config4 = SPEED_P_GAIN(7) | STARTUP_DUTY_CYCLE(7) | START_SPEED(3);
static const uint16_t default_config5 = SPEED_I_GAIN(7) | SPEED_FG | MAXIMUM_SPEED(3) | PHASE_ADVANCE(8);
static const uint16_t default_run = RUN_ENABLE | RESTART_ENABLE | CONTROL_OPEN_SPEED_INDIRECT;
static const uint16_t default_mask = 0;

static const uint8_t default_motor_pole = 1;
static const uint8_t default_sense_resistor = 11;

A4963Config::A4963Config():
	reg_config0(default_config0), reg_config1(default_config1),
	reg_config2(default_config2), reg_config3(default_config3),
	reg_config4(default_config4), reg_config5(default_config5),
	reg_run(default_run), reg_mask(default_mask),
	motor_pole(default_motor_pole), sense_resistor(default_sense_resistor),
	pwm_value(0)
{}

void A4963Config::run()
{
	reg_run |= RUN_ENABLE;
}

void A4963Config::stop()
{
	reg_run &= ~RUN_ENABLE;
}

bool A4963Config::isRunning()
{
	return reg_run & RUN_ENABLE;
}

void A4963Config::runningDirection(Direction dir)
{
	if(dir==FORWARD)
		reg_run &= ~DIR_BACKWARD;
	else if(dir==BACKWARD)
		reg_run |= DIR_BACKWARD;
}

Direction A4963Config::runningDirection()
{
	return (reg_run & DIR_BACKWARD) ? BACKWARD : FORWARD;
}

void A4963Config::stopOnFail(bool value)
{
	if(value)
		reg_run |= STOP_ON_FAIL;
	else
		reg_run &= ~STOP_ON_FAIL;
}

bool A4963Config::stopOnFail()
{
	return reg_run & STOP_ON_FAIL;
}

void A4963Config::restartOnSyncLoss(bool value)
{
	if(value)
		reg_run |= RESTART_ENABLE;
	else
		reg_run &= ~RESTART_ENABLE;
}

bool A4963Config::restartOnSyncLoss()
{
	return reg_run & RESTART_ENABLE;
}

void A4963Config::brake(bool value)
{
	if(value)
		reg_run |= BRAKE_ENABLE;
	else
		reg_run &= ~BRAKE_ENABLE;
}

bool A4963Config::brake()
{
	return reg_run & BRAKE_ENABLE;
}

void A4963Config::runningMode(RunningMode mode)
{
	reg_run &= ~((1<<CM1)|(1<<CM0));
	switch(mode)
	{
		case INDIRECT:
			reg_run |= CONTROL_OPEN_SPEED_INDIRECT;
			break;
		case DIRECT:
			reg_run |= CONTROL_OPEN_SPEED_DIRECT;
			break;
		case SPEED:
			reg_run |= CONTROL_CLOSED_SPEED;
			break;
		case CURRENT:
			reg_run |= CONTROL_CLOSED_CURRENT;
			break;
	}
}

RunningMode A4963Config::runningMode()
{
	switch(reg_run & ((1<<CM1)|(1<<CM0)))
	{
		case CONTROL_OPEN_SPEED_INDIRECT:
			return INDIRECT;
		case CONTROL_OPEN_SPEED_DIRECT:
			return DIRECT;
		case CONTROL_CLOSED_SPEED:
			return SPEED;
		case CONTROL_CLOSED_CURRENT:
			return CURRENT;
	}
	return INVALID_MODE;
}

void A4963Config::dutyCycle(uint8_t duty_cycle)
{
	pwm_value=duty_cycle;
}

uint8_t A4963Config::dutyCycle()
{
	return pwm_value;
}


