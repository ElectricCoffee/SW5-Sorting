// The header file of blueprint
#ifndef blueprint_hpp
#define blueprint_hpp
#include <StandardCplusplus.h>
#include <deque>
#include "brick.hpp"

class blueprint {
private:
  std::deque<brick> _registered_bricks;
public:
  blueprint();
  ~blueprint();
  brick front();
  void pop_front();
  bool is_brick_useful(brick);
};

#endif
