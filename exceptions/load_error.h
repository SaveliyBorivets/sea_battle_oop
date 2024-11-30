#ifndef NAVAL_WARFARE_EXCEPTIONS_LOAD_ERROR_H_
#define NAVAL_WARFARE_EXCEPTIONS_LOAD_ERROR_H_

#include <exception>
#include <string>

class Load_error: public std::exception
{
 public:
  Load_error(const std::string& message);
  const char* what() const noexcept override;
 private:
  std::string message;
};

#endif //NAVAL_WARFARE_EXCEPTIONS_LOAD_ERROR_H_
