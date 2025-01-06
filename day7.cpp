

//TODO I should just use a binary tree, left child is addition and right child is multiplication, to verify which chain of operators are correct just check the leaves.
#include <algorithm>
#include <iostream>
#include <map>
#include <ostream>
#include <stack>
#include<vector>
using std::vector;
auto input = vector<vector<int>>{
{190, 10, 19},
{3267, 81, 40, 27},
{83, 1,7, 5},
{156, 1,5, 6},
{7290, 6, 8, 6, 15},
{161011, 16, 10, 13},
{192, 17, 8, 14},
{21037, 9, 7, 18, 13},
{292, 11, 6, 16, 20}
};

int calculate(std::stack<int> input) {
  std::stack<int> output;
  auto lh = input.top(); input.pop();
  auto rh = input.top(); input.pop();
  output.push(lh + rh);
  output.push(lh * rh);

  rh = input.top(); input.pop();
  for (int i = 0; i < output.size(); i++) {

  }
  

}


std::stack<int> convertToStack(vector<int> input) {
  std::stack<int> s;
  for (int i = input.size(); i > 0; i--) {
    s.push(input[i]);
  }
  return s;

}


int main(){
  auto working_value = input[1];
  auto s = convertToStack(working_value);

}