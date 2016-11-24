// The implementation file of sensor
#include "sensor.hpp"

brick sensor::get_brick_data() {
  Serial.println("in the wrong get");
  return brick::empty_brick();
}

bool sensor::detect_brick() {
  return false;
}

/**
 * Initialises a sensor
 * @returns true if the initialisation was successful
 * @returns false if the initialisation was unsuccessful
 */
bool sensor::init() {
  // default value in case a sensor doesn't need initialisation
  return true;
}
