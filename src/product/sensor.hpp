// The header file of sensor
#ifndef sensor_hpp
#define sensor_hpp
#include <Arduino.h>
#include "component.hpp"

struct sensor : public component {
  uint8_t pin;
  sensor(uint8_t); //for initialising it
  virtual void check_measuring();
protected:
  virtual void start_measuring();
  virtual void stop_measuring();
};
#endif
