#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

// Function to display menu
void display_menu();

// Changing to upper case
char change_case(char);

// Printing the array elements
void print_elem(const vector<int> &vec);

// Adding an element
void add_elem(vector<int> &vec);

// Smallest elem
void small_elem(const vector<int> &vec);

// Largest element
void largest_elem(const vector<int> &vec);

//Computing mean
void compute_mean(const vector<int> &vec);

//Clearing the list
void clear_list(vector<int> &vec);




int main (void){

  char choice {};
  
  vector<int> vec;

  do{
    display_menu(); //Function call to display menu
    
    cout<<"Enter your choice: ";
    cin>>choice;

    choice = change_case(choice); //Coverting to upper case
    
    if(choice == 'P'){
      print_elem(vec);
    }
    else if(choice == 'A'){
      add_elem(vec);
    }
    else if(choice == 'M'){
      compute_mean(vec);
    }
    else if(choice == 'S'){
      small_elem(vec);
    }
    else if(choice == 'L'){
      largest_elem(vec);
    }
    else if(choice == 'C'){
      clear_list(vec);
    }
    else if(choice == 'Q'){
      cout<< "Exiting!!!" <<endl<< "\t\t\tGOODBYE!!!"<<endl;
    }
    else{
      cout<<"Invalid Choice!!! Try again!!!"<< endl;
    }

  }while(choice != 'Q');  

  return 0;
}



void display_menu(){
  cout<<"\n\n========= Manipulations on list of numbers (Using vectors) ==========="<<endl;
  cout<<"P - Print numbers"<<endl;
  cout<<"A - Add a number to the list"<<endl;
  cout<<"M - Display the mean of the numbers"<<endl;
  cout<<"S - Display the smallest numbers"<<endl;
  cout<<"L - Display the largest numbers"<<endl;
  cout<<"C - Clearing the entered list"<<endl;
  cout<<"Q - Quit" <<endl<<endl;
  cout<<"======================================================================"<<endl;    
}

char change_case(char c){
  char c_upper {};
  if(islower(c)){
    //Converting to upper case
    c_upper = toupper(c);
  }
  else{
    c_upper = c;
  }
  return c_upper;
}


void print_elem(const vector<int> &vec){
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

void add_elem(vector<int> &vec){
  //Passing by reference
  cout<<"Enter the element to be added: ";
  int elem {0};
  cin>>elem;
  cout<< elem <<" is added to list"<<endl;
  //Adding the element to the list
  vec.push_back(elem);
}

void small_elem(const vector<int> &vec){

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

void largest_elem(const vector<int> &vec){
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


void compute_mean(const vector<int> &vec){
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

void clear_list(vector<int> &vec){
  cout<<"The list is cleared!!!"<<endl;
  vec.clear();
}
