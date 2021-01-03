// Section 20
// Challenge 3  
// Maps and Sets

#include <iostream>
#include <fstream>
#include <sstream> // string stream
#include <map>
#include <set>
#include <string>
#include <iomanip>

// Used for Part1
// Display the word and count from the 
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words) {
    std::cout << std::setw(12) << std::left << "\nWord"
                << std::setw(7) << std::right << "Count"<< std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair: words)
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the 
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
     std::cout << std::setw(12) << std::left << "\nWord"
                << "Occurrences"<< std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::left << "[ ";
        for (auto i: pair.second) 
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() {
    std::map<std::string, int> words;
    std::ifstream in_file {"./words.txt"};
    if (in_file) {
      std::string full_line;
      std::string str;
      std::string str_clean;

      while(std::getline(in_file,full_line)){ //Reading a line a time from file
	std::istringstream iss{full_line}; //string stream on line
	while(iss>>str){//reading the word from string stream
	  str_clean = clean_string(str);
	  auto it = words.find(str_clean);
	  if(it == words.end()){
	    //Element not in the map
	    words.insert(std::make_pair(str_clean,1)); //Inserting the word with count 1
	  }
	  else{
	    //it => is the iterator
	    it->second++;//The count is incremented
	  }
	  //The if block can be replaced with one line => words[str_clean]++; //adds the word if not present
	}
      }
      
      in_file.close();
      display_words(words);
    }
    else {
      std::cerr << "Error opening input file" << std::endl;
    }
}

void add_to_words(std::map<std::string, std::set<int>>& words,std::string& word,int line_no){
  auto it = words.find(word);
  if(it == words.end()){
    // Word not in words
    std::set<int> line {line_no};
    words.insert(std::make_pair(word,line));
  }
  else{
    it->second.insert(line_no);
  }
}

// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file {"./words.txt"};
    if (in_file) {
      std::string full_line;
      int line_count = 0;
      std::string str {};
      std::string str_clean {};
 
      while(std::getline(in_file,full_line)){
	line_count++;
	std::istringstream iss{full_line}; // Using string stream
	while(iss>>str){//Reading string from string stream
	  str_clean = clean_string(str);
	  add_to_words(words,str_clean,line_count);
	}
      }
      
      in_file.close();
      display_words(words);
    }
    else {
      std::cerr << "Error opening input file" << std::endl;
    }
}

int main() {
    part1();
    part2();
    return 0;
}

