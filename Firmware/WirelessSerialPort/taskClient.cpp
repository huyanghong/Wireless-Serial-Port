#include "common.h"

WiFiClient client;
const char* Server = "192.168.4.1";
const int Port = 23;

void taskClient(void* parameter)
{   
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), password);
    Serial.println("\nConnecting to "); 
    Serial.println(ssid.c_str());
    msg.Id = "Client";
    while(1){
        if (WiFi.status() != WL_CONNECTED) {
            WiFi.begin(ssid.c_str(), password);
            Serial.print("."); 
            delay(500);
        }else{
            client.connect(Server, Port);
        }
        
        while(client.connected()){ 
            while(client.available()) {
                msg.Rx ++;
                char ch = client.read();
                Serial.write(ch);
                Serial2.write(ch);
            }
            if (Serial.available()) {
                size_t len = Serial.available();
                msg.Tx += len;
                uint8_t sbuf[len];
                Serial.readBytes(sbuf, len);
                client.write(sbuf, len);
            }
            if (Serial2.available()) {
                size_t len = Serial2.available();
                msg.Tx += len;
                uint8_t sbuf[len];
                Serial2.readBytes(sbuf, len);
                client.write(sbuf, len);
            }
        }        
    }
}
