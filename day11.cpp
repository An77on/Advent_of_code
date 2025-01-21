//
// Created by Anton on 2025-01-21.
//
#include <iostream>
#include <vector>

auto puzzleInput = std::vector<int>{125,17};

auto applyRule(int input) {
    std::vector<int> output;
    if (input == 0)
        output.push_back(1);
    else if (std::to_string(input).length() % 2 == 0) {
        auto temp = std::to_string(input).substr(0, std::to_string(input).length() / 2);
        output.push_back(std::stoi(temp));
        output.push_back(std::stoi(
            std::to_string(input).substr(std::to_string(input).length() / 2, std::to_string(input).length())));
    } else
        output.push_back(input * 2024);
    return output;
}

int main() {
    auto input = puzzleInput;
    std::vector<int> result;
    for (int i = 0; i < 25; i++) {
        result = std::vector<int>{};
        for (auto value: input) {
            for (auto resultValue: applyRule(value)) {
                result.push_back(resultValue);
            }
        }
        input = result;
    }
    std::cout << result.size() << std::endl;
    return 0;
}
