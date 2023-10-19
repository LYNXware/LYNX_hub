#ifndef EVENTS_H
#define EVENTS_H

#include <Arduino.h>

#include "USBHIDKeyboard.h"
#include "USBHIDMouse.h"

#include "layouts_manager.h"
#include "layer_control.h"



// this class is for trinigering the keyboard and mouse events
class Event {

public:

    void trigger_key(uint8_t device_side,  uint8_t event);

    void move_mouse(int8_t x_value, int8_t y_value);




private:

    bool trigger_state[2][46];




    String passing_event;
    char event_component;

    void actuate(String event);
    void deactuate(String event);





    byte pel;
    byte k;

    const char cat_function = 0xfa;
    const char mouse_function = 0xf0;

    void keyboard_press(String passingEvent);
    void keyboard_release(String passingEvent);

    void mouse_press(char m);
    void mouse_release(char m);    

};


extern USBHIDKeyboard Keyboard;
extern USBHIDMouse Mouse;

extern Event event;

#endif