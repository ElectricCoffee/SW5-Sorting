// The implementation file of memory
#include "memory.hpp"

/**
 * sets the queue at the proper starting size and creates the correct amount of conveyors
 * @param amount_conveyors how many conveyors that needs to be added
 */
memory::memory(uint8_t amount_conveyors) {
  _queue.resize(amount_conveyors);
  for (uint8_t i = 0; i < amount_conveyors; i++) {
    add_conveyor(); //initialization
  }
}

/**
 * puts a brick onto the queue into the back
 * fails if the conveyor doesn't exist
 * @param a_brick the brick to be added
 * @param a_conveyor_number which conveyor it gets put on
 */
void memory::enqueue(brick a_brick, uint8_t a_conveyor_number) {
  if (_queue.size() >= (size_t) a_conveyor_number) { //to ensure proper access
    _queue[a_conveyor_number]->push_back(a_brick);
  }
}

/**
 * removes the first brick on the chosen conveyor
 * shrinks the queue to use less memory
 * @param a_conveyor_number which conveyor to take on from
 */
brick memory::dequeue(uint8_t a_conveyor_number) {
  if (_queue.size() >= (size_t) a_conveyor_number) {
    brick temp_brick = (*_queue[a_conveyor_number])[0];
    _queue[a_conveyor_number]->erase(_queue[a_conveyor_number]->begin()); //deletes the first pos and should resize it
    return temp_brick;
  } else {
    return brick::empty_brick();
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
void memory::remove_conveyor(uint8_t a_conveyor_number) { //not saving any of the deleted data, dont run on existing conveyors
  if(_queue.size() >= (size_t) a_conveyor_number) {
    delete( _queue[a_conveyor_number] ); //this should delete what the pointers point at
    _queue.erase( _queue.begin() + a_conveyor_number ); //this deletes the pointer and resizes the vector
  }
}

/**
 * Deletes the references in the queue before clearing it of objects.
 */
memory::~memory() {
  std::vector<std::deque<brick>* >::iterator vector_iterator;

  // for each element in the vector "_queue"
  // delete the reference to the item
  for (vector_iterator  = _queue.begin();
       vector_iterator != _queue.end();
       vector_iterator++) {
    delete *vector_iterator;
  }

  // after the queue's references have been deleted,
  // clear the queue of elements
  _queue.clear();
}
