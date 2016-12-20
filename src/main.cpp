#include <Arduino.h>
#include "product/controller.hpp"
#include "product/motor.hpp"
#include "product/pusher.hpp"
#include "product/color.hpp"
#include "product/size.hpp"
#include "product/blueprint.hpp"
#include "product/brick.hpp"

#define NO_PIN 0

#define MK_BRK(MR, MG, MB, ML) {MR, MG, MB, ML}

// This is a string representation of a randomised brick dataset
// used for the blueprint to know what data to look for
// char bricks_str[] =
//   "COL:05794119 LEN:03\n";

brick_bytes bricks[] = {
   MK_BRK(0x5A, 0x2F, 0x0B, 6),
   MK_BRK(0x5A, 0x2F, 0x0B, 6),
   MK_BRK(0x5A, 0x2F, 0x0B, 6),
};

SFE_ISL29125 sparkfun_sensor; // OBS initialize in main
;
color *color_sensor = new color(A8, sparkfun_sensor);
motor motor1(128, M3, NO_PIN);
size  *size_sensor = new size(A10, motor1);
pusher *pusher1 = new pusher(M2, 22, 50);
blueprint blprt(bricks, 3);
controller contr(pusher1, blprt);

//controller(pusher*, blueprint&);
//~controller();
void register_brick(brick);
//void register_component(component);
// void register_sensor(sensor&);
void register_sensors(sensor*, sensor*);
void read_sensors();
// void register_pusher(pusher*);
void read_pushers();

unsigned _number_of_sensors = 0;
std::list<brick> _bricks;
//std::vector<std::deque<brick> > _sensor_brick_buffers;
//std::vector<component*> _components;
//std::vector<pusher*> _pushers; //couldnt see a way to do it with component
pusher *_pusher;
//std::vector<sensor*> _sensors;
sensor *_sensors[SENSOR_COUNT];
//std::queue<brick> _brick_queue;
brick _brick;
//blueprint _blueprint;

void setup() {
  Serial.begin(9600);
  sparkfun_sensor.init(); // initialising color sensor
  motor1.run_forward();
  contr.register_sensors(size_sensor, color_sensor);
  pinMode(A8, INPUT);
  pinMode(A10, INPUT);

  _sensors[0] = size_sensor;
  _sensors[1] = color_sensor;
}

void loop() {
  //delay(100);
  //color_sensor->get_color();
  //read sensors

  brick br1 = _sensors[0]->get_brick_data();
  brick br2 = _sensors[1]->get_brick_data();

  if (br1 != brick::empty_brick()) {
    _brick = br1;
  }

  if (br2 != brick::empty_brick()) {
    //_brick = _brick_size;
    //_brick_queue.pop();
    _brick = _brick.combine_with(br2);
    //_bricks.push_front(temp_brick);
    bool state = blprt.is_brick_useful(_brick);
    _pusher->add_state(state);
  } // else do nothing

  //read pushers
  if(_pusher->act_on_brick()){
    //Serial.println("true");
    //this is after a brick has been directed towards goal.
    //_bricks.pop_front(); //if the bricks need further processing change here
    _brick = brick::empty_brick();
    br1 = brick::empty_brick();
    br2 = brick::empty_brick();
  }

}
