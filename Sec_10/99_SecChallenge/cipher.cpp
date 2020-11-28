#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(void){

  string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

  string message {};
  cout << "Enter your message: ";
  getline(cin,message);

  cout << "\n\nEncrypting Message...\n\n";

  string encrypt {};



  //Going through the message
  for(auto c:message){
    if(isalpha(c)){//If it is alpha it has be encrypted
      
      //Finding the idx
      size_t idx = alphabet.find(c);
      if(idx != string::npos){ // Checking if char is found
	char c_encrypt = key.at(idx);
	encrypt.push_back(c_encrypt);
      } 
    }
    else{
      //No need for encryption
      encrypt.push_back(c);
    }
  }
  cout<< "Encrypted Message: "<<encrypt<< endl;

  //Decrypting
  cout << "\n\nDecrypting Message...\n\n";
  string decrypt {};

  for(auto c:encrypt){
    if(isalpha(c)){
      size_t idx = key.find(c);
      if(idx != string::npos){
	char c_decrypt = alphabet.at(idx);
	decrypt.push_back(c_decrypt);
      }
    }
    else{
      decrypt.push_back(c);
    }
  }


  cout<< "Encrypted Message: "<<decrypt<< endl;
  
  return 0;
}
