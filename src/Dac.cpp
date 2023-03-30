#include "Dac.h"
#include "Log.h"

#ifdef DAC_TLV320DAC3100_ENABLE
    RvX_TLV320DAC3100 dac = RvX_TLV320DAC3100();
	#define RESET_DAC_PIN 26
#endif
void Dac_Init(void) {
    #ifdef DAC_TLV320DAC3100_ENABLE
        const int i2c_sda = 5;
        const int i2c_scl = 6;

        pinMode(RESET_DAC_PIN, OUTPUT); 
        delay(50); 
        digitalWrite(RESET_DAC_PIN, 0);
        delay(10);
        digitalWrite(RESET_DAC_PIN, 1);
        delay(10);

        Wire.setPins(i2c_sda, i2c_scl);
        Wire.begin();
        if (!dac.begin(0x18)) {
			Log_Println((char *) F("DAC: NOT FOUND!"), LOGLEVEL_ERROR);
        } else {
			Log_Println((char *) F("DAC: FOUND!"), LOGLEVEL_INFO);
        }
        //dac.beep(); //hangs
    #endif
}
void Dac_Cyclic(void) {
    //
}
void Dac_Exit(void) {
    #ifdef DAC_TLV320DAC3100_ENABLE
        dac.powerDown();
        digitalWrite(RESET_DAC_PIN, 0); //Workaround
    #endif
}