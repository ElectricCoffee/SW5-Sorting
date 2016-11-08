// The implementation file of pusher
#include "pusher.hpp"
#include <Servo.h> //servo library in arduino

#define OPEN_STATE 0 //put here for easier editing
#define CLOSE_STATE 90

pusher::pusher(uint8_t temp_photo_pin, uint8_t temp_servo_pin) : component(temp_servo_pin) {
  photo_sensor = new sensor(temp_photo_pin);
  servo_sensor = new sensor(temp_servo_pin);
  _servo.attach(servo_sensor->pin);
}

void pusher::open() {
  _servo.write(OPEN_STATE);
}

void pusher::close() {
  _servo.write(CLOSE_STATE);
}

bool pusher::detect_brick() {
  return digitalRead(photo_sensor->pin);
}

bool pusher::operator==(const pusher p) const {
  return photo_sensor == p.photo_sensor
    &&   servo_sensor == p.servo_sensor;
}
