#include <iostream>
#include <string>

using namespace std;

int main(){

  string str {};
  cout << "Enter the string: ";
  getline(cin,str);

  cout<< "The pyramid pattern: "<<endl;
  size_t n {str.length()};
  
  size_t idx {};

  for(size_t i=0; i< n; i++){
    idx = 0;
    for(size_t j=0; j< n; j++){
      if((i+j)>= n-1){
	cout<<str.at(idx);
	idx++;
	
      }
      else{
	cout<< " "; 
      } 
    }

    for(size_t j=n; j<(2*n-1);j++){
      if((j-i)<= n-1){//Print element
	size_t idx_cal = n-1-(j-i);
	cout<<str.at(idx_cal);
      }
      else{
	cout<<" ";
      }
    }
    cout<<endl;
  }
  
  return 0;
}
