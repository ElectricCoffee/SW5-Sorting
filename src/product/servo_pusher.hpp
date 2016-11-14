// The header file of servo_pusher
#ifndef servo_pusher_hpp
#define servo_pusher_hpp
#include <Servo.h>
#include "interrupter.hpp"
#include "brick_detector.hpp"

class servo_pusher : public component, public brick_detector {
private:
  Servo _servo; //servo object from arduino servo library. creates its own in construction
  const int _OPEN_STATE   = 0;
  const int _CLOSED_STATE = 90;
public:
  // variables
  interrupter *photo_sensor;

  // methods
  servo_pusher(uint8_t, uint8_t); //constructor which takes the pins as input, first one photo
  ~servo_pusher();
  void open();
  void close();
  bool detect_brick(); //returns to ensure the controllers knows a new brick appeared
  bool operator ==(const servo_pusher&) const;
};
#endif
