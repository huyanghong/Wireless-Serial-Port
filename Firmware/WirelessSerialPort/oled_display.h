#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Wire.h>
#include <U8g2lib.h>

struct Show_Msg{
  int32_t Rx;
  int32_t Tx;
  String  Ip;
  String  Id;
  };
  
extern struct Show_Msg msg;

void taskDisplay(void* parameter);
void oledListeningDisplay(void);

#endif
