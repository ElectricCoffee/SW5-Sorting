// The header file of interrupter
#ifndef interrupter_hpp
#define interrupter_hpp
#include <Arduino.h>
#include "component.hpp"
#include "brick_detector.hpp"

struct interrupter : public component, public brick_detector {
  interrupter(uint8_t);
  bool detect_brick();
};

#endif
