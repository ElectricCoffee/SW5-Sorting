// The implementation file of pusher
#include "pusher.hpp"
/**
 * adds a brick which needs to be pushed
 * should be added after the last sensor
 * @param state the state the pusher needs to be in, true = open
 */
void pusher::add_brick(bool state){
  bricks_to_push.push_back(new push_states(millis(), state));
}

/**
 * checks if there are any bricks which needs to be acted on
 * will only do the act when the brick delay is up
 * @return true if the delay is over
 */
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
      return true;
    }
  }
  return false;
}
