#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include <iostream>
#include "Savings_Account.h"

// Trust Account is a type of Savings Account
//  
// Withdraw - same as a regular savings account
// Deposit:
//     Same as savings account but give a $50 bonus
//     for more than $5000$ deposits

// Limitation of 3 withdrawals
//

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double withdrawal_limit = 3;
protected:
    int withdraw_count; //Keeps count of withdraw this should be init to zero
public:
    Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    

    bool deposit(double amount);
    
    bool withdraw(double amount);
};

#endif // _TRUST_ACCOUNT_H_
