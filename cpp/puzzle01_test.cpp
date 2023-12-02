#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "puzzle01.hpp"


/* SAMPLE:
1abc2
pqr3stu8vw
a1b2c3d4e5f
treb7uchet
*/

TEST_CASE("calibration value for each sample line", "[part1]") {
    REQUIRE( GetCalibrationValue("1abc2") == 12 );
    REQUIRE( GetCalibrationValue("pqr3stu8vw") == 38 );
    REQUIRE( GetCalibrationValue("a1b2c3d4e5f") == 15 );
    REQUIRE( GetCalibrationValue("treb7uchet") == 77 );
}

TEST_CASE("sum of values for sample document", "[part1]") {
    REQUIRE( SumForDocument("../input/sample01") == 142 );
}

/* SAMPLE 2:
two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
*/

TEST_CASE("p2-revised-definition calibration value for each new sample line", "[part2]") {
    REQUIRE( GetCalibrationValue2("two1nine") == 29);
    REQUIRE( GetCalibrationValue2("eightwothree") == 83);
    REQUIRE( GetCalibrationValue2("abcone2threexyz") == 13);
    REQUIRE( GetCalibrationValue2("xtwone3four") == 24);
    REQUIRE( GetCalibrationValue2("4nineeightseven2") == 42);
    REQUIRE( GetCalibrationValue2("zoneight234") == 14);
    REQUIRE( GetCalibrationValue2("7pqrstsixteen") == 76);

}

TEST_CASE("sum of values for p2 sample document", "[part2]") {
    REQUIRE( SumForDocument2("../input/sample01-p2") == 281 );
}
