// The implementation file of brick
#include "brick.hpp"

#define BYTESIZE 8

enum brick_index{RED, GREEN, BLUE, SIZE};

brick::brick(uint8_t col_red,uint8_t col_green, uint8_t col_blue, uint8_t x/*, uint8_t y, uint8_t z*/) {
//  color  = col;
  color_red = col_red;
  color_green = col_green;
  color_blue = col_blue;
  size_x = x;
  /*
  size_y = y;
  size_z = z;
  */
}

brick::brick() {
  //color  = 0;
  color_red = 0;
  color_green = 0;
  color_blue = 0;
  size_x = 0;
  /*
  size_y = 0;
  size_z = 0;
  */
}

brick brick::combine_with(const brick &other) const {
  brick new_brick  = *this;
  //new_brick.color  = other.color  ?: color;
  new_brick.color_red = other.color_red ?: color_red;
  new_brick.color_green = other.color_green ?: color_green;
  new_brick.color_blue = other.color_blue ?: color_blue;
  new_brick.size_x = other.size_x ?: size_x;
  /*
  new_brick.size_y = other.size_y ?: size_y;
  new_brick.size_z = other.size_z ?: size_z;
  */
  return new_brick;
}

bool brick::operator ==(const brick &that) const {
  return color_red  == that.color_red
    &&   color_green  == that.color_green
    &&   color_blue  == that.color_blue
    &&   size_x == that.size_x;
    /*
    &&   size_y == that.size_y
    &&   size_z == that.size_z;
    */
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

brick brick::from_byte_array(const brick_bytes arr) {
  brick br;
  br.color_red  = arr[RED];
  br.color_green  = arr[GREEN];
  br.color_blue  = arr[BLUE];
  br.size_x = arr[SIZE];
  return br;
}
