// The implementation file of component
#include "component.hpp"

component::component(uint8_t a_pin) {
  pin = a_pin;
}

bool component::detect_brick() {
  return digitalRead(pin) == HIGH;
}
