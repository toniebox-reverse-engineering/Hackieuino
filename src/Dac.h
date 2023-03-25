#pragma once

#include "settings.h"
#ifdef DAC_TLV320DAC3100_ENABLE
	#include <RvX_TLV320DAC3100.h>
#endif

void Dac_Init(void);
void Dac_Cyclic(void);