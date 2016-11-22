// The implementation file of size
#include "size.hpp"

#define ENGINESPEED 0 //temporary, should be the speed of engine, prolly shouldnt be gotten here, maybe make a macro?

size::size(uint8_t read_pin, const motor &m) : component(read_pin), _motor(m) {
  pinMode(read_pin, INPUT);
}

/**
 * returns the last size it had read
 * doesnt measure a brick, only returns value of the last measured brick
 */
unsigned int size::get_size() {
  return _newest_size;
}

/**
 * starts measuring the size
 * millis() is a built in method in arduino
 * this will fuckup if it runs for 50 days
 */
void size::start_measuring() {
  _current_time = millis();
  _newest_size = 0;
}

/**
 * stops the measuring and calculates the speed
 */
void size::stop_measuring() {
  _newest_size = ENGINESPEED * (millis() - _current_time);
}

/**
 * checks if there are any bricks in the sensor
 * i think this is what should be done in loop, maybe this is where there should be a signal
 */
void size::check_measuring() {
  if (_newest_size != 0) { //this is when there isn't one being measured.
    if (analgRead(pin)) {
      start_measuring();
    }
  }
  else { //this is for when there currently is one being measured.
    if (analogRead(pin) == 0) {
      stop_measuring();
    }
  }
}

void size::stop_measuring_temporarily() {
  _break_time = millis();
}

void size::continue_measuring() {
  _current_time += millis() - _break_time;
}
