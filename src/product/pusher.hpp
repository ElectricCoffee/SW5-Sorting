// The header file of pusher
#ifndef pusher_hpp
#define pusher_hpp
#include <Arduino.h>
#include <deque>
#include "motor.hpp"
#include "brick_detector.hpp"
#include "interrupter.hpp"
#include "util/delay_handler.hpp"
#include "util/push_states.hpp"
//tried to put add and act in component but had trouble with inheritance
class pusher : public component, public brick_detector {
private:
  const uint8_t _pin;
  motor *_motor_ptr;
  std::deque<push_states*> bricks_to_push;
  delay_handler *_delay_handler;
  bool _is_open = false;
  uint8_t amount_bricks;
  void move_pusher(uint8_t);
public:
  interrupter *photo_sensor; //it needs one, but maybe could be an input var in detect brick instead? just need pin number
  pusher(uint8_t, uint8_t, unsigned long);
  ~pusher();
  void open();
  void close();
  void add_state(bool);
  bool act_on_brick(); //this is what should be checked each loop

  bool operator ==(const pusher&) const;
  bool detect_brick();
};
#endif
