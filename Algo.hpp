#pragma once

#include <vector>
#include "City.hpp"

#define cOut(message) std::cout << message << std::endl;

using namespace std;

typedef tuple<int, int, int, vector<int>> tupl;

class Algo
{
public:
  void printResult(long ans, vector<City> cities, City fromCity, City toCity, vector<int> path) const;
  long findShotestPath(const int cities, vector<vector<int>> &distances, int src, int dst, int stops, vector<int> &path) const;
};
