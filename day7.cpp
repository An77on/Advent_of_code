

#include <iostream>
#include <ostream>
#include <queue>
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

std::vector<int> calculate(std::stack<int> input) {
  auto results = vector<int>{};
  std::queue<int> output;
  auto lh = input.top(); input.pop();
  auto rh = input.top(); input.pop();
  //results from using operations on lh and rh, rh will always be a new value from the input equation
  // while lh will be results from previous computations stored in output, which will be a fifo queue while input is a lifo stack.
  output.push(lh + rh);
  output.push(lh * rh);

  // These are the values from the left-associate equations
  while (!input.empty()) {
    rh = input.top(); input.pop();
    auto end = output.size();
    for (int i = 0; i < end; i++) {
      //left hand is the results from previous computations
      lh = output.front(); output.pop();

      output.push(lh + rh);
      output.push(lh * rh);
    }
  }
  // convert it to a vector, there might be some implicit conversions
  while (!output.empty()) {
    results.push_back(output.front()); output.pop();
  }
  return results;
}


std::stack<int> convertToStack(vector<int> input) {
  std::stack<int> s;
  for (int i = input.size()-1; i > 0; i--) {
    s.push(input[i]);
  }
  return s;
}


int main(){
  auto working_value = input[7];
  auto s = convertToStack(working_value);
  auto candidates = calculate(s);
  for (auto c : candidates) {
    std::cout << c << std::endl;
  }


}