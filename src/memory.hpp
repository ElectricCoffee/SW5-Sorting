// The header file of memory
#ifndef memory_hpp
#define memory_hpp
class memory {
  public:
    void enque(brick, short); //short is for which conveyor it is
    brick deque(short);
    void add_conveyor();
    void remove_conveyor(short); //short is which conveyor to remove
    memory(short); //constructor takes as input the amount of conveyors to start with
  private:
    std::vector<std::deque< brick > > the_queue;
#endif
