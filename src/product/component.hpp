// The header file of component
#ifndef component_hpp
#define component_hpp

struct component {
  virtual int detect_brick();

  virtual bool operator==(const component) const;
};

#endif
