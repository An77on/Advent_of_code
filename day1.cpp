#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;

// examples given to verify the solution
auto input1 = vector<int>{3,4,2,1,3,3};
auto input2 = vector<int>{4,3,5,3,9,3};

vector<int> compareNumbers(vector<int> v1, vector<int> v2) {
    // a vector to store the intermidiate results
    vector<int> result = vector<int>{};
    // sort the two vectors to more easily compare the distance between them
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    //compare the distance of all individual elemtents
    for (int i = 0; i < v1.size(); i++) {
        result.push_back(std::abs(v1[i] - v2[i]));

    }
    return result;

}


int main() {

    // sum up the distances for the vector
    auto result = compareNumbers(input1, input2);
    auto totalDistance = 0;
    for (auto element : result) {totalDistance += element;}
    std::cout << totalDistance << std::endl;



    return 0;
}
