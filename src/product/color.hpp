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
#define COLOR_THRESHOLD 0x060907

class color : public sensor, public component {
private:
  // variables
  unsigned int _newest_color;
  SFE_ISL29125 *_RGB_sensor_ptr;
  // methods
  void add_color(uint8_t);
public:
  // variables
  interrupter *photo_sensor_ptr;
  // methods
  color(uint8_t);
  ~color();
  unsigned int get_color();
  // interface methods
  brick get_brick_data();
  bool detect_brick();
};
#endif
