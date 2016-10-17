// The header file of blueprint
#ifndef blueprint_hpp
#define blueprint_hpp
#include <StandardCPlusplus.h>
#include <vector>
#include "brick.hpp"

class blueprint {
private:
  std::vector<brick> _registered_bricks;
public:
  blueprint();
  bool is_brick_useful(brick);
};

#endif
