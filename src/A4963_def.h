#ifndef __A4963_DEF__
#define __A4963_DEF__

// register address (in the 16 word)
#define REG_CONFIG0 0x0000
#define REG_CONFIG1 0x2000
#define REG_CONFIG2 0x4000
#define REG_CONFIG3 0x6000
#define REG_CONFIG4 0x8000
#define REG_CONFIG5 0xA000
#define REG_MASK 0xC000
#define REG_RUN 0xE000

#define WR 12
#define REG_READ 0
#define REG_WRITE (1<<WR)

// register config0 bits
#define DT0 0
#define DT1 1
#define DT2 2
#define DT3 3
#define DT4 4
#define DT5 5
#define BT0 6
#define BT1 7
#define BT2 8
#define BT3 9
#define RM0 10
#define RM1 11

// register config1 bits
#define VT0 0
#define VT1 1
#define VT2 2
#define VT3 3
#define VT4 4
#define VDQ 5
#define VIL0 6
#define VIL1 7
#define VIL2 8
#define VIL3 9
#define IPI 10
#define PFD 11

// register config2 bits
#define PW0 0
#define PW1 1
#define PW2 2
#define PW3 3
#define PW4 4
#define DGC 5
#define SH0 6
#define SH1 7
#define CP0 8
#define CP1 9
#define CP2 10
#define CP3 11

// register config3 bits
#define HT0 0
#define HT1 1
#define HT2 2
#define HT3 3
#define HD0 4
#define HD1 5
#define HD2 6
#define HD3 7
#define CI0 8
#define CI1 9
#define CI2 10
#define CI3 11

// register config4 bits
#define SS0 0
#define SS1 1
#define SS2 2
#define SS3 3
#define SD0 4
#define SD1 5
#define SD2 6
#define SD3 7
#define SP0 8
#define SP1 9
#define SP2 10
#define SP3 11

// register config5 bits
#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define SMX0 4
#define SMX1 5
#define SMX2 6
#define SPO 7
#define SI0 8
#define SI1 9
#define SI2 10
#define SI3 11

// register run bits
#define RUN 0
#define DIR 1
#define BRK 2
#define RSC 3
#define DI0 4
#define DI1 5
#define DI2 6
#define DI3 7
#define DI4 8
#define ESF 9
#define CM0 10
#define CM1 11

// register diagnostic/mask bits
#define CL 0
#define CH 1
#define BL 2
#define BH 3
#define AL 4
#define AH 5
#define VS 7
#define LOS 9
#define OT 10
#define TW 11
#define SE 13
#define POR 14
#define FF 15


//config0 constants
#define RECIRCULATION_AUTO 0
#define RECIRCULATION_HIGH (1<<RM0)
#define RECIRCULATION_LOW (1<<RM1)
#define RECIRCULATION_ASYNC ((1<<RM1)|(1<<RM0))
#define BLANK_TIME(N) ((N&0x0F)<<BT0)
#define DEAD_TIME(N) ((N&0x3F)<<DT0)

//config1 constants
#define PERCENT_FAST_DECAY_12_5 0
#define PERCENT_FAST_DECAY_25 (1<<PFD)
#define INVERT_PWM (1<<IPI)
#define CURRENT_LIMIT(N) ((N&0x0F)<<VIL0)
#define VDS_DEBOUNCE_MODE 0
#define VDS_BLANK_MODE (1<<VDQ)
#define VDS_THRESHOLD(N) ((N&0x1F)<<VT0)

//config2 constants
#define POSITION_P_GAIN(N) ((N&0x0F)<<CP0)
#define OVERSPEED_100 0
#define OVERSPEED_125 (1<<SH0)
#define OVERSPEED_150 (1<<SH1)
#define OVERSPEED_200 ((1<<SH0)|(1<<SH1))
#define DEGAUSS_COMPENSATION (1<<DGC)
#define INDIRECT_PWM_PERIOD(N) ((N&0x1F)<<PW0)

//config3 constants
#define POSITION_I_GAIN(N) ((N&0x0F)<<CI0)
#define HOLD_DUTY_CYCLE(N) ((N&0x0F)<<HD0)
#define HOLD_TIME(N) ((N&0x0F)<<HT0)

//config4 constants
#define SPEED_P_GAIN(N) ((N&0x0F)<<SP0)
#define STARTUP_DUTY_CYCLE(N) ((N&0x0F)<<SD0)
#define START_SPEED(N) ((N&0x0F)<<SS0)

//config5 constants
#define SPEED_I_GAIN(N) ((N&0x0F)<<SI0)
#define SPEED_FG 0
#define SPEED_TACHO (1<<SPO)
#define MAXIMUM_SPEED(N) ((N&0x07)<<SMX0)
#define PHASE_ADVANCE(N) ((N&0x0F)<<PA0)

// run mode constants
#define RUN_ENABLE (1<<RUN)
#define DIR_BACKWARD (1<<DIR)
#define BRAKE_ENABLE (1<<BRK)
#define RESTART_ENABLE (1<<RSC)
#define STOP_ON_FAIL (1<<ESF)
#define CONTROL_OPEN_SPEED_INDIRECT 0
#define CONTROL_OPEN_SPEED_DIRECT (1<<CM0)
#define CONTROL_CLOSED_CURRENT (1<<CM1)
#define CONTROL_CLOSED_SPEED ((1<<CM1)|(1<<CM0))

// Range is given in RPM, for a motor with one pole pair
// Divide by the number of pole pair of your motor to get
// the actual speed range

//#define SPEED_RANGE_1530 0
//#define SPEED_RANGE_3066 1
//#define SPEED_RANGE_6138 2
//#define SPEED_RANGE_12282 3
//#define SPEED_RANGE_24570 4
//#define SPEED_RANGE_49146 5
//#define SPEED_RANGE_98298 6
//#define SPEED_RANGE_196602 7
#endif
