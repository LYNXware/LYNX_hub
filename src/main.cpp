/*
Version: 0.3.0
Date: 01.09.2023
Developer: Stanislaw Kirpicnikow (Ape Devil)
Remark: 
*/

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


  layouts_manager.load_events_package();


  hub_esp_now.initialize();
  // catnow.scan_for_cats();

  Serial.begin(115200);
  Keyboard.begin();
  Mouse.begin();

}





void loop() {

  usb_comms.get_layouts();


  bRead = digitalRead(pI);
  if (bRead == 0) {

    hub_esp_now.scan_for_cats();

    Serial.println(hub_esp_now.cats_set);

    // Serial.println(usb_comms.transmision);

    Serial.println(layouts_manager.layouts_package);
    Serial.println(layouts_manager.events_bank[0][0][0]);
    Serial.println(layouts_manager.events_bank[1][0][0]);

  }


}

