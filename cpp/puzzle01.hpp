#include <string>
#include <vector>
#include <cctype>
#include "aocutil.hpp"


int GetCalibrationValue(const std::string &line) {
    char first_digit;
    char last_digit;

    for(int i = 0; i < line.size(); i++) {
        if(isdigit(line[i])) {
            first_digit = line[i];
            break;
        }
    }
    for(int i = line.size()-1; i >= 0; i--) {
        if(isdigit(line[i])) {
            last_digit = line[i];
            break;
        }
    }

    char calibration_value[2] {first_digit, last_digit};
    return stoi(std::string(calibration_value));
}


int SumForDocument(const std::string &filename) {
    std::vector<std::string> lines = ReadFileAsLines(filename);

    int sum = 0;
    for(std::string line : lines) {
        sum += GetCalibrationValue(line);
    }

    return sum;
}
