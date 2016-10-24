// The implementation file of pusher
#include "pusher.hpp"
#include <Servo.h> //servo library in arduino

#define OPEN_STATE 0 //put here for easier editing
#define CLOSE_STATE 90

pusher::pusher(int temp_photo_pin, int temp_servo_pin){
  photo_sensor = new sensor(temp_photo_pin);
  servo_sensor = new sensor(temp_servo_pin);
  the_servo.attach(servo_sensor.pin);
}
pusher::open(){
  if(the_servo == null)
    the_servo.attach(servo_sensor.pin);
  the_servo.write(OPEN_STATE); 
}

pusher::close(){
  if(the_servo == null)
    the_servo.attach(servo_sensor.pin);
  the_servo.write(CLOSE_STATE);
}

pusher::detect_brick(){
  return digitalRead(photo_sensor); 
}
