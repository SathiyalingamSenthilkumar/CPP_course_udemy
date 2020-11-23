#include <iostream>

int main(void){

  const float price_smallroom {25};
  const float price_largeroom {35};
  const float Tax {6}; // In percentage
  const int valid_period {30}; // Days

  std::cout << "Enter the number of small rooms to be cleaned: ";

  int no_smallroom {0};
  std::cin>> no_smallroom;

  std::cout << "Enter the number of large rooms to be cleaned: ";

  int no_largeroom {0};
  std::cin>> no_largeroom;

  float cost_smallroom = price_smallroom * no_smallroom; 
  float cost_largeroom = price_largeroom * no_largeroom;

  float total_cost_before_tax = cost_smallroom + cost_largeroom;

  float total_cost = total_cost_before_tax + (Tax/100) * total_cost_before_tax; 
  
  std::cout<< std::endl;
  std::cout<< "=================================================="<<std::endl;
  std::cout<< "Number of small rooms: "<< no_smallroom<< std::endl;
  std::cout<< "Numver of large rooms: "<< no_largeroom<< std::endl;

  std::cout<< "Price per small room: $" << price_smallroom<< std::endl;
  std::cout<< "Price per large room: $" << price_largeroom<< std::endl;

  std::cout<< "Cost before tax: $" << total_cost_before_tax<< std::endl;
  std::cout << "Tax :"<< Tax<<"\%"<< std::endl;
  
  std::cout<< "=================================================="<<std::endl;

  std::cout << "Total estimate: $"<<total_cost<< std::endl;
  std::cout << "This estimate is valid for "<< valid_period <<" days"<<std::endl;
  
  std::cout<< "=================================================="<<std::endl;
  
  
  return 0;
}
