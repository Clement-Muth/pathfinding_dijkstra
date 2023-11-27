#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class City
{
public:
  string code;
  string name;
  int population;
  int elevation;

  vector<City> getCities(const string &filename) const;
  vector<vector<int>> getRoads(const string &filename) const;
};