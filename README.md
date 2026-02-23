# lvgl_arduino_giga

This project has been tested in PlatformIO on a Linux environment.

Please note: the symlink in /src will not work on NTFS or FAT filesystems (copy demos from library in this case).

Although the project folder may appear empty, opening it in a PlatformIO environment will load all the source code. 🙂

## directions in main.cpp

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

