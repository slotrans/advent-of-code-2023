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

int GetCalibrationValue2(const std::string &line) {
    char first_digit;
    char last_digit;

    for(int i = 0; i < line.size(); i++) {
        if(isdigit(line[i])) {
            first_digit = line[i];
            break;
        }
        if(line.substr(i, 3) == "one")   { first_digit = '1'; break; }
        if(line.substr(i, 3) == "two")   { first_digit = '2'; break; }
        if(line.substr(i, 5) == "three") { first_digit = '3'; break; }
        if(line.substr(i, 4) == "four")  { first_digit = '4'; break; }
        if(line.substr(i, 4) == "five")  { first_digit = '5'; break; }
        if(line.substr(i, 3) == "six")   { first_digit = '6'; break; }
        if(line.substr(i, 5) == "seven") { first_digit = '7'; break; }
        if(line.substr(i, 5) == "eight") { first_digit = '8'; break; }
        if(line.substr(i, 4) == "nine")  { first_digit = '9'; break; }
    }
    for(int i = line.size()-1; i >= 0; i--) {
        if(isdigit(line[i])) {
            last_digit = line[i];
            break;
        }
        if(line.substr(i, 3) == "one")   { last_digit = '1'; break; }
        if(line.substr(i, 3) == "two")   { last_digit = '2'; break; }
        if(line.substr(i, 5) == "three") { last_digit = '3'; break; }
        if(line.substr(i, 4) == "four")  { last_digit = '4'; break; }
        if(line.substr(i, 4) == "five")  { last_digit = '5'; break; }
        if(line.substr(i, 3) == "six")   { last_digit = '6'; break; }
        if(line.substr(i, 5) == "seven") { last_digit = '7'; break; }
        if(line.substr(i, 5) == "eight") { last_digit = '8'; break; }
        if(line.substr(i, 4) == "nine")  { last_digit = '9'; break; }
    }

    char calibration_value[2] {first_digit, last_digit};
    return stoi(std::string(calibration_value));
}

//bleh. Could avoid this by passing in the calibration value function but that's a pain. Copy paste!
int SumForDocument2(const std::string &filename) {
    std::vector<std::string> lines = ReadFileAsLines(filename);

    int sum = 0;
    for(std::string line : lines) {
        sum += GetCalibrationValue2(line);
    }

    return sum;
}
