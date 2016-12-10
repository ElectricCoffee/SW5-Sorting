// The header file of controller
#ifndef controller_hpp
#define controller_hpp
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include "brick.hpp"
#include "component.hpp"
#include "sensor.hpp"
#include "pusher.hpp"
#include "blueprint.hpp"

class controller {
private:
  unsigned _number_of_sensors = 0;
  std::list<brick> _bricks;
  std::vector<std::deque<brick> > _sensor_brick_buffers;
  std::vector<component*> _components;
  std::vector<pusher*> _pushers; //couldnt see a way to do it with component
  std::vector<sensor*> _sensors;
public:
  blueprint blprint;
  controller();
  ~controller();
  void register_brick(brick);
  void register_component(component);
  void register_sensor(sensor&);
  void read_sensors();
  void register_pusher(pusher&);
  void read_pushers();
};

#endif
