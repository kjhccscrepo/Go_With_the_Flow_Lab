#pragma once
#include <vector>
#include "heat_flow_config.hpp"

class heat_flow {
private:
    std::vector<double> heatFlow;
    std::vector<bool> sinksAndSources;
public:
    explicit heat_flow(HeatFlowConfiguration input);
};
