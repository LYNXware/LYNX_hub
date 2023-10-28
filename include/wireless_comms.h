#ifndef WIRELESS_COMMS_H
#define WIRELESS_COMMS_H

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

#include "config.h"
#include "events.h"
// #include "layer_control.h"



class HubEspNow {

public:

    // turn on wifi and CatNow
    void initialize();

    //search for available cats
    void scan_for_cats();

    // byte available_cats_count = 0;
    String available_cats[MAX_DEVICES];
    String cats_set = "LYNXhub";

    void send_switch_layer(uint8_t layer);

    // static void set_battery_level(uint8_t battery_value);
    static uint8_t battery_level;
    


    // const int StringLength = 10;
    // String* available_cats  = new String[StringLength];
    // String* cats_variants;
    
    // void event_triger(String event);

    // void scan_for_slave();

    
private:

    // wife credentials
    #define CHANNEL 1
    String wifi_hub = "LYNXhub_"; 
    String wifi_cat = "LYNX_";
    String HUB_DEVICE_DELIMITER = ":";


    uint8_t availibel_cats_index;
    uint8_t available_cats_count;
    uint8_t max_cats = 2;

    esp_now_peer_info_t peerList[2];




    // slave mac address
    esp_now_peer_info_t peerInfo;
    // peer is available
    bool peer_available = false;

    // esp-now callbacks
    static void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);
    static void OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len); 

};

//instance of the class 
extern HubEspNow hub_esp_now;

#endif