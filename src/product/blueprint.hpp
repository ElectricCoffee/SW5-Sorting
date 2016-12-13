// The header file of blueprint
#ifndef blueprint_hpp
#define blueprint_hpp
#include <StandardCplusplus.h>
#include <deque>
#include <cstring>
#include <Arduino.h>
#include "brick.hpp"
#include "util/status.hpp"

class blueprint {
private:
  std::deque<brick> _registered_bricks;
public:
  blueprint();
  ~blueprint();
  brick front();
  void pop_front();
  bool is_brick_useful(brick);
  status convert_to_brick(const char*, brick*);
  void add_from_string(char*);
  void add_from_bytes(const brick_bytes bricks[], size_t);
};

#endif
