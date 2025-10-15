#include <iostream>
#include "src/heat_flow.hpp"
#include "src/heat_flow_printer.hpp"
#include "src/heat_flow_config.hpp"
int main() {
  // Your driver program goes here
  int startTemp;
  std::cout << "Hello and Welcome to the Go With the Flow Lab!\n";
  std::cout << "Please enter your initial temperature for one-dimensional flow of heat in a thin rod\n";
  std::cout << "input:\t";
  std::cin >> startTemp;
  std::cout << "\nHow many segments would you like the the rod to be?\n";
  int segments;
  std::cout << "input:\t";
  std::cin >> segments;
  std::cout << "\nWhat do you want the constant to be?\n";
  double constant;
  std::cout << "input:\t";
  std::cin >> constant;
  HeatFlowConfiguration config(startTemp, constant, segments);
  config.specify_Sinks_and_Sources();
  heat_flow heatFlow(config);
  bool gameLoop = true;
  int intInput;
  heat_flow_printer printer = heat_flow_printer(heatFlow.getHeatFlow());
  while (gameLoop) {
    std::cout << "\nYour heat flow is:\n";
    std::cout << printer.prettyPrint_heat_flow();
    std::cout << "\n(type \"1\" to exit, anything else will advance a tick.)";
    std::cin >> intInput;
    if (intInput != 1) {
      gameLoop = false;
    } else {
      heatFlow.tick();
      printer = heat_flow_printer(heatFlow.getHeatFlow());
    }
  }
  std::cout << "\n\nThank you for using the Go With the Flow Lab!\n";
  return 0;
}