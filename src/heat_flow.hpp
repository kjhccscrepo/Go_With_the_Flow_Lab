#pragma once
#include <vector>
#include "heat_flow_config.hpp"
#include "heat_flow_brain.hpp"

class heat_flow {
private:
    std::vector<double> heatFlow;
    std::vector<bool> sinksAndSources;
public:
    explicit heat_flow(HeatFlowConfiguration input);


};
