// The implementation file of color
#include "color.hpp"

unsigned int color::get_color() {
  return color::start_measuring(); // temporary return value 0xDEAD
}

unsigned int color::start_measuring() {
  SFE_ISL29125 RGB_sensor; //declaring the sensor as an object
  unsigned int red = RGB_sensor.readRed(); //reads red value
  unsigned int green = RGB_sensor.readGreen(); //reads green value
  unsigned int blue = RGB_sensor.readBlue(); //reads blue value

  newest_color = 0; // ensures reset newest color everytime
  newest_color <<= red; //bitwise shift red.
  newest_color <<= green;
  newest_color <<= blue;

  return newest_color;
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
