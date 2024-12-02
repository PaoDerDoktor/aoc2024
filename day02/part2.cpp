#include <cstdint>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool validate_report(const std::vector<int> toValidate) {
    if (! (std::is_sorted(toValidate.begin(), toValidate.end()) || std::is_sorted(toValidate.begin(), toValidate.end(), std::greater<>{})) ) {
        return false;
    }

    bool valid(true);
    for (size_t i(1); i != toValidate.size(); ++i) {
        int d = abs(toValidate[i-1] - toValidate[i]);

        if (d == 0 || d > 3) {
            valid = false;
            break;
        }
    }

    return valid;
}

int64_t day02_part2_main(std::ifstream &iStream) {
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
        if (validate_report(report)) {
            acc += 1;
            continue;
        }

        bool validTol(false);
        for (size_t e(0); e != report.size(); ++e) {
            std::vector<int> tolReport;
            
            for (size_t i(0); i != report.size(); ++i) {
                if (i != e) {
                    tolReport.push_back(report[i]);
                }
            }

            if (validate_report(tolReport)) {
                validTol = true;
                break;
            }
        }

        if (validTol) {
            acc += 1;
        }
    }

    return acc;
}

int main() {
    std::ifstream f("input.txt");

    std::cout << day02_part2_main(f) << std::endl;

    f.close();
    
    return 0;
}
