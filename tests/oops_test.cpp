#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/oops.hpp"

inputValidator enterNumN1P1 (-1, 1, "Please enter an int between -1 and 1.\n");
TEST_CASE( "The number 0 is valid" ) {
    REQUIRE( enterNumN1P1.inBounds("0") == true );
}
TEST_CASE( "The number 1 is valid" ) {
    REQUIRE( enterNumN1P1.inBounds("1") == true );
}
TEST_CASE( "The number -1 is valid" ) {
    REQUIRE( enterNumN1P1.inBounds("-1") == true );
}
TEST_CASE( "The number 2 is NOT valid" ) {
    REQUIRE( enterNumN1P1.inBounds("2") == false );
}
TEST_CASE( "The number -2 is NOT valid" ) {
    REQUIRE( enterNumN1P1.inBounds("-2") == false );
}