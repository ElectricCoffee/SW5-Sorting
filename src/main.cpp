#include <Arduino.h>
#include "product/controller.hpp"
#include "product/motor_pusher.hpp"
#include "product/color.hpp"
#include "product/size.hpp"

#ifndef UNIT_TEST // important line, do not remove

controller contr;
color color_sensor(0);
//size  size_sensor;
motor_pusher pusher1(0, M4, 22);

void setup() {
  contr.register_sensor(color_sensor);
  contr.register_component(pusher1);
}

void loop() {
  contr.read_sensors();
}

#endif // important line, do not remove
