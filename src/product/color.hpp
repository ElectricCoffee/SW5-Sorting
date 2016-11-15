// The header file of color
#ifndef color_hpp
#define color_hpp
#include <Arduino.h>
#include "sensor.hpp"
#include <src/SparkFunISL29125.h>
#include <Wire.h>

class color : public sensor {
private:
  unsigned int start_measuring();
  void stop_measuring();
  unsigned long current_time;
  unsigned int newest_color;
public:
  unsigned int get_color();
  void check_measuring();
};

#endif
