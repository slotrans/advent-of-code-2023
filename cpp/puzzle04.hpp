#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <pystring.h>
#include "aocutil.hpp"

using std::string;
using std::vector;
using std::unordered_set;


struct ScratchCard {
    int cardNum;
    unordered_set<int> winningNumbers;
    vector<int> numbersYouHave;
    //
    bool operator==(const ScratchCard&) const = default;
} ;

ScratchCard ParseCard(const string &line) {
    ScratchCard card;

    vector<string> colon_split;
    pystring::split(line, colon_split, ":");
    card.cardNum = std::stoi(colon_split[0].substr(5, colon_split[0].size()));

    vector<string> pipe_split;
    pystring::split(colon_split[1], pipe_split, "|");

    vector<string> winning_num_temp;
    pystring::split(pipe_split[0], winning_num_temp, " ");
    for(string s : winning_num_temp) {
        string s2 = pystring::strip(s);
        if(s2.size() == 0) {
            continue;
        }
        int temp = std::stoi(s2);
        card.winningNumbers.insert(temp);
    }

    vector<string> numbers_you_have_temp;
    pystring::split(pipe_split[1], numbers_you_have_temp, " ");
    for(string s : numbers_you_have_temp) {
        string s2 = pystring::strip(s);
        if(s2.size() == 0) {
            continue;
        }

        int temp = std::stoi(s2);
        card.numbersYouHave.push_back(temp);
    }

    return card;
}

int CardScore(const ScratchCard &card) {
    int points = 0;
    vector<int> winners;

    for(int num_to_check : card.numbersYouHave) {
        if(card.winningNumbers.contains(num_to_check)) {
            winners.push_back(num_to_check);
        }
    }
    if(winners.size() > 0) {
        points = pow(2, winners.size()-1);
    }

    return points;
}

int SumOfPoints(const string &filename) {
    vector<string> lines = ReadFileAsLines(filename);

    int total_points = 0;

    for(string line : lines) {
        ScratchCard card = ParseCard(line);
        int points = CardScore(card);
        total_points += points;
    }

    return total_points;
}