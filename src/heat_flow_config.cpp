#include "heat_flow_config.hpp"
void HeatFlowConfiguration::generateHeatFlowVector() {
    for (int i = 0; i < sections; i++) {
        heatFlowVector.push_back(initial_temperature);
    }
}
void HeatFlowConfiguration::genSinkOrSource() {
    for (int i = 0; i < sections; i++) {
        isSourceOrSink.push_back(false);
    }
}
HeatFlowConfiguration::HeatFlowConfiguration(const int &startTemp, const double &constant, const int &speciSections) {
    this->initial_temperature = startTemp;
    this->sections = speciSections;
    this->k = constant;
    generateHeatFlowVector();
    genSinkOrSource();
}
void HeatFlowConfiguration::specify_Sinks_and_Sources() {
    std::string inputString;
    std::string heatSourceSink_message = "In what section would you like to place a heat sink/source?\n";
    inputValidator placeSourceSink (1, sections + 1, heatSourceSink_message);
    int bufferInt = placeSourceSink.oops(inputString) - 1;
    if (isSourceOrSink[bufferInt] == true) {
        std::cout << "That section is already a sink/source! Try again!\n";
        void specify_Sinks_and_Sources();
    }
    std::string temperatureAtSinkSource = "What would you like to be the temperature of the sink/source to be?\n";
    inputValidator tempSinkSource (0, maxTemp, temperatureAtSinkSource);
    int bufferIntTemperature = tempSinkSource.oops(inputString);
    std::cout << "A heat sink/source of " + std::to_string(bufferIntTemperature) + "∘C ";
    std::cout << "placed in section " + std::to_string(bufferInt) + "!\n";
    isSourceOrSink[bufferInt] = true;
    heatFlowVector[bufferInt] = bufferIntTemperature;
    std::string anotherOne = "\nWould you like to enter in another sink/source?\nyes = 1\nno = 0\n";
    inputValidator goAgain (0, 1, anotherOne);
    int noYes = goAgain.oops(inputString);
    if (noYes == 1) {
        void specify_Sinks_and_Sources();
    }
}
std::vector<double> HeatFlowConfiguration::get_HeatFlowVector() {
    return heatFlowVector;
}
std::vector<bool> HeatFlowConfiguration::get_SinksAndSources() {
    return isSourceOrSink;
}
double HeatFlowConfiguration::get_K() {
    return k;
}