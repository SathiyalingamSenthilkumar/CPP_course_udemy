#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;

          //Operator overloading
    // == operator
    bool operator == (const Mystring& rhs);
    // != operator
    bool operator != (const Mystring& rhs);
    // < operator
    bool operator < (const Mystring& rhs);
    // > operator
    bool operator > (const Mystring& rhs);
    
    // - return lower case
    Mystring operator -(); //Unary operator

    // + Concatenate
    Mystring operator +(const Mystring &); //Binary Operator

    // += Operator Concatenate syntactic sugar
    Mystring& operator += (const Mystring & rhs);

    // * Repeat
    Mystring operator *(int);

    // *= Repeat syntactic sugar
    Mystring& operator *= (int);

    // Pre increment operator (making upper case)
    Mystring& operator ++();

    // Post increment operator (making upper case)
    Mystring operator ++(int);
    
    

};

#endif // _MYSTRING_H_
