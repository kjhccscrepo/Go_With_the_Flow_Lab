#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/heat_flow_config.hpp"
int s = 8;
double k = 0.1;
HeatFlowConfiguration config1(10, k, s);
TEST_CASE( "generation of heat flow works" ) {
    for (int i = 0; i < s; i++) {
        REQUIRE( config1.get_HeatFlowVector()[i] == 10 );
    }
}
TEST_CASE( "making of a source/sink works, and doesnt change anything it shouldnt" ) {
    REQUIRE( config1.get_K() == k );
    config1.setSinkOrSource(0, 100);
    REQUIRE( config1.get_SinksAndSources()[0] == true );
    for (int i = 1; i < s; i++) {
        REQUIRE( config1.get_SinksAndSources()[i] == false );
    }
    REQUIRE( config1.get_K() == k );
}
std::vector<double> expectedResult = {100, 10, 10, 10, 10, 10, 10, 10};
TEST_CASE( "our vector is expected" ) {
    REQUIRE( config1.get_HeatFlowVector() == expectedResult );
}
TEST_CASE ( "we can add another source and a sink and it will will still work" ) {
    config1.setSinkOrSource(7, 0);
    config1.setSinkOrSource(4, 120);
    expectedResult = {100, 10, 10, 10, 120, 10, 10, 0};
    REQUIRE( config1.get_HeatFlowVector() == expectedResult );
    REQUIRE( config1.get_SinksAndSources()[0] == true );
    REQUIRE( config1.get_SinksAndSources()[1] == false );
    REQUIRE( config1.get_SinksAndSources()[2] == false );
    REQUIRE( config1.get_SinksAndSources()[3] == false );
    REQUIRE( config1.get_SinksAndSources()[4] == true );
    REQUIRE( config1.get_SinksAndSources()[5] == false );
    REQUIRE( config1.get_SinksAndSources()[6] == false );
    REQUIRE( config1.get_SinksAndSources()[7] == true );
}