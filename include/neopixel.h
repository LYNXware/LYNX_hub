#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN    48
#define LED_COUNT 1

// creating an instance of the Adafruit_NeoPixel class
extern Adafruit_NeoPixel strip_layer_switch;


class NeopixelLED {
public:

    void initialize();
    void off();

    void reed();
    void green();
    void blue();
    void yellow();
    void purple();
    void cyan();
    void white();



private:

    uint8_t color_on = 50;
    
};

// creating an instance of the NeopixelLED class
extern NeopixelLED neopixelled;

#endif