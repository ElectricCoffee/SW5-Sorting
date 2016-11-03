// The header file of memory
#ifndef memory_hpp
#define memory_hpp
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>
#include <deque>
#include "brick.hpp"

class memory {
private:
  std::vector<std::deque<brick>*> _queue;
  ~memory();
public:
  void enqueue(brick, uint8_t);
  brick dequeue(uint8_t);
  void add_conveyor();
  void remove_conveyor(uint8_t);
  memory(uint8_t);
};
#endif
