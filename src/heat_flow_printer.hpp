#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
class heat_flow_printer {
private:
    std::stringstream myBuffer;
    void clearMyBuffer();
    std::vector<std::string> heat_flow_string;
    void print_border_generate();
    std::string myBorder;
    std::string getBorder();
public:
    explicit heat_flow_printer(const std::vector<double> &heat_flow_input,  int precision = 2);
    std::string prettyPrint_heat_flow();
};