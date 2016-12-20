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
void color::get_color() {
  // the sensor returns a 16-bit integer...
  red   = (uint8_t) _RGB_sensor_ptr.readRed();
  green = (uint8_t) _RGB_sensor_ptr.readGreen();
  blue  = (uint8_t) _RGB_sensor_ptr.readBlue();
/*
  Serial.print("red = "); Serial.println(red,HEX);
  Serial.print("green = "); Serial.println(green,HEX);
  Serial.print("blue = "); Serial.println(blue,HEX);
  /*
  _newest_color = 0;
  add_color(red);
  add_color(green);
  add_color(blue);

  return _newest_color;
*/
}

/**
 * @returns an empty brick if below reading is below COLOR_THRESHOLD.
 * Returns the brick if it isn't.
 */
brick color::get_brick_data() {
  if(!detect_brick() == _flipping_pin_read){
    return brick::empty_brick(); //if there isn't a brick then dont read it
  }

  //the part below needs delay before reading

  if(_current_time == 0){
    _current_time = millis();
    _flipping_pin_read = !_flipping_pin_read;
  }

  if(_current_time + delay_between_photo_color <= millis()){
    get_color();
  //Serial.println(tsvet);
  //Serial.println("in color get_brick_data");
  _current_time = 0;
  _flipping_pin_read = !_flipping_pin_read;

/*
  //TEMPORARY, IF THIS GETS PUSHED ANDERS FUCKED UP
  Serial.println("giving fake color");
  _newest_color = 0;
  add_color(14);
  add_color(19);
  add_color(8);
  return brick(_newest_color, 0);
  //END OF TEMPORARY
*/
    if (red <= RED_THRESHOLD && green <= GREEN_THRESHOLD) {
      return brick::empty_brick();

    } else {
      //Serial.println(tsvet);
      return brick(red,green,blue, 0/*, 0, 0*/);
    }
    }

    /*
    Serial.print("delay is weird: ");
    Serial.print(_current_time);
    Serial.print(" ");
    Serial.print(delay_between_photo_color);
    Serial.print(" ");
    Serial.println(millis());
    */
  return brick::empty_brick();
}

bool color::detect_brick() {
  //Serial.println(analogRead(pin));
  return analogRead(pin) < PHOTO_THRESHOLD_COLOR; //with battery: 358 unblocked, 310 blocked
}
/*
bool color::init() {
  return _RGB_sensor_ptr.init()s;
}*/
