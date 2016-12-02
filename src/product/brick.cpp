// The implementation file of brick
#include "brick.hpp"

brick::brick(unsigned int col, unsigned int x, unsigned int y, unsigned int z) {
  color  = col;
  size_x = x;
  size_y = y;
  size_z = z;
}

brick::brick() {
  color = 0;
  size_x = 0;
  size_y = 0;
  size_z = 0;
}

brick brick::combine_with(const brick &other) const {
  brick new_brick = *this;
  new_brick.color  = other.color  ?: color;
  new_brick.size_x = other.size_x ?: size_x;
  new_brick.size_y = other.size_y ?: size_y;
  new_brick.size_z = other.size_z ?: size_z;

  return new_brick;
}

bool brick::operator ==(const brick &that) const {
  return color  == that.color
    &&   size_x == that.size_x
    &&   size_y == that.size_y
    &&   size_z == that.size_z;
}

bool brick::operator !=(const brick &that) const {
  return !(*this == that);
}

/**
 * @return An instance of a brick with all fields set to 0
 */
brick brick::empty_brick() {
  return brick();
}
