// Section 19
// Challenge 3
// Word counter
#include <iostream>

#include <fstream>
#include <string>

bool is_susbstr_in_word (const std::string&, const std::string&);

int main(int argc, char ** argv) {
  if(argc == 1){
    std::cerr<<"ERROR:File name not entered"<<std::endl;
    std::cerr<<"SOLVE: Run executable as: ./WordSearch FILENAME"<<std::endl;
    return 1; //Exiting main
  }
  else if(argc>2){
    std::cerr<<"ERROR: More than required arguments entered"<<std::endl;
    std::cerr<<"SOLVE: Run executable as: ./WordSearch FILENAME"<<std::endl;    
    return 1; //Exiting main
  }

  std::string Filename {argv[1]}; //Enters the file name as std string

  //Opeing the file
  std::ifstream in_file(Filename);

  if(!in_file){
    //File not opened
    std::cerr<<"Error with opening the file!!"<<std::endl;
    return 1; //Exiting main
  }

  std::string search_4_substr {};
  std::cout<<"Enter the substring to search for: ";
  std::cin>>search_4_substr;

  int num_words_searched {0};
  int num_times_found {0};

  std::string word_read{};
  
  //Reading the file
  while(in_file>>word_read){
    num_words_searched++; //increamenting the count
    if(is_susbstr_in_word(search_4_substr,word_read)){
      num_times_found++; //incrementing count
    }
  }

  std::cout<<num_words_searched<<" words were searched."<<std::endl;
  std::cout<<"The substring was found "<<num_times_found<<" times."<<std::endl;

  in_file.close();
  std::cout<<std::endl<<std::endl;
  return 0;
}

bool is_susbstr_in_word (const std::string& substr,const std::string& word){
  size_t idx_found = word.find(substr); //finds the substring
  return (idx_found == std::string::npos)? false:true;
}
