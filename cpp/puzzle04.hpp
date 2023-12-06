#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <pystring.h>
#include "aocutil.hpp"

using std::string;
using std::vector;
using std::unordered_set;
using std::unordered_map;


struct ScratchCard {
    int cardNum;
    int copies = 1;
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

int NumWinners(const ScratchCard &card) {
    vector<int> winners;

    for(int num_to_check : card.numbersYouHave) {
        if(card.winningNumbers.contains(num_to_check)) {
            winners.push_back(num_to_check);
        }
    }

    return winners.size();
}

int CardScore(const ScratchCard &card) {
    int points = 0;

    int num_winners = NumWinners(card);
    if(num_winners > 0) {
        points = pow(2, num_winners-1);
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

void ApplyWinnings(const ScratchCard &card, unordered_map<int, ScratchCard> &cardDeck, int n_times) {
    int num_winners = NumWinners(card);

    //e.g. Card 1 has 4 winners, so loop through cards 2,3,4,5 and add a copy of each
    for(int i = 1; i <= num_winners; i++) {
        if(cardDeck.contains(card.cardNum+i)) {
            cardDeck[card.cardNum+i].copies += n_times;
        }
    }
}

int PlayP2Game(const string &filename) {
    vector<string> lines = ReadFileAsLines(filename);

    unordered_map<int, ScratchCard> cardDeck;
    int min_card_num = 999999999;
    int max_card_num = 0;
    for(string line : lines) {
        ScratchCard card = ParseCard(line);
        cardDeck[card.cardNum] = card;

        if(card.cardNum < min_card_num) {
            min_card_num = card.cardNum;
        }
        if(card.cardNum > max_card_num) {
            max_card_num = card.cardNum;
        }
    }

    for(int i = min_card_num; i <= max_card_num; i++) {
        ApplyWinnings(cardDeck[i], cardDeck, cardDeck[i].copies);
    }

    int total_cards = 0;
    for(int i = min_card_num; i <= max_card_num; i++) {
        total_cards += cardDeck[i].copies;
    }
    return total_cards;
}
