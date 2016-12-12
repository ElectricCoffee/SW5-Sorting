// The implementation of file motor_pusher
#include "motor_pusher.hpp"

/**
 * The constructor for the pusher that uses a LEGO NXT motor
 * @param interrupter_pin is the pin on which the interrupter is attached
 * @param motor_pin is the motor-shield pin (M1 to M4) on which the motor is attached
 * @param tach_pin is the pin that reads the motor's tachometer
 */
motor_pusher::motor_pusher(uint8_t interrupter_pin, uint8_t motor_pin, uint8_t tach_pin, unsigned long a_delay_length)
    : component(motor_pin), _pin(motor_pin), pusher(a_delay_length) {
  photo_sensor = new interrupter(interrupter_pin);
  _motor_ptr   = new motor(MAX_SPEED, motor_pin, tach_pin);
  //_delay_handler = delay_handler(a_delay_length);
}

motor_pusher::~motor_pusher() {
  delete photo_sensor;
  delete _motor_ptr;
}

void motor_pusher::move_pusher(uint8_t forward) {
  int count = 0;
  bool last_high = false;

  unsigned long start_time = millis();

  if (forward == FORWARD) {
    _motor_ptr->run_forward();
  } else if(forward == BACKWARD) {
    _motor_ptr->run_backward();
  } else {
    return;
  }

  while(start_time + 190 > millis()){
    Serial.println("running motor");
  } //get prettier way of doing this
  /* WE TRIED THIS IT DIDN'T WORK

  // run ~180 degrees forward
  while (count < 80) {
    Serial.println(digitalRead(_motor_ptr->read_pin));
    if (digitalRead(_motor_ptr->read_pin) == HIGH && !last_high) {
      count++;
      last_high = true;
    } else if (digitalRead(_motor_ptr->read_pin) == LOW) {
      last_high = false;
    }
  }
  */
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
