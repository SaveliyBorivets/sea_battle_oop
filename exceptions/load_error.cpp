#include "load_error.h"

Load_error::Load_error(const std::string& message): message{message} {}

const char* Load_error::what() const noexcept {
  return message.c_str();
}