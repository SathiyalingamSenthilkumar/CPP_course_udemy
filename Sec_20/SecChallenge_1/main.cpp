// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

template <typename T>
void disp(const T& elems){
  // A template display function for debug
  std::cout<<"[ ";
  for(const auto& elem:elems){
    std::cout<<elem<<" ";
  }
  std::cout<<"]"<<std::endl;
}


bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.

  std::deque<char> deq_back; //To fill using push_back
  std::deque<char> deq_front; //To fill using push_front =>reverses the string

  for(const auto& c:s){
    if(isalpha(c)){
      deq_back.push_back(toupper(c));
      deq_front.push_front(toupper(c));
    }
  }

  return deq_front == deq_back; // Both are same if s is palindrome
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;

    for(const auto& s : test_strings) {
      std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
