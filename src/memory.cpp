// The implementation file of memory
#include "memory.hpp"

/**
 * sets the queue at the proper starting size and creates the correct amount of conveyors
 * @param amount_conveyors how many conveyors that needs to be added
 */
memory::memory(short amount_conveyors) { 
  _queue.resize(amount_conveyors); 
  for(int i = 0; i < amount_conveyors; i++) {
    add_conveyor(); //initialization
  }
}

/**
 * puts a brick onto the queue into the back
 * fails if the conveyor doesn't exist
 * @param a_brick the brick to be added
 * @param a_conveyor_number which conveyor it gets put on
 */
void memory::enqueue(brick a_brick, short a_conveyor_number) {
  if(_queue.size() >= a_conveyor_number) { //to ensure proper access
    _queue[a_conveyor_number]->push_back(a_brick);
  }
}

/**
 * removes the first brick on the chosen conveyor
 * shrinks the queue to use less memory
 * @param a_conveyor_number which conveyor to take on from
 */
brick memory::dequeue(short a_conveyor_number) {
  if(_queue.size() >= amount_conveyors) {
    brick temp_brick = (*_queue[a_conveyor_number])[0]; 
    _queue[a_conveyor_number]->erase( _queue[a_conveyor_number]->begin() ); //deletes the first pos and should resize it
    return temp_brick;
  } 
  else {
    return null;
  }
}

/**
 * creates a new conveyor, nothing to see here move along
 */
void memory::add_conveyor() {
  _queue.push_back(new std::deque<brick>); 
}

/**
 * deletes a conveyor
 * @param a_conveyor_number which conveyor to remove
 * \todo this probably needs testing to see if both delete and erase works this way
 */
void memory::remove_conveyor(short a_conveyor_number) { //not saving any of the deleted data, dont run on existing conveyors
  if(_queue.size() >= a_conveyor_number) {
    delete( _queue[a_conveyor_number] ); //this should delete what the pointers point at
    _queue.erase( _queue.begin() + a_conveyor_number ); //this deletes the pointer and resizes the vector
  }
}

/**
 * deletes all bricks inside the deque before destroying the object
 */
void memory::~memory(){ 
  int temp_size = _queue.size();
  for(int i = 0; i < temp_size; i++){
    remove_conveyor(i);
  }
}
