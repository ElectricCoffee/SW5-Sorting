// The implementation file of pusher
#include "pusher.hpp"
pusher::pusher(uint8_t motor_pin, uint8_t tach_pin, uint16_t a_delay_length)
  : component(motor_pin), _pin(motor_pin) {
  _delay_length = a_delay_length;
  _motor_ptr = motor((uint8_t)128, (uint8_t)M2, (uint8_t)0);
  brick_to_push = 0;
  is_brick_empty = true;
}

pusher::~pusher() {
}

void pusher::open() {
  _slate = true;
  move_pusher(push_forward);
}

void pusher::close() {
  _slate = 0;
  move_pusher(push_backward);
}

void pusher::move_pusher(uint8_t forward) {
  uint32_t start_time = millis();

  if (forward == push_forward) {
    _motor_ptr.run_forward();
  } else if(forward == push_backward) {
    _motor_ptr.run_backward();
  } else {
    return;
  }
  while(start_time + 190 > millis()){
    //Serial.println("running motor");
  }
  _motor_ptr.stop();
}

/**
 * adds a brick which needs to be pushed
 * should be added after the last sensor
 * @param state the state the pusher needs to be in, true = open
 */
void pusher::add_state(bool state) {
  brick_to_push = new state_time(state, millis());
  is_brick_empty = false;
  /*
  Serial.print("current time is: ");
  Serial.print(temp_start_time);
  Serial.print("  registered time is: ");
  Serial.println(brick_to_push->start_delay);
  */
}

/**
 * checks if there are any bricks which needs to be acted on
 * will only do the act when the brick delay is up
 * @return true if the delay is over
 */
bool pusher::act_on_brick() {
  //Serial.print("st: ");
  //Serial.println(_state);
  //Serial.print(amount_bricks); Serial.println("pusher");

  if(!is_brick_empty){
    //Serial.print("size is: ");
    //Serial.println(brick_to_push->start_delay);
    if(brick_to_push->start_delay + _delay_length < millis()) {
      if(brick_to_push->state != _slate) {
        if(brick_to_push->state){
          open();
        } else{
          close();
        }
      } else {

      }
      delete brick_to_push;
      brick_to_push = 0;
      is_brick_empty = true;
      return true;
    }

  }
  return false;
}

bool pusher::operator==(const pusher &p) const {
  return /*photo_sensor == p.photo_sensor
    &&   */_pin == p._pin;
}
