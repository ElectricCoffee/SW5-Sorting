// The implementation file of memory
#include "memory.hpp"

memory::memory(short amount_conveyors) { //just to give it correct size at start
  _queue.resize(amount_conveyors);
  for(int i = 0; i < amount_conveyors; i++) {
    add_conveyor();
  }
}

void memory::enqueue(brick a_brick, short a_conveyor_number) {
  if(_queue.size >= a_conveyor_number) { //to ensure proper access
    _queue[a_conveyor_number]->push_back(a_brick);
  }
}

brick memory::dequeue(short a_conveyor_number) {
  if(_queue.size >= amount_conveyors) {
    brick temp_brick = (*_queue[a_conveyor_number])[0]; // unsure about this...
    _queue[a_conveyor_number]->pop_front(); //this doesn't actually return anything, kinda stupid
    _queue[a_conveyor_number]->shrink_to_fit(); //if it's too slow then could remove this, linear growth
    return temp_brick;
  } else {
    return null;
  }
}

void memory::add_conveyor() {
  _queue.push_back(new std::deque<brick>);
}

void memory::remove_conveyor(short a_conveyor_number) { //not saving any of the deleted data, dont run on existing conveyors
  if(_queue.size >= a_conveyor_number) {
    _queue.erase(_queue.begin() + a_conveyor_number -1); //begin sets iterator first place
  }
}


