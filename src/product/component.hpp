// The header file of component
#ifndef component_hpp
#define component_hpp

struct component {
  void detect_brick();

  virtual bool operator==(const component) const;
};

#endif
