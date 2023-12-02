#include <iostream>
#include <fstream>
#include <string>
#include <fmt/core.h>


std::vector<std::string> ReadFileAsLines(const std::string &filename) {
    std::vector<std::string> lines_out;

    std::ifstream infile;
    infile.open(filename);

    std::string temp_line;
    if(infile.is_open()) {
        while(std::getline(infile, temp_line)) {
            lines_out.push_back(temp_line);
        }
    }
    else {
        throw std::runtime_error(fmt::format("could not open file: {}", filename));
    }

    infile.close();

    //trim trailing newline
    if(lines_out.size() > 1 && lines_out.back() == "") {
        lines_out.pop_back();
    }

    return lines_out;
}
