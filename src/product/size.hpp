// The header file of size
#ifndef size_hpp
#define size_hpp
#include <Arduino.h>
#include "sensor.hpp"
#include "component.hpp"

class size : public sensor, public component {
private:
  void start_measuring();
  void stop_measuring();
  unsigned long _current_time;
  unsigned long _break_time;
  int _newest_size;
public:
  size(uint8_t);
  unsigned int get_size();
  brick check_measuring();
  void stop_measuring_temporarily();
  void continue_measuring();
  virtual brick get_brick_data();
};

#endif
