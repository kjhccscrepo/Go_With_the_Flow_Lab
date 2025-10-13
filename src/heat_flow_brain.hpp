#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>


class Heat_Flow_Brain {
private:
    std::vector<double> heatFlowVector;
    std::vector<std::vector<int>> sinks_and_sources_sectors_and_temperature;
    int sinksourceIterations;
    int maxTemp = 3000;
    int initial_temperature;
    int sections;
    float k;
    void generateHeatFlowVector();
public:
    explicit Heat_Flow_Brain(const int &startTemp, const int &speciSections, const float &constant);
    bool validInput_Bool(const int &lowerBound, const int &upperBound, std::string inputString);
    std::string validInput(const int &lowerBound, const int &upperBound, std::string inputString);
    void specify_Sinks_and_Sources();

    std::vector<double> tick();
    double getCertainRod();
};