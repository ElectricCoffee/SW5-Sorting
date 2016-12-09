#ifndef delay_handler_hpp
#define delay_handler_hpp
#include <Arduino.h>

class delay_handler {
public:
  bool should_do_now(unsigned long);
  const unsigned long delay_length;
  delay_handler(unsigned long);
private:
  //unsigned long delay_start = 0;


};

#endif
