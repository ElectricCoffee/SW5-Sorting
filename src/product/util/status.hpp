// The header file of status
#ifndef status_hpp
#define status_hpp
#include <Arduino.h>

/**
 * @brief The status class is intended as a return type for
 * functions that may or may not succeed.
 * The class has no public constructors.
 * Its only means of construction are through success and failure.
 */
struct status {
  const bool   is_successful;
  const String error_message;

  static status success();
  static status failure(String);
private:
  status(bool, String);
};

#endif
