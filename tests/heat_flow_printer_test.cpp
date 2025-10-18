#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/heat_flow_printer.hpp"
#include <iostream>

TEST_CASE( "it works" ) {
    std::vector<double> test1 = {100, 10, 10, 10, 120, 10, 10, 0};
    std::vector<double> test2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    heat_flow_printer printTest1(test1);
    heat_flow_printer printTest2(test2);
    std::stringstream expected;
    expected    << "+-----+----+----+----+-----+----+----+---+\n"
                << "| 100 | 10 | 10 | 10 | 120 | 10 | 10 | 0 |\n"
                << "+-----+----+----+----+-----+----+----+---+\n";
    REQUIRE( printTest1.prettyPrint_heat_flow() == expected.str() );
    expected.str("");
    expected.clear();
    expected    << "+---+---+---+---+---+---+---+---+---+---+----+\n"
                << "| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |\n"
                << "+---+---+---+---+---+---+---+---+---+---+----+\n";
    REQUIRE( printTest2.prettyPrint_heat_flow() == expected.str() );
}
TEST_CASE( "it works with decimals" ) {
    std::vector<double> testDecimals = {100.29, 0.0004, 80.2, 12.135};
    heat_flow_printer printTestDecimals(testDecimals);
    std::stringstream expectedDecimals;
    expectedDecimals    << "+--------+--------+------+--------+\n"
                        << "| 100.29 | 0.0004 | 80.2 | 12.135 |\n"
                        << "+--------+--------+------+--------+\n";
    REQUIRE( printTestDecimals.prettyPrint_heat_flow() == expectedDecimals.str() );
}