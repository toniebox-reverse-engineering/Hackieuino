#include "Dac.h"

#ifdef DAC_TLV320DAC3100_ENABLE
    RvX_TLV320DAC3100 dac = RvX_TLV320DAC3100();
#endif
void Dac_Init(void) {
    #ifdef DAC_TLV320DAC3100_ENABLE
        const int i2c_sda = 5;
        const int i2c_scl = 6;
        Wire.setPins(i2c_sda, i2c_scl);
        dac.begin(0x18);
        dac.beep();
    #endif
}
void Dac_Cyclic(void) {
    //
}