// The header file of size
#ifndef size_hpp
#define size_hpp
#include "sensor.hpp"

class size : private sensor {
private:
  void start_measuring;	
  void stop_measuring;
  unsigned long current_time;
  unsigned int newest_size;
public:
  unsigned int get_size();
  void check_measuring;
};

#endif
