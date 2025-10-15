#include "heat_flow_printer.hpp"
heat_flow_printer::heat_flow_printer(const std::vector<double> &heat_flow_input, int precision) {
    for (int i = 0; i <= heat_flow_input.size() - 1; i++) {
        myBuffer << std::setprecision(precision);
        myBuffer << heat_flow_input[i];
        heat_flow_string.push_back(myBuffer.str());
        clearMyBuffer();
    }
    print_border_generate();
}
void heat_flow_printer::clearMyBuffer() {
    myBuffer.str("");
    myBuffer.clear();
}
void heat_flow_printer::print_border_generate() {
    for (int i = 0; i <= heat_flow_string.size() - 1; i++) {
        myBorder.push_back('+');
        for (int x = 0; x <= heat_flow_string.at(i).size() + 1; x++) {
            myBorder.push_back('-');
        }
    }
    myBorder.push_back('+');
    myBorder.push_back('\n');
}
std::string heat_flow_printer::getBorder() {
    return myBorder;
}
std::string heat_flow_printer::prettyPrint_heat_flow() {
    clearMyBuffer();
    // ROW 1
    myBuffer << getBorder();
    // ROW 2
    for (int a = 0; a <= heat_flow_string.size() - 1; a++) {
        myBuffer << "|";
        myBuffer << " ";
        myBuffer << heat_flow_string.at(a);
        myBuffer << " ";
    }
    myBuffer << "|\n";
    // ROW 3
    myBuffer << getBorder();
    return myBuffer.str();
}