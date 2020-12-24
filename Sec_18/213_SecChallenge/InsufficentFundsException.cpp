#include "InsufficentFundsException.h"

const char* InsufficentFundsException::what() const noexcept{

  return "Insufficient funds after withdrawal";
  
}
