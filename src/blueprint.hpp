// The header file of blueprint
#ifndef blueprint_hpp
#define blueprint_hpp
#include <StandardCPlusplus.h>
#include <deque>
#include "brick.hpp"

class blueprint {
private:
  std::deque<brick> _registered_bricks;
public:
  blueprint();
  ~blueprint();
  bool is_brick_useful(brick);
};

#endif
