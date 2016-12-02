// The header file of size
#ifndef size_hpp
#define size_hpp
#include <Arduino.h>
#include "sensor.hpp"
#include "component.hpp"
#include "motor.hpp"

class size : public sensor, public component {
private:
  unsigned long _current_time;
  unsigned long _break_time;
  unsigned int _newest_size;
  const motor &_motor;

  void start_measuring();
  void stop_measuring();
public:
  size(uint8_t, const motor&);
  unsigned int get_size();
  brick check_measuring();
  void stop_measuring_temporarily();
  void continue_measuring();
  virtual brick get_brick_data();
};

#endif
