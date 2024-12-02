#include <cstdint>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int64_t day02_part1_main(std::ifstream &iStream) {
    std::vector<std::vector<int>> reports;

    for (std::string line; std::getline(iStream, line); )  {
        std::vector<int> report;
        std::istringstream sLine(line);

        for (std::string rawLevel; std::getline(sLine, rawLevel, ' '); ) {

            int level = atoi(rawLevel.c_str());

            report.push_back(level);
        }

        reports.push_back(report);
    }

    int64_t acc(0);

    for (std::vector<int> report : reports) {
        if (! (std::is_sorted(report.begin(), report.end()) || std::is_sorted(report.begin(), report.end(), std::greater<>{})) ) {
            continue;
        }

        bool valid(true);
        for (size_t i(1); i != report.size(); ++i) {
            int d = abs(report[i-1] - report[i]);

            if (d == 0 || d > 3) {
                valid = false;
                break;
            }
        }

        if (valid) {
            acc += 1;
        }
    }

    return acc;
}

int main() {
    std::ifstream f("input.txt");

    std::cout << day02_part1_main(f) << std::endl;

    f.close();
    
    return 0;
}
