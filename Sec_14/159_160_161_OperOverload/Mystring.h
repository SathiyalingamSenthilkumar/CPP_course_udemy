#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                      // No-args contstructor
    Mystring(const char *s);                         // Overloaded contstructor              
    Mystring(const Mystring &source);                // Copy constructor
    ~Mystring();                                     // Destructor
    void display() const;
    int get_length() const;                          // getters
    const char *get_str() const;

    //Overloaded assignment operator(copy)
    Mystring& operator = (const Mystring & rhs); //Overloading with copy

    //Overloaded assignment operator (move)
    Mystring& operator = (Mystring && rhs); //Overloading with move

    //Move constructor
    Mystring(Mystring && source); //R-value reference
};

#endif // _MYSTRING_H_
