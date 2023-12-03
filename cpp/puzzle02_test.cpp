#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle02.hpp"

/*
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
*/

Game game1 = { .gameId=1, .cubeSets={ {.red=4, .blue=3, .green=0}, {.red=1, .blue=6, .green=2}, {.red=0, .blue=0, .green=2} } };
Game game2 = { .gameId=2, .cubeSets={ {.red=0, .green=2, .blue=1}, {.red=1, .green=3, .blue=4}, {.red=0, .green=1, .blue=1} } };
Game game3 = { .gameId=3, .cubeSets={ {.red=20, .green=8, .blue=6}, {.red=4, .green=13, .blue=5}, {.red=1, .green=5, .blue=0} } };
Game game4 = { .gameId=4, .cubeSets={ {.red=3, .green=1, .blue=6}, {.red=6, .green=3, .blue=0}, {.red=14, .green=3, .blue=15} } };
Game game5 = { .gameId=5, .cubeSets={ {.red=6, .green=3, .blue=1}, {.red=1, .green=2, .blue=2} } };

TEST_CASE("parsed game for each sample line", "[part1]") {
    REQUIRE( ParseGame("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green") == game1 );
    REQUIRE( ParseGame("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue") == game2 );
    REQUIRE( ParseGame("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red") == game3 );
    REQUIRE( ParseGame("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red") == game4 );
    REQUIRE( ParseGame("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green") == game5 );
}

/*
The Elf would first like to know which games would have been possible if
the bag contained only 12 red cubes, 13 green cubes, and 14 blue cubes?

In the example above, games 1, 2, and 5 would have been possible if the bag
had been loaded with that configuration. However, game 3 would have been
impossible because at one point the Elf showed you 20 red cubes at once;
similarly, game 4 would also have been impossible because the Elf showed
you 15 blue cubes at once.
*/

TEST_CASE("possibility check for each sample game against the sample reference cubes", "[part1]") {
    CubeSet referenceCubes = {.red=12, .green=13, .blue=14};
    REQUIRE( IsGamePossible(game1, referenceCubes) == true );
    REQUIRE( IsGamePossible(game2, referenceCubes) == true );
    REQUIRE( IsGamePossible(game3, referenceCubes) == false );
    REQUIRE( IsGamePossible(game4, referenceCubes) == false );
    REQUIRE( IsGamePossible(game5, referenceCubes) == true );
}

TEST_CASE("answer for sample", "[part1]") {
    REQUIRE( P1Answer("../input/sample02") == 8 );
}
