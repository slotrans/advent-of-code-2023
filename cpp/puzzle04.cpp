#include <iostream>
#include "puzzle04.hpp"

using std::cout;
using std::endl;

int main() {
    int p1_answer = SumOfPoints("../input/input04");
    cout << "(p1 answer) sum of points on scratch cards: " << p1_answer << endl;

    return 0;
}