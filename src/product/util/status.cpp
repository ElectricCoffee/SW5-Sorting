// The implementation of file status
#include "status.hpp"

status::status(bool success, String msg)
: is_successful(success), error_message(msg) {}

/**
 * Returns a success status
 */
status status::success() {
  return status(true, "");
}

/**
 * Returns a failure status
 * @param err_msg The message associated with the error
 */
status status::failure(String err_msg) {
  return status(false, err_msg);
}
