// The header file of pusher
#ifndef pusher_hpp
#define pusher_hpp
#include <Arduino.h>
#include <deque>
#include "motor.hpp"
#include <AFMotor.h>
//#include "brick_detector.hpp"
//#include "interrupter.hpp"
#include "util/delay_handler.hpp"
#include "util/push_states.hpp"

#define push_forward 1
#define push_backward 2

//tried to put add and act in component but had trouble with inheritance
class pusher : public component {
private:
  const uint8_t _pin;
  motor _motor_ptr;
  state_time *brick_to_push;
  bool _slate = false;
  void move_pusher(uint8_t);
  bool is_brick_empty = true;
  uint16_t _delay_length;
  unsigned long _delay_start;
public:
  //interrupter *photo_sensor; //it needs one, but maybe could be an input var in detect brick instead? just need pin number
  pusher(uint8_t, uint8_t, uint16_t);
  ~pusher();
  void open();
  void close();
  void add_state(bool);
  bool act_on_brick(); //this is what should be checked each loop

  bool operator ==(const pusher&) const;
  bool detect_brick();
};
#endif
