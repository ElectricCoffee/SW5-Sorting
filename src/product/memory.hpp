// The header file of memory
#ifndef memory_hpp
#define memory_hpp
#include <StandardCplusplus.h>
#include <vector>
#include <deque>
#include "brick.hpp"

class memory {
  public:
    void enqueue(brick, short); //short is for which conveyor it is
    brick dequeue(short);
    void add_conveyor();
    void remove_conveyor(short); //short is which conveyor to remove
    memory(short); //constructor takes as input the amount of conveyors to start with
  private:
    std::vector<std::deque<brick>* > _queue;
    ~memory(); //deconstructor
};
#endif
