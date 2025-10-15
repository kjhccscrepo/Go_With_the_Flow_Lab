#include <iostream>
#include "src/heat_flow.hpp"
#include "src/heat_flow_printer.hpp"
#include "src/heat_flow_config.hpp"
#include "src/oops.hpp"

int main() {
  std::string inputString;
  std::cout << "Hello and Welcome to the Go With the Flow Lab!\n";
  std::string q1 = "Please enter your initial temperature for one-dimensional flow of heat in a thin rod\n";
  inputValidator Qa1 (0, 300 , q1);
  int startTemp = Qa1.oops(inputString);
  std::string q2 = "\nHow many segments would you like the the rod to be?\n";
  inputValidator Qa2 (4, 12 , q2);
  int segments = Qa2.oops(inputString);
  double constant;
  bool doubleCheck = true;
  while (doubleCheck) {
    std::cout << "\nWhat do you want the constant to be?\n";
    std::cout << "input:\t ";
    std::getline(std::cin, inputString);
    if (inputString.empty() || std::stod(inputString) < 0 || std::stod(inputString) > 10) {
      std::cout << "\nInvalid Input! Try again...\n";
    } else {
      constant = stod(inputString);
      doubleCheck = false;
    }
  }
  HeatFlowConfiguration config(startTemp, constant, segments);
  config.specify_Sinks_and_Sources();

  config.goAgain();

  heat_flow heatFlow(config);
  bool gameLoop = true;
  heat_flow_printer printer = heat_flow_printer(heatFlow.getHeatFlow());
  while (gameLoop) {
    std::cout << "\nYour heat flow is:\n";
    std::cout << printer.prettyPrint_heat_flow();
    std::cout << "\n(type \"1\" to exit, anything else will advance a tick.)";

    std::getline(std::cin, inputString);
    if (inputString.empty() || std::stod(inputString) != 1) {
      heatFlow.tick();
      printer = heat_flow_printer(heatFlow.getHeatFlow());
    }
    else {
      gameLoop = false;
    }
  }
  std::cout << "\n\nThank you for using the Go With the Flow Lab!\n";
  return 0;
}