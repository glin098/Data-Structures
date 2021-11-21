#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <sstream>

void tokenize(std::string const &str, const char delim, std::vector<std::string> &out) { 
  // construct a stream from the string 
  std::stringstream ss(str); 
  std::string s; 
  while (std::getline(ss, s, delim)) { 
    out.push_back(s); 
  } 
} 

int main(){
  std::unordered_set <std::string> table;
  std::string input;
  std::cout << "Enter names (type \"Done\" when done): \n";
  getline (std::cin, input);
  
  while(input != "Done"){
    std::vector<std::string> words;
    tokenize(input, ' ', words);

    for(int i = 0; i < words.size(); i++)
    {
      std::string word = words[i];
      std::unordered_set<std::string>::const_iterator got = table.find(word);

      // if the name is not found in table, insert the input
      if(got == table.end()){
        table.insert(word); 
      }   
      //else if name is found, erase the input
      else{
        table.erase(word);
      }
    }
    std::cout << "Enter names (type \"Done\" when done): \n";
    getline (std::cin, input);
  }

  //print
  for(auto i = table.begin(); i != table.end(); i++){
    std::cout << *i << " ";
  }
} 
