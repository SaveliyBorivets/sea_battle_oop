#include "attack_out_of_bound.h"

Attack_out_of_bound::Attack_out_of_bound(const std::string& message): message{message} {}

const char* Attack_out_of_bound::what() const noexcept {
  return message.c_str();
}