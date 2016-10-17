// The header file of sensor
#ifndef sensor_hpp
#define sensor_hpp
#include "component.hpp"

struct sensor : public component {
  int pin;
};

#endif
