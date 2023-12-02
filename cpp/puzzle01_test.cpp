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
