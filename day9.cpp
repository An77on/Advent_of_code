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
  std::string result;
  for(int i = 0; i < input.size(); i++) {
    auto c = input[i];
    // if we find a '.' char we can compress by inserting the last character that is not a '.' character.
    if(c == '.') {
      auto index = input.find_last_not_of('.');

      // break so it does not continue to iterate on our inserted '.' characters.
      if (index < i) {
        break;
      }

      // move the last valid character to the empy slot "compress"
      auto nextChar = input[index];
      input.erase(input.begin() + index);
      input[i] = nextChar;
      input.push_back('.');
    }
  }

  return input;
}

int main() {
  auto s1 = convertToIDRepresentation(puzzle_input);
  std::cout << s1 << std::endl;
  auto s2 = compress(s1);
  std::cout << s2 << std::endl;
  std::cout << puzzle_solution << std::endl;
}