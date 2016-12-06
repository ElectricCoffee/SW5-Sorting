// The implementation of file sd_reader
#include "sd_reader.hpp"

sd_reader::sd_reader(const char *file_name) {
  pinMode(SS_PIN, OUTPUT);

  while(!SD.begin(SS_PIN));
  _file = SD.open(file_name);
 Serial.println("Success!");
}

sd_reader::~sd_reader() {
  if (_file) {
    _file.close();
  }
}

status sd_reader::read_file_to_string(char *output) {
  //COL:02430737 LEN:00005254
  const char *method_name = "sd_reader::read_file_to_string";

  if (!_file) {
    return status::failure(method_name, "Failed to open the file.");
  }

  String str = _file.readString();
  unsigned int strlen = str.length();
  size_t bytes = (strlen + 1) * sizeof(char*);

  if (strlen == 0) {
    return status::failure(method_name, "Read 0 bytes from file, is this right?");
  }

  void *result_ptr = realloc(output, bytes);
  memset(output, '\0', bytes);

  if (result_ptr == NULL) {
    return status::failure(method_name, "Failed to resize the output");
  }

  str.toCharArray(output, strlen);

  Serial.println(output);

  return status::success();
}
