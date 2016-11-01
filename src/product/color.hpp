// The header file of color
#ifndef color_hpp
#define color_hpp
#include <Arduino.h>
#include "sensor.hpp"

class color : public sensor {
private:
  void start_measuring();
  void stop_measuring();
  unsigned long current_time;
  unsigned int newest_color;
public:
  int get_color();
  void check_measuring();
};

#endif
