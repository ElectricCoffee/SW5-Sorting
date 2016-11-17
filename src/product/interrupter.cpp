// The implementation of file interrupter
#include "interrupter.hpp"

interrupter::interrupter(uint8_t pin) : component(pin) {
  pinMode(pin, INPUT);
}

bool interrupter::detect_brick() {
  return digitalRead(pin) == HIGH;
}
