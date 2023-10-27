#include "buttons.h"

Buttons buttons;

void Buttons::initialize(){

    pinMode(LB_outputPin,OUTPUT);
    digitalWrite(LB_outputPin,LOW);  

    pinMode(LB_inputPin,INPUT_PULLUP);

    pinMode(RB_outputPin,OUTPUT);
    digitalWrite(RB_outputPin,LOW);

    pinMode(RB_inputPin,INPUT_PULLUP);    

}

void Buttons::read(){

    // Serial.println("read");

    if (digitalRead(LB_inputPin) == LOW){
        Serial.println("LB");
        // neopixelled.green();
        // neopixelled.yellow();
        neopixelled.cyan();

    }
    else if (digitalRead(RB_inputPin) == LOW){
        Serial.println("RB");
        // neopixelled.reed();
        // neopixelled.purple();
        neopixelled.white();
    }

}