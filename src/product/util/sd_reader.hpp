// The header file of sd_reader
#ifndef sd_reader_hpp
#define sd_reader_hpp
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <StandardCplusplus.h>
#include <deque>
#include "status.hpp"

#define LINE_LEN 26
#define SS_PIN 53

class sd_reader {
  File _file;
public:
  sd_reader(const char*);
  ~sd_reader();

  status read_file_to_string(char*);
};

#endif
