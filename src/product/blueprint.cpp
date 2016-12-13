// The implementation file of blueprint
#include "blueprint.hpp"

// blueprint::blueprint() {
//   // add initialiser code here
// }
//
// blueprint::~blueprint() {
//   // add destruction code here
// }

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

/**
 * Takes a c-string as an input, and attempts to split it into a brick.
 * @param input is a c-string containing a line from the input-file.
 * @param br_ptr is a brick-pointer output-parameter.
 * @returns a status::success if successful,
 * and a status::fail if the conversion failed.
 */
/*status blueprint::convert_to_brick(const char *input, brick *br_ptr) {
  int reads = sscanf(input, "COL:%lu LEN:%hhu", &br_ptr->color, &br_ptr->size_x);
  if (reads != 2) { // 2 is the number of inputs to the sscanf above
    return status::failure (
      "blueprint::convert_to_brick",
      "Brick was of invalid format, could not read."
    );
  } else {
    return status::success();
  }
}*/

/**
 * Takes the input-file as a string, and scans it line by line,
 * converting each to a brick. The bricks are then added to _registered_bricks.
 * @param file_data is a c-string containing the data from a blueprint file.
 */
/*void blueprint::add_from_string(char *file_data) {
  char* current_line = strtok(file_data, "\n");
  while (current_line != NULL) {
    brick br;
    status stat = convert_to_brick(current_line, &br);
    if (stat.is_successful) {
      _registered_bricks.push_front(br);
    } else {
      Serial.println(stat.error_message);
    }
    current_line = strtok(NULL, "\n");
  }
}*/

void blueprint::add_from_bytes(const brick_bytes bricks[], size_t arr_size) {
  for (size_t i = 0; i < arr_size; i++) {
    _registered_bricks.push_front(brick::from_byte_array(bricks[i]));
  }
}
