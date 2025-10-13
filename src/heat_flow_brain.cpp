#include "heat_flow_brain.hpp"

void Heat_Flow_Brain::generateHeatFlowVector() {
    for (int i = 0; i < sections; i++) {
        heatFlowVector.push_back(initial_temperature);
    }
}

Heat_Flow_Brain::Heat_Flow_Brain(const int &startTemp, const int &speciSections, const float &constant) {
    this->initial_temperature = startTemp;
    this->sections = speciSections;
    this->k = constant;
    generateHeatFlowVector();
}

bool Heat_Flow_Brain::validInput_Bool(const int &lowerBound, const int &upperBound, std::string inputString) {
    if (inputString.empty()) {
        return false;
    }
    for(char& c : inputString) {
        if (!(isdigit(c))) {
            return false;
        }
    }
    if (std::stoi(inputString) >= lowerBound && std::stoi(inputString) <= upperBound) {
        return true;
    }
    return false;
}

std::string Heat_Flow_Brain::validInput(const int &lowerBound, const int &upperBound, std::string inputString) {
    std::getline(std::cin, inputString);
    if (validInput_Bool(lowerBound, upperBound, inputString)) {
        return inputString;
    }
    return "-";
}

void Heat_Flow_Brain::specify_Sinks_and_Sources() {
    std::string bufferString = "-";
    std::cout << "In what section would you like to place a heat source/sink?\n";
    while (bufferString == "-") {
        bufferString = validInput(1, sections - 1, bufferString);
        if (bufferString == "-") {
            std::cout << "\nInvalid Input!\n";
        }
    }
    sinks_and_sources_sectors_and_temperature[sinksourceIterations].push_back(std::stoi(bufferString));
    std::cout << "What would you like to be the temperature of the source/sink?\n";
    bufferString = "-";
    while (bufferString == "-") {
        bufferString = validInput(0, maxTemp, bufferString);
        if (bufferString == "-") {
            std::cout << "\nInvalid Input!\n";
        }
    }
    sinks_and_sources_sectors_and_temperature[sinksourceIterations].push_back(std::stoi(bufferString));
    sinksourceIterations++;
}

std::vector<double> Heat_Flow_Brain::tick() {


    return {0};
}

double Heat_Flow_Brain::getCertainRod() {


    return 0.0;
}
