//! main.c
// 
// 
#include <Arduino.h>
#include "Arduino_H7_Video.h"
#include "Arduino_GigaDisplayTouch.h"
#include "lvgl.h"
#include "lv_conf.h"
#include "demos/lv_demos.h"



Arduino_H7_Video          Display(800, 480, GigaDisplayShield);
Arduino_GigaDisplayTouch  TouchDetector;

// lv_conf.h should be configured to enable the demo you want to run. See lv_conf.h for more details.
// If you use Arudino Giga board with Giga Display Shield in platformio, the appropriate lv_conf.h takes place here:
// /home/user/.platformio/packages/framework-arduino-mbed/libraries/Arduino_H7_Video/src/lv_conf_9.h
// If you faces a white diplay after uploading the code, please check if the correct lv_conf.h is used and configured properly. 
// There are options for enabling different demos in lv_conf.h, and you can enable the one (or more) you want to run by setting the corresponding macro to 1. 
// for example, if you want to run the widgets demo, set `LV_USE_DEMO_WIDGETS` to 1.
//
// You can change the demo by modifying the `demo_name` array below and re-uploading the code.
//
// I am sure you will see problems during the compilation. It could be a missing font. That is also a missig 1 after a font definition in lv_conf.h. 
// For example, if the compliler missed the `lv_font_montserrat_14`, make sure to set `LV_USE_FONT_MONTSERRAT_14` to 1 in lv_conf.h.
//
// Available demos:
//  widgets music stress keypad_encoder vector_graphic_buffered vector_graphic_not_buffered benchmark
// 
// Tested demos were: widgets and bechmark. (Benchmark requires more options to be enabled in lv_conf.h, please check the options in lv_conf.h if you want to run benchmark demo)
static const char * demo_name[] = {"stress"};

void setup( )
{
  Serial.begin(115200);

  lv_init();

  if (Display.begin() != 0) {
    while (1);
  }
  TouchDetector.begin();

  if (!lv_demos_create( (char **)demo_name, 1 )) {
    lv_demos_show_help();
  }
}

void loop( )
{
  uint32_t delay = lv_timer_handler();
    if (delay < 1) delay = 1; /*delay for at least 1 ms*/
    else if(delay == LV_NO_TIMER_READY) delay = LV_DEF_REFR_PERIOD; /*handle LV_NO_TIMER_READY. Another option is to `sleep` for longer*/
    delayMicroseconds(delay * 1000);
}
