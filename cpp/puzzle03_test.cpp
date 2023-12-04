#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle03.hpp"


/* Here is an example engine schematic:

467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..
*/

Grid sampleGrid = {
    .xSize=10,
    .ySize=10,
    .points=(char*)
        "467..114.."
        "...*......"
        "..35..633."
        "......#..."
        "617*......"
        ".....+.58."
        "..592....."
        "......755."
        "...$.*...."
        ".664.598.."
};

TEST_CASE("parse sample grid", "[part1]") {
    Grid actual = GridFromFile("../input/sample03");
    REQUIRE( actual.xSize == sampleGrid.xSize );
    REQUIRE( actual.ySize == sampleGrid.ySize );
    for(int x = 0; x < actual.xSize; x++) {
        for(int y = 0; y < actual.ySize; y++) {
            REQUIRE( actual.getAtXY(x, y) == sampleGrid.getAtXY(x, y) );
        }
    }
}

TEST_CASE("part numbers in sample grid", "[part1]") {
    vector<int> expected = {467, 35, 633, 617, 592, 755, 664, 598};
    REQUIRE( FindPartNumbers(sampleGrid) == expected );
}

TEST_CASE("sum of part numbers", "[part1]") {
    REQUIRE( SumOfPartNumbers("../input/sample03") == 4361 );
}
