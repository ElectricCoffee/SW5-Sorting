// The header file of brick
#ifndef brick_hpp
#define brick_hpp

/* structs in C++ are classes that are public by default
 * a struct was used intentionally here, don't change to class. */
struct brick {
  int color;
  int size_x;
  int size_y;
  int size_z;
  brick(int, int, int, int);
  brick combine_with(const brick&) const;
  bool operator ==(const brick &) const;
  bool operator !=(const brick &) const;
  static brick empty_brick();
};

#endif
