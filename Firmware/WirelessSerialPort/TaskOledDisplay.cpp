#include "common.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0 , /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 13, /* data=*/ 15); 
 
struct Show_Msg msg;

void taskDisplay(void* parameter)
{   
    msg.Ip = "未连接";
    msg.Id = "未连接";
    u8g2.begin();
    u8g2.enableUTF8Print();
    u8g2.clearBuffer();
    while(1){
        vTaskDelay(100);
        msg.Ip = WiFi.localIP().toString(); 
        if(msg.Id == "Service") 
            msg.Ip = "192.168.4.1"; 
        oledListeningDisplay();
    }
}

void oledListeningDisplay(void)
{
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_wqy14_t_gb2312);
    u8g2.setCursor(10, 15);
    u8g2.print(msg.Id);
    u8g2.setCursor(10, 30);
    u8g2.print("IP: ");
    u8g2.print(msg.Ip);
    u8g2.setCursor(10, 45);
    u8g2.print("Rx: ");
    u8g2.print(msg.Rx); u8g2.print(" byte");
    u8g2.setCursor(10, 60);
    u8g2.print("Tx: ");
    u8g2.print(msg.Tx); u8g2.print(" byte");
    u8g2.sendBuffer(); 
}
