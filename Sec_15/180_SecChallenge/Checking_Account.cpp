#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee)
  : Account(name,balance), fee{fee}{
  
}

//Withdraw:
//  The fee is added to the amount to be withdrawn
//  The final amount is withdrawn from the account

bool Checking_Account::withdraw(double amount){
  amount += fee; //Adding the fee with the amount
  return Account::withdraw(amount);
}

std::ostream& operator << (std::ostream& os,const Checking_Account& account){
  os<<"[Checking_Account: " << account.name << ": " << account.balance << ", " <<"withdrawal fee: " <<account.fee<< "$]";
  return os;
}
