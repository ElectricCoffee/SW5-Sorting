// The implementation file of size
#include "size.hpp"

#define ENGINESPEED 10 //temporary, should be the speed of engine, prolly shouldnt be gotten here, maybe make a macro?

size::size(uint8_t read_pin) : component(read_pin) {
  pinMode(read_pin, INPUT);
}

/**
 * returns the last size it had read
 * doesnt measure a brick, only returns value of the last measured brick
 */
unsigned int size::get_size() {
  Serial.println(_newest_size);
  unsigned int temp_newest_size = (unsigned int)_newest_size;
  _newest_size = 0;
  return temp_newest_size;
}

/**
 * starts measuring the size
 * millis() is a built in method in arduino
 * this will fuckup if it runs for 50 days
 */
void size::start_measuring() {
  _current_time = millis();
  _newest_size = -1;
  Serial.println("starting measurement");
}

/**
 * stops the measuring and calculates the speed
 */
void size::stop_measuring() {
  _newest_size = ENGINESPEED * (millis() - _current_time);
  Serial.println("ending measurement");
}

/**
 * checks if there are any bricks in the sensor
 * i think this is what should be done in loop, maybe this is where there should be a signal
 */
brick size::check_measuring() {
  Serial.println("starts measuring");
  if (_newest_size == 0) { //this is when there isn't one being measured.
    if (analogRead(pin) > 0 && analogRead(pin) < 300) {
      start_measuring();
    }
  }
  else if(_newest_size == -1) { //this is for when there currently is one being measured.
    if (!analogRead(pin) && analogRead(pin) > 320) {
      stop_measuring();
    }
  }
  else {
    //this is when a brick has been made, but havent been read by controller
    return brick(0, get_size() ,0, 0);
  }
  return brick::empty_brick();
}


void size::stop_measuring_temporarily() {
  _break_time = millis();
}

void size::continue_measuring() {
  _current_time += millis() - _break_time;
}

brick size::get_brick_data(){
  Serial.println("in get_brick_data");
  return check_measuring();
}
