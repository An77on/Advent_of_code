//
// Created by Anton on 2025-01-07.
//
#include <iostream>
#include <ostream>
#include <vector>
using std::vector;

auto puzzleInput = vector<vector<int>>{
  {8,9,0,1,0,1,2,3},
  {7,8,1,2,1,8,7,4},
  {8,7,4,3,0,9,6,5},
  {9,6,5,4,9,8,7,4},
  {4,5,6,7,8,9,0,3},
  {3,2,0,1,9,0,1,2},
  {0,1,3,2,9,8,0,1},
  {1,0,4,5,6,7,3,2}
};

bool valid(vector<vector<int>> board, int row, int col){
  if(row >= 0 && col >= 0 && row < board.size() && col < board[row].size()){
    return true;
  } else {
    return false;
  }
}


auto validNeightbours(vector<vector<int>> board, int row, int col){
  vector<vector<int>> neighbours;
  if (valid(board, row, col)) {
    auto height = board[row][col];

  // we are just cheking the four cardinal directions and no diagonals so these can be seperate for loops
  for(int i = row - 1; i <= row+1; i++){
    if(valid(board,row,i) && board[i][col] == height + 1) {
      neighbours.push_back(vector<int>{i,col});
      }
  }
  for(int i = col - 1; i <= col+1; i++){
    if(valid(board,i,col) && board[row][i] == height + 1){
      neighbours.push_back(vector<int>{row,i});
    }
  }
  }
  return neighbours;
  }



int main() {
  std::cout << validNeightbours(puzzleInput, 0, 2).size() << std::endl;


  return 0;
}
