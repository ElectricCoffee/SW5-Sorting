// The header file of brick
#ifndef brick_hpp
#define brick_hpp

/* structs in C++ are classes that are public by default
 * a struct was used intentionally here, don't change to class. */
struct brick {
  unsigned int color;
  unsigned int size_x;
  unsigned int size_y;
  unsigned int size_z;
  brick(unsigned int c, unsigned int x, unsigned int y, unsigned int z);
  brick();
  brick combine_with(const brick&) const;
  bool operator ==(const brick &) const;
  bool operator !=(const brick &) const;
  static brick empty_brick();
};

#endif
