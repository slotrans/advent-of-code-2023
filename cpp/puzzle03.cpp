#include <iostream>
#include "puzzle03.hpp"

using std::cout;
using std::endl;

int main() {
    int p1_answer = SumOfPartNumbers("../input/input03");
    cout << "(p1 answer) sum of part numbers: " << p1_answer << endl;

    int p2_answer = SumOfGearRatios("../input/input03");
    cout << "(p2 answer) sum of gear ratios: " << p2_answer << endl;

    return 0;
}
