// The implementation file of blueprint
#include "blueprint.hpp"

blueprint::blueprint() {
  // add initialiser code here
}

blueprint::~blueprint() {
  // add destruction code here
}

/**
 * Gets the next available brick from the deque without deleing it
 */
brick blueprint::front() {
  return _registered_bricks.front();
}

/**
 * Deletes the next available brick from the deque.
 */
void blueprint::pop_front() {
  _registered_bricks.pop_front();
}

/**
 * Checks if a brick is useful
 * @param brick the brick to be checked
 */
bool blueprint::is_brick_useful(brick a_brick) {
  std::deque<brick>::iterator deque_iterator;
  
  for (deque_iterator  = _registered_bricks.begin();
       deque_iterator != _registered_bricks.end();
       deque_iterator++) {
    if (*deque_iterator == a_brick) {
      return true;
    } // else continue looking
  }

  return false;
}
