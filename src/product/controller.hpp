// The header file of controller
#ifndef controller_hpp
#define controller_hpp
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>
#include <list>
#include "brick.hpp"
#include "component.hpp"

class controller {
private:
  std::list<brick> _registered_bricks;
  std::vector<component> _registered_components;
public:
  controller();
  ~controller();
  void register_brick(brick);
  void register_component(component);
};

#endif
