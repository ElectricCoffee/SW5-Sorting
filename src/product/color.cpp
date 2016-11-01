// The implementation file of color
#include "color.hpp"

int color::get_color() {
  return 57005; // temporary return value 0xDEAD
}

void color::start_measuring() {
  newest_color = analogRead(pin); // Reads input from color sensor pin needs work tho
}

void color::stop_measuring() {
  newest_color = 57005; // Resets the color to 0xDEAD which means it waits for next brick 0xDEAD
}

//check_measuring will either clear the newest_color
//or read the newest color from the sensor
//check_measuring should only be called to read or reset a reading
void color::check_measuring() {
  if (newest_color != 57005) { //It will measure the sensor 0xDEAD
    start_measuring();
  }
  else {
    stop_measuring(); //newest_color will be reste since it's not 0xDEAD
  }
}
