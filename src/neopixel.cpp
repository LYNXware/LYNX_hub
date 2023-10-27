#include "neopixel.h"

// creating led strip object
Adafruit_NeoPixel strip_layer_switch(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// creating an instance of the NeopixelLED class
NeopixelLED neopixelled;



void NeopixelLED::initialize(){

    // initializing the led strip
    strip_layer_switch.begin();
    strip_layer_switch.setPixelColor(0, 0, 0, color_on); //blue
    strip_layer_switch.show(); 

}

void NeopixelLED::off(){
    strip_layer_switch.setPixelColor(0, 0, 0, 0); //off
    strip_layer_switch.show();
}


void NeopixelLED::reed(){
    strip_layer_switch.setPixelColor(0, color_on, 0, 0); //red
    strip_layer_switch.show();
}

void NeopixelLED::green(){
    strip_layer_switch.setPixelColor(0, 0, color_on, 0); //green
    strip_layer_switch.show();
}

void NeopixelLED::blue(){
    strip_layer_switch.setPixelColor(0, 0, 0, color_on); //blue
    strip_layer_switch.show();
}

void NeopixelLED::yellow(){
    strip_layer_switch.setPixelColor(0, color_on, color_on, 0); //yellow
    strip_layer_switch.show();
}

void NeopixelLED::purple(){
    strip_layer_switch.setPixelColor(0, color_on, 0, color_on); //purple
    strip_layer_switch.show();
}

void NeopixelLED::cyan(){
    strip_layer_switch.setPixelColor(0, 0, color_on, color_on);
    strip_layer_switch.show();
}

void NeopixelLED::white(){
    strip_layer_switch.setPixelColor(0, color_on, color_on, color_on); //white
    strip_layer_switch.show();
}






