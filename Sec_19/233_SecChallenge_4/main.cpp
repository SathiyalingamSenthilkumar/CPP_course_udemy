// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>

#include <fstream>
#include <string>
#include <iomanip>

int main() {
  std::ifstream in_file{"romeoandjuliet.txt"};
  std::ofstream out_file{"./Copy_romeoandjuliet.txt"};

  if(!in_file){
    std::cerr<<"ERROR: While opening the source file to be copied"<<std::endl;
    return 1;
  }

  if(!out_file){
    std::cerr<<"ERROR: While opening the target file"<<std::endl;
    return 1;
  }

  size_t line_no = 0;
  std::string line;

  while(getline(in_file,line)){
    line_no++;
    out_file<<std::setw(8)<<std::left<<line_no;
    out_file<<line<<std::endl;
  }

  std::cout<<"Done copying!!"<<std::endl;
  in_file.close();
  out_file.close();
  return 0;
}

