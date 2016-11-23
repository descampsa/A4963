
#include <stdint.h>

enum Direction
{
	FORWARD,
	BACKWARD
};

enum RunningMode
{
	INDIRECT,
	DIRECT,
	SPEED,
	CURRENT,
	INVALID_MODE
};

class A4963Config
{
	public:
	A4963Config();
	
	// enable/disable motor control
	void run();
	void stop();
	bool isRunning();
	
	//turning direction
	void runningDirection(Direction dir);
	Direction runningDirection();
	
	void stopOnFail(bool value);
	bool stopOnFail();
	
	void restartOnSyncLoss(bool value);
	bool restartOnSyncLoss();
	
	void brake(bool value);
	bool brake();
	
	void runningMode(RunningMode mode);
	RunningMode runningMode();
	
	// raw pwm value
	void dutyCycle(uint8_t duty_cycle);
	uint8_t dutyCycle();
	
	// A4963 registers
	uint16_t reg_config0, reg_config1, reg_config2, reg_config3, reg_config4, reg_config5;
	uint16_t reg_run;
	uint16_t reg_mask;
	
	uint8_t pwm_value;
	
	// number of motor pole pair(s)
	uint8_t motor_pole;
	// current sense resistor value, in milliohm
	uint8_t sense_resistor;
};
