#include "heat_flow.hpp"
heat_flow::heat_flow(HeatFlowConfiguration input) {
    this->heatFlow = input.get_HeatFlowVector();
    this->sinksAndSources = input.get_SinksAndSources();
}