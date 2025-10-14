#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "oops.hpp"
class HeatFlowConfiguration {
private:
    std::vector<double> heatFlowVector;
    std::vector<bool> isSourceOrSink;
    int maxTemp = 3000;
    int initial_temperature;
    int sections;
    float k;
    void generateHeatFlowVector();
    void genSinkOrSource();
public:
    explicit HeatFlowConfiguration(const int &startTemp, const float &constant, const int &speciSections = 8);
    bool validInput_Bool(const int &lowerBound, const int &upperBound, std::string inputString);
    std::string validInput(const int &lowerBound, const int &upperBound, std::string inputString);
    void specify_Sinks_and_Sources();

    std::vector<double> get_HeatFlowVector();
    std::vector<bool> get_SinksAndSources();

};