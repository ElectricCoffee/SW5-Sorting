#include <Arduino.h>
#include "product/controller.hpp"
#include "product/motor.hpp"
#include "product/motor_pusher.hpp"
#include "product/color.hpp"
#include "product/size.hpp"

#ifndef UNIT_TEST // important line, do not remove
#define NO_PIN 0

controller contr;
color color_sensor(NO_PIN);
//size  size_sensor;
motor_pusher pusher1(NO_PIN, M4, 22);
motor motor1(128, M1, NO_PIN);

void setup() {
  motor1.run_forward();
  contr.register_sensor(color_sensor);
  contr.register_component(pusher1);
}

void loop() {
  contr.read_sensors();
}

#endif // important line, do not remove
