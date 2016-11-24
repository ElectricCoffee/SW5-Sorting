#include <Arduino.h>
#include "product/controller.hpp"
#include "product/motor.hpp"
#include "product/motor_pusher.hpp"
#include "product/color.hpp"
#include "product/size.hpp"

#ifndef UNIT_TEST // important line, do not remove
#define NO_PIN 0

controller contr;
SFE_ISL29125 sparkfun_sensor;
color color_sensor(53, sparkfun_sensor);
size  size_sensor(A8);
motor_pusher pusher1(NO_PIN, M4, 22);
motor motor1(128, M2, NO_PIN);

void setup() {
  Serial.begin(115200);
  //sparkfun_sensor.init();
  Serial.println("test");
  motor1.run_forward();
  contr.register_sensor(size_sensor);
  contr.register_sensor(color_sensor);
  //contr.register_component(pusher1);
}

void loop() {
  contr.read_sensors();
  pinMode(24, INPUT);
  pinMode(A8, INPUT);
  //Serial.println(analogRead(A8));
//  Serial.println(analogRead(A8));
}

#endif // important line, do not remove
