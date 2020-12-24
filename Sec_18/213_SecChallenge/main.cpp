#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

using namespace std;

int main() {
  try{
    auto Acc_ptr1 = make_unique<Checking_Account>(Checking_Account("Sathya",1000));
    cout<<*Acc_ptr1<<endl;
    
    auto Acc_ptr2 = make_unique<Checking_Account>(Checking_Account("Sathya",-1000));//Throw exception illegal bal
    cout<<*Acc_ptr2<<endl;
    
  }
  catch(const IllegalBalanceException& ex){
    cout<<ex.what()<<endl;
  }

  try{
    auto Acc_ptr = make_unique<Savings_Account>(Savings_Account("Batman",500));
    cout<<*Acc_ptr<<endl;
    Acc_ptr->withdraw(1000); // should throw execption Insufficientfund
    cout<<*Acc_ptr<<endl;
  }
  catch(const InsufficentFundsException& ex){
  //catch (const exception & ex){  //Even this will work dynamic binding
    cout<<ex.what()<<endl;
  }
  
  cout << "Program completed successfully" << endl;
  return 0;
}

