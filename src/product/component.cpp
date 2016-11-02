// The implementation file of component
#include "component.hpp"

component::component(uint8_t a_pin) {
  pin = a_pin;
}

bool component::detect_brick() {
  return digitalRead(pin) == HIGH;
}

bool component::operator ==(const component &comp) const {
  // if they share the same pin, they're probably the same component
  return pin == comp.pin;
}

bool component::operator !=(const component &comp) const {
  return pin != comp.pin;
}
