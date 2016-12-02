// The header file of blueprint
#ifndef blueprint_hpp
#define blueprint_hpp
#include <StandardCplusplus.h>
#include <deque>
#include <Arduino.h>
#include "brick.hpp"

class blueprint {
private:
  std::deque<brick> _registered_bricks;
  const char* _format_string = "COL:%d LEN:%d\n";
public:
  blueprint();
  ~blueprint();
  brick front();
  void pop_front();
  bool is_brick_useful(brick);
  brick convert_to_brick(String);
};

#endif
