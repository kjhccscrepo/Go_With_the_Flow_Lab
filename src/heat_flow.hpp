#pragma once
#include <vector>
#include "heat_flow_config.hpp"
class heat_flow {
private:
    std::vector<double> heatFlow;
    std::vector<bool> sinksAndSources;
    double k;
    int ticks;
public:
    explicit heat_flow(HeatFlowConfiguration input);
    void tick();
    double getCertainRod(const int &x) const;
    std::vector<double> getHeatFlow() const;
};
