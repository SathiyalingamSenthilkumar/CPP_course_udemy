#include <iostream>

using namespace std;

int main(){

  cout<< "Enter the amount in cents: ";
  int amount {0};
  cin>>amount;

  int dollars {0};    //100 cents
  int quarters {0};   //25 cents
  int dimes {0};      //10 cents
  int nickels {0};    //5 cents
  int pennies {0};    //1 cent

  dollars = amount / 100;
  amount %= 100;

  quarters = amount / 25;
  amount %= 25;

  dimes = amount / 10;
  amount %= 10;

  nickels = amount / 5;
  amount %= 5;

  //remaining is the pennies
  pennies = amount;

  // Printing
  cout << "\nThe denominations can be as follows:"<<endl;

  cout<< "Dollars: "<< dollars <<endl;
  cout<< "Quarters: "<< quarters<<endl;
  cout<< "Dimes: "<< dimes<<endl;
  cout<< "Nickels: "<< nickels<<endl;
  cout<< "Pennies: "<< pennies<<endl;
  
  return 0;
}
