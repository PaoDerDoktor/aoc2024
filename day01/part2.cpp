#include <cstdint>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int64_t day01_part2_main(std::ifstream &iStream) {
    std::vector<int> left;
    std::map<int, int> right;
    

    for (std::string line; std::getline(iStream, line); )  {
        size_t spacePos = line.find("   ");
        left.push_back(std::atoi(line.substr(0, spacePos).c_str()));

        int rightRaw = (std::atoi(line.substr(spacePos+3, line.length()-(spacePos+3)).c_str()));

        if (right.count(rightRaw) != 0) {
            right.at(rightRaw) += 1;
        } else {
            right.insert(std::make_pair(rightRaw, 1));
        }
    }

    int acc(0);
    for (size_t i = 0; i != left.size(); ++i) {
        if (right.count(left[i]) != 0) {
            acc += left[i]*right.at(left[i]);
        }
    }

    return acc;
}

int main() {
    std::ifstream f("input.txt");

    std::cout << day01_part2_main(f) << std::endl;

    f.close();
    
    return 0;
}
