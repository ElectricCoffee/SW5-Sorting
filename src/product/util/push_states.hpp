#ifndef push_states_hpp
#define push_states_hpp
#include<Arduino.h>

enum push_state { CLOSED, OPEN };

class state_time {
public:
  const push_state state;
  const uint16_t start_delay; //the millis() time when the brick passed the last sensor
  state_time(push_state, uint16_t);
};
#endif
