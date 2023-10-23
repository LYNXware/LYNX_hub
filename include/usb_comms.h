#ifndef USB_COMMS_H
#define USB_COMMS_H

#include <Arduino.h>

#include "wireless_comms.h"
#include "layouts_manager.h"



class USB_Comms {

public:

    void get_layouts();


private:

    String incoming_raw_layouts = "empty";
    String comms_message = "are_you_a_cat";

};


extern USB_Comms usb_comms;

#endif