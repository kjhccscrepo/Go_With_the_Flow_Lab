#include <iostream>
#include "src/heat_flow_brain.hpp"
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
  float constant;
  std::cout << "input:\t";
  std::cin >> constant;
  HeatFlowConfiguration config(startTemp, constant, segments);


  std::cout << "\nWhere do you want a heat source/sink to be?\n";
  std::vector<bool> sinkSource;
  std::cout << "(min: 1, max: " + std::to_string((segments + 1)) + "))\n";
  int sourcesinkInput;
  std::cout << "input:\t";
  std::cin >> sourcesinkInput;
  sinkSource.resize(segments);
  for (int i = 0; i < segments; i++) {
    sinkSource[i] = false;
  }
  sinkSource[sourcesinkInput] = true;



}
