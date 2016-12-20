// The implementation file of size
#include "size.hpp"


size::size(uint8_t read_pin, const motor &m) : component(read_pin), _motor(m) {
  pinMode(read_pin, INPUT);
}

/**
 * returns the last size it had read
 * doesnt measure a brick, only returns value of the last measured brick
 */
unsigned int size::get_size() {
  //Serial.println(_newest_size);
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
  _newest_size = 1;
  //Serial.println("starting measurement");
}

/**
 * stops the measuring and calculates the speed
 */
void size::stop_measuring() {
  _newest_size =  convert_delay_size(millis() - _current_time);
  //Serial.println("ending measurement");
}

/**
 * checks if there are any bricks in the sensor
 * i think this is what should be done in loop, maybe this is where there should be a signal
 */
brick size::check_measuring() {
  //Serial.println("starts measuring");
  if (_newest_size == 0) { //this is when there isn't one being measured.
    if (analogRead(pin) > 0 && analogRead(pin) < PHOTOTHRESHOLD) {
      start_measuring();
      //Serial.println("starting measurement");
    }
    //Serial.println(analogRead(A10));
  }
  else if(_newest_size == 1) { //this is for when there currently is one being measured.
    if (analogRead(pin) > PHOTOTHRESHOLD) {
      stop_measuring();
      //Serial.println("ending measurement");
    }
  }
  else {
    //this is when a brick has been made, but havent been read by controller
    //Serial.println("size");
    return brick(0,0,0, get_size()/*, 0, 0*/);
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
  //Serial.println("in get_brick_data");
  return check_measuring();
}

/**
 * converts the delay from the photo into a lego unit
 * still temporary, should use the speed from the motor
 @param a_delay the time it traveled between the interruptors
*/
unsigned int size::convert_delay_size(unsigned int a_delay){
  //Serial.println(a_delay);
  unsigned int return_value = a_delay / DELAYBRICKRELATION;
  if(a_delay%DELAYBRICKRELATION > DELAYBRICKRELATION * 0.5){
    ++return_value;
  }
  Serial.println(return_value);
  return return_value;
}
