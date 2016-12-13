// The implementation file of controller
#include "controller.hpp"

using namespace std;

// empty for now
controller::controller() {}
controller::~controller() {
  vector<component*>::iterator c_it;
  vector<sensor*>::iterator s_it;

  for(c_it = _components.begin(); c_it != _components.end(); c_it++) {
    delete *c_it;
  }

  for(s_it = _sensors.begin(); s_it != _sensors.end(); s_it++) {
    delete *s_it;
  }
}

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
  vector<component*>::iterator it;
  bool component_exists = false;

  for (it  = _components.begin(); it != _components.end(); it++) {
    if (**it == comp) {
      component_exists = true;
      break;
    }
  }

  if (!component_exists) {
    _components.push_back(&comp); // possibly dangerous
  }
}

/**
 * Registers a sensor if it doesn't already exist in the system.
 * If it does exist, nothing happens.
 * @param sen The sensor to be registered.
 */
void controller::register_sensor(sensor &sen) {
  vector<sensor>::iterator it;
  bool sensor_exists = false;

  /*
  for (it = _sensors.begin(); it != _sensors.end(); it++) {
    if (*it == sen) {
      sensor_exists = true;
      break;
    }
  }
  */

  if (!sensor_exists) {
    ++_number_of_sensors;
    _sensors.push_back(&sen); // possibly dangerous
    sen.init(); // may need a failure check.
    if (_number_of_sensors > 1) {
      _sensor_brick_buffers.push_back(deque<brick>());
    }
  }
}

/**
 * Reads the sensors one by one to collect their input and construct a completed brick.
 */
void controller::read_sensors() {
  vector<sensor*>::iterator it;
  sensor **first = &_sensors.front(),
         **last  = &_sensors.back();

  for (it = _sensors.begin(); it != _sensors.end(); ++it) {
    int index = std::distance(_sensors.begin(), it);
    brick old_brick = brick::empty_brick();

    if ((*it)->get_brick_data() != brick::empty_brick()) {
      Serial.println("mergebrick");

      if (it != first) { // if not first, pop from the previous buffer
        old_brick = _sensor_brick_buffers[index].back();
        _sensor_brick_buffers[index - 1].pop_back();
      }

      brick read_brick = (*it)->get_brick_data(),
            new_brick  = old_brick.combine_with(read_brick);

      if (it != last) { // if not last, push to the next buffer
        _sensor_brick_buffers[index].push_front(new_brick);
      } else { // else push to the brick deque
        _bricks.push_front(new_brick);
//this is where it puts the brick into the pushers
        _pushers.front()->add_state(blprint.is_brick_useful(new_brick));
      }
    }
  }
}
//i just copied register component and changed typing
void controller::register_pusher(pusher *a_pusher){
  vector<pusher*>::iterator it;
  bool pusher_exists = false;

  if (!pusher_exists) {
    _pushers.push_back(a_pusher); // possibly dangerous
  }
}
/**
 * checks each pusher to see if it needs to act on it
 * will then remove the bricks which have been acted on
 */
void controller::read_pushers(){
  //int it;
  //Serial.println("a");
  if(_pushers[0]->act_on_brick()){
    Serial.println("true");
    //this is after a brick has been directed towards goal.
    _bricks.pop_front(); //if the bricks need further processing change here
  }
  //for (it = _pushers.begin(); it != _pushers.end()+1; ++it) {

  //}
}
