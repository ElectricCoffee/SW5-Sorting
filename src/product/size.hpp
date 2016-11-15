// The header file of size
#ifndef size_hpp
#define size_hpp
#include <Arduino.h>
#include "sensor.hpp"

class size : private sensor {
private:
  void start_measuring();
  void stop_measuring();
  unsigned long _current_time;
  unsigned long _break_time;
  unsigned int _newest_size;
public:
  unsigned int get_size();
  void check_measuring();
  void stop_measuring_temporarily();
  void continue_measuring();
};

#endif
