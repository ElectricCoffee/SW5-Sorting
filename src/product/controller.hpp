// The header file of controller
#ifndef controller_hpp
#define controller_hpp
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>
#include <list>
#include <queue>
#include <iterator>
#include "brick.hpp"
//#include "component.hpp"
#include "sensor.hpp"
#include "pusher.hpp"
#include "blueprint.hpp"

#define SENSOR_COUNT 2

class controller {
private:
  //unsigned _number_of_sensors = 0;
  std::list<brick> _bricks;
  //std::vector<std::deque<brick> > _sensor_brick_buffers;
  //std::vector<component*> _components;
  //std::vector<pusher*> _pushers; //couldnt see a way to do it with component
  pusher *_pusher;
  //std::vector<sensor*> _sensors;
  sensor *_sensors[SENSOR_COUNT];
  std::queue<brick> _brick_queue;
  blueprint _blueprint;
public:
  controller(pusher*, blueprint&);
  ~controller();
  void register_brick(brick);
  //void register_component(component);
  // void register_sensor(sensor&);
  void register_sensors(sensor*, sensor*);
  void read_sensors();
  // void register_pusher(pusher*);
  void read_pushers();
};

#endif
