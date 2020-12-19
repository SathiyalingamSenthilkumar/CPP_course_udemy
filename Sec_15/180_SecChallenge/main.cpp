// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"

#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking Account
    vector<Checking_Account> checking_accounts;
    checking_accounts.push_back(Checking_Account {} );
    checking_accounts.push_back(Checking_Account {"Hulk"} );
    checking_accounts.push_back(Checking_Account {"Thor", 2000} );
    checking_accounts.push_back(Checking_Account {"Loki", 5000, 1.5} );

    display(checking_accounts);
    deposit(checking_accounts, 1000);
    withdraw(checking_accounts, 2000);

    // Trust
    vector<Trust_Account> Trust_accounts;
    Trust_accounts.push_back(Trust_Account {} );
    Trust_accounts.push_back(Trust_Account {"Spiderman"} );
    Trust_accounts.push_back(Trust_Account {"antman", 2000} );
    Trust_accounts.push_back(Trust_Account {"falcon", 5000, 5.0} );

    display(Trust_accounts);
    deposit(Trust_accounts, 1000);
    withdraw(Trust_accounts, 2000);

    cout<<"\n\nChecking the functionality of trust account:\n"<<endl;
    Trust_Account Sathya {"Sathya",1000,0.0};
    cout<<"Account Created:"<<Sathya<<endl;
    Sathya.deposit(5000);
    cout<<"Despositing 5000 to "<<Sathya<<endl;

    Sathya.deposit(8000);
    cout<<"Despositing 8000 to "<<Sathya<<endl;

    //Withdrawing a amount bigger than balacne
    cout<<"Trying to withdraw 15000 from Sathya"<<" :\n";
    if(Sathya.withdraw(15000)){
      cout<<"----       Success   -----"<< Sathya<<endl;
    }
    else{
      cout<<"--Failed due to insufficient funds--"<<Sathya<<endl;
    }

    //Withdrawing a amount bigger than balacne
    cout<<"Trying to withdraw 2000 from Sathya"<<" :\n";
    if(Sathya.withdraw(2000)){
      cout<<"----       Success   -----"<< Sathya<<endl;
    }
    else{
      cout<<"--Failed due to insufficient funds--"<<Sathya<<endl;
    }

//Withdrawing a amount bigger than balacne
    cout<<"Trying to withdraw 2000 from Sathya"<<" :\n";
    if(Sathya.withdraw(2000)){
      cout<<"----       Success   -----"<< Sathya<<endl;
    }
    else{
      cout<<"--Failed due to insufficient funds--"<<Sathya<<endl;
    }
    
//Withdrawing a amount bigger than balacne
    cout<<"Trying to withdraw 2000 from Sathya"<<" :\n";
    if(Sathya.withdraw(2000)){
      cout<<"----       Success   -----"<< Sathya<<endl;
    }
    else{
      cout<<"--Failed due to insufficient funds--"<<Sathya<<endl;
    }

    //Withdrawing a amount bigger than balacne
    cout<<"Trying to withdraw 2000 from Sathya"<<" :\n";
    Sathya.withdraw(2000);
    cout<<endl;
     
    

    
    return 0;
}

