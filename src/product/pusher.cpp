// The implementation file of pusher
#include "pusher.hpp"
pusher::pusher(uint8_t motor_pin, uint8_t tach_pin, uint16_t a_delay_length)
    : component(motor_pin), _pin(motor_pin) {
  _delay_handler = new delay_handler(a_delay_length);
  _motor_ptr     = new motor(MAX_SPEED, motor_pin, tach_pin);
  amount_bricks = 0;
}

pusher::~pusher() {
  delete _delay_handler;
  delete _motor_ptr;
}

void pusher::open() {
  move_pusher(FORWARD);
}

void pusher::close() {
  move_pusher(BACKWARD);
}

void pusher::move_pusher(uint8_t forward) {
  uint16_t start_time = millis();

  if (forward == FORWARD) {
    _motor_ptr->run_forward();
  } else if(forward == BACKWARD) {
    _motor_ptr->run_backward();
  } else {
    return;
  }

  while(start_time + 190 > millis()){
    //Serial.println("running motor");
  }
  _motor_ptr->stop();
}

/**
 * adds a brick which needs to be pushed
 * should be added after the last sensor
 * @param state the state the pusher needs to be in, true = open
 */
void pusher::add_state(bool state) {
  bricks_to_push.push_back(new push_states(millis(), state));
  amount_bricks++; //NEITHER SIZE NOR EMPTY METHOD IN DEQUE WORKED
}

/**
 * checks if there are any bricks which needs to be acted on
 * will only do the act when the brick delay is up
 * @return true if the delay is over
 */
bool pusher::act_on_brick() {
  //Serial.print(amount_bricks); Serial.println("pusher");

  if(amount_bricks != 0){
    if(_delay_handler->should_do_now(bricks_to_push.front()->start_delay)){
      //Serial.println("its time");
      bricks_to_push.pop_front();
      amount_bricks--;
      if(bricks_to_push.front()->state != _is_open){
        if(bricks_to_push.front()->state){
          open();
        } else{
          close();
        }
      }
      return true;
    }
    //Serial.println("not yet");
  }
  return false;
}

bool pusher::operator==(const pusher &p) const {
  return photo_sensor == p.photo_sensor
    &&   _pin == p._pin;
}
