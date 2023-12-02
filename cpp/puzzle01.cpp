#include <iostream>
#include "puzzle01.hpp"


int main(int argc, char** argv) {
    int part1_answer = SumForDocument("../input/input01");
    std::cout << "(p1 answer) sum of calibration values: " << part1_answer << std::endl;

    return 0;
}
