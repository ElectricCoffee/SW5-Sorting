// The implementation file of size
#include "size.hpp"

#define ENGINESPEED 0 //temporary, should be the speed of engine, prolly shouldnt be gotten here, maybe make a macro?

/**
 * returns the last size it had read
 * doesnt measure a brick, only returns value of the last measured brick
 */
int size::get_size() {
  return newest_size; 
}

/**
 * starts measuring the size
 * millis() is a built in method in arduino
 * this will fuckup if it runs for 50 days
 */
void size::start_measuring() {
  current_time = millis();
  newest_size = null; 
}

/**
 * stops the measuring and calculates the speed
 */
void size::stop_measuring() {
  newest_size = ENGINESPEED * ( millis() - current_time);  
}

/**
 * checks if there are any bricks in the sensor
 * i think this is what should be done in loop, maybe this is where there should be a signal
 */
void size::check_measuring() {
  if(newest_size != null) { //this is when there isn't one being measured. 
    if(digitalRead(pin) == true) {
      start_measuring();
    }
  } 
  else { //this is for when there currently is one being measured.
    if(digitalRead(pin) == false) {
      stop_measuring();
    }
  }
}
