#include <Arduino.h>
#include "settings.h"

#include "TbControl.h"
#include "Battery.h"
#include "Led.h"
#include "Cmd.h"
#include "Log.h"

#include <RvX_LIS3DH_TB.h>
#include <JC_Button.h>
RvX_LIS3DH_TB lis = RvX_LIS3DH_TB();
Button _earSmall = Button(21, 25, false, true);
Button _earBig = Button(20, 25, false, true);
Button _charger = Button(8, 150, false, false);

enum class PressedTime { NOT, SHORT, LONG, VERY_LONG };
enum class EarButton { NONE, SMALL, BIG, BOTH };
enum class PressedType { NONE, PRESS, RELEASE };

uint16_t _earLongPressMs = 5000;
uint16_t _earVeryLongPressMs = 10000;

PressedTime _earSmallPressedTime = PressedTime::NOT;
PressedTime _earBigPressedTime = PressedTime::NOT;
PressedTime _earBothPressedTime = PressedTime::NOT;

void TbControl_Init_LIS3DH(void);
void TbControl_Init_Buttons(void);
void TbControl_Init_Charger(void);
void TbControl_Cyclic_LIS3DH(void);
void TbControl_Cyclic_Buttons(void);
void TbControl_Cyclic_Charger(void);
void TbControl_Ears_WaitForRelease(void);
void handleEarEvent(EarButton earId, PressedType pressType, PressedTime pressLength);

void TbControl_Init(void) {
    TbControl_Init_LIS3DH();
    TbControl_Init_Buttons();
    TbControl_Init_Charger();
}
void TbControl_Init_LIS3DH(void) {
    const int i2c_sda = 5;
    const int i2c_scl = 6;
    Wire.setPins(i2c_sda, i2c_scl);
    Wire.begin();
    if (!lis.begin(0x19)) {
		Log_Println((char *) F("LIS3DH: NOT FOUND!"), LOGLEVEL_ERROR);
    }
}
void TbControl_Init_Buttons(void) {
    _earSmall.begin();
    _earBig.begin();
}
void TbControl_Init_Charger(void) {
    _charger.begin();
    _charger.read(); //Prevent indicating status after boot.
}

void TbControl_Cyclic(void) {
    TbControl_Cyclic_LIS3DH();
    TbControl_Cyclic_Buttons();
    TbControl_Cyclic_Charger();
}
void TbControl_Cyclic_LIS3DH(void) {
    lis.read();
}
void TbControl_Cyclic_Buttons(void) {
    _earSmall.read();
    if (_earSmall.pressedFor(_earVeryLongPressMs) && _earSmallPressedTime == PressedTime::LONG) {
        _earSmallPressedTime = PressedTime::VERY_LONG;
        if (!_earBig.isPressed() && _earBigPressedTime == PressedTime::NOT)
            handleEarEvent(EarButton::SMALL, PressedType::PRESS, _earSmallPressedTime);
    } else if (_earSmall.pressedFor(_earLongPressMs) && _earSmallPressedTime == PressedTime::SHORT) {
        _earSmallPressedTime = PressedTime::LONG;
        if (!_earBig.isPressed() && _earBigPressedTime == PressedTime::NOT)
            handleEarEvent(EarButton::SMALL, PressedType::PRESS, _earSmallPressedTime);
    } else if (_earSmall.isPressed() && _earSmallPressedTime == PressedTime::NOT) {
        _earSmallPressedTime = PressedTime::SHORT;
        if (!_earBig.isPressed() && _earBigPressedTime == PressedTime::NOT)
            handleEarEvent(EarButton::SMALL, PressedType::PRESS, _earSmallPressedTime);
    }
    
    _earBig.read();
    if (_earBig.pressedFor(_earVeryLongPressMs) && _earBigPressedTime == PressedTime::LONG) {
        _earBigPressedTime = PressedTime::VERY_LONG;
        if (!_earSmall.isPressed() && _earSmallPressedTime == PressedTime::NOT)
            handleEarEvent(EarButton::BIG, PressedType::PRESS, _earBigPressedTime);
    } else if (_earBig.pressedFor(_earLongPressMs) && _earBigPressedTime == PressedTime::SHORT) {
        _earBigPressedTime = PressedTime::LONG;
        if (!_earSmall.isPressed() && _earSmallPressedTime == PressedTime::NOT)
            handleEarEvent(EarButton::BIG, PressedType::PRESS, _earBigPressedTime);
    } else if (_earBig.isPressed() && _earBigPressedTime == PressedTime::NOT) {
        _earBigPressedTime = PressedTime::SHORT;
        if (!_earSmall.isPressed() && _earSmallPressedTime == PressedTime::NOT)
            handleEarEvent(EarButton::BIG, PressedType::PRESS, _earBigPressedTime);
    }

    if (_earSmallPressedTime == PressedTime::VERY_LONG && _earBigPressedTime == PressedTime::VERY_LONG && _earBothPressedTime == PressedTime::LONG) {
        _earBothPressedTime = PressedTime::VERY_LONG;
        handleEarEvent(EarButton::BOTH, PressedType::PRESS, _earBothPressedTime);
    } else if (_earSmallPressedTime == PressedTime::LONG && _earBigPressedTime == PressedTime::LONG && _earBothPressedTime == PressedTime::SHORT) {
        _earBothPressedTime = PressedTime::LONG;
        handleEarEvent(EarButton::BOTH, PressedType::PRESS, _earBothPressedTime);
    } else if (_earSmallPressedTime == PressedTime::SHORT && _earBigPressedTime == PressedTime::SHORT && _earBothPressedTime == PressedTime::NOT) {
        _earBothPressedTime = PressedTime::SHORT;
        handleEarEvent(EarButton::BOTH, PressedType::PRESS, _earBothPressedTime);
    }
    
    if (_earBothPressedTime == PressedTime::NOT) {
        if (_earSmall.wasReleased()) {
            handleEarEvent(EarButton::SMALL, PressedType::RELEASE, _earSmallPressedTime);
            _earSmallPressedTime = PressedTime::NOT;
        } else if (_earBig.wasReleased()) {
            handleEarEvent(EarButton::BIG, PressedType::RELEASE, _earBigPressedTime);
            _earBigPressedTime = PressedTime::NOT;
        }
    } else if (_earSmall.wasReleased() || _earBig.wasReleased()) {
        //TODO Prevent release event of other ear
        handleEarEvent(EarButton::BOTH, PressedType::RELEASE, _earBothPressedTime);
        _earBothPressedTime = PressedTime::NOT;
        _earSmallPressedTime = PressedTime::NOT;
        _earBigPressedTime = PressedTime::NOT;
    }
}
void handleEarEvent(EarButton earId, PressedType pressType, PressedTime pressLength) {
    if (pressType == PressedType::PRESS) {
        if (pressLength == PressedTime::SHORT) {
            if (earId == EarButton::SMALL) {
                Cmd_Action(CMD_VOLUMEDOWN);
            } else if (earId == EarButton::BIG) {
                Cmd_Action(CMD_VOLUMEUP);
            } else if (earId == EarButton::BOTH) {
            } 
        } else if (pressLength == PressedTime::LONG) {
        } else if (pressLength == PressedTime::VERY_LONG) {
            if (earId == EarButton::SMALL) {
            } else if (earId == EarButton::BIG) {
            } else if (earId == EarButton::BOTH) {
                if (lis.orientation == RvX_LIS3DH_TB::Orientation::EARS_FRONT) {
                    TbControl_Ears_WaitForRelease();
                    Cmd_Action(CMD_SLEEPMODE);
                } else if (lis.orientation == RvX_LIS3DH_TB::Orientation::EARS_DOWN) {
                    TbControl_Ears_WaitForRelease();
                    Cmd_Action(CMD_RESTARTSYSTEM);
                }
            } 
        }
    }
}
void TbControl_Cyclic_Charger(void) {
    _charger.read();
    if (_charger.wasPressed()) {
        Led_Indicate(LedIndicatorType::Ok);
        Log_Println((char *) F("Charger connected..."), LOGLEVEL_INFO);
        Battery_Cyclic(true);
    } else if (_charger.wasReleased()) {
        Led_Indicate(LedIndicatorType::Error);
        Log_Println((char *) F("Charger disconnected..."), LOGLEVEL_INFO);
        Battery_Cyclic(true);
    }
}

void TbControl_Exit(void) {

}

void TbControl_Ears_WaitForRelease(void) {
    while (true) {
        delay(100);
        //Box.watchdog_feed();
        _earSmall.read();
        _earBig.read();
        if (!_earSmall.isPressed() && !_earBig.isPressed()) 
            break;
        Led_Indicate(LedIndicatorType::Error);
    }
}