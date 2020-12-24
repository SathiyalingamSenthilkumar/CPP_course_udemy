#ifndef __INSUFFICIENT_FUNDS_EXCEPTION_H__
#define __INSUFFICIENT_FUNDS_EXCEPTION_H__
#include <exception>

class  InsufficentFundsException: public std::exception
{
public:
  InsufficentFundsException() = default;
  ~InsufficentFundsException()= default;
  virtual const char * what() const noexcept override;
};

#endif // __INSUFFICIENT_FUNDS_EXCEPTION_H__
