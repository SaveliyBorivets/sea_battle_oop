#include "ship_placement_error.h"

Ship_placement_error::Ship_placement_error(const std::string& message): message{message} {}

const char* Ship_placement_error::what() const noexcept {
  return message.c_str();
}