// The header file of sensor
#ifndef sensor_hpp
#define sensor_hpp
#include <Arduino.h>
#include "component.hpp"

struct sensor : public component {
  sensor(uint8_t); //for initialising it

  //bool operator==(const sensor) const override;
};
#endif
