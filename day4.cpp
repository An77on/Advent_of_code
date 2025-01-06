#include <iostream>
#include <string>
#include <vector>
using std::vector;

auto input = vector<std::string>{
    "MMMSXXMASM",
    "MSAMXMSMSA",
    "AMXSXMAAMM",
    "MSAMASMSMX",
    "XMASAMXAMM",
    "XXAMMXXAMA",
    "SMSMSASXSS",
    "SAXAMASAAA",
    "MAMMMXMMMM",
    "MXMXAXMASX",
};



int main(int argc, char *argv[]) {

    auto matrix = vector<vector<char>>();
    //read in and populate the data inside matrix
    for (auto s : input) {
        auto temp = vector<char>();
        std::copy(s.begin(), s.end(), std::back_inserter(temp));
        matrix.push_back(temp);
    }

    auto strings = vector<std::string>();
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {

        }
    }

}



