// The header file of src/motor
#ifndef motor_hpp
#define motor_hpp
#include <AFMotor.h>
#include "component.hpp"

#define RAMP_UP_TIME 10
#define M1 1
#define M2 2
#define M3 3
#define M4 4

class motor : public component {
private:
  AF_DCMotor *_motor_ptr;
  char _speed = 0;
public:
  // char here used as an 8-bit integer
  motor(char, int);
  ~motor();
  void run_forward(bool ramp_up = false);
  void run_backward(bool ramp_up = false);
  void stop(bool ramp_down = false);
};

#endif
