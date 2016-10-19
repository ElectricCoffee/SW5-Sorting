// The header file of sensor
#ifndef sensor_hpp
#define sensor_hpp
#include "component.hpp"

struct sensor {
  char pin;
  sensor(char); //for initialising it
};
#endif
