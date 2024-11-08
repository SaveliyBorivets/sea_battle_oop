#ifndef NAVAL_WARFARE_EXCEPTIONS_ATTACK_OUT_OF_BOUND_H_
#define NAVAL_WARFARE_EXCEPTIONS_ATTACK_OUT_OF_BOUND_H_

#include <exception>
#include <string>

class Attack_out_of_bound: public std::exception
{
 public:
  Attack_out_of_bound(const std::string& message);
  const char* what() const noexcept override;
 private:
  std::string message;
};

#endif //NAVAL_WARFARE_EXCEPTIONS_ATTACK_OUT_OF_BOUND_H_
