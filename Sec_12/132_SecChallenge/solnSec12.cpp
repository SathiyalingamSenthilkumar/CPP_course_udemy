#include <iostream>

using namespace std;

void print(int * arr, size_t n);

int * apply_all(int * arr1, size_t n1, int * arr2, size_t n2);


int main() {

  const size_t array1_size {5};
  const size_t array2_size {3};
    
  int array1[] {1,2,3,4,5};
  int array2[] {10,20,30};

  cout << "Array 1: " ;
  print(array1,array1_size);
    
  cout << "Array 2: " ;
  print(array2,array2_size);
    
  int *results = apply_all(array1, array1_size, array2, array2_size);
  constexpr size_t results_size {array1_size * array2_size};

  cout << "Result: " ;
  print(results, results_size);    
  cout << endl;

  delete [] results; //Deallocating the memory
  
  return 0;
}


void print(int * arr, size_t n){
  cout<<"[ ";
  for(size_t i = 0; i < n; i++){
    cout<<arr[i]<< " "; 
  }
  cout<<"]\n";
}

int * apply_all(int * arr1, size_t n1, int * arr2, size_t n2){
  size_t n_res = n1 * n2;
  int * arr_res {nullptr};
  arr_res = new int[n_res];

  size_t k = 0;
  for(size_t i = 0; i<n2; i++){//Outer loop
    for(size_t j = 0; j<n1; j++){
      arr_res[k] = arr2[i] * arr1[j];
      k++;
    }
  }
  
  return arr_res;
}
