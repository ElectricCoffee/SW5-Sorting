// The header file of pusher
#ifndef pusher_hpp
#define pusher_hpp
#include <Arduino.h>
#include "brick_detector.hpp"
#include "interrupter.hpp"

class pusher : public component, public brick_detector {
  public:
    interrupter *photo_sensor; //it needs one, but maybe could be an input var in detect brick instead? just need pin number
    virtual void open() = 0;
    virtual void close() = 0;
};
#endif
