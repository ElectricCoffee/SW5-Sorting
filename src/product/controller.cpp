// The implementation file of controller
#include "controller.hpp"

using namespace std;

// empty for now
controller::controller() {}
controller::~controller() {}

/**
 * Registers bricks that have been scanned to keep track of the bricks in the system
 * @param brk the brick to be added
 */
void controller::register_brick(brick brk) {
  _bricks.push_back(brk);
}

/**
 * Registers a component in the set of available components
 * If a component already exists, it won't be added to the set.
 * @param comp the component to be added to the set.
 */
void controller::register_component(component comp) {
  vector<component>::iterator it;
  bool component_exists = false;

  for (it  = _components.begin(); it != _components.end(); it++) {
    if (*it == comp) {
      component_exists = true;
      break;
    }
  }

  if (!component_exists) {
    _components.push_back(comp);
  }
}

/**
 * Registers a sensor if it doesn't already exist in the system.
 * If it does exist, nothing happens.
 * @param sen The sensor to be registered.
 */
void controller::register_sensor(sensor sen) {
  vector<sensor>::iterator it;
  bool sensor_exists = false;

  for (it = _sensors.begin(); it != _sensors.end(); it++) {
    if (*it == sen) {
      sensor_exists = true;
      break;
    }
  }

  if (!sensor_exists) {
    _sensors.push_back(sen);
    _sensor_buffers.push_back(std::deque<brick>());
  }
}

