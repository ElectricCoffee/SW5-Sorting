#include <Arduino.h>
#include "product/controller.hpp"
#include "product/motor.hpp"
#include "product/pusher.hpp"
#include "product/color.hpp"
#include "product/size.hpp"
#include "product/blueprint.hpp"
#include "product/brick.hpp"

#ifndef UNIT_TEST // important line, do not remove
#define NO_PIN 0

#define MK_BRK(MR, MG, MB, ML) {MR, MG, MB, ML}

controller contr;
SFE_ISL29125 sparkfun_sensor; // OBS initialize in main
color color_sensor(A8, sparkfun_sensor);
motor motor1(128, M2, NO_PIN);
size  size_sensor(A10, motor1);
pusher *pusher1 = new pusher(M1, 22, 5000);

// This is a string representation of a randomised brick dataset
// used for the blueprint to know what data to look for
// char bricks_str[] =
//   "COL:05794119 LEN:03\n";

brick_bytes bricks[] = {
  MK_BRK(0x58, 0x69, 0x47, 3),
  MK_BRK(0xFF, 0xFF, 0xFF, 4),
  MK_BRK(0x00, 0x00, 0x00, 2)
};


void setup() {
  Serial.begin(9600);
  sparkfun_sensor.init(); // initialising color sensor
  Serial.println("test");
  motor1.run_forward();
  contr.register_sensor(size_sensor);
  //contr.register_sensor(color_sensor);
  pinMode(A8, INPUT);
  pinMode(A10, INPUT);
  //contr.register_component(pusher1);

  blueprint test_blueprint; //dont use here in final build
  test_blueprint.add_from_bytes(bricks, 3);
  //test_blueprint.add_from_file("DATA.BRK");
}

void loop() {
  contr.read_sensors();
  contr.read_pushers();
  delay(100);
  //Serial.println(analogRead(A10));
  //Serial.println(analogRead(A8));
}

#endif // important line, do not remove
