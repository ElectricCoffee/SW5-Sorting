#include "delay_handler.hpp"

delay_handler::delay_handler(unsigned long a_delay_length)
 : delay_length(a_delay_length){
}

bool delay_handler::should_do_now(unsigned long delay_start){
  if(delay_length + delay_start < millis()){
    return true;
  }
  return false;
}
