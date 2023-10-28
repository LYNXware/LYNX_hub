#include "wireless_comms.h"

//instance of the class
HubEspNow hub_esp_now;



void HubEspNow::initialize() {

    // Initialize Wi-Fi: simultanious (Station Mode) and WIFI_AP (Access Point Mode)
    WiFi.mode(WIFI_AP_STA);

    // set up an Access Point 
    WiFi.softAP(wifi_hub + config.VERSION, "Slave_1_Password", CHANNEL, 0);

    // Initialize ESP-NOW
    esp_now_init();

    // Register callback functions
    esp_now_register_send_cb(OnDataSent);
    esp_now_register_recv_cb(OnDataReceived);
}






void HubEspNow::scan_for_cats(){
      
    // Scan only on one channel for slaves
    int8_t scanResults = WiFi.scanNetworks(false, false, false, 300, CHANNEL);
    
    // reset mac address
    // memset(&peerInfo, 0, sizeof(peerInfo));
    for (uint8_t i = 0; i < max_cats; ++i) {
        memset(&peerList[i], 0, sizeof(peerList[i]));
    }

    availibel_cats_index = 0;

    cats_set = "LYNXhub";



    if (scanResults == 0) {
        Serial.println("No ESP32 devices nearby found");
    } else {
        Serial.print("Found ");
        Serial.print(scanResults);
        Serial.println(" device(s)");

        for (int i = 0; i < scanResults; ++i) {

            // Print SSID and RSSI for each device found
            String SSID = WiFi.SSID(i);
            int32_t RSSI = WiFi.RSSI(i);
            String BSSIDstr = WiFi.BSSIDstr(i);


            Serial.printf("%d: %s (%d) %s\n", i + 1, SSID.c_str(), RSSI, BSSIDstr.c_str());
            delay(10);

            // Check if the current device starts with `Slave`
            if (SSID.indexOf(wifi_cat) == 0) {


                available_cats[available_cats_count] = SSID;
                // available_cats_count++;

                cats_set = cats_set + HUB_DEVICE_DELIMITER + SSID;
            
                // SSID of interest
                Serial.println("Found a Slave.");
                // Get BSSID => Mac Address of the Slave
                int mac[6];

                // if ( 6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x%c", 
                //     &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5])) {
                //     for (int ii = 0; ii < 6; ++ii) {
                //         peerInfo.peer_addr[ii] = (uint8_t) mac[ii];
                //     }
                // }
                // peerInfo.channel = CHANNEL; // pick a channel
                // peerInfo.encrypt = false; // no encryption
                // Add peer        
                // esp_now_add_peer(&peerInfo);

                if ( 6 == sscanf(BSSIDstr.c_str(), "%x:%x:%x:%x:%x:%x%c", 
                    &mac[0], &mac[1], &mac[2], &mac[3], &mac[4], &mac[5])) {
                    for (int ii = 0; ii < 6; ++ii) {
                        peerList[availibel_cats_index].peer_addr[ii] = (uint8_t) mac[ii];
                    }
                }
                peerList[availibel_cats_index].channel = CHANNEL;
                peerList[availibel_cats_index].encrypt = false;
                

                esp_now_add_peer(&peerList[availibel_cats_index]);

                available_cats_count = availibel_cats_index + 1;
                availibel_cats_index++;
                
            }
        }
    }
    // clean up ram
    WiFi.scanDelete();
}



// void HubEspNow::scan_for_cats(){
      
//     // Scan only on one channel for slaves
//     int8_t scanResults = WiFi.scanNetworks(false, false, false, 300, CHANNEL);

//     cats_set = "LYNXhub";

//     for (int i = 0; i < scanResults; ++i) {

//         String SSID = WiFi.SSID(i);
        
//         if (SSID.indexOf(wifi_cat) == 0) {

//             available_cats[available_cats_count] = SSID;
//             available_cats_count++;

//             cats_set = cats_set + HUB_DEVICE_DELIMITER + SSID;
//         }

//     }
//     // clean up ram
//     WiFi.scanDelete();
// }




void HubEspNow::OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len) {

    // Serial.println("OnDataReceived");
    // Serial.println(data[0]);
    // Serial.println(data[1]);

    if (data[0] == 'L')
    {
        event.trigger_key(0, data[1], data[2]);
        Serial.println(data[1]);
    }
    else if (data[0] == 'R')
    {
        event.trigger_key(1, data[1], data[2]);
    }
    else if (data[0] == 'M')
    {
        event.move_mouse(data[1], data[2]);
        Serial.print(data[1]);
        Serial.print(" ");
        Serial.println(data[2]);
        // Serial.print(map(data[1], 0, 255, 0, 4095));
        // Serial.print(" ");
        // Serial.println(map(data[2], 0, 255, 0, 4095));

    }    
    else if (data[0]=='B'){
        // set_battery_level(data[1]);
        // battery_level = data[1];
        // Serial.print("battery: ");
        // Serial.println(data[1]);
    }
    


}


// void HubEspNow::set_battery_level(uint8_t battery_value){
//     battery_level = battery_value;
//     Serial.print("battery: ");
//     Serial.println(battery_value);
// }




// Callback function for sending data
void HubEspNow::OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status) {
//   Serial.println("OnDataSent");
  // Handle send status
}






void HubEspNow::send_switch_layer(uint8_t layer) {

    Serial.print("send_switch_layer  ");
    Serial.println(layer);

    // // Check if the peer exists
    // if (peer_available == false) {
    //     Serial.println("No peer available");
    //     // scan_for_slave();
    // }

    uint8_t data[] = {'H', 'L', layer};

    for (uint8_t i = 0; i < available_cats_count; ++i) {
        esp_now_send(peerList[i].peer_addr, data, sizeof(data));
    }

    // Send the data using ESP-NOW
    // esp_now_send(peerInfo.peer_addr, data, sizeof(data));
}












    // if (data_len == 4) {
    //     if (data[0] == 'c' && data[1] == 'a' && data[2] == 't') {
    //         uint8_t dynamicValue = data[3];

    //         Serial.print("Received data: ");
    //         Serial.println(dynamicValue);

    //         Serial.print(mac_addr[0], HEX);
    //         Serial.print("-");
    //         Serial.print(mac_addr[1], HEX);
    //         Serial.print("-");
    //         Serial.print(mac_addr[2], HEX);
    //         Serial.print("-");
    //         Serial.print(mac_addr[3], HEX);
    //         Serial.print("-");
    //         Serial.print(mac_addr[4], HEX);
    //         Serial.print("-");
    //         Serial.println(mac_addr[5], HEX);
            // layer_control.received_layer_switch(dynamicValue);
        // }
    // }