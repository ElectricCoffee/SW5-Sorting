// The implementation file of pusher
#include "pusher.hpp"
pusher::pusher(unsigned long a_delay_length) {
  _delay_handler = new delay_handler(a_delay_length);
  amount_bricks = 0;
}
/**
 * adds a brick which needs to be pushed
 * should be added after the last sensor
 * @param state the state the pusher needs to be in, true = open
 */
void pusher::add_brick(bool state){
  open();
  close();
  bricks_to_push.push_back(new push_states(millis(), state));
  amount_bricks++; //NEITHER SIZE NOR EMPTY METHOD IN DEQUE WORKED
}

/**
 * checks if there are any bricks which needs to be acted on
 * will only do the act when the brick delay is up
 * @return true if the delay is over
 */
bool pusher::act_on_brick(){
  Serial.print(amount_bricks); Serial.println("pusher");

  if(amount_bricks != 0){
    if(_delay_handler->should_do_now(bricks_to_push.front()->start_delay)){
      Serial.println("its time");
      bricks_to_push.pop_front();
      amount_bricks--;
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
    Serial.println("not yet");
  }
  return false;
}
