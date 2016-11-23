#include "Arduino.h"
#include "A4963_def.h"
#include "A4963_config.h"

class A4963Controler
{
	public:
	
	typedef void (*CallbackPtr)();
	
	void begin();
	void end();
	
	void setPWM(uint8_t pwm_value);
	
	uint16_t write(uint16_t address, uint16_t value);
	uint16_t read(uint16_t address);
	
	uint16_t SPITransaction(uint16_t value);
	
	void onFault(CallbackPtr callback);
	void onSpeed(CallbackPtr callback);
};


extern A4963Controler A4963;


