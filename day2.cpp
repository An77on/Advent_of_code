#include <ios>
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
using std::vector;
auto data1 = vector<int> {7,6,4,2,1};
auto data2 = vector<int> {1, 2, 7, 8, 9};
auto data3 = vector<int> {9, 7, 6, 2, 1,};
auto data4 = vector<int> {1, 3, 2, 4, 5};
auto data5 = vector<int> {8,6,4,4,11};
auto data6 = vector<int> {1,3,6,7,9};

bool safetyCheck(vector<int> report) {
    //strictly increasing check
    if (!std::ranges::is_sorted(report.begin(), report.end())){
        // wish this one did not mutate, so I could just use one if case with the or operator, but these probably would return the same assembly code anyhow
        std::reverse(report.begin(), report.end());
        //strictly decreasing check (well increasing but the vector is reversed now)
        if (!std::ranges::is_sorted(report.begin(), report.end())) {
            return false;
        }
    }

    // check so that they are not increasing/decreasing by a value larger than 3
    for (int i = 0; i < report.size() -1; i++) {
        auto dif = std::abs(report[i+1] - report[i]);
        if (dif > 3) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << safetyCheck(data1) << '\n'; // supposed to be true
    std::cout << safetyCheck(data2) << '\n';// supposed to be fasle
    std::cout << safetyCheck(data3) << '\n';// supposed to be fasle
    std::cout << safetyCheck(data4) << '\n';// supposed to be fasle
    std::cout << safetyCheck(data5) << '\n';// supposed to be fasle
    std::cout << safetyCheck(data6) << '\n';// supposed to be true



}

