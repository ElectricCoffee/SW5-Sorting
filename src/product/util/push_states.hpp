#ifndef push_states_hpp
#define push_states_hpp
#include<Arduino.h>
class push_states{
public:
  bool state; //how the pusher should be when the brick arrives, true = open
  unsigned long start_delay; //the millis() time when the brick passed the last sensor
  push_states(bool, unsigned long);
};
#endif
