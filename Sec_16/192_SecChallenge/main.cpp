// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    /*
    Account * ptr = new Savings_Account {"Sathiya_Savings",5000,5.0};
    cout<< *ptr <<endl;
    ptr->deposit(1000);
    cout<< *ptr <<endl;
    ptr->withdraw(1000);
    cout<< *ptr <<endl;
    delete ptr;
    ptr = nullptr;
    
    
    
    //reusing the ptr (Account *)
    ptr = new Checking_Account {"Sathya_CheckingAcc",5000};
    cout<< *ptr <<endl;
    ptr->deposit(1000);
    cout<< *ptr <<endl;
    ptr->withdraw(1000);
    cout<< *ptr <<endl;
    delete ptr;
    ptr = nullptr;
    
  
    //reusing the ptr (Account *)
    ptr = new Trust_Account {"Sathya_TrustAcc",5000,2};
    cout<< *ptr <<endl;
    ptr->deposit(1000);
    cout<< *ptr <<endl;
    ptr->withdraw(1000);
    cout<< *ptr <<endl;
    delete ptr;
    ptr = nullptr;
    */

    Account* ptr1 = new Savings_Account {"Sathiya_Savings",10000,5.0};
    Account* ptr2 = new Checking_Account {"Sathya_CheckingAcc",10000};
    Account* ptr3 = new Trust_Account {"Sathya_TrustAcc",10000,1};
    
    
    vector<Account*> ptrs {ptr1,ptr2,ptr3};

    display(ptrs);
    deposit(ptrs,5000);
    withdraw(ptrs,3000);
    
    delete ptr1;
    delete ptr2;
    delete ptr3;
    
    return 0;
}

