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
  catnow.scan_for_cats();

}

void loop() {

  usb_comms.get_layouts();


  bRead = digitalRead(pI);
  if (bRead == 0) {
  
  Serial.println(layouts_manager.incoming_layouts);
  Serial.println(catnow.cats_set);
  Serial.println("Hello World");
  // delay(1000);

    // catnow.test();
    // catnow.scan_for_cats();
    // // catnow.send_switch_layer(66);
    // Serial.println(catnow.available_cats[0]);
    // Serial.println(sizeof(catnow.available_cats));
  }

  



}

