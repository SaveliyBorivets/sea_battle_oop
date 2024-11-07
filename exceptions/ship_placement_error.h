#ifndef NAVAL_WARFARE_EXCEPTIONS_SHIP_PLACEMENT_ERROR_H_
#define NAVAL_WARFARE_EXCEPTIONS_SHIP_PLACEMENT_ERROR_H_

#include <exception>
#include <string>

class Ship_placement_error: public std::exception
{
 public:
  Ship_placement_error(const std::string& message);
  const char* what() const noexcept override;
 private:
  std::string message;
};

#endif //NAVAL_WARFARE_EXCEPTIONS_SHIP_PLACEMENT_ERROR_H_
