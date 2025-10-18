#include "../src/heat_flow_config.hpp"
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
void HeatFlowConfiguration::setSinkOrSource(int location, int temperature) {
    isSourceOrSink[location] = true;
    heatFlowVector[location] = temperature;
}
void HeatFlowConfiguration::specify_Sinks_and_Sources() {
    bool goLoop = true;
    while (goLoop) {
        std::string inputString;
        std::string heatSourceSink_message = "In what section would you like to place a heat sink/source?\n";
        inputValidator placeSourceSink (1, sections + 1, heatSourceSink_message);
        int bufferLocation = placeSourceSink.oops(inputString) - 1;
        if (isSourceOrSink[bufferLocation] == true) {
            std::cout << "That section is already a sink/source! Try again!\n";
            void specify_Sinks_and_Sources();
        }
        std::string temperatureAtSinkSource = "What would you like to be the temperature of the sink/source to be?\n";
        inputValidator tempSinkSource (0, 300, temperatureAtSinkSource);
        int bufferTemperature = tempSinkSource.oops(inputString);
        std::cout << "A heat sink/source of " + std::to_string(bufferTemperature) + "∘C ";
        std::cout << "placed in section " + std::to_string(bufferLocation) + "!\n";
        setSinkOrSource(bufferLocation, bufferTemperature);
        std::string anotherOne = "\nWould you like to enter in another sink/source?\nyes = 1\nno = 0\n";
        inputValidator goAgain (0, 1, anotherOne);
        if (goAgain.oops(inputString) != 1) {
            goLoop = false;
        }
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