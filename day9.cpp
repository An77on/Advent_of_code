//
// Created by Anton on 2025-01-07.
//
#include <algorithm>
#include <string>
#include <iostream>
std::string puzzle_input = "2333133121414131402";
std::string puzzle_solution = "0099811188827773336446555566..............";

std::string convertToIDRepresentation(std::string input){
  auto informationBlock = 0;
  auto id = 0 +48;
  std::string result = "";
  for (auto c : input){
    int ic = int(c) -48; // due to returning the ascii representation
    //even i.e. in this case it is a text block and not a block of freetext
    if(informationBlock% 2 == 0){
      for(int i = 0; i < ic; i++){
        result.push_back(id);
      }
      id++;
    } else {
      for(int i = 0; i < ic; i++){
        result.push_back('.');
      }
    }
    informationBlock++;
  }
  return result;
  }

std::string compress(std::string input) {
  std::string result = "";

  for(int i = 0; i < input.size(); i++) {
    auto c = input[i];

    if(c == '.') { //an empty space we can recreate
      auto index = result.find_last_not_of('.');
      auto nextChar = result[index];
      result.erase(index + 1);
      result.push_back(nextChar);
    } else {
      result.push_back(c);
    }
  }

  return result;
}

int main() {
  auto s1 = convertToIDRepresentation(puzzle_input);
  std::cout << s1 << std::endl;
  auto s2 = compress(s1);
  std::cout << s2 << std::endl;
  std::cout << puzzle_solution << std::endl;
}