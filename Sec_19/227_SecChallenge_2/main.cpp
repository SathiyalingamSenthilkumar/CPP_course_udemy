// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>


struct Student{
  std::string name;
  std::string answer;
  int score; //To keep track of score
};

void print_students(std::vector<Student>&);

double compute_avg(std::vector<Student>&);

void compute_scores(std::vector<Student>& students,std::string& Ans_key);

int main() {
  
  std::ifstream in_file("responses.txt");

  if(!in_file){
    std::cerr<<"Error opening the file"<<std::endl;
    return 1; //Exiting main
  }
  
  std::vector<Student> students;
  /*
  students.push_back(Student{"Sathiya","ABCD",2});
  students.push_back(Student{"Suriya","ABCDE",3});
  */
  std::string Ans_key;
  std::string name;
  std::string ans;
  int count = 0;
  while(!in_file.eof()){
    if(count == 0){
      //first line is the key
      in_file>>Ans_key;
    }
    else{
      //reading name and answer
      in_file>>name;
      in_file>>ans;
      students.push_back(Student{name,ans,0});
    }
    count++;
  }

  compute_scores(students,Ans_key);
  
  print_students(students);

  std::cout<<std::endl<<std::endl;
  in_file.close();
  return 0;
}

void print_students(std::vector<Student> & students){
  std::cout<<std::setw(20)<<std::left<<"Student"
	   <<std::setw(10)<<std::right<<"Score"<<std::endl; // Total 30


  std::cout<<std::setfill('-');
  std::cout<<std::setw(30)<<"-"<<std::endl;
  std::cout<<std::setfill(' ');
	     

  for(const auto& stud:students){
    std::cout<<std::setw(20)<<std::left<<stud.name;
    std::cout<<std::setw(10)<<std::right<<stud.score<<std::endl;
  }
	     
  std::cout<<std::setfill('-');
  std::cout<<std::setw(30)<<"-"<<std::endl;
  std::cout<<std::setfill(' ');

  double avg = compute_avg(students);
  std::cout<<std::setw(20)<<std::left<<"Average score";
  std::cout<<std::setw(10)<<std::right<<avg<<std::endl;
}


double compute_avg(std::vector<Student>& students){
  int sum = 0;
  for(const auto& stud:students){
    sum += stud.score;
  }
  return static_cast<double>(sum)/students.size();
   
}

void compute_scores(std::vector<Student>& students,std::string& Ans_key){
  for (auto& stud:students){
    for(size_t i=0; i<Ans_key.length();i++){
      if(stud.answer.at(i)==Ans_key.at(i)){
	stud.score++;
      }
    }
  }
}
