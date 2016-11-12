#include "A4963.h"
#include "SPI.h"
#ifdef ARDUINO_ARCH_AVR
#include "PinChangeInterrupt.h"
#endif

#define SS_PIN 10
#define PWM_PIN 9
#define SPD_PIN 8
#define FAULT_PIN 7

#define SPI_SPEED 20000000 // max speed supported by the A4963, actual speed will probably be slower depending of your arduino max speed


void A4963Controler::begin()
{
	SPI.begin();
	// set SPD and FAULT as inputs with pullup
	pinMode(SPD_PIN, INPUT_PULLUP);
	pinMode(FAULT_PIN, INPUT_PULLUP);
	// set PWM as output
	pinMode(PWM_PIN, OUTPUT);
	digitalWrite(PWM_PIN, LOW);
};

void A4963Controler::end()
{
	SPI.end();
}

void A4963Controler::setPWM(uint8_t pwm_value)
{
	analogWrite(PWM_PIN, pwm_value);
}

uint16_t A4963Controler::SPITransaction(uint16_t value)
{
	SPI.beginTransaction(SPISettings(SPI_SPEED, MSBFIRST, SPI_MODE3));
	digitalWrite(SS_PIN, LOW);
	value = SPI.transfer16(value);
	digitalWrite(SS_PIN, HIGH);
	SPI.endTransaction();
	return value;
}

uint16_t A4963Controler::write(uint16_t address, uint16_t value)
{
	return SPITransaction(address | REG_WRITE | value);
}

uint16_t A4963Controler::read(uint16_t address)
{
	return SPITransaction(address | REG_READ);
}

#ifdef ARDUINO_ARCH_AVR
void A4963Controler::onFault(CallbackPtr callback)
{
	if(callback)
	{
		attachPCINT(digitalPinToPCINT(FAULT_PIN), callback, FALLING);
	}
	else
	{
		detachPCINT(digitalPinToPCINT(FAULT_PIN));
	}
}

void A4963Controler::onSpeed(CallbackPtr callback)
{
	if(callback)
	{
		attachPCINT(digitalPinToPCINT(SPD_PIN), callback, FALLING);
	}
	else
	{
		detachPCINT(digitalPinToPCINT(SPD_PIN));
	}
}
#endif

A4963Controler A4963;


