// The header file of src/motor
#ifndef motor_hpp
#define motor_hpp
#include <Arduino.h>
#include <AFMotor.h>
#include "component.hpp"

#define MIN_SPEED 1
#define MAX_SPEED 255
#define RAMP_UP_TIME 10
#define M1 1
#define M2 2
#define M3 3
#define M4 4

class motor : public component {
private:
  AF_DCMotor *_motor_ptr;
  uint8_t _speed = 0;
public:
  uint8_t read_pin;
  motor(uint8_t, uint8_t, uint8_t);
  ~motor();
  void run_forward(bool ramp_up = false);
  void run_backward(bool ramp_up = false);
  void stop(bool ramp_down = false);

  bool operator==(const motor) const;
};

#endif
