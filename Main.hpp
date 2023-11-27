#pragma once

#include <iostream>
#include "Algo.hpp"
#include "City.hpp"

#define cOut(message) std::cout << message << std::endl;
#define cErr(message) std::cerr << message << std::endl;

class Main
{
private:
  /* data */
public:
  void printHeader(City fromCity, City toCity) const
  {
    cOut("Author: Clément Nicolas Denis Muth and Romanie Marie Nadia De Meyer");
    cOut("Date: 11/26/2023");
    cOut("Course: CS311 (Data structures and Algorithms)");
    cOut("Description: Program to find the shortest route between cities");
    cOut("----------------------------------------------------------------");
    cOut("From City: " << fromCity.name << ", population " << fromCity.population
                       << ", elevation " << fromCity.elevation);
    cOut("To City: " << toCity.name << ", population " << toCity.population
                     << ", elevation " << toCity.elevation);
  }
};

