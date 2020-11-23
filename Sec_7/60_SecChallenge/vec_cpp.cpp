#include <iostream>
#include <vector>

using namespace std;

int main(){

  //Creating two vectors
  vector<int> vector1;
  vector<int> vector2;

  //Adding 10 and 20 to vector1
  vector1.push_back(10);
  vector1.push_back(20);

  cout << "The vector1 elements are: "<<vector1.at(0)<<" and "<<vector1.at(1)<<endl;
  cout << "Size of vector 1: "<<vector1.size()<<endl;
  
  //Adding 100 and 200 to vector2
  vector2.push_back(100);
  vector2.push_back(200);

  cout << "The vector2 elements are: "<<vector2.at(0)<<" and "<<vector2.at(1)<<endl;
  cout << "Size of vector 2: "<<vector2.size()<<endl;
  
  //Declaring an empty 2D vecotr
  vector<vector<int>> vector_2d;

  //Adding the vectors dynamically to 2D vector
  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  cout<<"\n\nThe elements of vector_2d are: "<<endl;
  cout<<vector_2d.at(0).at(0)<<"\t"<<vector_2d.at(0).at(1)<<endl;
  cout<<vector_2d.at(1).at(0)<<"\t"<<vector_2d.at(1).at(1)<<endl;  
 

  cout<<"\n*** Changing vector1 data ******"<<endl;
  vector1.at(0) = 1000;
    
  cout<< "Printing the vector_2d Data again after modifying vector 1"<<endl;
  cout<<"\n\nThe elements of vector_2d now are: "<<endl;
  cout<<vector_2d.at(0).at(0)<<"\t"<<vector_2d.at(0).at(1)<<endl;
  cout<<vector_2d.at(1).at(0)<<"\t"<<vector_2d.at(1).at(1)<<endl;  

  
  return 0;
}
