// The implementation of file servo_pusher
#include "servo_pusher.hpp"

servo_pusher::servo_pusher(uint8_t interrupter_pin, uint8_t servo_pin) : component(servo_pin) {
  pinMode(servo_pin, OUTPUT);
  photo_sensor = new interrupter(interrupter_pin);
  _servo.attach(servo_pin);
}

servo_pusher::~servo_pusher() {
  delete photo_sensor;
}

void servo_pusher::open() {
  _servo.write(_OPEN_STATE);
}

void servo_pusher::close() {
  _servo.write(_CLOSED_STATE);
}

bool servo_pusher::detect_brick() {
  return photo_sensor->detect_brick();
}

bool servo_pusher::operator==(const servo_pusher& p) const {
  return photo_sensor == p.photo_sensor;
}
