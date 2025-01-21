//
// Created by Anton on 2025-01-07.
//
#include <iostream>
#include <vector>
#include <ostream>
#include <stack>

using std::vector;

auto puzzleInput = vector<vector<int> >{
    {8, 9, 0, 1, 0, 1, 2, 3},
    {7, 8, 1, 2, 1, 8, 7, 4},
    {8, 7, 4, 3, 0, 9, 6, 5},
    {9, 6, 5, 4, 9, 8, 7, 4},
    {4, 5, 6, 7, 8, 9, 0, 3},
    {3, 2, 0, 1, 9, 0, 1, 2},
    {0, 1, 3, 2, 9, 8, 0, 1},
    {1, 0, 4, 5, 6, 7, 3, 2}
};

bool valid(const vector<vector<int> > &board, const int row, const int col) {
    if (row >= 0 && col >= 0 && row < board.size() && col < board[row].size()) {
        return true;
    }
    return false;
}


auto validNeighbours(const vector<vector<int> > &board, const int row, const int col) {
    vector<vector<int> > neighbours;
    if (valid(board, row, col)) {
        const auto height = board[row][col];

        // we are just checking the four cardinal directions and no diagonals so these can be separate for loops
        for (int i = row - 1; i <= row + 1; i++) {
            if (valid(board, row, i) && board[i][col] == height - 1) {
                neighbours.push_back(vector<int>{i, col});
            }
        }
        for (int i = col - 1; i <= col + 1; i++) {
            if (valid(board, i, col) && board[row][i] == height - 1) {
                neighbours.push_back(vector<int>{row, i});
            }
        }
    }
    return neighbours;
}

void pushOntoStack(std::stack<vector<int>, vector<vector<int> > > &stack, const vector<vector<int> >& toPush) {
    for (const auto& value: toPush) {
        stack.push(value);
    }
}

bool isDistinct(const vector<vector<int> >& board, const vector<vector<int>>& list, const vector<int>& toCheck) {
    for (const auto& elem : list) {
        if (elem == toCheck) {
            return false;
        }
    }
    return true;

}


int main() {
    std::stack<vector<int>, vector<vector<int> > > m_stack;
    auto counter = 0;
    for (auto row = 0; row <8; row++) {
        for (auto col = 0; col < 8; col++) {
            if (puzzleInput[row][col] == 9) { //starting point
                pushOntoStack(m_stack, validNeighbours(puzzleInput, row, col));
                std::vector<std::vector<int> > checkedSpaces; // we only want distinct destinations for each starting point
                while (!m_stack.empty()) {
                    auto curr = m_stack.top();
                    m_stack.pop();
                    const auto storedValue = puzzleInput[curr[0]][curr[1]];
                    if (storedValue == 0 && isDistinct(puzzleInput, checkedSpaces, curr)) {
                        checkedSpaces.push_back(curr);
                        counter++;
                    } else
                        pushOntoStack(m_stack, validNeighbours(puzzleInput, curr[0], curr[1]));
                }
            }
        }
    }
    std::cout << counter << '\n';
    return 0;
}
