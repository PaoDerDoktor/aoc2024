#include <cstdint>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int64_t day01_part1_main(std::ifstream &iStream) {
    std::vector<int> left;
    std::vector<int> right;
    

    for (std::string line; std::getline(iStream, line); )  {
        size_t spacePos = line.find("   ");
        left.push_back(std::atoi(line.substr(0, spacePos).c_str()));
        right.push_back(std::atoi(line.substr(spacePos+3, line.length()-(spacePos+3)).c_str()));
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    int acc(0);
    for (size_t i = 0; i != left.size(); ++i) {
        acc += abs(left[i] - right[i]);
    }

    return acc;
}

int main() {
    std::ifstream f("input.txt");

    std::cout << day01_part1_main(f) << std::endl;

    f.close();
    
    return 0;
}
