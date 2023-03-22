#pragma once

#ifdef INVERT_POWER
	#define POWER_ON LOW
	#define POWER_OFF HIGH
#else
	#define POWER_ON HIGH
	#define POWER_OFF LOW
#endif
#ifdef INVERT_POWER2
	#define POWER2_ON LOW
	#define POWER2_OFF HIGH
#else
	#define POWER2_ON HIGH
	#define POWER2_OFF LOW
#endif

void Power_Init(void);
void Power_PeripheralOn(void);
void Power_PeripheralOff(void);
