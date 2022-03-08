#include <Arduino.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <ArduinoJson.h> 

#include "oled_display.h"

extern String ssid;
extern const char* password; 

void taskService(void* parameter);
void taskClient(void* parameter);

 
