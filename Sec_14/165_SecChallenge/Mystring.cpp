#include <iostream>
#include <cstring>
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
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}



//Operator overloading
// == operator
bool Mystring::operator == (const Mystring & rhs){
  if(std::strcmp(this->str, rhs.str) == 0){
    return true;
  }
  else{
    return false;
  }
}

// != operator
bool Mystring::operator != (const Mystring & rhs){
  if(std::strcmp(this->str, rhs.str) == 0){
    return false;
  }
  else{
    return true;
  }
}

// <  operator
bool Mystring::operator < (const Mystring & rhs){
  if(std::strcmp(this->str, rhs.str) < 0){
    return true;
  }
  else{
    return false;
  }
}

// >  operator
bool Mystring::operator > (const Mystring & rhs){
  if(std::strcmp(this->str, rhs.str) > 0){
    return true;
  }
  else{
    return false;
  }
}

// - Return lower case (Unary operator)
Mystring Mystring::operator -(){
  char * temp_buf = new char[std::strlen(str)+1];
  std::strcpy(temp_buf,this->str);
  for(unsigned i=0; i< std::strlen(str); i++){
    temp_buf[i]=std::tolower(str[i]); // Copying the lower case
  }
  Mystring temp (temp_buf); //Creating a temporary object of temp

  delete [] temp_buf; //Freeing up the temporary buffer
  return temp;
}


// + Concatenate
Mystring Mystring::operator +(const Mystring & rhs){
  char * temp_buf = new char[std::strlen(this->str)+std::strlen(rhs.str)+1];
  std::strcpy(temp_buf,this->str);//Copying the 1st string
  std::strcat(temp_buf,rhs.str); //Appending the second string

  Mystring temp (temp_buf);
  delete [] temp_buf;  
  return temp;
}


// += Operator Concatenate syntactic sugar
Mystring& Mystring::operator += (const Mystring & rhs){
  char * temp_buf = new char[std::strlen(this->str)+std::strlen(rhs.str)+1];
  strcpy(temp_buf,this->str); //Copying lhs
  strcat(temp_buf,rhs.str);   //Appending the RHS
  Mystring temp {temp_buf};
  *this = temp;

  delete [] temp_buf; //Clearing the temp buffer
  return *this;
}


// * Repeat
Mystring Mystring::operator * (int n){
  char * temp_buf = new char[std::strlen(this->str)*n+1];

  strcpy(temp_buf,this->str); //Copying for 1st time
  
  for(int i=0; i<n-1; i++){
    strcat(temp_buf,this->str); //Concatenating for n-1 times
  }
  Mystring temp{temp_buf};

  delete [] temp_buf; // Deallocating the temp buf
  return temp;
}

// *= Repeat syntactic sugar

Mystring& Mystring::operator *= (int n){
  *this = *this * n; //using the overloaded operator
  return *this;
}

// Pre increment operator (making upper case)
Mystring & Mystring::operator ++(){
  for(unsigned i=0; i<std::strlen(this->str);i++){
    this->str[i] = std::toupper(this->str[i]);
  }
  return * this;
}

// Post increment operator (making upper case)
Mystring Mystring::operator ++(int){ 
  Mystring temp{*this};
  ++(*this); //Incrementing
  return temp; //Returning old value before incrementing
}
