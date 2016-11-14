// The header file of sensor
#ifndef sensor_hpp
#define sensor_hpp
#include <Arduino.h>
#include "brick_detector.hpp"
#include "component.hpp"
#include "brick.hpp"

struct sensor : public component, public brick_detector {
  //sensor(uint8_t); //for initialising it
  virtual brick get_brick_data() = 0;
};
#endif
