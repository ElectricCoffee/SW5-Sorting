// The header file of color
#ifndef color_hpp
#define color_hpp
#include <Arduino.h>
#include "sensor.hpp"

struct color : public sensor {
  int get_color();
};

#endif
