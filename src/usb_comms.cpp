#include "usb_comms.h"


void USB_Comms::get_layouts() {

    if (Serial.available() > 0){

        incoming_raw_layouts = Serial.readString();

        if (comms_message == incoming_raw_layouts){
            Serial.println(hub_esp_now.cats_set);
        }
        else{

            layouts_manager.split_layouts_package(incoming_raw_layouts);

        }
    }
}  



// // Preferences preferences;
USB_Comms usb_comms;