/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini
*/
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <WiFi.h>
#include <HTTPClient.h>


//For Internal Temperature Sensor
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
#ifndef __cplusplus
uint8_t temprature_sens_read();
#endif

//For uBeac and WiFi
const char* url = "http://smarok123.hub.ubeac.io/mygateway";
const char* ssid = "Momentaj-2";
const char* password =  "9123100292";

//For Bluetooth
int scanTime = 5; //In seconds
BLEScan* pBLEScan;

void setup() {
  Serial.begin(115200);

  ble_setup();
  //wifi_setup();
}

void loop() {

  ble_find();

  // Convert raw temperature in F to Celsius degrees
  float value = (temprature_sens_read() - 32) / 1.8;
  //String my_str = "Temperature: ";
  
  //send_data(value, my_str);
  delay(1000);
}
