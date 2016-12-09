// The header file of pusher
#ifndef pusher_hpp
#define pusher_hpp
#include <Arduino.h>
#include "brick_detector.hpp"
#include "interrupter.hpp"
#include <deque>
#include "util/delay_handler.hpp"
#include "util/push_states.hpp"

class pusher : public component, public brick_detector {
  public:
    interrupter *photo_sensor; //it needs one, but maybe could be an input var in detect brick instead? just need pin number
    virtual void open() = 0;
    virtual void close() = 0;
    void add_brick(bool);
    void act_on_brick(); //this is what should be checked each loop
  private:
    std::deque<push_states*> bricks_to_push;
    delay_handler _delay_handler;
    bool _is_open = false;
};
#endif
