#include "invalid_ability_usage.h"

Invalid_ability_usage::Invalid_ability_usage(const std::string& message): message{message} {}

const char* Invalid_ability_usage::what() const noexcept {
  return message.c_str();
}
