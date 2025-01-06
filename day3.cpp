#include <iostream>
#include  <string>
#include <regex>
int main(int argc, char *argv[]) {
    std::string s = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";
    //regex to match anywhere in string starting with mul(, then some logic for integers of length 1-3, separated by , then once again integers of length 1-3.
    std::regex r(R"((\mul\(\d{1,3},\d{1,3}\)))");
    auto words_begin = std::sregex_iterator(s.begin(),s.end(),r);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
          << std::distance(words_begin, words_end)
          << " occurences\n";

    for (auto it = words_begin; it != words_end; it++) {
        auto match = *it;
        auto match_str = match.str();
        std::cout << "Matched string: " << match_str << "\n";

    }
}
