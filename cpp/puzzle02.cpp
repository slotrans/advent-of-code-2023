#include <iostream>
#include "puzzle02.hpp"

using std::cout;
using std::endl;

int main() {
    int part1_answer = P1Answer("../input/input02");
    cout << "(p1 answer) sum of possible game IDs: " << part1_answer << endl;

    int part2_answer = P2Answer("../input/input02");
    cout << "(p2 answer) sum of power of minimum cube sets: " << part2_answer << endl;

    return 0;
}
