#include "A4963.h"

uint8_t pwm=160;
uint32_t t=0;

uint8_t n=0;

void speedCallback()
{
  // compute speed in RPM, for a two poles motor
  // count for 100 events, and compute average speed
  if(n<100)
  {
    ++n;
  }
  else
  {
    uint32_t new_t=millis();
    uint32_t measured_speed=(6000000ul)/(new_t-t);
    t=new_t;
    n=0;
    Serial.println(measured_speed);
  }
}

void setup()
{
  Serial.begin(115200);
  A4963.begin();
  A4963.write(REG_CONFIG0, RECIRCULATION_AUTO | BLANK_TIME(8) | DEAD_TIME(20));
  A4963.write(REG_CONFIG1, PERCENT_FAST_DECAY_12_5 | CURRENT_LIMIT(15) | VDS_DEBOUNCE_MODE | VDS_THRESHOLD(31));
  
  A4963.write(REG_CONFIG2, POSITION_P_GAIN(7) | OVERSPEED_150 | INDIRECT_PWM_PERIOD(19));
  A4963.write(REG_CONFIG3, POSITION_I_GAIN(7) | HOLD_DUTY_CYCLE(5) | HOLD_TIME(2));
  
  A4963.write(REG_CONFIG4, SPEED_P_GAIN(7) | STARTUP_DUTY_CYCLE(7) | START_SPEED(3));
  A4963.write(REG_CONFIG5, SPEED_I_GAIN(7) | SPEED_FG | MAXIMUM_SPEED(3) | PHASE_ADVANCE(8));
  
  A4963.write(REG_RUN, RUN_ENABLE | RESTART_ENABLE | STOP_ON_FAIL | CONTROL_CLOSED_SPEED);

  A4963.onSpeed(speedCallback);

  A4963.setPWM(pwm);
}

void loop(){
  }
