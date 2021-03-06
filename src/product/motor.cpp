// The implementation file of src/motor
#include "motor.hpp"

/**
 * Constructs the motor object.
 * @param a_speed sets the speed of the motor, can be any value between 0 and 255.
 * @param a_motor_number sets the motor's pin number, can be the values 1 to 4.
 */
motor::motor(uint8_t a_speed, uint8_t a_motor_number, uint8_t a_read_pin)
    : component(a_motor_number) {
  pinMode(a_motor_number, OUTPUT); // may not be needed
  pinMode(a_read_pin, INPUT);
  _speed = a_speed;
  _motor_ptr = new AF_DCMotor(a_motor_number);
  read_pin = a_read_pin;
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

/**
 * Samples the tachometer on the motor for a given number of milliseconds
 * @param sample_time_millis is the amount of time it needs to sample in
 * it's set to 500ms by default
 * @param sample_time_millis the sample time in milliseconds
 * @returns a speed in ticks/second (what ticks are, is up to you)
 */
void motor::sample_speed(unsigned int sample_time_millis) {
  unsigned long start_time = millis();
  unsigned long current_time   = 0;
  bool last_high = false;
  double ticks = 0;

  do {
    if (digitalRead(read_pin) == HIGH && !last_high) {
      ticks++;
      last_high = true;
    } else if(digitalRead(read_pin) == LOW) {
      last_high = false;
    }
    current_time = millis();
  } while (current_time - start_time >= sample_time_millis);

  speed = (ticks / sample_time_millis) * 1000;
}

bool motor::operator==(const motor m) const {
  return _motor_ptr == m._motor_ptr
    &&   _speed     == m._speed;
}
