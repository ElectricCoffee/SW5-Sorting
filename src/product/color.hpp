// The header file of color
#ifndef color_hpp
#define color_hpp
#include <Arduino.h>
#include <SparkFunISL29125.h>
#include <Wire.h>
#include "sensor.hpp"
#include "brick.hpp"
#include "interrupter.hpp"

#define RESET_VALUE 0
#define COLOR_THRESHOLD 0x00076c
#define PHOTO_THRESHOLD_COLOR 500

class color : public sensor, public component {
private:
  // variables
  unsigned int _newest_color;
  unsigned int _current_time;
  SFE_ISL29125 &_RGB_sensor_ptr;
  // methods
  void add_color(uint8_t);
  bool _flipping_pin_read = true;
public:
  unsigned int delay_between_photo_color = 5;
  // variables
  interrupter *photo_sensor_ptr;
  // methods
  color(uint8_t, SFE_ISL29125&);
  ~color();
  unsigned int get_color();
  // inherited interface methods
  brick get_brick_data();
  bool detect_brick();
  bool init();
};
#endif
