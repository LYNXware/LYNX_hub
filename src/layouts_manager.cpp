#include "layouts_manager.h"





void Layouts_Manager::split_layouts_package(String events_package){
    
    // left_cat_layout = place_holder;

    // int sourceArray[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int destinationArray[3][3];

    // memcpy(left_cat_layout, place_holder, sizeof(place_holder));

    layouts_package = events_package;


    // bool left_cat = false;
    // bool right_cat = false;

    int package_length = events_package.length();


    for (int i = 0; i < package_length; i++) {

        if (events_package.charAt(i) == LEFT_CAT){
            // left_cat = true;
            // right_cat = false;
            device_side = 0;
            layer = 0;
            event_index = 0;
            front_of_events = i+1;
        }
        if (events_package.charAt(i) == RIGHT_CAT){
            // left_cat = false;
            // right_cat = true;
            device_side = 1;
            layer = 0;
            event_index = 0;
            front_of_events = i+1;
        }

    
        if (events_package[i] == DELIMITER_LAYOUT){
            layer++;
            event_index = 0;
            front_of_events = i+1;
        }

        if (events_package[i] == DELIMITER_EVENT){

            events_bank[device_side][layer][event_index] = events_package.substring(front_of_events,i);

            front_of_events = i+1;
            event_index++;  
            // if (left_cat){
            //     left_cat_layout[layer][event_index] = events_package.substring(front_of_events,i);
            // }

            // if (right_cat){
            //     right_cat_layout[layer][event_index] = events_package.substring(front_of_events,i);
            // }

            // events_array[layer][event_index] = events_package.substring(f,b);
  
        }   
    }
        // if (layouts_package.charAt(i) == LEFT_CAT){
        //     device_layouts[device_index] = incoming_layouts.substring(start,i);
        //     start = i+1;
        //     device_index++;
            
        // }
}












void Layouts_Manager::get_layouts(String variant) {

    if (Serial.available() > 0){

        incoming_raw_layouts = Serial.readString();

        if (comms_message == incoming_raw_layouts){
            Serial.println(variant);
        }
        else{
            split_raw_layouts();
            preferences.begin("myPrefs", false);
            preferences.clear();
            preferences.putString("layout", incoming_raw_layouts);
            preferences.end();
        }
    }
}  


void Layouts_Manager::split_raw_layouts(){
    
    inBL = incoming_raw_layouts.length();
    b = 0;
    f = 0;
    event_index = 0;
    layer = 0;

    for(b; b < inBL; b++) {
    
        if (incoming_raw_layouts[b] == delimiter_layout){
            layer++;
            event_index = 0;
            f++;
        }
        if (incoming_raw_layouts[b] == delimiter){
            events_array[layer][event_index] = incoming_raw_layouts.substring(f,b);
            f = b+1;
            event_index++;    
        }   
    }
    adjust_mouse_speed();      
}



void Layouts_Manager::adjust_mouse_speed(){
    m = 0;
    for (m; m < 4; m++){
    mouse_factor[m][0] = pow((float(events_array[m][44][0])/100), 2);  // horizontal mouse factor
    mouse_factor[m][1] = pow((float(events_array[m][45][0])/100), 2);  // vertical mouse factor
    }
}



void Layouts_Manager::load_layouts(){
    preferences.begin("myPrefs", false);
    incoming_raw_layouts = preferences.getString("layout", "empty");
    preferences.end();
    split_raw_layouts();
}

Preferences preferences;
Layouts_Manager layouts_manager;