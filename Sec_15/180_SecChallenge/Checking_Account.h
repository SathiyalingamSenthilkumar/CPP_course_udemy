// Checking Account 
#ifndef _CHECK_ACCOUNT_H_
#define _CHECK_ACCOUNT_H_
#include <iostream>
#include <string>
#include "Account.h"

class Checking_Account:public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
private:   
  static constexpr const char *def_name = "Unnamed Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_fee = 1.50;

protected:
    double fee;
public:
  Checking_Account(std::string name = def_name, double balance = def_balance, double fee = def_fee);
  //Inherits deposit

  bool withdraw(double amount);

};
#endif  //_CHECKING_ACCOUNT_H_
