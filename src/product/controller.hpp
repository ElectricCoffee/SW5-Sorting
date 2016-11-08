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

class controller {
private:
  unsigned _number_of_sensors = 0;
  std::list<brick> _bricks;
  std::vector<std::deque<brick> > _sensor_buffers;
  std::vector<component> _components;
  std::vector<sensor> _sensors;
public:
  controller();
  ~controller();
  void register_brick(brick);
  void register_component(component);
  void register_sensor(sensor);
  void read_sensors();
};

#endif
