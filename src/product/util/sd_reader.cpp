// The implementation of file sd_reader
#include "sd_reader.hpp"

sd_reader::sd_reader(const char *file_name) {
  _file = SD.open(file_name);
}

sd_reader::~sd_reader() {
  if (_file) {
    _file.close();
  }
}

status sd_reader::read_file_to_string(char *output) {
  char *method_name = "sd_reader::read_file_to_string";
  std::deque<char> de_buffer;
  std::deque<char>::iterator it;
  if (!_file) {
    return status::failure(method_name, "Could not open the file.");
  } else {
    while (_file.available()) {
      de_buffer.push_back((char)_file.read());
    }

    int file_len = de_buffer.size();

    void *success = realloc(output, file_len * sizeof(char*));

    if (success != NULL) {
      int i;
      for (i = 0, it = de_buffer.begin(); it != de_buffer.end(); it++, i++) {
        output[i] = *it;
      }
    } else {
      return status::failure(method_name, "Failed to reallocate string");
    }

    return status::success();
  }
}
