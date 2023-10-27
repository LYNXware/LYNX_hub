#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include "neopixel.h"

class Buttons {
public:

    byte LB_outputPin = 16;
    byte LB_inputPin = 7;

    byte RB_outputPin = 9;
    byte RB_inputPin = 11;

    void initialize();

    void read();

private:

};

extern Buttons buttons;


#endif
