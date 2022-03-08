#include "common.h"

WiFiServer server(23);
extern WiFiClient client;

void taskService(void* parameter)
{   
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid.c_str(), password);
    IPAddress IP = WiFi.softAPIP(); 
    server.begin();
    server.setNoDelay(true);  
    msg.Id = "Service";
    while(1){
        if (server.hasClient()) {
           client = server.available();
        }
        
        if (client.connected()) {
            while (client.available()) {
                msg.Rx ++;
                char ch = client.read();
                Serial.write(ch);
                Serial2.write(ch);
            }
        }

        
        if (Serial.available()) {
            size_t len = Serial.available();
            uint8_t sbuf[len];
            msg.Tx += len;
            Serial.readBytes(sbuf, len);
            if (client.connected()) {
                client.write(sbuf, len);
            }
        } 
        if (Serial2.available()) {
            size_t len = Serial2.available();
            uint8_t sbuf[len];
            msg.Tx += len;
            Serial2.readBytes(sbuf, len);
              if (client.connected()) {
                  client.write(sbuf, len);
              }
        }       
    }
}
