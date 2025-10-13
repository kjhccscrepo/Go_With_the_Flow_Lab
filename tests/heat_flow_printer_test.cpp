#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include "../src/heat_flow_printer.hpp"

#include <iostream>

int testMain() {
    std::vector<double> myTestVector;
    myTestVector.push_back(1.1);
    for (double i = 0; i < 20; i += 1) {
        myTestVector.push_back(i * 0.2 + 1);
    }
    std::cout << "Testing....\n\n";
    heat_flow_printer test(myTestVector);
    std::cout << test.prettyPrint_heat_flow() << "\n";
    return 0;
}

TEST_CASE( "it works" ) {
    REQUIRE( true == true );
}
