#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/heat_flow.hpp"

TEST_CASE(" it generates the heat flow logic class correctly ") {
    HeatFlowConfiguration config(10, 0.1, 8);
    config.setSinkOrSource(0, 100);
    heat_flow testHeatFlow (config);
    std::vector<double> expectedVector = {100, 10, 10, 10, 10, 10, 10, 10};
    REQUIRE (testHeatFlow.getHeatFlow() == expectedVector);
    testHeatFlow.tick();
    expectedVector = {100, 19, 10, 10, 10, 10, 10, 10};
    REQUIRE (testHeatFlow.getHeatFlow() == expectedVector);
    testHeatFlow.tick();
    expectedVector = {100, 26.2, 10.9, 10, 10, 10, 10, 10};
    REQUIRE (testHeatFlow.getHeatFlow() == expectedVector);
}