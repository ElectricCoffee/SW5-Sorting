// The header file of sensor
#ifndef sensor_hpp
#define sensor_hpp
#include <Arduino.h>
#include "brick_detector.hpp"
#include "component.hpp"
#include "brick.hpp"

struct sensor : public component, public brick_detector {
  // setting a function = 0, makes it a "pure virtual function"
  // don't touch it.
  sensor(uint8_t pin) : component(pin) {}
  virtual brick        get_brick_data()  = 0;
  virtual unsigned int check_measuring() = 0;
  virtual unsigned int start_measuring() = 0;
  virtual unsigned int stop_measuring()  = 0;
};
#endif
