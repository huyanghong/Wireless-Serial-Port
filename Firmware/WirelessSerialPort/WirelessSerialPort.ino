#include "common.h"

#define SERVICE 0
#define CLIENT  1
uint8_t  service_or_client = SERVICE;

String ssid = "net-Serial";
const char* password = "12345678";  

void setup(){
    Serial.begin(115200);
    Serial2.begin(115200);
    vTaskDelay(1000);
  
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i) {
        if(!strcmp(WiFi.SSID(i).c_str(), ssid.c_str())){
            service_or_client = CLIENT;
            break;
        }
    }
    

        
  xTaskCreatePinnedToCore(taskDisplay,          /* Task function. */
              "taskDisplay",        /* String with name of task. */
              10000,            /* Stack size in bytes. */
              NULL,             /* Parameter passed as input of the task */
              1,                /* Priority of the task. */
              NULL, 0);            /* Task handle. */      

    if(service_or_client == CLIENT){
        xTaskCreatePinnedToCore(taskClient,          /* Task function. */
                    "taskClient",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL, 1);            /* Task handle. */     
    }else if(service_or_client == SERVICE){
        xTaskCreatePinnedToCore(taskService,          /* Task function. */
                    "taskService",        /* String with name of task. */
                    10000,            /* Stack size in bytes. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    NULL, 1);            /* Task handle. */    
    } 
}

void loop() {        

}
