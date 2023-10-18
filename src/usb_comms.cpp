#include "usb_comms.h"


void USB_Comms::get_layouts() {

    if (Serial.available() > 0){

        incoming_raw_layouts = Serial.readString();

        if (comms_message == incoming_raw_layouts){
            Serial.println(catnow.cats_set);
        }
        else{

            layouts_manager.split_layouts_package(incoming_raw_layouts);

            // split_raw_layouts();
            // preferences.begin("myPrefs", false);
            // preferences.clear();
            // preferences.putString("layout", incoming_raw_layouts);
            // preferences.end();
        }
    }
}  








// void USB_Comms::split_raw_layouts(){
    
//     inBL = incoming_raw_layouts.length();
//     b = 0;
//     f = 0;
//     event_index = 0;
//     layer = 0;

//     for(b; b < inBL; b++) {
    
//         if (incoming_raw_layouts[b] == delimiter_layout){
//             layer++;
//             event_index = 0;
//             f++;
//         }
//         if (incoming_raw_layouts[b] == delimiter){
//             events_array[layer][event_index] = incoming_raw_layouts.substring(f,b);
//             f = b+1;
//             event_index++;    
//         }   
//     }
//     adjust_mouse_speed();      
// }



// void USB_Comms::adjust_mouse_speed(){
//     m = 0;
//     for (m; m < 4; m++){
//     mouse_factor[m][0] = pow((float(events_array[m][44][0])/100), 2);  // horizontal mouse factor
//     mouse_factor[m][1] = pow((float(events_array[m][45][0])/100), 2);  // vertical mouse factor
//     }
// }



// void USB_Comms::load_layouts(){
//     // preferences.begin("myPrefs", false);
//     // incoming_raw_layouts = preferences.getString("layout", "empty");
//     // preferences.end();
//     split_raw_layouts();
// }

// // Preferences preferences;
USB_Comms usb_comms;