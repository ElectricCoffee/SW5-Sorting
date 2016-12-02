// The implementation file of color
#include "color.hpp"

/**
 * Constructs an instance of the colour sensor.
 * The ISL29125 Colour Sensor runs over the SDA and SCL pins
 * @param interrupter_pin the pin of the photo-interrupter
 */
color::color(uint8_t interrupter_pin, SFE_ISL29125 &sensor)
    : component(interrupter_pin), _RGB_sensor_ptr(sensor) {
  photo_sensor_ptr = new interrupter(interrupter_pin);
  pinMode(interrupter_pin, INPUT);
}

/** Destructor */
color::~color() {
  delete photo_sensor_ptr;
}

/**
 * Shifts and adds the value of a colour read.
 * This is done to ensure the individual RGB values
 * are stored correctly in a unified integer.
 * @param value The colour value to be pushed onto the integer.
 */
void color::add_color(uint8_t value) {
  _newest_color <<= 8;
  _newest_color += value;
}

/**
 * Reads the colour value from the ISL29125 sensor
 * @returns a single unsigned int containing the colour.
 */
unsigned int color::get_color() {
  // the sensor returns a 16-bit integer...
  uint8_t red   = (uint8_t) _RGB_sensor_ptr.readRed();
  uint8_t green = (uint8_t) _RGB_sensor_ptr.readGreen();
  uint8_t blue  = (uint8_t) _RGB_sensor_ptr.readBlue();
  /*Serial.print("red = "); Serial.println(red,DEC);
  Serial.print("green = "); Serial.println(green,DEC);
  Serial.print("blue = "); Serial.println(blue,DEC);*/

  _newest_color = 0;
  add_color(red);
  add_color(green);
  add_color(blue);

  return _newest_color;
}

/**
 * @returns an empty brick if below reading is below COLOR_THRESHOLD.
 * Returns the brick if it isn't.
 */
brick color::get_brick_data() {
  if(!detect_brick()){
  if(!detect_brick() == flipping_pin_read){
  if(!detect_brick() == _flipping_pin_read){
    return brick::empty_brick(); //if there isn't a brick then dont read it
  }
  unsigned int tsvet = get_color();
  _flipping_pin_read = !_flipping_pin_read;
  //Serial.println(tsvet);
  flipping_pin_read = !flipping_pin_read;
  if (tsvet <= COLOR_THRESHOLD) {
    return brick::empty_brick();
  } else {
    Serial.println(tsvet);
    return brick(tsvet, 0, 0, 0);
  }
}

bool color::detect_brick() {
  //Serial.println(analogRead(pin));
  return analogRead(pin) < 335; //with battery: 358 unblocked, 310 blocked
}

bool color::init() {
  return _RGB_sensor_ptr.init();
}
