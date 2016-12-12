// The header file of motor_pusher
#ifndef motor_pusher_hpp
#define motor_pusher_hpp
#include "motor.hpp"
#include "interrupter.hpp"
#include "brick_detector.hpp"
#include "pusher.hpp"

class motor_pusher : public component, public brick_detector, public pusher {
private:
  const uint8_t _pin;
  motor *_motor_ptr;
  void move_pusher(uint8_t);
public:
  interrupter *photo_sensor;
  void open();
  void close();
  motor_pusher(uint8_t, uint8_t, uint8_t, unsigned long);
  ~motor_pusher();
  bool operator ==(const motor_pusher&) const;
  // interface methods
  bool detect_brick();
};
#endif
