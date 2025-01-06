
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using std::vector;
using std::map;

auto rules = vector<vector<int>>{
{47,53},
{97,13},
{97,61},
{97,47},
{75,29},
{61,13},
{75,53},
{29,13},
{97,29},
{53,29},
{61,53},
{97,53},
{61,29},
{47,13},
{75,47},
{97,75},
{47,61},
{75,61},
{47,29},
{75,13},
{53,13}
};
auto print_order = vector{75,47,61,53,29};

// vector.push_back() does for some reason not allow appending of two vectors to each other by default
void appendVector(vector<int> & v, const vector<int> & w){
  for(int i=0; i < w.size(); ++i){
    v.push_back(w[i]);
  }
}

bool verifyPrint(vector<int> page_order, map<int, vector<int>> constraints){
  std::reverse(page_order.begin(), page_order.end());
  auto banned_pages = vector<int>{};
  for (auto page : page_order) {
    appendVector(banned_pages, constraints[page]);
    auto it = std::find(banned_pages.begin(), banned_pages.end(), page);
    if (it != banned_pages.end()) {
      return false;
    }
  }
  return true;
  }



map<int, vector<int>> createConstraints(vector<vector<int>> rules){
  map<int, vector<int>> constraints;
  for(auto rule : rules){
    constraints[rule[0]].push_back(rule[1]);
  }
  return constraints;
}

int main(int argc, char *argv[]) {
  auto constraints = createConstraints(rules);
  std::cout << verifyPrint(vector{75,47,61,53,29}, constraints) << std::endl;        //should be true
  std::cout << verifyPrint(vector{97,61,53,29,13}, constraints) << std::endl;        //should be true
  std::cout << verifyPrint(vector{75,29,13}, constraints) << std::endl;              //should be true
  std::cout << verifyPrint(vector{75,97,47,61,53}, constraints) << std::endl;        //should be false
  std::cout << verifyPrint(vector{61,13,29}, constraints) << std::endl;              //should be false
  std::cout << verifyPrint(vector{97,13,75,29,47}, constraints) << std::endl;        //should be false
  return 0;
}

