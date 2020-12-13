#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1]; // +1 is for the null character
            std::strcpy(str, s);   //Strcpy also copies the null character
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
     : str{nullptr} {
  std::cout<<"COPY constructor is called for : "<< source.get_str()<<std::endl;
        str = new char[std::strlen(source.str )+ 1]; //Deep copy
        std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
  // string getter
 const char *Mystring::get_str() const { return str; }

 //Overloaded assignment operator
Mystring& Mystring::operator = (const Mystring & rhs){

  std::cout<<"COPY Assignment operator invoked for:"<<rhs.str<<std::endl;
  if(this == &rhs){
    //For checking for same object calls
    return *this; //Do not perform copy and simply returns the object
  }

  //Deleting the existing string
  delete [] this->str;
  //Creating new space on heap
  str = new char[std::strlen(rhs.get_str())+1];
  std::strcpy(str,rhs.get_str());
  
  return *this; //Returns to object that is calling this func (to allow chain assignments)
}


//Overloaded assignment operator (move)
Mystring& Mystring::operator = (Mystring && rhs){ //Overloading with move
  std::cout<<"MOVE Assignment operator for:"<<rhs.str<<std::endl;
  if(this == &rhs){
    return *this;
  }

  delete [] this->str;
  str = rhs.str; //No need for creating extra memory
  rhs.str = nullptr;
  return *this;
}

//Move constructor
Mystring::Mystring(Mystring && source)
  :str{source.str}{
  std::cout<<"Move constructor is called for : "<< source.get_str()<<std::endl;
  source.str = nullptr; //Stealing the pointer and nulling out source
}

