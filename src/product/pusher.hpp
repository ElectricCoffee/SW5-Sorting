// The header file of pusher
#ifndef pusher_hpp
#define pusher_hpp
#include <Arduino.h>
#include <Servo.h>
#include "sensor.hpp"

class pusher {
  public:
    sensor photo_sensor; //it needs one, but maybe could be an input var in detect brick instead? just need pin number
    sensor servo_sensor; //or maybe just be some ints instead? might just be objects for objects sake. or maybe inherit
    void open();
    void close();
    bool detect_brick(); //returns to ensure the controllers knows a new brick appeared
    pusher(uint8_t, uint8_t); //constructor which takes the pins as input, first one photo

  private:
    Servo the_servo; //servo object from arduino servo library. creates its own in construction

};
#endif
