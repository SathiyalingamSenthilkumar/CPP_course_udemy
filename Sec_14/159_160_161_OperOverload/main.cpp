// Section 14
// Mystring - starting point
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {

  Mystring empty {"Stooge"};                      // no-args constructor
    Mystring larry("Larry");             // overloaded constructor
    Mystring stooge;
      
    //Mystring stooge1 {empty};            // copy constructor 
    //Mystring stooge2 {move(empty)};   //Move Constructor

    cout<<"=================================================="<<endl;
    cout<<"\nLarry and Stooge Before assingment:"<<endl;
    larry.display();
    stooge.display();

    //Assignment operator
    stooge = larry;

    cout<<"\nLarry and Stooge AFTER  assingment:"<<endl;
    larry.display();
    stooge.display();

    cout<<"=================================================="<<endl;
    
    Mystring s1("s1");
    Mystring s2("s2");
    Mystring s3("s3");
    cout<<"=================================================="<<endl;
    cout<<"\nThree strings:"<<endl;
    s1.display();
    s2.display();
    s3.display();

    s1 = s3 = s2; // Chain assignment

    cout<<"\n\nPerforming chain assignment s1 = s3 = s2, we get:"<<endl;
    s1.display();
    s2.display();
    s3.display();
    cout<<"=================================================="<<endl;
    
    //String
    Mystring assign;
    cout<<"=================================================="<<endl;    
    cout<<"\n\nBefore assigning => assign: ";
    assign.display();
    
    assign = "This is new"; //Assigning a string will create a temporary overloaded
                            // constructor.. then assignment will be done

    cout<<"\n\nAfter assigning => assign: ";
    assign.display();
    cout<<"=================================================="<<endl;    
    
    return 0;
}

