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
  std::list<brick> _registered_bricks;
  std::vector<std::deque<brick> > _sensor_buffers;
  std::vector<component> _registered_components;
  std::vector<sensor> _registered_sensors;
public:
  controller();
  ~controller();
  void register_brick(brick);
  void register_component(component);
};

#endif
