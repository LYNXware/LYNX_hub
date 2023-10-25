#include "usb_comms.h"


void USB_Comms::get_layouts() {

    if (Serial.available() > 0){

        incoming_raw_layouts = Serial.readString();

        if (comms_message == incoming_raw_layouts){
            Serial.println(hub_esp_now.cats_set);
        }
        else{

            layouts_manager.split_events_package(incoming_raw_layouts);
            layouts_manager.save_events_package(incoming_raw_layouts);
            transmision = "transmision complete";

        }
    }
}  



// // Preferences preferences;
USB_Comms usb_comms;