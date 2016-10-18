// The implementation file of blueprint
#include "blueprint.hpp"

blueprint::blueprint() {
  // add initialiser code here
}

bool blueprint::is_brick_useful(brick b) {
  // insert relevant checks here
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

