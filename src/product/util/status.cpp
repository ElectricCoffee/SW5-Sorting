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
 * @param location The method in which the error occurred.
 * @param err_msg The message associated with the error
 */
status status::failure(String location, String err_msg) {
  String msg = ">> ERROR In " + location + ": " + err_msg;
  return status(false, msg);
}
