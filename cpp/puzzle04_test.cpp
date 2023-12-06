#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle04.hpp"

/*
Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19
Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83
Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36
Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11
*/

ScratchCard card1 = {.cardNum=1, .winningNumbers={41, 48, 83, 86, 17}, .numbersYouHave={83, 86,  6, 31, 17,  9, 48, 53}};
ScratchCard card2 = {.cardNum=2, .winningNumbers={13, 32, 20, 16, 61}, .numbersYouHave={61, 30, 68, 82, 17, 32, 24, 19}};
ScratchCard card3 = {.cardNum=3, .winningNumbers={ 1, 21, 53, 59, 44}, .numbersYouHave={69, 82, 63, 72, 16, 21, 14,  1}};
ScratchCard card4 = {.cardNum=4, .winningNumbers={41, 92, 73, 84, 69}, .numbersYouHave={59, 84, 76, 51, 58,  5, 54, 83}};
ScratchCard card5 = {.cardNum=5, .winningNumbers={87, 83, 26, 28, 32}, .numbersYouHave={88, 30, 70, 12, 93, 22, 82, 36}};
ScratchCard card6 = {.cardNum=6, .winningNumbers={31, 18, 13, 56, 72}, .numbersYouHave={74, 77, 10, 23, 35, 67, 36, 11}};

TEST_CASE("parse cards in sample", "[part1]") {
    REQUIRE( ParseCard("Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53") == card1 );
    REQUIRE( ParseCard("Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19") == card2 );
    REQUIRE( ParseCard("Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1") == card3 );
    REQUIRE( ParseCard("Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83") == card4 );
    REQUIRE( ParseCard("Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36") == card5 );
    REQUIRE( ParseCard("Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11") == card6 );
}

TEST_CASE("point totals for cards in sample", "[part1]") {
    REQUIRE( CardScore(card1) == 8 );
    REQUIRE( CardScore(card2) == 2 );
    REQUIRE( CardScore(card3) == 2 );
    REQUIRE( CardScore(card4) == 1 );
    REQUIRE( CardScore(card5) == 0 );
    REQUIRE( CardScore(card6) == 0 );
}

TEST_CASE("total points for sample", "[part1]") {
    REQUIRE( SumOfPoints("../input/sample04") == 13 );
}
