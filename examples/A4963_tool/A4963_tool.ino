#include "A4963.h"

#define FAULT_ADDRESS 8
#define SPEED_ADDRESS 9
#define PWM_ADDRESS 10

uint8_t pwm_value=0;

void setup()
{
  Serial.begin(115200);
  A4963.begin();
  
  A4963.setPWM(pwm_value);
}

void ping()
{
  Serial.write("A4963");
} 

void write()
{
  uint8_t data[3];
  Serial.readBytes(data, 3);
  
  uint16_t address=data[0];
  uint16_t value=(uint16_t(data[1]) | uint16_t(data[2])<<8);
  uint16_t result=0;

  if(address<8)
  {
    result=A4963.write(address<<13, value);
  }
  else if(address==PWM_ADDRESS)
  {
    A4963.setPWM(value);
    pwm_value=value;
  }
  Serial.write(result&0xFF);
  Serial.write(result>>8);
}

void read()
{
  uint8_t data[1];
  Serial.readBytes(data, 1);
  
  uint16_t address=data[0];
  uint16_t result=0;

  if(address<8)
  {
    result=A4963.read(address<<13);
  }
  else if(address==PWM_ADDRESS)
  {
    result=pwm_value;
  }
  Serial.write(result&0xFF);
  Serial.write(result>>8);
}


void loop(){
  uint8_t command=Serial.read();
  switch(command)
  {
    case 'p':
      ping();
      break;
    case 'w':
      write();
      break;
    case 'r':
      read();
      break;
    default:;
  }
}
