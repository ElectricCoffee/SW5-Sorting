// The header file of sensor
#ifndef sensor_hpp
#define sensor_hpp
#include <Arduino.h>
#include "component.hpp"
#include "brick_data_getter.hpp"

struct sensor : public component, public brick_data_getter {
  sensor(uint8_t); //for initialising it

  //bool operator==(const sensor) const override;
};
#endif
