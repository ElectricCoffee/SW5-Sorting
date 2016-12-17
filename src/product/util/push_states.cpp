#include "push_states.hpp"

state_time::state_time(push_state a_state, uint16_t a_start_delay)
  : state(a_state), start_delay(a_start_delay) {}
