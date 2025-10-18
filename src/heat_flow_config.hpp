#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "oops.hpp"
class HeatFlowConfiguration {
private:
    std::vector<double> heatFlowVector;
    std::vector<bool> isSourceOrSink;
    int initial_temperature;
    int sections;
    double k;
    void generateHeatFlowVector();
    void genSinkOrSource();
public:
    explicit HeatFlowConfiguration(const int &startTemp, const double &constant, const int &speciSections = 8);
    void setSinkOrSource(const int &location, const int &temperature);
    void specify_Sinks_and_Sources();
    std::vector<double> get_HeatFlowVector();
    std::vector<bool> get_SinksAndSources();
    double get_K();
};