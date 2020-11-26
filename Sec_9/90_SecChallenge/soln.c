#include <iostream>
#include <vector>

using namespace std;

int main (void){

  char choice {};
  
  vector<int> vec;

  do{
    cout<<"\n\n========= Manipulations on list of numbers (Using vectors) ==========="<<endl;
    cout<<"P - Print numbers"<<endl;
    cout<<"A - Add a number to the list"<<endl;
    cout<<"M - Display the mean of the numbers"<<endl;
    cout<<"S - Display the smallest numbers"<<endl;
    cout<<"L - Display the largest numbers"<<endl;
    cout<<"C - Clearing the entered list"<<endl;
    cout<<"Q - Quit" <<endl<<endl;
    cout<<"======================================================================"<<endl;
    
    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice == 'p' || choice == 'P'){
      if(vec.size() == 0){
	// The vector is empty
	cout<< "[] - the list is empty" <<endl;
      }
      else{
	cout<<"[ ";
	for(auto val:vec){
	  cout<<val<<" ";
	}
	cout<<"]"<<endl;
      }
    }
    else if(choice == 'a' || choice == 'A'){
      cout<<"Enter the element to be added: ";
      int elem {0};
      cin>>elem;
      cout<< elem <<" is added to list"<<endl;
      //Adding the element to the list
      vec.push_back(elem);
    }
    else if(choice == 'm' || choice == 'M'){
      double mean {0};
      double sum {0};
      if(vec.size() != 0){
	//Computing the mean
	for(auto val:vec){
	  sum += val;
	}
	mean = sum/vec.size();
	cout<< "The mean is: " << mean<<endl;
      }
      else{
	cout << "Unable to calculate the mean - no data"<<endl;
      }
    }
    else if(choice == 's' || choice == 'S'){
      if(vec.size() != 0){
	int small = vec.at(0);
	for( auto val: vec){
	  if(val < small){
	    small = val;
	  }
	}
	cout <<"The smallest number is "<< small << endl;
      }
      else{
	cout<< "Unable to determine the smallest number - list is empty" <<endl;
      }
    }
    else if(choice == 'l' || choice == 'L'){
      if(vec.size() != 0){
	int large = vec.at(0);
	for(auto val: vec){
	  if(val > large){
	    large = val;
	  }
	}
	cout <<"The largest number is "<< large << endl;
      }
      else{
	cout<< "Unable to determine the largest number - list is empty" <<endl;
      }

    }
    else if(choice == 'c' || choice == 'C'){
      cout<<"The list is cleared!!!"<<endl;
      vec.clear();
    }
    else if(choice == 'q' || choice == 'Q'){
      cout<< "Exiting!!!" <<endl<< "\t\t\tGOODBYE!!!"<<endl;
    }
    else{
      cout<<"Invalid Choice!!! Try again!!!"<< endl;
    }
    
  }while(choice != 'q' && choice != 'Q');

  
  return 0;
}
