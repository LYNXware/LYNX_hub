#include <Arduino.h>

#include "wireless_comms.h"
#include "usb_comms.h"
#include "layouts_manager.h"


//test button
#define pI 46
int bRead;





void setup() {
    //test buton
  pinMode(pI, INPUT_PULLUP);

  catnow.initialize();
  // catnow.scan_for_cats();

  Serial.begin(115200);
  Keyboard.begin();
  Mouse.begin();

}





void loop() {

  usb_comms.get_layouts();


  bRead = digitalRead(pI);
  if (bRead == 0) {

    catnow.scan_for_cats();
    Serial.println(catnow.cats_set);

    Serial.println(layouts_manager.layouts_package);
    Serial.println(layouts_manager.events_bank[0][0][0]);
    Serial.println(layouts_manager.events_bank[1][0][0]);


    // Serial.println(layouts_manager.layouts_package);
    // Serial.println(layouts_manager.layouts_package[0]);
    // Serial.println(layouts_manager.layouts_package[1]);
    // Serial.println(layouts_manager.layouts_package[2]);
    // Serial.println(layouts_manager.layouts_package[3]);

    // Serial.println(layouts_manager.left_cat_layout[0][0]);
    // Serial.println(layouts_manager.left_cat_layout[0][1]);
    // Serial.println(layouts_manager.left_cat_layout[1][0]);
    // Serial.println(layouts_manager.left_cat_layout[1][1]);

    // Serial.println(layouts_manager.right_cat_layout[0][0]);
    // Serial.println(layouts_manager.right_cat_layout[0][1]);
    // Serial.println(layouts_manager.right_cat_layout[1][0]);
    // Serial.println(layouts_manager.right_cat_layout[1][1]);
    // 
    
    // Serial.println("Hello World");
    // delay(1000);

    // catnow.test();
    // catnow.scan_for_cats();
    // // catnow.send_switch_layer(66);
    // Serial.println(catnow.available_cats[0]);
    // Serial.println(sizeof(catnow.available_cats));
  }

  



}

