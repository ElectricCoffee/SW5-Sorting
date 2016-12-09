// The header file of component
#ifndef component_hpp
#define component_hpp
#include <Arduino.h>

struct component {
  uint8_t pin;
  component(uint8_t);

  bool operator ==(const component&) const;
  bool operator !=(const component&) const;

  virtual void add_brick(bool) = 0;
  virtual void act_on_brick() = 0;
};

#endif
