// The implementation file of brick
#include "brick.hpp"

brick::brick(int col, int x, int y, int z) {
  color  = col;
  size_x = x;
  size_y = y;
  size_z = z;
}

bool brick::operator ==(const brick &that) const {
  return color  == that.color
    &&   size_x == that.size_x
    &&   size_y == that.size_y
    &&   size_z == that.size_z;
}
