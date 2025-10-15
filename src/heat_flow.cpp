#include "heat_flow.hpp"
heat_flow::heat_flow(HeatFlowConfiguration input) {
    this->heatFlow = input.get_HeatFlowVector();
    this->sinksAndSources = input.get_SinksAndSources();
    this->k = input.get_K();
    this->ticks = 0;
}
void heat_flow::tick() {
    ticks++;
    for (int i = 0; i < heatFlow.size(); i++) {
        if (!sinksAndSources[i]) {
            // do code
            if (i == 0) {
                heatFlow[i] = heatFlow[i] + ( k * (heatFlow[i + 1] - ( 2 * heatFlow[i] ) + heatFlow[i]));
            }
            if (i != heatFlow.size() - 1) {
                heatFlow[i] = heatFlow[i] + ( k * (heatFlow[i + 1] - ( 2 * heatFlow[i] ) + heatFlow[i - 1]));
            } else {
                heatFlow[i] = heatFlow[i] + ( k * (heatFlow[i] - ( 2 * heatFlow[i] ) + heatFlow[i - 1]));
            }
        }
    }
}
double heat_flow::getCertainRod(const int &x) const {
    return this->heatFlow[x];
}
std::vector<double> heat_flow::getHeatFlow() const {
    return this->heatFlow;
}