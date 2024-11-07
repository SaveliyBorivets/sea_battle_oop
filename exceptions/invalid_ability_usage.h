#ifndef NAVAL_WARFARE_EXCEPTIONS_INVALID_ABILITY_USAGE_H_
#define NAVAL_WARFARE_EXCEPTIONS_INVALID_ABILITY_USAGE_H_

#include <exception>
#include <string>

class Invalid_ability_usage: public std::exception
{
 public:
  Invalid_ability_usage(const std::string& message);
  const char* what() const noexcept override;
 private:
  std::string message;
};

#endif //NAVAL_WARFARE_EXCEPTIONS_INVALID_ABILITY_USAGE_H_
