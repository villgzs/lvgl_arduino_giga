//! main.c
#include <Arduino.h>
#include "Arduino_H7_Video.h"
#include "Arduino_GigaDisplayTouch.h"
#include "lvgl.h"
#include "lv_conf.h"
#include "../.pio/libdeps/lvgldemos/lvgl/demos/lv_demos.h"


Arduino_H7_Video          Display(800, 480, GigaDisplayShield);
Arduino_GigaDisplayTouch  TouchDetector;

static const char * demo_name[] = {"widgets"};

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
