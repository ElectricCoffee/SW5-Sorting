// The header file of brick
#ifndef brick_hpp
#define brick_hpp

#include <Arduino.h>
// til daniel: uint8_t == byte.
typedef uint8_t brick_bytes[4];

/* structs in C++ are classes that are public by default
 * a struct was used intentionally here, don't change to class. */
struct brick {
  //uint32_t color;
  uint8_t color_red;
  uint8_t color_green;
  uint8_t color_blue;
  uint8_t size_x;
/*
  uint8_t size_y;
  uint8_t size_z;
*/
  brick(uint8_t color_red, uint8_t color_green, uint8_t color_blue, uint8_t x/*, uint8_t y, uint8_t z*/);
  brick();
  brick combine_with(const brick&) const;
  bool operator ==(const brick &) const;
  bool operator !=(const brick &) const;
  static brick empty_brick();
  static brick from_byte_array(const brick_bytes);
};

#endif
