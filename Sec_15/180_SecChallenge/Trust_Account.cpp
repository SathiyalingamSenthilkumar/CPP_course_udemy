#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
  :Savings_Account(name,balance,int_rate),withdraw_count{0}{
  
}

bool Trust_Account::deposit(double amount){
  if(amount >= 5000){
    amount += 50; //50$ bonus
  }
  return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
  if(withdraw_count < 3){
    if(Savings_Account::withdraw(amount)){
      //If successful
      withdraw_count++;
      return true;
    }
    else{
      return false;
    }
  }
  else{
    std::cout<<"Withdrawal count limit reach for "<<*this;
    return false; // No withdraw
  }
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account){
  os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate<<"%,"<<" Withdraw count: "<< account.withdraw_count<< " (limit = "<<Trust_Account::withdrawal_limit<<")"<< "]";
  return os;
}


