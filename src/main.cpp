#include <Arduino.h>
#include "product/controller.hpp"
#include "product/motor.hpp"
#include "product/motor_pusher.hpp"
#include "product/color.hpp"
#include "product/size.hpp"
#include "product/blueprint.hpp"

#ifndef UNIT_TEST // important line, do not remove
#define NO_PIN 0

controller contr;
SFE_ISL29125 sparkfun_sensor; // OBS initialize in main
color color_sensor(A8, sparkfun_sensor);
motor motor1(128, M2, NO_PIN);
size  size_sensor(A10, motor1);
motor_pusher pusher1(NO_PIN, M4, 22);
char bricks_str[] =
  "COL:05794119 LEN:03\n"
  "COL:04544030 LEN:02\n"
  "COL:05850652 LEN:04\n"
  "COL:03759907 LEN:04\n"
  "COL:00725001 LEN:03\n"
  "COL:00527900 LEN:02\n"
  "COL:05794119 LEN:04\n"
  "COL:00527900 LEN:03\n"
  "COL:00527900 LEN:04\n"
  "COL:03759907 LEN:03\n"
  "COL:04544030 LEN:03\n"
  "COL:02430737 LEN:04\n"
  "COL:00395527 LEN:04\n"
  "COL:05850652 LEN:02\n"
  "COL:00725001 LEN:04\n"
  "COL:05850652 LEN:03\n"
  "COL:02430737 LEN:03\n"
  "COL:00395527 LEN:03\n"
  "COL:03759907 LEN:02\n"
  "COL:05794119 LEN:02\n"
  "COL:02430737 LEN:02\n"
  "COL:04544030 LEN:04\n"
  "COL:00395527 LEN:02\n"
  "COL:00725001 LEN:02\n"
  "COL:05794119 LEN:03\n";


void setup() {
  Serial.begin(9600);
  sparkfun_sensor.init(); // initialising color sensor
  Serial.println("test");
  motor1.run_forward();
  contr.register_sensor(size_sensor);
  contr.register_sensor(color_sensor);
  pinMode(A8, INPUT);
  pinMode(A10, INPUT);
  //contr.register_component(pusher1);

  blueprint test_blueprint; //dont use here in final build
  test_blueprint.add_from_string(bricks_str);
  //test_blueprint.add_from_file("DATA.BRK");
}

void loop() {
  contr.read_sensors();

  //Serial.println(analogRead(A10));
  //Serial.println(analogRead(A8));
}

#endif // important line, do not remove
