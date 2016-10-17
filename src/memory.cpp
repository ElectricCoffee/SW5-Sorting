// The implementation file of memory
#include "memory.hpp"

memory::memory(short amount_conveyors){ //just to give it correct size at start
  the_queue.resize(amount_conveyors);
  for(int i = 0; i < amount_conveyors; i++){
    add_conveyor();
  }
}

void memory::enque(brick the_brick, short the_conveyor){
  if(the_queue.size >= amount_conveyors){ //to ensure proper access
    the_queue[the_conveyor].push_back(the_brick);
  }
}

brick memory::deque(short the_conveyor){
  if(the_queue.size >= amount_conveyors){
    temp_brick = the_queue[the_conveyor].[0];
    the_queue[the_conveyor].pop_front(); //this doesn't actually return anything, kinda stupid
    the_queue[the_conveyor].shrink_to_fit(); //if it's too slow then could remove this, linear growth
    return temp_brick;
  }
}

void memory::add_conveyor(){
  the_queue.push_back(new std::deque<brick>);
}

void memory::remove_conveyor(short the_conveyor){ //not saving any of the deleted data, dont run on existing conveyors
  if(the_queue.size >= the_conveyor){
    the_queue.erase(the_queue.begin() + the_conveyor -1); //begin sets iterator first place
  } else{
    return null;
  }
}


