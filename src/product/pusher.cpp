// The implementation file of pusher
#include "pusher.hpp"
void pusher::add_brick(bool state){
  bricks_to_push.push_back(new push_states(millis(), state));
}

bool pusher::act_on_brick(){
  if(bricks_to_push.empty()){
    if(_delay_handler.should_do_now(bricks_to_push.front()->start_delay)){
      bricks_to_push.pop_front();
      if(bricks_to_push.front()->state != _is_open){
        if(bricks_to_push.front()->state){
          open();
        }
        else{
          close();
        }
      }
    }
    return true;
  }
  return false;
}
