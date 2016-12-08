#include "delay_handler.hpp"

delay_handler::delay_handler(const unsigned long a_delay_length) : delay_length(a_delay_length){
  //it's really only here for assigning the const
}

bool delay_handler::should_do_now(){
  if(delay_length + delay_start < millis()){
    delay_start = 0;
    return true;
  }
  return false;
}

void delay_handler::start_delay(){
  if(delay_start != 0){
    delay_start = millis();
  }
}
