#ifndef LAYOUTS_MANAGER_H
#define LAYOUTS_MANAGER_H

#include <Arduino.h>

#include "config.h"


#include <Preferences.h>
extern Preferences preferences;



class Layouts_Manager {

    public:

        String incoming_layouts = "empty";

        void split_into_devices();




        // events_array[layer][event];
        String events_array[4][46];
        // mouse_factor[layer][axis];
        float mouse_factor[4][2];

        // this functlon is checküng if the LYNXapp is sending the layouts via SerialComms
        // if yes, it will save the layouts in the preferences (espressif library)
        void get_layouts(String variant);

        // this function is loading the layouts from the preferences (espressif library)
        void load_layouts();
        



    private:

        const char delimiter_device = 0x01;

        String device_layouts[MAX_DEVICES];

        byte device_index = 0;
        int start = 0;



        // String variant = config.variant;

        String incoming_raw_layouts = "empty";

        String comms_message = "are_you_a_cat";

        int inBL;
        int b;
        int f;

        byte layer;
        byte event_index;

        const char delimiter = 0xff;
        const char delimiter_layout = 0xfe;
        const char last_byte = 0xfd;

        int m;


        // this function is splitting the incoming raw layouts into the events_array
        void split_raw_layouts();
        
        // this function is calculating the mouse speed factor
        void adjust_mouse_speed();

};


extern Layouts_Manager layouts_manager;

#endif