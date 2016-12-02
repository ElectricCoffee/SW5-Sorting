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
color color_sensor(A8, sparkfun_sensor);
size  size_sensor(A10);
motor_pusher pusher1(NO_PIN, M4, 22);
motor motor1(128, M2, NO_PIN);

void setup() {
  Serial.begin(9600);
  //sparkfun_sensor.init();
  Serial.println("test");
  motor1.run_forward();
  contr.register_sensor(size_sensor);
  contr.register_sensor(color_sensor);
  pinMode(A8, INPUT);
  pinMode(A10, INPUT);
  //contr.register_component(pusher1);
}

void loop() {
  contr.read_sensors();
  delay(100);

  //Serial.println(analogRead(A10));
  //Serial.println(analogRead(A8));
}

#endif // important line, do not remove
