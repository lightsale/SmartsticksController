// modes.h

#ifndef _MODES_h
#define _MODES_h
#include "Constants.h"
#include <vector>
#include "FastLED.h"
#include "images.h"
#include "input.h"

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum class RequestedAction {
    donothing, lastmode
};

class Mode {
protected:
    void mirrorBackHalf();
public:
    bool active = false;
    CRGB* leds;
    virtual RequestedAction handleInput(byte input) = 0;
    virtual void fillLEDs() = 0;
    virtual void start();
};
#endif