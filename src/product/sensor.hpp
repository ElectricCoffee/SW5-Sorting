// The header file of sensor
#ifndef sensor_hpp
#define sensor_hpp
#include <Arduino.h>
#include "component.hpp"
#include "brick_data_getter.hpp"

struct sensor : public component {
  sensor(uint8_t); //for initialising it
  virtual brick get_brick_data();
};
#endif
