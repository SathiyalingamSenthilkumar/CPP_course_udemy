// Section 17 -  Challenge 1
#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const {return data; }
    ~Test() {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

int main() {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make(){
  return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num){
  std::shared_ptr<Test> ptr;
  int n;
  for(int i=0; i < num; i++){
    std::cout<<"Enter the data point-"<<i+1<<" : ";
    std::cin>>n;
    /* Assigning temp ptr and reseting
    ptr = std::make_shared<Test>(n);
    vec.push_back(ptr); //Pushing back of the vector
    ptr.reset();//Resetting the pointer
    */
    
    //Efficient way using move semantics
    vec.push_back(std::make_shared<Test>(n));
  }
}

void display(const std::vector<std::shared_ptr<Test>>&vec){
  std::cout<<"\n\nDisplaying vector data"<<std::endl;
  std::cout<<"======================="<<std::endl;

  for(const auto& elem:vec){//elem would be a reference to shared_ptr<Test>
    std::cout<<elem->get_data()<<std::endl;
  }
  
  std::cout<<"======================="<<std::endl;
}
