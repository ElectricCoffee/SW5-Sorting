// The implementation file of src/motor
#include "motor.hpp"

/**
 * Constructs the motor object.
 * @param a_speed sets the speed of the motor, can be any value between 0 and 255.
 * @param a_motor_number sets the motor's pin number, can be the values 1 to 4.
 */
motor::motor(char a_speed, int a_motor_number) {
  _speed = a_speed;
  _motor_ptr = new AF_DCMotor(a_motor_number);
}

/**
 * Destructor makes sure the motor pointer is deleted.
 * This is done to prevent a potential memory leak.
 */
motor::~motor() {
  delete _motor_ptr;
}

/**
 * Runs the motor forward at the speed defined in the constructor.
 * @param ramp_up If true, the motor will gently ramp up to full speed.
 *                If false, the motor will immediately engage at full speed.
 */
void motor::run_forward(bool ramp_up) {
  _motor_ptr->run(FORWARD);

  if (!ramp_up) {
    _motor_ptr->setSpeed(_speed);
  } else {
    for (int i = 0; i <= _speed; i++) {
      _motor_ptr->setSpeed(i);
      delay(RAMP_UP_TIME);
    }
  }
}


/**
 * Runs the motor backward at the speed defined in the constructor.
 * @param ramp_up If true, the motor will gently ramp up to full speed.
 *                If false, the motor will immediately engage at full speed.
 */
void motor::run_backward(bool ramp_up) {
    _motor_ptr->run(BACKWARD);

  if (!ramp_up) {
    _motor_ptr->setSpeed(_speed);
  } else {
    for (int i = 0; i <= _speed; i++) {
      _motor_ptr->setSpeed(i);
      delay(RAMP_UP_TIME);
    }
  }
}

/**
 * Stops the motor from running.
 * @param ramp_down If true, the motor will gently ramp down to a halt.
 *                  If false, the motor will stop immediately.
 */
void motor::stop(bool ramp_down) {
  if (ramp_down) {
    for (int i = _speed; i != 0; i--) {
      _motor_ptr->setSpeed(i);
      delay(RAMP_UP_TIME);
    }
  }

  _motor_ptr->run(RELEASE);
}
