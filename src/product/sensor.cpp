// The implementation file of sensor
#include "sensor.hpp"

brick sensor::get_brick_data() {
  Serial.println("in the wrong get");
  return brick::empty_brick();
}

bool sensor::detect_brick() {
  return false;
}
