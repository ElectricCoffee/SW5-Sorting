#ifndef push_states_hpp
#define push_states_hpp
#include<Arduino.h>

//enum push_state { OPEN, CLOSED };

class state_time {
public:
  const bool state;
  const uint32_t start_delay; //the millis() time when the brick passed the last sensor
  state_time(bool, uint32_t);
};
#endif
