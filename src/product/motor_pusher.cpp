// The implementation of file motor_pusher
#include "motor_pusher.hpp"

motor_pusher::motor_pusher(uint8_t interrupter_pin, uint8_t motor_pin, uint8_t read_pin)
    : component(motor_pin), _pin(motor_pin) {
  photo_sensor = new interrupter(interrupter_pin);
  _motor_ptr   = new motor(MAX_SPEED, motor_pin, read_pin);
}

motor_pusher::~motor_pusher() {
  delete photo_sensor;
  delete _motor_ptr;
}

void motor_pusher::move_pusher(uint8_t forward) {
  int count = 0;
  bool last_high = false;

  if (forward == FORWARD) {
    _motor_ptr->run_forward();
  } else if(forward == BACKWARD) {
    _motor_ptr->run_backward();
  } else {
    return;
  }
  // run ~180 degrees forward
  while (count < 80) {
    if (digitalRead(_motor_ptr->read_pin) == HIGH && !last_high) {
      count++;
      last_high = true;
    } else if (digitalRead(_motor_ptr->read_pin) == LOW) {
      last_high = false;
    }
  }
  _motor_ptr->stop();
}

void motor_pusher::open() {
  move_pusher(FORWARD);
}

void motor_pusher::close() {
  move_pusher(BACKWARD);
}

bool motor_pusher::detect_brick() {
  return photo_sensor->detect_brick();
}

bool motor_pusher::operator==(const motor_pusher& p) const {
  return photo_sensor == p.photo_sensor
    &&   _pin == p._pin;
}