#include <string>
#include <vector>
#include <cctype>
#include <pystring.h>
#include "aocutil.hpp"

using std::vector;
using std::string;


struct CubeSet {
    int red = 0;
    int green = 0;
    int blue = 0;
    //
    bool operator==(const CubeSet&) const = default;
} ;

struct Game {
    int gameId;
    vector<CubeSet> cubeSets;
    //
    bool operator==(const Game&) const = default;
} ;

Game ParseGame(const string &line) {
    Game game;

    //ex: "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"
    //gameId starts at index 5 and goes to the colon
    int colon_pos = line.find(":");
    game.gameId = stoi(line.substr(5, colon_pos-5));

    vector<string> cube_set_strings;
    pystring::split(line.substr(colon_pos+2), cube_set_strings, "; ");
    for(string cube_set_to_parse : cube_set_strings) {
        CubeSet tempCubeSet;
        vector<string> cube_counts;
        pystring::split(cube_set_to_parse, cube_counts, ", ");
        for(string cube_count : cube_counts) {
            int space_pos = cube_count.find(" ");
            string count_part = cube_count.substr(0, space_pos);
            string color_part = cube_count.substr(space_pos+1, cube_count.size());
            if(color_part == "red") {
                tempCubeSet.red = stoi(count_part);
            }
            else if(color_part == "green") {
                tempCubeSet.green = stoi(count_part);
            }
            else if(color_part == "blue") {
                tempCubeSet.blue = stoi(count_part);
            }
        }
        game.cubeSets.push_back(tempCubeSet);
    }

    return game;
}

bool IsGamePossible(const Game &game, const CubeSet &referenceCubes) {
    for(CubeSet cube_set : game.cubeSets) {
        if(cube_set.red > referenceCubes.red) {
            return false;
        }
        if(cube_set.green > referenceCubes.green) {
            return false;
        }
        if(cube_set.blue > referenceCubes.blue) {
            return false;
        }
    }

    return true;
}

int P1Answer(const string &filename) {
    vector<string> lines = ReadFileAsLines(filename);

    CubeSet referenceCubes = {.red=12, .green=13, .blue=14};

    int gameIdTotal = 0;
    for(string line : lines) {
        Game tempGame = ParseGame(line);
        if(IsGamePossible(tempGame, referenceCubes)) {
            gameIdTotal += tempGame.gameId;
        }
    }

    return gameIdTotal;
}
