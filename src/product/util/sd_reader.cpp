// The implementation of file sd_reader
#include "sd_reader.hpp"

/**
 * Creates a file pointer to a file on the SD card
 * @param file_name is the name of the input file.
 * Note that the file name should be in all caps for it to be read.
 */
sd_reader::sd_reader(const char *file_name) {
  pinMode(SS_PIN, OUTPUT);

  while(!SD.begin(SS_PIN));
  _file = SD.open(file_name);
 Serial.println("Success!");
}

/**
 * Makes sure the file is closed again if it exists
 */
sd_reader::~sd_reader() {
  if (_file) {
    _file.close();
  }
}

/**
 * Reads the contents of the SD Reader's file handle to a string.
 * @param output is the output-string as an output-parameter.
 * @returns a status::success if successful,
 * or a status::failure if something went wrong
 */
status sd_reader::read_file_to_string(char *output) {
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

  // resize and nullify the output buffer before copying data into it
  // this is done to ensure there's enough room for the read string,
  // and that there's a null-terminator at the end of the string.
  void *result_ptr = realloc(output, bytes);
  memset(output, '\0', bytes);

  if (result_ptr == NULL) {
    return status::failure(method_name, "Failed to resize the output");
  }

  str.toCharArray(output, strlen);

  Serial.println(output);

  return status::success();
}
